#include "game.h"
#include "map.h"
#include "player.h"
#include "monster.h"
#include "item.h"
#include "effect.h"
#include "ui.h"

int main() {
	//创建游戏窗口
	initgraph(SCREEN_W, SCREEN_H);
	//加载游戏胜利界面图片
	loadimage(&winImg, _T("win.png"), SCREEN_W, SCREEN_H);
	//加载游戏失败界面图片
	loadimage(&loseImg, _T("lose.png"), SCREEN_W, SCREEN_H);

	BeginBatchDraw();
	setfont(24, 0, _T("Consolas"));//设置字体
	setbkmode(TRANSPARENT);

	Map map;//创建地图对象
	initChests();//初始化5个宝箱的位置和图片
	initSwords();//初始化10把剑的位置和图片
	//生成地图
	map.generateFromImage();
	Player player;

	//创建攻击特效对象
	AttackEffect atkEffect;

	//设置按钮，游戏规则
	UI gameUI;

	//设置随机数种子，保证怪物每次移动不一样
	srand((unsigned int)time(NULL));
	//创建4只怪物
	Monster m1(8, 7);
	Monster m2(30, 6);
	Monster m3(12, 14);
	Monster m4(28, 15);

	bool gameOver = false;

	//游戏主循环
	while (!gameOver) {

		if (gameUI.isShowRule()) {
			cleardevice();
			gameUI.drawRule();
			//按ESC键关闭规则
			if (GetAsyncKeyState(VK_ESCAPE) & 1) {
				gameUI.toggleRule();
				Sleep(200);
			}
			FlushBatchDraw();
			continue;
		}

		//四只怪物全死则游戏结束
		if (!isWin && checkALLMonsterDead(m1, m2, m3, m4)) {
			isWin = true;
		}
		//如果游戏胜利的话，直接绘制游戏胜利的界面，不再走游戏界面
		if (isWin) {
			cleardevice();
			//绘制胜利画面
			putimage(0, 0, &winImg);
			FlushBatchDraw();

			//只有按ESC键才会退出游戏
			if (GetAsyncKeyState(VK_ESCAPE)) {
				gameOver = true;
			}
			continue;
		}

		//如果游戏失败的话，直接绘制游戏失败的界面
		if (isLose) {
			cleardevice();
			//绘制失败图片
			putimage(0, 0, &loseImg);
			FlushBatchDraw();
			continue;
		}

		cleardevice();
		map.draw();
		player.draw();

		//4只怪物的移动+绘制
		m1.move(map); m1.draw();
		m2.move(map); m2.draw();
		m3.move(map); m3.draw();
		m4.move(map); m4.draw();

		//绘制宝箱+检查玩家是否碰到宝箱
		drawChests();
		updateChests(player);
		//更新玩家受伤冷却（防止连续掉血）
		player.updateCD();
		//碰到任意一只怪兽，掉血15个点
		if (isCollide(player, m1))player.hurt(15);
		if (isCollide(player, m2))player.hurt(15);
		if (isCollide(player, m3))player.hurt(15);
		if (isCollide(player, m4))player.hurt(15);

		//绘制剑+检测玩家是否捡剑
		drawSwords();
		updateSwords(player);

		//更新并绘制攻击特效
		atkEffect.update();
		atkEffect.draw();


		//定义攻击怪物函数
		auto attackMonster = [&](Monster& m) {
			//判断玩家与怪物是否发生碰撞
			if (player.getX() == m.getX() && player.getY() == m.getY())
			{
				touchTimer++;
				//按空格键进行攻击！
				if (GetAsyncKeyState(VK_SPACE) & 0x8000)
				{
					if (playerSword > 0) {
						m.takeDamage(5);//怪物掉5滴血
						playerSword--;
						touchTimer = 0;//重置接触计时
						Sleep(200);//防止连续攻击

						//播放攻击对象
						atkEffect.play();
					}
				}
				//如果1.5秒后不攻击则玩家掉血
				else
				{
					if (touchTimer >= 38) {
						player.hurt(15);//玩家掉15滴血
						touchTimer = 0;//重置时间
					}
				}
			}
			else {
				touchTimer = 0;
			}
			};

		attackMonster(m1);
		attackMonster(m2);
		attackMonster(m3);
		attackMonster(m4);
		//血量为零则游戏结束
		if (player.isDead()) {
			isLose = true;

		}

		//玩家通过WASD键进行移动
		if (GetAsyncKeyState('W') & 0x8000)
		{
			player.move(0, -1, map);
			Sleep(120);
		}
		if (GetAsyncKeyState('S') & 0x8000)
		{
			player.move(0, 1, map);
			Sleep(120);
		}
		if (GetAsyncKeyState('A') & 0x8000)
		{
			player.move(-1, 0, map);
			Sleep(120);
		}
		if (GetAsyncKeyState('D') & 0x8000)
		{
			player.move(1, 0, map);
			Sleep(120);
		}

		//鼠标左键点击设置按钮
		if (GetAsyncKeyState(VK_LBUTTON) & 0x80000)
		{
			POINT p;
			GetCursorPos(&p);            // 获取屏幕鼠标坐标
			ScreenToClient(GetHWnd(), &p); // 转成游戏窗口内坐标

			int mx = p.x;
			int my = p.y;

			if (gameUI.isClickBtn(mx, my))
			{
				gameUI.toggleRule();
				Sleep(200);  // 防止重复点击
			}
		}

		setcolor(WHITE);
		outtextxy(10, 10, L"地牢探险 | WASD移动 | 空格攻击 | ESC退出");

		//ESC键退出游戏
		if (GetAsyncKeyState(VK_ESCAPE)) {
			gameOver = true;
		}

		// 最后画设置按钮 —— 置顶，不会被任何东西盖住
		gameUI.drawSettingBtn();
		//画音乐播放按钮
		gameUI.drawMusicBtn();

		FlushBatchDraw();
		Sleep(40);
	}

	//退出处理
	EndBatchDraw();
	//关闭图形窗口
	closegraph();
	return 0;
}
#include "game.h"
#include "item.h"
Chest chests[MAX_CHEST];
Sword swords[MAX_SWORD];

void initChests()
{
	//5个宝箱的位置
	chests[0] = { 5, 17, false };
	chests[1] = { 24, 4, false };
	chests[2] = { 33, 3, false };
	chests[3] = { 5, 10, false };
	chests[4] = { 35, 17, false };
	//加载宝箱图片
	for (int i = 0; i < MAX_CHEST; i++)
	{
		loadimage(&chests[i].img, _T("chest.png"), CELL, CELL);
	}
}

void drawChests()
{
	for (int i = 0; i < MAX_CHEST; i++)
	{
		if (!chests[i].opened)
		{
			int px = chests[i].x * CELL;
			int py = chests[i].y * CELL;
			putimage(px, py, &chests[i].img);
		}
	}
}

//玩家碰到宝箱：血量+10，上限100
void updateChests(Player& player)
{
	for (int i = 0; i < MAX_CHEST; i++)
	{
		if (!chests[i].opened &&
			player.getX() == chests[i].x &&
			player.getY() == chests[i].y)
		{
			chests[i].opened = true;
			player.hp += 10;//碰到宝箱增加10个点的血量
			if (player.hp > 100) {
				player.hp = 100;
			}
		}
	}
}

void initSwords()
{
	int swordPos[MAX_SWORD][2] = {
		{1, 5},
		{14, 3},
		{30, 11},
		{10, 12},
		{19, 18},
		{35, 8},
		{7, 17},
		{25, 15},
		{33, 18},
		{18, 6}
	};

	for (int i = 0; i < MAX_SWORD; i++)
	{
		swords[i].x = swordPos[i][0];
		swords[i].y = swordPos[i][1];
		swords[i].picked = false;
		loadimage(&swords[i].img, _T("sword.png"), CELL, CELL);
	}
}

//绘制所有未被拾取的剑
void drawSwords()
{
	for (int i = 0; i < MAX_SWORD; i++)
	{
		if (!swords[i].picked)
		{
			int px = swords[i].x * CELL;
			int py = swords[i].y * CELL;
			putimage(px, py, &swords[i].img);
		}
	}
}

//玩家捡剑逻辑
void updateSwords(Player& player)
{
	for (int i = 0; i < MAX_SWORD; i++)
	{
		if (!swords[i].picked &&
			player.getX() == swords[i].x &&
			player.getY() == swords[i].y)
		{
			swords[i].picked = true;
			playerSword++;//获得一次攻击次数
		}
	}
}
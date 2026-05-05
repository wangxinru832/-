#include "monster.h"
#include "player.h"

//初始化怪物的位置和血量
Monster::Monster(int startX, int startY) {
	x = startX;
	y = startY;
	hp = 10;
	moveDir = rand() % 4;//随机初始方向
	moveTimer = 0;//移动计时器清零
	//加载怪物图片
	loadimage(&slimeImg, _T("slime.png"), CELL, CELL);
}

int Monster::getX() const { return x; }
int Monster::getY() const { return y; }

bool Monster::isDead() { return hp <= 0; }

//怪物随机移动：定时移动，撞墙随机换方向
void Monster::move(Map& map) {
	moveTimer++;
	if (moveTimer < 15) return;//控制移动速度，15帧移动一次
	moveTimer = 0;

	int nx = x, ny = y;
	switch (moveDir) {
	case 0: ny--; break;//上
	case 1: ny++; break;//下
	case 2: nx--; break;//左
	case 3: nx++; break;//右
	}
	//如果下一步是墙或出界，就随机换一个方向
	if (map.getKind(nx, ny) == WALL || nx < 1 || nx >= 39 || ny < 1 || ny >= 19) {
		int newDir;
		do {
			newDir = rand() % 4;
		} while (newDir == moveDir);
		moveDir = newDir;
		return;
	}
	x = nx;
	y = ny;
}

void Monster::draw() {
	if (!isDead())//死了就不画了
	{
		int px = x * CELL;
		int py = y * CELL;
		putimage(px, py, &slimeImg);
	}
}

//怪物受到攻击扣血
void Monster::takeDamage(int damage) {
	hp -= damage;
	if (hp <= 0)hp = 0;
}
//判断玩家与怪物是否发生碰撞
bool isCollide(Player& p, Monster& m) {
	return(p.getX() == m.getX() && p.getY() == m.getY());
}

//判断四只怪物是否全部死亡
bool checkALLMonsterDead(Monster& m1, Monster& m2, Monster& m3, Monster& m4) {
	return m1.isDead() && m2.isDead() && m3.isDead() && m4.isDead();
}
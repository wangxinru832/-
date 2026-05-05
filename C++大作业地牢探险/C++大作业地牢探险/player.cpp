#include "player.h"

Player::Player() {
	//玩家初始位置
	x = 19;
	y = 9;
	hp = 100;
	//初始受伤冷却为0
	hurtCD = 0;
	hasPlayerImg = false;
	//安全加载图片
	if (loadimage(&playerImg, _T("player.png"), CELL, CELL))
	{
		hasPlayerImg = true;
	}
}

//玩家移动逻辑：判断下一个格子不是墙才会移动
void Player::move(int dx, int dy, Map& map) {
	int nx = x + dx;
	int ny = y + dy;
	if (map.getKind(nx, ny) != WALL) {
		x = nx;
		y = ny;
	}
}

//绘制玩家和右上角血条
void Player::draw() {
	int px = x * CELL;
	int py = y * CELL;
	//绘制玩家图片
	putimage(px, py, &playerImg);

	//绘制玩家血条
	setfillcolor(RED);
	bar(SCREEN_W - 210, 10, SCREEN_W - 210 + hp * 2, 30);
	rectangle(SCREEN_W - 210, 10, SCREEN_W, 30);

	setbkmode(TRANSPARENT);//设置文字背景透明
	setcolor(WHITE);
	wchar_t text[20];
	swprintf(text, 20, L"%d/100", hp);
	outtextxy(SCREEN_W - 110, 12, text);
}

void Player::updateCD() {
	if (hurtCD > 0)
		hurtCD--;
}

//被怪物碰撞后掉血
void Player::hurt(int damage) {
	if (hurtCD <= 0) {
		hp -= damage;
		//受伤后锁定60帧不能再受伤
		hurtCD = 60;
		if (hp < 0)hp = 0;
	}
}

//判断玩家是否死亡
bool Player::isDead() {
	return hp <= 0;
}

int Player::getX()const { return x; }
int Player::getY()const { return y; }
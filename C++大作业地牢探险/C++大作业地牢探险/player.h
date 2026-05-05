#pragma once
#include "game.h"
#include "map.h"

class Player {
private:
	int x, y;
	IMAGE playerImg;
	bool hasPlayerImg;//标记图片是否加载成功
	int hurtCD;//受伤冷却帧数，防止连续扣血
public:
	int hp;
	Player();
	//玩家移动
	void move(int dx, int dy, Map& map);
	//绘制玩家
	void draw();
	void updateCD();
	//玩家收到伤害，传入伤害值
	void hurt(int damage);
	//判断玩家血量为0时死亡
	bool isDead();
	int getX() const;
	int getY() const;
};
#pragma once
#include "game.h"
#include "map.h"
#include"player.h"
class Monster {
private:
	int x, y;
	IMAGE slimeImg;
	int moveDir;//怪物移动方向
	int moveTimer;//移动计时器，控制移动速度
public:
	int hp;
	Monster(int startX, int startY);
	int getX() const;
	int getY() const;
	bool isDead();
	void move(Map& map);
	//绘制怪物，死亡则不绘制
	void draw();
	void takeDamage(int damage);
};

//判断玩家是否与怪物发生碰撞（是否处于同一个格子上）
bool isCollide(Player& p, Monster& m);
//判断四只怪物是否全部死亡，用于判断游戏是否胜利
bool checkALLMonsterDead(Monster& m1, Monster& m2, Monster& m3, Monster& m4);
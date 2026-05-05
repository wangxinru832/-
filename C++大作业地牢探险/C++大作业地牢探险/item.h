#pragma once
#include "game.h"
#include "player.h"

//宝箱结构体
struct Chest
{
	int x, y;
	bool opened;
	IMAGE img;
};

//剑的结构体
struct Sword
{
	int x, y;
	bool picked;
	IMAGE img;
};

extern Chest chests[MAX_CHEST];
extern Sword swords[MAX_SWORD];

//初始化所有的宝箱位置、图片
void initChests();
//绘制所有未被拾取的宝箱
void drawChests();
//检测玩家是否碰到宝箱，加血
void updateChests(Player& player);

void initSwords();
void drawSwords();
void updateSwords(Player& player);
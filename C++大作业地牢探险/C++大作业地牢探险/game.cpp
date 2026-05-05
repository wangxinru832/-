#include "game.h"//引入合并后的头文件，包含所有常量和全局声明

int touchTimer = 0;//玩家和怪物碰撞接触计时
IMAGE winImg;//游戏胜利背景图
bool isWin = false;
int playerSword = 0;//玩家拾起剑的数量

IMAGE loseImg;//游戏失败背景图
bool isLose = false;
#include "game.h"//引入合并后的头文件，包含所有常量和全局声明

int touchTimer = 0;//玩家和怪物碰撞接触计时
IMAGE winImg;//游戏胜利背景图
bool isWin = false;
int playerSword = 0;//玩家拾起剑的数量

IMAGE loseImg;//游戏失败背景图
bool isLose = false;

// BOSS 全局变量
bool bossAppear = false;
bool bossLive = false;
int  bossHp = 15;
int  bossX = 18;  // 格子坐标
int  bossY = 8;
int bossTouchTimer = 0;

//播放背景音乐循环
void PlayBGM()
{
    // 播放wav 循环 + 后台不卡程序
    PlaySound(_T("C:\\Users\\admin\\Desktop\\bgm.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

//关闭背景音乐
void CloseBGM()
{
    // 停止音乐
    PlaySound(NULL, NULL, 0);
}
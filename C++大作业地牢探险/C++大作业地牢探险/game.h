#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<mmsystem.h>

using namespace std;

// 全局常量定义
#define CELL 35
#define SCREEN_W (40 * CELL)//窗口的宽度
#define SCREEN_H (20 * CELL)//窗口的高度

#define MAX_CHEST 5//最大宝箱数量
#define MAX_SWORD 10//最大剑的数量

#define FLOOR '.'//空地
#define WALL 'W'//墙壁
#define PLAYER 'P'

#define EFFECT_FRAME 15//攻击特效显示帧数

// 全局变量声明
extern int touchTimer;//控制玩家与怪物接触1秒后掉血
extern IMAGE winImg;//游戏胜利界面图片对象
extern bool isWin;//游戏胜利状态标记
extern int playerSword;//玩家当前拥有的剑的数量
extern IMAGE loseImg;//游戏失败界面图片对象
extern bool isLose;//游戏失败状态标记

#define SETTING_BTN_X (SCREEN_W/2-20)//按钮X坐标
#define SETTING_BTN_Y 8//按钮Y坐标
#define RULE_FRAME    9999//界面一直显示直到关闭

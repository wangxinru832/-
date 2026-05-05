#pragma once
#include "game.h"
//攻击特效类
class AttackEffect {
private:
	IMAGE effectImg;//特效图片加载
	int showFrame;//剩余显示帧数
	bool isActive;//特效是否激活显示
public:
	//构造函数：加载图片和初始化
	AttackEffect();
	//激活特效,触发全屏特效
	void play();
	//每帧更新特效倒计时
	void update();
	//绘制特效
	void draw();
};
#include "effect.h"
// 构造函数：加载特效图片，默认不激活
AttackEffect::AttackEffect()
{
	// 加载特效图片 effect.png，自动铺满整个窗口
	loadimage(&effectImg, _T("effect.png"), SCREEN_W, SCREEN_H);
	isActive = false;
	showFrame = 0;
}

// 播放特效：传入格子坐标，激活特效
void AttackEffect::play()
{
	isActive = true;
	showFrame = EFFECT_FRAME;
}

// 每帧更新特效倒计时
void AttackEffect::update()
{
	if (!isActive)
		return;

	showFrame--;
	// 帧数走完，关闭特效
	if (showFrame <= 0)
	{
		isActive = false;
	}
}

// 绘制特效
void AttackEffect::draw()
{
	if (!isActive)
		return;

	//从（0,0）开始绘制，全屏覆盖
	putimage(0, 0, &effectImg);
}
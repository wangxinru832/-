#pragma once
#include "game.h"
// UI类：设置按钮 + 游戏规则界面
class UI
{
private:
    bool showRule;       // 是否显示游戏规则
    IMAGE ruleImg;       // 游戏规则图片

public:
    IMAGE startImg;        // 开始界面背景图
    bool isGameStart;      // 游戏是否已开始

    // 记录文字区域坐标
    int textX;
    int textY;
    UI();                // 构造：加载规则图

    void DrawStartPage();  // 分装：绘制开始界面
    bool CheckStartClick();// 分装：检测点击开始

    void drawSettingBtn();// 绘制右上角 "..." 设置按钮
    bool isClickBtn(int mouseX, int mouseY);// 判断是否点击设置按钮
 
    void toggleRule();   // 切换规则显示/隐藏

    void drawRule();
    bool isShowRule();   // 返回是否正在显示规则
};
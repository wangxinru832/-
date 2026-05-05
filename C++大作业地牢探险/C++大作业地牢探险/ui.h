#pragma once
#include "game.h"
// UI类：设置按钮 + 游戏规则界面
class UI
{
private:
    bool showRule;       // 是否显示游戏规则
    IMAGE ruleImg;       // 游戏规则图片

    bool isMusicPlay;//标记当前 背景音乐是否正在播放

public:
    UI();                // 构造：加载规则图

    void drawSettingBtn();// 绘制右上角 "..." 设置按钮
    void drawMusicBtn();//绘制在设置右侧的音乐控制键

    bool isClickBtn(int mouseX, int mouseY);// 判断是否点击设置按钮
    bool isClickMusicBtn(int mouseX, int mouseY);//判断是否点击音乐按钮
    void toggleRule();   // 切换规则显示/隐藏
    void toggleMusic();//切换音乐，播放或停止
    void drawRule();
    bool isShowRule();   // 返回是否正在显示规则
};
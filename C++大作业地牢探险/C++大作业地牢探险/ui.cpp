#include "ui.h"
// 构造：加载规则图片
UI::UI()
{
    
    // 规则图片名：rule.png（全屏大小）
    loadimage(&ruleImg, _T("rule.png"), SCREEN_W, SCREEN_H);
    showRule = false;
    
    isGameStart = false;
    loadimage(&startImg, _T("start.png"),SCREEN_W,SCREEN_H);
    void DrawStartPage();

}

void UI::DrawStartPage()
{
    // 画背景图
    putimage(0, 0, SCREEN_W, SCREEN_H, &startImg,0,0);

    // 文字样式
    setbkmode(TRANSPARENT);
    setcolor(RGB(120,55,15));
    setfont(60, 0, _T("华文行楷"));

    // 居中显示点击开始
    int x = SCREEN_W / 2 - 100;
    int y = SCREEN_H / 2-30;
    outtextxy(x, y, L"点击开始");
}

bool UI::CheckStartClick()
{
    MOUSEMSG m = GetMouseMsg();
    if (m.uMsg == WM_LBUTTONDOWN)
    {
        return true;
    }
    return false;
}

// 绘制右上角 "..." 设置按钮
void UI::drawSettingBtn()
{
    //文字背景透明
    setbkmode(TRANSPARENT);
    // 字体大小、白色三点
    setfont(28, 0, _T("Consolas"));
    setcolor(RGB(255, 255, 255));

    // 画三个点 ... 位置居中在小方框里
    outtextxy(SCREEN_W / 2 - 8+6, 2-4, L"...");
}



// 判断鼠标是否点中了 "..."
bool UI::isClickBtn(int mouseX, int mouseY)
{
    // 对应顶部中间墙体格子的范围
    int btnL = SCREEN_W / 2 - CELL / 2+6;
    int btnR = SCREEN_W / 2 + CELL / 2+6;
    int btnT = 0-4;
    int btnB = CELL-4;

    if (mouseX >= btnL && mouseX <= btnR &&
        mouseY >= btnT && mouseY <= btnB)
    {
        return true;
    }
    return false;
}


// 切换规则显示/隐藏
void UI::toggleRule()
{
    showRule = !showRule;
}



// 绘制规则全屏图
void UI::drawRule()
{
    if (showRule)
    {
        putimage(0, 0, &ruleImg);
    }
}

// 返回是否正在显示规则
bool UI::isShowRule()
{
    return showRule;
}
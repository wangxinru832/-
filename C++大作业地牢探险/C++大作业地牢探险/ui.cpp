#include "ui.h"
// 构造：加载规则图片
UI::UI()
{
    // 规则图片名：rule.png（全屏大小）
    loadimage(&ruleImg, _T("rule.png"), SCREEN_W, SCREEN_H);
    showRule = false;

    isMusicPlay = false;//默认音乐未播放
}

// 绘制右上角 "..." 设置按钮
void UI::drawSettingBtn()
{
    //文字背景透明
    setbkmode(TRANSPARENT);
    // 字体大小、白色三点
    setfont(28, 0, _T("Consolas"));
    setcolor(RGB(255, 255, 255));

    // 定位到最顶部中间 墙体格子正中心
    int centerX = SCREEN_W / 2;

    // 画三个点 ... 位置居中在小方框里
    outtextxy(SCREEN_W / 2 - 8, 2, L"...");
}

void UI::drawMusicBtn() {
    setbkmode(TRANSPARENT);//设置文字背景透明，不遮挡地图墙体
    setfont(26, 0, _T("Consolas"));
    setcolor(WHITE);//白色音符符号

    outtextxy(SCREEN_W / 2 + 50, 2, L"♫");
}

// 判断鼠标是否点中了 "..."
bool UI::isClickBtn(int mouseX, int mouseY)
{
    // 对应顶部中间墙体格子的范围
    int btnL = SCREEN_W / 2 - CELL / 2;
    int btnR = SCREEN_W / 2 + CELL / 2;
    int btnT = 0;
    int btnB = CELL;

    if (mouseX >= btnL && mouseX <= btnR &&
        mouseY >= btnT && mouseY <= btnB)
    {
        return true;
    }
    return false;
}

// 检测是否点击了音乐按钮区域
bool UI::isClickMusicBtn(int mouseX, int mouseY)
{
    // 音乐按钮范围：三个点右侧相邻区域
    int btnL = SCREEN_W / 2 + 20;
    int btnR = SCREEN_W / 2 + 60;
    int btnT = 0;
    int btnB = CELL;

    return (mouseX >= btnL && mouseX <= btnR && mouseY >= btnT && mouseY <= btnB);
}

// 切换规则显示/隐藏
void UI::toggleRule()
{
    showRule = !showRule;
}

//切换背景音乐：没播放就播放，已播放就停止
void UI::toggleMusic()
{ 
       if(!isMusicPlay){
           // 打开音乐文件，设置别名 bgm
           mciSendString(TEXT("open bgm.mp3 alias bgm"), NULL, 0, NULL);
           // 循环播放
           mciSendString(TEXT("play bgm repeat"), NULL, 0, NULL);
           isMusicPlay = true;
       }
       else
       {
           // 停止音乐
           mciSendString(TEXT("stop bgm"), NULL, 0, NULL);
           // 关闭释放资源
           mciSendString(TEXT("close bgm"), NULL, 0, NULL);
           isMusicPlay = false;
       }
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
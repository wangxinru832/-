#pragma once
#pragma once
#include "game.h"

class Map {
private:
    char data[20][40];
    IMAGE imgWall;
    IMAGE imgFloor;
public:
    //加载图片
    void loadWallImage();

    //生成地图围墙和内部迷宫
    void generateFromImage();
    void draw();
    //获得指定坐标的地图元素，越界默认为墙壁
    char getKind(int x, int y);
};
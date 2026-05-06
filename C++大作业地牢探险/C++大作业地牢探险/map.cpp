#include "map.h"

void Map::generateFromImage() {
	//先把整个地图初始化为空地
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 40; x++) {
			data[y][x] = FLOOR;
		}
	}
	//绘制外围一圈围墙
	//上下边界墙
	for (int x = 0; x < 40; x++) {
		data[0][x] = WALL;
		data[19][x] = WALL;
	}
	//左右边界墙
	for (int y = 0; y < 20; y++) {
		data[y][0] = WALL;
		data[y][39] = WALL;
	}

	//手动搭建的内部迷宫墙壁
	for (int i = 2; i <= 6; i++) data[2][i] = WALL;
	data[3][6] = WALL; data[4][6] = WALL;
	for (int i = 3; i <= 5; i++) data[i][5] = WALL;

	for (int i = 10; i <= 16; i++) data[2][i] = WALL;
	data[3][16] = WALL;
	data[4][16] = WALL;
	data[3][15] = WALL;

	for (int i = 12; i <= 24; i++) data[5][i] = WALL;

	for (int i = 26; i <= 32; i++) data[2][i] = WALL;
	data[3][26] = WALL; data[4][26] = WALL;
	data[3][27] = WALL; data[4][27] = WALL;

	data[10][14] = WALL; data[11][14] = WALL;
	data[12][14] = WALL;
	for (int i = 28; i <= 34; i++) data[10][i] = WALL;
	for (int i = 11; i <= 13; i++) data[i][32] = WALL;
	for (int i = 34; i <= 36; i++) data[13][i] = WALL;

	for (int i = 2; i <= 8; i++) data[16][i] = WALL;
	for (int i = 28; i <= 36; i++) data[16][i] = WALL;
	//自行添加内部墙体
	data[1][18] = WALL; data[1][19] = WALL; data[1][20] = WALL; data[1][21] = WALL;

	data[6][3] = WALL; data[7][3] = WALL; data[8][3] = WALL; data[7][6] = WALL;
	data[7][7] = WALL; data[7][8] = WALL; data[7][9] = WALL; data[10][20] = WALL;
	data[10][21] = WALL; data[11][21] = WALL; data[12][1] = WALL; data[13][1] = WALL;
	data[13][2] = WALL; data[13][3] = WALL; data[14][10] = WALL; data[14][11] = WALL;
	data[15][11] = WALL; data[6][30] = WALL; data[6][31] = WALL; data[6][32] = WALL;

	data[15][5] = WALL; data[15][6] = WALL; data[16][5] = WALL; data[7][12] = WALL;
	data[8][12] = WALL; data[9][12] = WALL; data[11][6] = WALL; data[12][6] = WALL;
	data[12][8] = WALL; data[13][18] = WALL;  data[13][19] = WALL; data[14][19] = WALL;

	data[8][28] = WALL; data[9][28] = WALL; data[9][30] = WALL; data[17][12] = WALL;
	data[17][13] = WALL; data[16][15] = WALL; data[17][15] = WALL; data[18][1] = WALL;
	data[18][2] = WALL; data[4][2] = WALL; data[5][2] = WALL; data[5][4] = WALL;

	data[4][12] = WALL; data[4][14] = WALL; data[6][16] = WALL; data[7][16] = WALL;

	data[10][8] = WALL; data[14][23] = WALL; data[7][23] = WALL;
	data[11][8] = WALL;
	data[11][10] = WALL;
	data[11][7] = WALL;
	data[13][14] = WALL;

	data[7][22] = WALL;
	data[7][24] = WALL;
	data[7][26] = WALL;
	data[8][22] = WALL;
	data[8][26] = WALL;
	data[9][26] = WALL;

	data[12][22] = WALL;
	data[12][24] = WALL;
	data[14][22] = WALL;
	data[14][24] = WALL;
	data[15][26] = WALL;

	data[17][8] = WALL;
	data[17][18] = WALL;
	data[17][22] = WALL;
	data[18][10] = WALL;
	data[18][20] = WALL;
	data[18][25] = WALL;
	data[18][26] = WALL;
	data[18][27] = WALL;
	data[18][28] = WALL;

	data[5][11] = WALL; data[17][14] = WALL; data[9][17] = WALL; data[10][16] = WALL;
	data[11][15] = WALL; data[2][23] = WALL; data[3][21] = WALL; data[3][22] = WALL;
	data[3][23] = WALL; data[4][21] = WALL; data[12][21] = WALL; data[18][21] = WALL;
	data[9][24] = WALL; data[9][25] = WALL; data[2][36] = WALL; data[3][36] = WALL;
	data[4][36] = WALL; data[4][37] = WALL; data[4][38] = WALL; data[5][38] = WALL;
	data[6][38] = WALL; data[7][38] = WALL; data[8][38] = WALL; data[5][35] = WALL;
	data[6][34] = WALL; data[6][35] = WALL; data[7][34] = WALL; data[9][37] = WALL;
	data[10][37] = WALL; data[11][36] = WALL; data[11][37] = WALL;
}

void Map::loadWallImage() {
	// 加载 35×35 墙体贴图，只加载一次
	loadimage(&imgWall, _T("wall.png"), CELL, CELL);
	// 加载地板 35×35
	loadimage(&imgFloor, _T("floor.png"), CELL, CELL);
}
//绘制地图
void Map::draw() {
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 40; x++) {
			int px = x * CELL;
			int py = y * CELL;
			//绘制地板底色
			putimage(px, py, &imgFloor);
			if (data[y][x] == WALL) {
				putimage(px, py, &imgWall);
			}
		}
	}
}

//获得指定坐标的地图类型，越界直接返回墙
char Map::getKind(int x, int y) {
	//越界当做墙壁
	if (x < 0 || x >= 40 || y < 0 || y >= 20) return WALL;
	return data[y][x];
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int matrix[2][100000] = { 0 };  //两行10000列的数组 第一行存放是否占领 第二行存放联通道路
	int citys = 0;
	int roads = 0;
	int matrixRoad[10000][2] = { 0 };

	//用于向array中存放第二行输出值
	int input2line = 0;
	printf("城市数 道路数：");
	scanf("%d""%d", &citys,&roads);
	printf("是否被占领：");

	//输入数据看是否被占领
	for (int i = 0;i < citys;i++)
	{
		scanf("%d", &input2line);
		matrix[0][i] = input2line;
	}
	int kbCity1 = 0;
	int kbCity2 = 0;
	int start = 0;
	for (int i = 0;i < roads;i++)
	{
		printf("输入有道路连接的两个城市编号：");
		scanf("%d""%d", &kbCity1, &kbCity2);


		matrixRoad[i][0] = kbCity1;
		matrixRoad[i][0] = kbCity2;
//求出因获得这座城所带来的直接收益
		if ((matrix[0][kbCity1 - 1] == 0) && (matrix[0][kbCity2 - 1] == 1))
		{
					matrix[1][kbCity1 - 1]++;
		}
		else if ((matrix[0][kbCity2 - 1] == 0) && (matrix[0][kbCity1 - 1] == 1))
		{
					matrix[1][kbCity2 - 1]++;
		}
	
	}

	//获得这座城会带来的间接受益（经过）
	


	//判断最大值
	int largestCity = 0;
	int largestRoad = 0;
	for (int i = 0;i < roads;i++)
	{
		if (matrix[0][i] == 0)
		{
			if (matrix[1][i] > largestCity) 
			{
				largestRoad = matrix[1][i];
				largestCity = i + 1;
			}
		}
	}
	/*for (int j = 0;j < 2;j++) {
		for (int i = 0;i < citys;i++) {
			printf("%d", matrix[j][i]);
		}
		printf("\n");
	}*/
	int finalIncome = largestRoad + start;
	printf("%d %d", largestCity, finalIncome);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int matrix[2][100000] = { 0 };  //����10000�е����� ��һ�д���Ƿ�ռ�� �ڶ��д����ͨ��·
	int citys = 0;
	int roads = 0;
	int matrixRoad[10000][2] = { 0 };

	//������array�д�ŵڶ������ֵ
	int input2line = 0;
	printf("������ ��·����");
	scanf("%d""%d", &citys,&roads);
	printf("�Ƿ�ռ�죺");

	//�������ݿ��Ƿ�ռ��
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
		printf("�����е�·���ӵ��������б�ţ�");
		scanf("%d""%d", &kbCity1, &kbCity2);


		matrixRoad[i][0] = kbCity1;
		matrixRoad[i][0] = kbCity2;
//���������������������ֱ������
		if ((matrix[0][kbCity1 - 1] == 0) && (matrix[0][kbCity2 - 1] == 1))
		{
					matrix[1][kbCity1 - 1]++;
		}
		else if ((matrix[0][kbCity2 - 1] == 0) && (matrix[0][kbCity1 - 1] == 1))
		{
					matrix[1][kbCity2 - 1]++;
		}
	
	}

	//��������ǻ�����ļ�����棨������
	


	//�ж����ֵ
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
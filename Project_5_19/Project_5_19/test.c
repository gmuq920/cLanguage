#define _CRT_SECURE_NO_WARNINGS

////To make a calculator which can be used to (add,subtract,devide,miltiply)
//#include<stdio.h>
//void menu()
//{
//	printf("**************************\n");
//	printf("***** Calculator *********\n");
//	printf("***** 1.Add **************\n");
//	printf("***** 2.Subtract *********\n");
//	printf("***** 3.Multiply *********\n");
//	printf("***** 4.Devide ***********\n");
//	printf("***** 0.Exit *************\n");
//	printf("**************************\n");
//	printf("Which function do u choose: ");
//}
//int Add(int m, int n)
//{
//	return m + n;
//}
//int Sub(int m, int n)
//{
//	return m - n;
//}
//int Mul(int m, int n) 
//{
//	return m * n;
//}
//int Dev(int m, int n)
//{
//	return m / n;
//}
//
//int main() 
//{
//	
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int (*pfArr[5])(int, int) = { 0 ,Add,Sub,Mul,Dev };
//	int ret = 0;
//	do {
//		menu();
//		scanf("%d", &input);
//		if (0 == input) 
//		{
//			printf("Exit the calculator!\n");
//			break;
//		}
//		
//		else if(input > 0 && input < 5) 
//		{
//			printf("Input the first number:");
//			scanf("%d", &x);
//			printf("Input the second number:");
//			scanf("%d", &y);
//			printf("The answer is %d\n\n", pfArr[input](x, y));
//		}
//		else 
//		{
//			printf("Invalid input,please input again!\n\n");
//			
//		}
//	}
//
//	while (1);
//	return 0;
//}

//To make a calculator which can be used to (add,subtract,devide,miltiply)
//callback function
//#include<stdio.h>
//void menu()
//{
//	printf("**************************\n");
//	printf("***** Calculator *********\n");
//	printf("***** 1.Add **************\n");
//	printf("***** 2.Subtract *********\n");
//	printf("***** 3.Multiply *********\n");
//	printf("***** 4.Devide ***********\n");
//	printf("***** 0.Exit *************\n");
//	printf("**************************\n");
//	printf("Which function do u choose: ");
//}
//int Add(int m, int n)
//{
//	return m + n;
//}
//int Sub(int m, int n)
//{
//	return m - n;
//}
//int Mul(int m, int n)
//{
//	return m * n;
//}
//int Dev(int m, int n)
//{
//	return m / n;
//}
//void Calc(int(*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("Input the first number:");
//	scanf("%d", &x);
//	printf("Input the second number:");
//	scanf("%d", &y);
//	printf("The answer is %d\n", pf(x, y));
//	
//
//}
//
//int main()
//{
//
//	int input = 0;
//	int bool = 1;
//	
//
//	do {
//		menu();
//		scanf("%d", &input);
//		switch (input) 
//		{
//		case 1:
//			Calc(Add);
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Dev);
//			break;
//		case 0:
//			bool = 0;
//			printf("Exit\n");
//			break;
//		default:
//			printf("Invalid input,try again!\n");
//			break;
//		}
//	}
//	while (bool);
//	return 0;
//}


//
////日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
////以下为4个嫌疑犯的供词:
////A说：不是我。
////B说：是C。
////C说：是D。
////D说：C在胡说
////已知3个人说了真话，1个人说的是假话。
////现在请根据这些信息，写一个程序来确定到底谁是凶手。
//
////从a-d假设每次假设一个人为凶手， 判断真话数量是否为3；
//
//
//// A murder occurred somewhere in Japan. The police investigated and determined that the killer must be one of the four suspects.
//// The following are the testimonies of the four suspects:
//// A says: It wasn't me.
//// B says: It was C.
//// C says: It was D.
//// D says: C is lying.
//// It is known that 3 people are telling the truth, and 1 person is lying.
//// Now, write a program to determine who the killer is based on this information.
//
//// Try assuming each person (A-D) is the killer and check if the number of true statements is exactly 3.
//
//#include<stdio.h>
//int main() 
//{
//	for (char killer= 'A';killer <= 'D';killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3) 
//		{
//			printf("The killer is %c", killer);
//			break;
//		}
//	}
//	return 0;
//}


//Print Pascal's Triangle

#include<stdio.h>
int main() 
{
	int size = 0;
	printf("Input the size of the Pascal's Triangle:");
	scanf("%d", &size);
	int array[][50] = { 0 };
	for (int i = 1;i <= size;i++)
	{
		array[i][1] = 1;
		array[i][i] = 1;
		for (int j = 2;j < i;j++) 
		{
			array[i][j] = array[i - 1][j -1] + array[i - 1][j ];
		}
	}
	for (int m = 1;m <=size;m++) {
		for (int n = 1;n <= m;n++) {
			printf("%d ", array[m][n]);
		}
		printf("\n");
	}
	return 0;
}
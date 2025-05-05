#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>
int main()
{
	char boolPw = 'N';
	while ( boolPw != 'Y' && boolPw != 'y' ) 
	{
		char pw[20] = { 0 };
		char pwCheck[20] = { 0 };
		printf("请输入密码：");
		scanf( "%s" , pw );
		getchar();
		printf("请再次输入密码: ");
		scanf( "%s" , pwCheck );
		getchar();
		
		if (0 == strcmp(pw,pwCheck))
 		{
			printf( "您的密码是否为%s?(Y/N): " , pw );
;			scanf("%c", &boolPw);
			
		}
		else 
		{
			printf( "两次输入密码不同，请重新输入\n" );
		}
	}
	printf( "密码设置成功" );
	return 0;
}





//打印1-10
	//int i = 1;
	//while (i <= 10 )
	//{
	//	if (5 == i)  //常量写前面
	//	{
	//		break; //中止循环
	//		
	//		//continue;//只打印1234， 一直卡在if循环中一直continue，想跳过这段需要在前面加上i++

	//	}
	//	printf("%d ", i);
	//	i++;
	//}

	/*int ch = 0;
	while ((ch = getchar()) != EOF) {
		putchar(ch+1);
	}*/
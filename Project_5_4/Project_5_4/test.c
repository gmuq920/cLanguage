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
		printf("���������룺");
		scanf( "%s" , pw );
		getchar();
		printf("���ٴ���������: ");
		scanf( "%s" , pwCheck );
		getchar();
		
		if (0 == strcmp(pw,pwCheck))
 		{
			printf( "���������Ƿ�Ϊ%s?(Y/N): " , pw );
;			scanf("%c", &boolPw);
			
		}
		else 
		{
			printf( "�����������벻ͬ������������\n" );
		}
	}
	printf( "�������óɹ�" );
	return 0;
}





//��ӡ1-10
	//int i = 1;
	//while (i <= 10 )
	//{
	//	if (5 == i)  //����дǰ��
	//	{
	//		break; //��ֹѭ��
	//		
	//		//continue;//ֻ��ӡ1234�� һֱ����ifѭ����һֱcontinue�������������Ҫ��ǰ�����i++

	//	}
	//	printf("%d ", i);
	//	i++;
	//}

	/*int ch = 0;
	while ((ch = getchar()) != EOF) {
		putchar(ch+1);
	}*/
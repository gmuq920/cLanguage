#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"


//void SLTest01()
//{
//	SL sl;
//	SLInit(&sl);
//	SLPushBack(&sl, 1);
//	SLPushBack(&sl, 1);
//	SLPopBack(&sl);
//	SLDestroy(&sl);
//}

//void ContactTest01()
//{
//	Contact con;
//	ContactInit(&con);
//	ContactAdd(&con);
//	ContactAdd(&con);
//	ContactShow(&con);
//	ContactModify(&con);
//	ContactShow(&con);
//
//	ContactDestroy(&con);
//}
//int main()
//{
//	//LTest01();
//	ContactTest01(); 
//	
//	return 0;
//}
void menu()
{
	printf("\n");
	printf("*******************Contact**********************\n");
	printf("****** 1.Add Contact     2.Delate Contact ******\n");
	printf("****** 3.Modify Contact  4.Search Contact ******\n");
	printf("****** 5.Show Contacts   0.Exit           ******\n");
	printf("************************************************\n");
	printf("\n");

}

int main()
{
	Contact con;
	ContactInit(&con);
	int op = -1;
	do {
		menu();
		printf("Please choose a number: ");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			ContactAdd(&con);
			printf("Add successfully!");
			break;
		case 2:
			ContactDel(&con);
			break;
		case 3:
			ContactModify(&con);
			break;
		case 4:
			ContactFind(&con);
			break;
		case 5:
			ContactShow(&con);
			break;
		case 0:
			printf("Exit Contact!\n");
			break;
		default:
			printf("Invalid input number, please input again!\n");
			break;
		}
	} while (op != 0);
	
	ContactDestroy(&con);
	return 0;
}
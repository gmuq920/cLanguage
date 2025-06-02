 #pragma once
#include"Contact.h"
#include"Seqlist.h"


//Initialize the contact
void ContactInit(Contact*con) 
{
	SLInit(con);
}


void ContactDestroy(Contact* con) 
{
	SLDestroy(con);
}

void ContactAdd(Contact* con)
{
	//scanf the information(name +gender+age + tel + addr)
	peoInfo info;
	printf("Input the name: ");
	scanf("%s", info.name);

	printf("Input the gender: ");
	scanf("%s", info.gender);

	printf("Input the age: ");
	scanf("%d", &info.age);

	printf("Input the tel number: ");
	scanf("%s", info.tel);

	printf("Input the address: ");
	scanf("%s", info.addr);

	SLPushBack(con, info);
} 

int FindByName(Contact* con, char name[])
{
	for (int i = 0;i < con->size;i++)
	{
		if (strcmp(con->arr[i].name ,name)==0) 
		{
			return i;
		}
	}
	return -1;
}

void ContactDel(Contact* con) 
{
	char name[NAME_MAX];
	printf("Input the name to be deleted: ");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find<0) 
	{
		printf("Invalid name!\n");
		return;
	}
	SLErase(con, find);
	printf("Delete successful!\n");
}

void ContactShow(Contact* con) 
{
	printf("%s  %s  %s   %s  %s\n", "Name", "Gender", "age", "TelNumber", "Address");
	for (int i = 0;i < con->size;i++) 
	{
		printf("%3s %3s %3d %3s %3s\n",
			con->arr[i].name,
			con->arr[i].gender,
			con->arr[i].age,
			con->arr[i].tel,
			con->arr[i].addr);
	}
}

void ContactModify(Contact* con) 
{
	char name[NAME_MAX];
	printf("Input the name of the contact to be modified:");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0) 
	{
		printf("Invalid input name!");
		return;
	}

	printf("Input the new name: ");
	scanf("%s", con->arr[find].name);

	printf("Input the new gender: ");
	scanf("%s", con->arr[find].gender);

	printf("Input the new age: ");
	scanf("%d", &con->arr[find].age);

	printf("Input the new TelNumber: ");
	scanf("%s", con->arr[find].tel);

	printf("Input the new address: ");
	scanf("%s", con->arr[find].addr);
	
	printf("Modify successful\n");
}

void ContactFind(Contact* con) 
{
	char name[NAME_MAX];
	printf("Input the name to search:");
	scanf("%s", name);

	int find = FindByName(con, name); 
	if (find < 0)
	{
		printf("Invalid name!");
		return;
	}
	printf("%s  %s  %s   %s  %s\n", "Name", "Gender", "age", "TelNumber", "Address");
	printf("%3s %3s %3d %3s %3s\n",
		con->arr[find].name,
		con->arr[find].gender,
		con->arr[find].age,
		con->arr[find].tel,
		con->arr[find].addr);
}
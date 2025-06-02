#pragma once
#define NAME_MAX 20
#define GENDER_MAX 10
#define TEL_MAX 20
#define ADDR_MAX 100

typedef struct personInfo 
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}peoInfo;


//Change the seqlist name to contacts
typedef struct SeqList Contact;

//Initialize contacts
void ContactInit(Contact* con);

//Destroy contacts
void ContactDestroy(Contact* con);

//Add information
void ContactAdd(Contact* con);

//Delete information
void ContactDel(Contact* con);

//Modify
void ContactModify(Contact* con);

//Find
void ContactFind(Contact* con);

//Show the contact
void ContactShow(Contact* con);



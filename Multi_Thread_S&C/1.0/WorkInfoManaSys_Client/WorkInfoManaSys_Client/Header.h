#pragma once


typedef struct SWork
{
	int nNumb;			//¹¤ºÅ
	char sName[20];
	float fSala;
	char cSex;			//0 For Man ,1 For Woman
}WDATA;
typedef struct SHR
{
	int nNumb;			//HR±àºÅºÅ
	char sName[20];
	int nPrior;			//0 For Senior,1 For common
	char sPass[20];

}HDATA;

enum PORT{
	PORT1 = 20000,
	PORT2,
	PORT3,

};



enum ProtocalNumber{

	ADMIN_LOGIN = 50,

	WORK_ADD = 100,
	WORK_DELETE,
	WORk_MODIFY,
	WORK_SAVE,
	WORK_LOAD,

	HR_ADD = 200,
	HR_DELETE,
	HR_MODIFY,
	HR_SAVE,
	HR_LOAD,



};
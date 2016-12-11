#include"Stud.h"
#include<stdlib.h>



int TestIfExist(int i)
{
	SNode *p = g_pHead;
	while(p)
	{
		if(p->data.nNumb == i)
			return 1;
		p = p->pNext;
	}
	return 0;
}

void Add()
{//1.继续输入功能，2.页面逻辑问题
	char c=0;
	while(c != 'n'&& c != 'N')
	{
		DATA DNewStud;
		puts("请输入您要添加的学号：");		//按#号键退出；
		scanf_s("%d",&DNewStud.nNumb);
		if(TestIfExist(DNewStud.nNumb))
		{
			puts("你所输入的学号已存在，请重新输入！");
			continue;
		}

		puts("请输入您要添加的姓名和数学成绩【以空格隔开】：");
		scanf_s("%s %f",DNewStud.sName,sizeof(DNewStud.sName),&DNewStud.fMath);

		SNode *pNewStud = new SNode;
		pNewStud->data = DNewStud;
		pNewStud->pNext = NULL;


		SNode *p = g_pHead;
		if(!g_pHead)
		{
			g_pHead = pNewStud;
			puts("是否继续输入？【y/n】");
			fflush(stdin);
			c = getchar();
			continue;
		}
		while(p->pNext)
			p = p->pNext;
		p->pNext = pNewStud;

		Print();

		puts("是否继续输入？【y/n】");
		fflush(stdin);
		c = getchar();
	}
	return;

}

void Print()
{
	SNode *p = g_pHead;
	if(!p)
	{
		puts("系统中还没有任何学生信息，请返回菜单录入！");
		system("pause");
		return;
	}	
	do
	{
		printf("学号：%d\t\t姓名：%s\t\t数学：%.2f\t\t\n",p->data.nNumb,p->data.sName,p->data.fMath);
		p = p->pNext;

	}while(p);
	system("pause");

}


void Delete()
{
	char c=0,a=0;
	do
	{
		a=0;
		if(!g_pHead)
		{
			puts("系统中没有任何学生信息，请选择其他选项");
			system("pause");
			return;
		}
		DATA DNewStud;
		SNode *p = g_pHead;
		SNode *q = 0;
		puts("请输入您要删除的学号：");		//按#号键退出；
		scanf_s("%d",&DNewStud.nNumb);
		if(!TestIfExist(DNewStud.nNumb))
		{
			puts("你所输入的学号不存在，请重新输入！");
			Print();
			continue;
		}
		else
		{//
			while(p->data.nNumb != DNewStud.nNumb)
			{
				p = p->pNext;
			}
			puts("确认要删除以下信息【y/n】：");
			printf("学号：%d\t\t姓名：%s\t\t数学：%.2f\t\t\n",p->data.nNumb,p->data.sName,p->data.fMath);
			fflush(stdin);
			a = getchar();
			if(a == 'n'|| a == 'N')
				continue;
		}

		p = g_pHead;
		q = 0;

		if(p -> data.nNumb == DNewStud.nNumb)
		{
			if(p->pNext == 0)
				g_pHead = 0;
			else
			{
				g_pHead = p -> pNext;
				delete p;
			}
		}
		else
		{
			p = g_pHead;
			while(p)
			{
				if(p -> data.nNumb == DNewStud.nNumb)
					break;
				q = p;
				p = p -> pNext;
			}
			if(p -> pNext == 0)
			{
				q->pNext = 0;
				delete p;
			}
			else
			{
				q->pNext = p->pNext;
				delete p;
			}
		}
		Print();

		puts("是否继续删除？【y/n】");
		fflush(stdin);
		c = getchar();
	}while(c != 'n'&& c != 'N');
	return;


}
void Browse()
{
	Print();
}
void Search()
{

}
void Modify()
{

}


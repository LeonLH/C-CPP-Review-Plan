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
{//1.�������빦�ܣ�2.ҳ���߼�����
	char c=0;
	while(c != 'n'&& c != 'N')
	{
		DATA DNewStud;
		puts("��������Ҫ��ӵ�ѧ�ţ�");		//��#�ż��˳���
		scanf_s("%d",&DNewStud.nNumb);
		if(TestIfExist(DNewStud.nNumb))
		{
			puts("���������ѧ���Ѵ��ڣ����������룡");
			continue;
		}

		puts("��������Ҫ��ӵ���������ѧ�ɼ����Կո��������");
		scanf_s("%s %f",DNewStud.sName,sizeof(DNewStud.sName),&DNewStud.fMath);

		SNode *pNewStud = new SNode;
		pNewStud->data = DNewStud;
		pNewStud->pNext = NULL;


		SNode *p = g_pHead;
		if(!g_pHead)
		{
			g_pHead = pNewStud;
			puts("�Ƿ�������룿��y/n��");
			fflush(stdin);
			c = getchar();
			continue;
		}
		while(p->pNext)
			p = p->pNext;
		p->pNext = pNewStud;

		Print();

		puts("�Ƿ�������룿��y/n��");
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
		puts("ϵͳ�л�û���κ�ѧ����Ϣ���뷵�ز˵�¼�룡");
		system("pause");
		return;
	}	
	do
	{
		printf("ѧ�ţ�%d\t\t������%s\t\t��ѧ��%.2f\t\t\n",p->data.nNumb,p->data.sName,p->data.fMath);
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
			puts("ϵͳ��û���κ�ѧ����Ϣ����ѡ������ѡ��");
			system("pause");
			return;
		}
		DATA DNewStud;
		SNode *p = g_pHead;
		SNode *q = 0;
		puts("��������Ҫɾ����ѧ�ţ�");		//��#�ż��˳���
		scanf_s("%d",&DNewStud.nNumb);
		if(!TestIfExist(DNewStud.nNumb))
		{
			puts("���������ѧ�Ų����ڣ����������룡");
			Print();
			continue;
		}
		else
		{//
			while(p->data.nNumb != DNewStud.nNumb)
			{
				p = p->pNext;
			}
			puts("ȷ��Ҫɾ��������Ϣ��y/n����");
			printf("ѧ�ţ�%d\t\t������%s\t\t��ѧ��%.2f\t\t\n",p->data.nNumb,p->data.sName,p->data.fMath);
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

		puts("�Ƿ����ɾ������y/n��");
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


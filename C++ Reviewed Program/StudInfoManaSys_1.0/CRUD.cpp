#include "HEAD.h"
using namespace std;

void Print()
{
	POSITION pos = g_list.GetHeadPosition();
	DATA stud;

	while(pos)
	{
		stud = g_list.GetAt(pos);
		cout << "\tNUMB: " << stud.nNumb << "\tNAME: "<< stud.sName << "\tMATH: " << stud.fMath << endl;
		g_list.GetNext(pos);
	}

}
bool IsExist(int n)
{
	POSITION pos = g_list.GetHeadPosition();
	DATA stud;
	while(pos)
	{
		stud = g_list.GetAt(pos);
		if(stud.nNumb == n)
			return true;
		g_list.GetNext(pos);
	}
	return false;

}


void Browse()
{//���ܣ���ѧ�š��������ɼ�����
	cout << endl;
	Print();
	system("pause");
}
void Input()
{//���ܣ�1.����Ƿ��Ѵ��ڣ�����������ʾ�󷵻�������ӣ����������2.��ӳɹ����ӡ�������ݣ�3.���֮��ѯ���Ƿ������ӣ�4.��ÿ�����ʱ����ѡ���˳���Ӻ�����
	char c = 0;

	do
	{
		cout << "Please Input Student's Number [0000 For exit]:"<< endl;
		DATA stud;
		cin >> stud.nNumb;
		if(stud.nNumb == 0)
			return;
		if(IsExist(stud.nNumb))
		{
			cout << "Your Inputs were existed,Please Input agian:" <<endl;
			continue;
		}
		cout << "Please Input the Student's Name and Math scores[Seperate with an ' ']:" <<endl;
		cin >> stud.sName >>stud.fMath ;
		g_list.AddTail(stud);
		Print();
		cout << "Going on?[y/n]" << endl;
		fflush(stdin);
		c = getchar();	//ע��˴���getchar ������cin
	}while(c!='n' && c!='N');
	return;
	

}
void Delete()
{//���ܣ����ʼ�ȼ��ϵͳ���Ƿ������ݣ�1.����Ƿ���ڣ�������������ʾ�󷵻��������룬���������2.���������ӡ�����ݣ���ѯ��ȷ��ɾ����No�����ؼ������룩��
//3.�ɹ�ɾ�����ӡ�������ݣ���ѯ���Ƿ����ɾ��;4.ÿ������ɾ������ʱ����ѡ�񷵻��ϲ�˵���
	char c = 0,affirm = 0;
	Print();
	do
	{
		cout << "Please Input Student's Number [0000 For exit]:"<< endl;
		DATA stud;
		cin >> stud.nNumb;
		if(stud.nNumb == 0)
			return;
		if(!IsExist(stud.nNumb))
		{
			cout << "Your Inputs were Not Existed,Please Input agian:" <<endl;
			continue;
		}
		//�ҵ�����ӡ����ѧ����Ϣ��
		POSITION pos = g_list.GetHeadPosition();
		while(pos)
		{
			DATA stud1 = g_list.GetAt(pos);
			if(stud1.nNumb == stud.nNumb)
			{
				cout << "\tNUMB: " << stud1.nNumb << "\tNAME: "<< stud1.sName << "\tMATH: " << stud1.fMath << endl;
				break;
			}
			g_list.GetNext(pos);
		}
		//ȷ��ɾ����
		cout << "Confirm Delete this Information? [y/n]";
		fflush(stdin);
		affirm = getchar();
		if(affirm != 'y' && affirm !='Y')
			continue;
		g_list.RemoveAt(pos);
		cout << endl;
		Print();
		cout << "Going on?[y/n]" << endl;
		fflush(stdin);
		c = getchar();	//ע��˴���getchar ������cin

	}while(c!='n' && c!='N');
	return;

}
void Modify()
{//���ܣ�1.���ϵͳ���Ƿ������ݣ�2.�������ݺ����Ƿ���ڣ�3.���������ӡ�����ݣ���ѯ��ȷ���޸ģ�No�����ؼ������룩��
//4.�ɹ��޸ĺ��ӡ�������ݣ���ѯ���Ƿ����ɾ��;4.ÿ�������޸�����ʱ����ѡ�񷵻��ϲ�˵���
	char c = 0,affirm = 0;
	Print();
	do
	{
		cout << "Please Input Student's Number [0000 For exit]:"<< endl;
		DATA stud;
		cin >> stud.nNumb;
		if(stud.nNumb == 0)
			return;
		if(!IsExist(stud.nNumb))
		{
			cout << "Your Inputs were Not Existed,Please Input agian:" <<endl;
			continue;
		}
		//
		cout <<"Please Input Student's Name and Math score: [Seperate with ' ']"<<endl;
		cin >> stud.sName >> stud.fMath;
		cout <<endl;
		//�ҵ�����ӡ����ѧ����Ϣ��
		POSITION pos = g_list.GetHeadPosition();
		while(pos)
		{
			DATA stud1 = g_list.GetAt(pos);
			if(stud1.nNumb == stud.nNumb)
			{
				cout << "\tNUMB: " << stud1.nNumb << "\tNAME: "<< stud1.sName << "\tMATH: " << stud1.fMath << endl;
				break;
			}
			g_list.GetNext(pos);
		}
		//ȷ���޸ģ�
		cout << "\tConfirm Modify Above Information To:"<<endl;
		cout << "\tNUMB: " << stud.nNumb << "\tNAME: "<< stud.sName << "\tMATH: " << stud.fMath << "\t[y/n]?" << endl;
		fflush(stdin);
		affirm = getchar();
		if(affirm != 'y' && affirm !='Y')
			continue;
		g_list.SetAt(pos,stud);
		cout << endl;
		Print();
		cout << "Going on?[y/n]" << endl;
		fflush(stdin);
		c = getchar();	//ע��˴���getchar ������cin
	}while(c!='n' && c!='N');
	return;

}
void FindbyNumb()
{
	Print();
	char c = 0;
	do
	{
		cout << "Please Input the Numb for Finding:"<< endl;
		int n ;
		cin >> n;
		if(!IsExist(n))
		{
			cout << "Not Finded!Please Input again" << endl;
			continue;
		}
		POSITION pos = g_list.GetHeadPosition();
		while(pos)
		{
			DATA stud = g_list.GetAt(pos);
			if(n == stud.nNumb)
			{
				cout << "\tNUMB: " << stud.nNumb << "\tNAME: "<< stud.sName << "\tMATH: " << stud.fMath << endl;
				system("pause");
				break;	
			}
			g_list.GetNext(pos);
		}
		cout << "Going on?[y/n]" <<endl;
		fflush(stdin);
		c = getchar();

	}while(c != 'n' && c!='N');

}
void FindbyName()
{
	Print();
	char c = 0;

	do
	{
		cout << "Please Input the NAME for Finding:"<< endl;
		char s[20] ;
		cin >> s;

		POSITION pos = g_list.GetHeadPosition();
		int i = 0;
		while(pos)
		{
			DATA stud = g_list.GetAt(pos);
			if(!strcmp(s,stud.sName))
				{
					cout << "\tNUMB: " << stud.nNumb << "\tNAME: "<< stud.sName << "\tMATH: " << stud.fMath << endl;
					++i;
				}
			g_list.GetNext(pos);
			
		}
		if(!i)
			cout << "Not Finded! ";
		cout << "Going on?[y/n]" <<endl;
		fflush(stdin);
		c = getchar();

	}while(c != 'n' && c!='N');

}
void FindbyMath()
{
	Print();
	char c = 0;
	do
	{
		cout << "Please Input the Range of Math scores for Finding:[Seperate with ' ']"<< endl;
		float fMin,fMax;
		cin >> fMin >>fMax ;

		POSITION pos = g_list.GetHeadPosition();
		int i = 0;
		while(pos)
		{
			DATA stud = g_list.GetAt(pos);
			if(stud.fMath > fMin && stud.fMath < fMax)
			{
				cout << "\tNUMB: " << stud.nNumb << "\tNAME: "<< stud.sName << "\tMATH: " << stud.fMath << endl;
				++i;
			}
			g_list.GetNext(pos);
		}
		if(!i)
			cout << "Not Finded! ";
		cout << "Going on?[y/n]" <<endl;
		fflush(stdin);
		c = getchar();

	}while(c != 'n' && c!='N');

}


int Find()
{//���ܣ���ѧ�ŷ�Χ���ҡ����ɼ���Χ������������
	system("cls");
	puts("\n\n");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t*******                                *******");
	puts("\t\t*******     1.����ѧ�Ų���             *******");
	puts("\t\t*******     2.���ݳɼ���Χ����         *******");
	puts("\t\t*******     3.������������             *******");
	puts("\t\t*******     0.�˳�                     *******");
	puts("\t\t*******                                *******");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	int i;
	scanf_s("%d",&i);
	switch(i)
		{
			case 1:
				FindbyNumb();
				break;
			case 2:
				FindbyMath();
				break;
			case 3:
				FindbyName();
				break;
			case 0:
				break;
	}
	return i;
}
void Welcome()
{
	puts("\n\n");
	puts("\t\t*************************************************");
	puts("\t\t*************************************************");
	puts("\t\t*************************************************");
	puts("\t\t*************************************************");
	puts("\t\t********                                *********");
	puts("\t\t********    ��ӭ����ѧ����Ϣ����ϵͳ    *********");
	puts("\t\t********                                *********");
	puts("\t\t*************************************************");
	puts("\t\t*************************************************");
	puts("\t\t*************************************************");
	puts("\t\t************************************  byLeonLH  *");
	puts("\t\t*************************************************");
	system("pause");

}

int Menu()
{
	system("cls");
	puts("\n\n");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t*******                                *******");
	puts("\t\t*******         1.���ѧ����Ϣ         *******");
	puts("\t\t*******         2.���ѧ����Ϣ         *******");
	puts("\t\t*******         3.ɾ��ѧ����Ϣ         *******");
	puts("\t\t*******         4.�޸�ѧ����Ϣ         *******");
	puts("\t\t*******         5.����ѧ����Ϣ         *******");
	puts("\t\t*******         0.�˳�                 *******");
	puts("\t\t*******                                *******");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	int i;
	scanf_s("%d",&i);
	switch(i)
		{
			case 1:
				Browse();
				break;
			case 2:
				Input();
				break;
			case 3:
				Delete();
				break;
			case 4:
				Modify();
				break;
			case 5:
				while(Find())
					;
				break;
			case 0:
				break;
	}
	return i;

}
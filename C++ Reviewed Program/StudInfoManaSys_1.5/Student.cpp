#include "Student.h"
#include <iostream>
#include <afxtempl.h>
#include <stdio.h>


using namespace std;

CStudent::CStudent(void)
{
	Load();
}


CStudent::~CStudent(void)
{
	Save();
	m_list.RemoveAll();
}

int CStudent::Menu()
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
void CStudent::Print()
{
	POSITION pos = m_list.GetHeadPosition();
	DATA stud;

	while(pos)
	{
		stud = m_list.GetAt(pos);
		cout << "\tNUMB: " << stud.nNumb << "\tNAME: "<< stud.sName << "\tMATH: " << stud.fMath << endl;
		m_list.GetNext(pos);
	}

}
bool CStudent::IsExist(int n)
{
	POSITION pos = m_list.GetHeadPosition();
	DATA stud;
	while(pos)
	{
		stud = m_list.GetAt(pos);
		if(stud.nNumb == n)
			return true;
		m_list.GetNext(pos);
	}
	return false;

}


void CStudent::Browse()
{//���ܣ���ѧ�š��������ɼ�����
	cout << endl;
	Print();
	system("pause");
}
void CStudent::Input()
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
		m_list.AddTail(stud);
		Print();
		cout << "Going on?[y/n]" << endl;
		fflush(stdin);
		c = getchar();	//ע��˴���getchar ������cin
	}while(c!='n' && c!='N');
	return;
	

}
void CStudent::Delete()
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
		POSITION pos = m_list.GetHeadPosition();
		while(pos)
		{
			DATA stud1 = m_list.GetAt(pos);
			if(stud1.nNumb == stud.nNumb)
			{
				cout << "\tNUMB: " << stud1.nNumb << "\tNAME: "<< stud1.sName << "\tMATH: " << stud1.fMath << endl;
				break;
			}
			m_list.GetNext(pos);
		}
		//ȷ��ɾ����
		cout << "Confirm Delete this Information? [y/n]";
		fflush(stdin);
		affirm = getchar();
		if(affirm != 'y' && affirm !='Y')
			continue;
		m_list.RemoveAt(pos);
		cout << endl;
		Print();
		cout << "Going on?[y/n]" << endl;
		fflush(stdin);
		c = getchar();	//ע��˴���getchar ������cin

	}while(c!='n' && c!='N');
	return;

}
void CStudent::Modify()
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
		POSITION pos = m_list.GetHeadPosition();
		while(pos)
		{
			DATA stud1 = m_list.GetAt(pos);
			if(stud1.nNumb == stud.nNumb)
			{
				cout << "\tNUMB: " << stud1.nNumb << "\tNAME: "<< stud1.sName << "\tMATH: " << stud1.fMath << endl;
				break;
			}
			m_list.GetNext(pos);
		}
		//ȷ���޸ģ�
		cout << "\tConfirm Modify Above Information To:"<<endl;
		cout << "\tNUMB: " << stud.nNumb << "\tNAME: "<< stud.sName << "\tMATH: " << stud.fMath << "\t[y/n]?" << endl;
		fflush(stdin);
		affirm = getchar();
		if(affirm != 'y' && affirm !='Y')
			continue;
		m_list.SetAt(pos,stud);
		cout << endl;
		Print();
		cout << "Going on?[y/n]" << endl;
		fflush(stdin);
		c = getchar();	//ע��˴���getchar ������cin
	}while(c!='n' && c!='N');
	return;

}
void CStudent::FindbyNumb()
{
	Print();
	char c = 0;
	do
	{
		cout << "Please Input the Numb for Finding:"<< endl;
		int n ;
		fflush(stdin);
		cin >> n;
		if(!IsExist(n))
		{
			cout << "Not Finded!Please Input again" << endl;
			continue;
		}
		POSITION pos = m_list.GetHeadPosition();
		while(pos)
		{
			DATA stud = m_list.GetAt(pos);
			if(n == stud.nNumb)
			{
				cout << "\tNUMB: " << stud.nNumb << "\tNAME: "<< stud.sName << "\tMATH: " << stud.fMath << endl;
				system("pause");
				break;	
			}
			m_list.GetNext(pos);
		}
		cout << "Going on?[y/n]" <<endl;
		fflush(stdin);
		c = getchar();

	}while(c != 'n' && c!='N');

}
void CStudent::FindbyName()
{
	Print();
	char c = 0;

	do
	{
		cout << "Please Input the NAME for Finding:"<< endl;
		char s[20] ;
		fflush(stdin);
		cin >> s;
		POSITION pos = m_list.GetHeadPosition();
		int i = 0;
		while(pos)
		{
			DATA stud = m_list.GetAt(pos);
			if(!strcmp(s,stud.sName))
				{
					cout << "\tNUMB: " << stud.nNumb << "\tNAME: "<< stud.sName << "\tMATH: " << stud.fMath << endl;
					++i;
				}
			m_list.GetNext(pos);
			
		}
		if(!i)
			cout << "Not Finded! ";
		cout << "Going on?[y/n]" <<endl;
		fflush(stdin);
		c = getchar();

	}while(c != 'n' && c!='N');

}
void CStudent::FindbyMath()
{
	Print();
	char c = 0;
	do
	{
		cout << "Please Input the Range of Math scores for Finding:[Seperate with ' ']"<< endl;
		float fMin,fMax;
		fflush(stdin);
		cin >> fMin >>fMax ;
		POSITION pos = m_list.GetHeadPosition();
		int i = 0;
		while(pos)
		{
			DATA stud = m_list.GetAt(pos);
			if(stud.fMath > fMin && stud.fMath < fMax)
			{
				cout << "\tNUMB: " << stud.nNumb << "\tNAME: "<< stud.sName << "\tMATH: " << stud.fMath << endl;
				++i;
			}
			m_list.GetNext(pos);
		}
		if(!i)
			cout << "Not Finded! ";
		cout << "Going on?[y/n]" <<endl;
		fflush(stdin);
		c = getchar();

	}while(c != 'n' && c!='N');

}


int CStudent::Find()
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

//����C����ʵ�ֹ��ܣ��ٸ�д��C++����ʹ�ã�ifstream()�Ⱥ���
void CStudent::Load()
{

	FILE *fp ;
	errno_t err = fopen_s(&fp,"./stud.czy","r");
	if(err)
		return;
	DATA Data;
	while(fread(&Data,1,sizeof(DATA),fp))
		m_list.AddTail(Data);
	fclose(fp);

}

void CStudent::Save()
{

	FILE *fp ;
	errno_t err = fopen_s(&fp,"./stud.czy","w");
	if(err)
		return;
	POSITION pos = m_list.GetHeadPosition();
	while(pos)
	{

		DATA data = m_list.GetNext(pos);
		fwrite(&data,1,sizeof(DATA),fp);

	}
	fclose(fp);
	
}	

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
	puts("\t\t*******         1.浏览学生信息         *******");
	puts("\t\t*******         2.添加学生信息         *******");
	puts("\t\t*******         3.删除学生信息         *******");
	puts("\t\t*******         4.修改学生信息         *******");
	puts("\t\t*******         5.查找学生信息         *******");
	puts("\t\t*******         0.退出                 *******");
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
{//功能：按学号、姓名、成绩排序
	cout << endl;
	Print();
	system("pause");
}
void CStudent::Input()
{//功能：1.检查是否已存在，若存在则提示后返回重新添加，否则继续；2.添加成功后打印所有数据；3.添加之后询问是否继续添加；4.在每次添加时可以选择退出添加函数；
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
		c = getchar();	//注意此处用getchar 而不用cin
	}while(c!='n' && c!='N');
	return;
	

}
void CStudent::Delete()
{//功能：（最开始先检查系统中是否有数据）1.检查是否存在，若不存在则提示后返回重新输入，否则继续；2.若存在则打印该数据，并询问确认删除，No（返回继续输入）；
//3.成功删除后打印所有数据，并询问是否继续删除;4.每次输入删除数据时可以选择返回上层菜单；
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
		//找到并打印出该学生信息：
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
		//确认删除：
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
		c = getchar();	//注意此处用getchar 而不用cin

	}while(c!='n' && c!='N');
	return;

}
void CStudent::Modify()
{//功能：1.检查系统中是否有数据；2.输入数据后检查是否存在；3.若存在则打印该数据，并询问确认修改，No（返回继续输入）；
//4.成功修改后打印所有数据，并询问是否继续删除;4.每次输入修改数据时可以选择返回上层菜单；
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
		//找到并打印出该学生信息：
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
		//确认修改：
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
		c = getchar();	//注意此处用getchar 而不用cin
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
{//功能：按学号范围查找、按成绩范围、按姓名查找
	system("cls");
	puts("\n\n");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t*******                                *******");
	puts("\t\t*******     1.根据学号查找             *******");
	puts("\t\t*******     2.根据成绩范围查找         *******");
	puts("\t\t*******     3.根据姓名查找             *******");
	puts("\t\t*******     0.退出                     *******");
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

//先用C函数实现功能，再改写成C++函数使用：ifstream()等函数
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

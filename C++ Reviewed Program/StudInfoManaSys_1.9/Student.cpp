#include "Student.h"
#include <iostream>
#include <afxtempl.h>
#include <stdio.h>


using namespace std;

CStudent::CStudent(void)
{
//	Load();
}


CStudent::~CStudent(void)
{
	Save();
	m_list.RemoveAll();
}

void DATA::Input()
{//他这里不是往nNumb里输入，而是往结构体里面的成员变量输入（初始化）
	cout << "Please Input the Student's Infomation:(Number,Name,Sex,Chinese Score,Math Score and English Score.Seperated with ' ')" << endl;
	cin.clear(),cin.sync();
	cin >> nNumb >> sName >> nSex >> fChin >> fMath >> fEngl ;
	
}
void DATA::Print()
{
	cout << "\t" << nNumb << "\t" << sName << "\t" << (nSex?"Man":"Women") << "\t" << (nType?"Science":"Arts") << "\t" << fChin << "\t" << fMath << "\t" << fEngl ;
}
void SArt::Input()
{
	nType = 0;
	cout << "Please Input the Student's Infomation:(Number,Name,Sex,Chinese Score,Math Score,English Score,Geograph Score and History Score,Seperated with ' ')" << endl;
	cin.clear(),cin.sync();
	cin >> nNumb >> sName >> nSex >> fChin >> fMath >> fEngl >> fGeog >> fHist;
}
void SArt::Print()
{
	DATA::Print();
	cout << "\t" << fGeog << "\t" << fHist<<"\t" <<"\t" <<"\t"<<endl;
}
void SScn::Input()
{
	nType = 1;
	cout << "Please Input the Student's Infomation:(Number,Name,Sex,Chinese Score,Math Score,English Score,Physics Score,Chemical Score and Biology,Seperated with ' ')" << endl;
	cin.clear(),cin.sync();
	cin >> nNumb >> sName >> nSex >> fChin >> fMath >> fEngl >> fPhys>> fChem >> fBiol;

}
void SScn::Print()
{
	DATA::Print();
	cout <<"\t" <<"\t" << "\t" << fPhys << "\t" << fChem <<"\t" << fBiol  << endl;

}


void CStudent::Print()
{
	POSITION pos = m_list.GetHeadPosition();
	DATA *pstud;

	cout << "\t" << "NUMBER"<< "\t" <<"NAME"<< "\t" <<"SEX"<< "\t" <<"SUBCATE"<< "\t" <<"CHINESE"<< "\t" <<	"MATH"<< "\t" <<
		"ENGLISH"<< "\t" <<"GEOLOGY"<< "\t" <<"HISTORY"<< "\t" <<"PHYSICS"<< "\t" <<"CHEMIST"<< "\t" <<"BIOLOGY"<<endl;
	while(pos)
	{
		pstud = m_list.GetAt(pos);
		if(pstud->nType)
		{
			SScn *p = (SScn*)pstud;
			p->Print();
		}
		else
		{
			SArt *p = (SArt*)pstud;
			p->Print();
		}

		m_list.GetNext(pos);
	}

}

bool CStudent::IsExist(int n)
{
	POSITION pos = m_list.GetHeadPosition();
	DATA *pstud;
	while(pos)
	{
		pstud = m_list.GetAt(pos);
		if(pstud->nNumb == n)
			return true;
		m_list.GetNext(pos);
	}
	return false;

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
		int nType;
		cout << "Please Choose Subject Category[0 For Arts and 1 For Science]:" <<endl;
		cin >> nType;
		if(nType)
		{
			SScn *pdata = new SScn;
			pdata->Input();
			m_list.AddTail(pdata);
		}
		else
		{
			SArt *pdata = new SArt;
			pdata->Input();
			m_list.AddTail(pdata);
		}

		Print();
		cout << "Going on?[y/n]" << endl;
		fflush(stdin);
		c = getchar();	//注意此处用getchar 而不用cin
	}while(c!='n' && c!='N');
	return;
	

}
/*

POSITION* CStudent::MallocArray()
{
	POSITION *p = new POSITION [m_list.GetCount()+1];
	p[m_list.GetCount()] = nullptr;
	POSITION pos = m_list.GetHeadPosition();
	int i = 0;
	while (pos)
	{
		p[i] = pos;
		++i;
		m_list.GetNext(pos);
	}
	return p;
}
void CStudent::FreeArray(POSITION *p)
{
	delete []p;
}

void CStudent::Print(POSITION *p)
{
	int i = 0;
	DATA stud;
	while(p[i])
	{
		stud = m_list.GetAt(p[i]);
		cout << "\tNUMB: " << stud.nNumb << "\tNAME: "<< stud.sName << "\tMATH: " << stud.fMath << endl;
		++i;
	}


}

//函数指针,表外排序
void CStudent::Sort(funcp fp)
{
	POSITION * p = MallocArray();
	int i = 0,j = 0,min = 0;
	POSITION tmp = 0;
	p[i] = m_list.GetHeadPosition();
	p[j] = m_list.GetHeadPosition();
	
	while (p[i])
	{
		min = i;
		j = i+1;
		while (p[j])
		{
			if((*fp)(m_list.GetAt(p[j]),m_list.GetAt(p[min])))
				min = j;	
			j += 1;
		}
		tmp = p[i];
		p[i] = p[min];
		p[min] = tmp;
		++i;
	}
	Print(p);
	system("pause");
	FreeArray(p);
	return ;
}


int CStudent::Browse()
{//功能：按学号、姓名、成绩排序

	system("cls");
	puts("\n\n");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t*******                                *******");
	puts("\t\t*******     1.根据学号排序             *******");
	puts("\t\t*******     2.根据成绩排序             *******");
	puts("\t\t*******     3.根据姓名排序             *******");
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
			Sort(byNumb);
			break;
		case 2:
			Sort(byMath);
			break;
		case 3:
			Sort(byName);
			break;
		case 0:
			break;
	}
	return i;
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
{//载入的时候，先读标记，然后再根据标记判断类型，读取数据

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
{//存的时候先存标志，再根据标记，判断类型，写入数据

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

*/
//先用C函数实现功能，再改写成C++函数使用：ifstream()等函数
void CStudent::Load()
{//载入的时候，先读标记，然后再根据标记判断类型，读取数据

	FILE *fp ;
	errno_t err = fopen_s(&fp,"./stud.czy","r");
	if(err)
		return;
	DATA Data;
	char s[5];
	while(fread(s,1,sizeof(int),fp))
	{
//		if(nType = 
		fread(&Data,1,sizeof(DATA),fp);
		m_list.AddTail(Data);
	}
	fclose(fp);

}

void CStudent::Save()
{//存的时候先存标志，再根据标记，判断类型，写入数据

	FILE *fp ;
	errno_t err = fopen_s(&fp,"./stud.czy","w");
	if(err)
		return;
	POSITION pos = m_list.GetHeadPosition();
	while(pos)
	{

		DATA *pdata = m_list.GetNext(pos);
		if(pdata->nType)
		{
			fwrite("1",1,sizeof(int),fp);
			fwrite(pdata,1,sizeof(SScn),fp);
		}
		else
		{
			fwrite("0",1,sizeof(int),fp);
			fwrite(pdata,1,sizeof(SArt),fp);
		}
	}
	fclose(fp);
	
}	
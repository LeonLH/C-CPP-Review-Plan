#include "Student.h";
#include <iostream>

using namespace std;

void CStudent::FindbyNumb()
{
	Print();
	char c = 0;
	do
	{
		cout << "Please Input the Numb for Finding:"<< endl;
		int n ;
		cin.clear(),cin.sync();
		cin >> n;
		if(!IsExist(n))
		{
			cout << "Not Finded!Please Input again" << endl;
			continue;
		}
		POSITION pos = m_list.GetHeadPosition();
		while(pos)
		{
			DATA *pstud = m_list.GetAt(pos);
			if(n == pstud->nNumb)
			{
				Print(pstud);
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

void CStudent::FindbySex()
{
	Print();
	char c = 0;
	do
	{
		cout << "Please Input the Sex for Finding[0 For Man and 1 For Woman]:"<< endl;
		int n;
		cin.clear(),cin.sync();
		cin >> n;
		POSITION pos = m_list.GetHeadPosition();
		int i = 0;
		while(pos)
		{
			DATA *pstud = m_list.GetAt(pos);
			if(pstud->nSex == n)
			{
				Print(pstud);
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

void CStudent::FindbySubCate()
{
	Print();
	char c = 0;
	do
	{
		cout << "Please Input the Subject Category for Finding[0 For Arts and 1 For Science]:"<< endl;
		int n;
		cin.clear(),cin.sync();
		cin >> n;
		POSITION pos = m_list.GetHeadPosition();
		int i = 0;
		while(pos)
		{
			DATA *pstud = m_list.GetAt(pos);
			if(pstud->nType == n)
			{
				Print(pstud);
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
void CStudent::FindbyName()
{
	Print();
	char c = 0;

	do
	{
		cout << "Please Input the NAME for Finding:"<< endl;
		char s[20] ;
		cin.clear(),cin.sync();
		cin >> s;
		POSITION pos = m_list.GetHeadPosition();
		int i = 0;
		while(pos)
		{
			DATA *pstud = m_list.GetAt(pos);
			if(!strcmp(s,pstud->sName))
				{
					Print(pstud);
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
		cin.clear(),cin.sync();
		cin >> fMin >>fMax ;
		POSITION pos = m_list.GetHeadPosition();
		int i = 0;
		while(pos)
		{
			DATA *pstud = m_list.GetAt(pos);
			if(pstud->fMath > fMin && pstud->fMath < fMax)
			{
				Print(pstud);
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
void CStudent::FindbyGeog()
{
	Print();
	char c = 0;
	do
	{
		cout << "Please Input the Range of Geography scores for Finding:[Seperate with ' ']"<< endl;
		float fMin,fMax;
		cin.clear(),cin.sync();
		cin >> fMin >>fMax ;
		POSITION pos = m_list.GetHeadPosition();
		int i = 0;
		while(pos)
		{
			DATA *pstud = m_list.GetAt(pos);
			if(!pstud->nType)
			{
				SArt *p = (SArt*)pstud;
				if(p->fGeog> fMin && p->fGeog< fMax)
				{
					Print(pstud);
					++i;
				}
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
void CStudent::FindbyPhys()
{
	Print();
	char c = 0;
	do
	{
		cout << "Please Input the Range of Physics scores for Finding:[Seperate with ' ']"<< endl;
		float fMin,fMax;
		cin.clear(),cin.sync();
		cin >> fMin >>fMax ;
		POSITION pos = m_list.GetHeadPosition();
		int i = 0;
		while(pos)
		{
			DATA *pstud = m_list.GetAt(pos);
			if(pstud->nType)
			{
				SScn *p = (SScn*)pstud;
				if(p->fPhys> fMin && p->fPhys< fMax)
				{
					Print(pstud);
					++i;
				}
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

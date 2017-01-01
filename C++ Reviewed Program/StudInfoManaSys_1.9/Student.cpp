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
{//�����ﲻ����nNumb�����룬�������ṹ������ĳ�Ա�������루��ʼ����
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
		c = getchar();	//ע��˴���getchar ������cin
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

//����ָ��,��������
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
{//���ܣ���ѧ�š��������ɼ�����

	system("cls");
	puts("\n\n");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t*******                                *******");
	puts("\t\t*******     1.����ѧ������             *******");
	puts("\t\t*******     2.���ݳɼ�����             *******");
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
{//�����ʱ���ȶ���ǣ�Ȼ���ٸ��ݱ���ж����ͣ���ȡ����

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
{//���ʱ���ȴ��־���ٸ��ݱ�ǣ��ж����ͣ�д������

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
//����C����ʵ�ֹ��ܣ��ٸ�д��C++����ʹ�ã�ifstream()�Ⱥ���
void CStudent::Load()
{//�����ʱ���ȶ���ǣ�Ȼ���ٸ��ݱ���ж����ͣ���ȡ����

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
{//���ʱ���ȴ��־���ٸ��ݱ�ǣ��ж����ͣ�д������

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
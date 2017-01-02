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
	RemoveAll();
	m_list.RemoveAll();
}
void CStudent::RemoveAll()
{
	POSITION pos = m_list.GetHeadPosition();
	while(pos)
	{
		DATA *p = m_list.GetAt(pos);
		if(p->nType)
		{
			SScn *pS = (SScn*)p;
			delete pS;
		}
		else
		{
			SArt *pS = (SArt*)p;
			delete pS;
		}
		m_list.GetNext(pos);
	}

}

void DATA::Input()		//����������ȱʡֵ��
{//�����ﲻ����nNumb�����룬�������ṹ������ĳ�Ա�������루��ʼ����
	cout << "Please Input the Student's Infomation:(Number,Name,Sex,Chinese Score,Math Score and English Score.Seperated with ' ')" << endl;
	cin.clear(),cin.sync();
	cin >> nNumb >> sName >> nSex >> fChin >> fMath >> fEngl ;
	
}
void DATA::Print()
{
	cout << "\t" << nNumb << "\t" << sName << "\t" << (nSex?"Girl":"Boy") << "\t" << (nType?"Science":"Arts") << "\t" << fChin << "\t" << fMath << "\t" << fEngl ;
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
{//�����ӡ������������
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
void CStudent::Print(DATA* pData)
{//��ӡ����ָ��ָ�������
	cout << "\t" << "NUMBER"<< "\t" <<"NAME"<< "\t" <<"SEX"<< "\t" <<"SUBCATE"<< "\t" <<"CHINESE"<< "\t" <<	"MATH"<< "\t" <<
	"ENGLISH"<< "\t" <<"GEOLOGY"<< "\t" <<"HISTORY"<< "\t" <<"PHYSICS"<< "\t" <<"CHEMIST"<< "\t" <<"BIOLOGY"<<endl;
	if(pData->nType)
	{
		SScn *p = (SScn*)pData;
		p->Print();
	}
	else
	{
		SArt *p = (SArt*)pData;
		p->Print();
	}

}


void CStudent::Print(DATA** p)
{//��ӡ������ָ������
	int i = 0;
	cout << "\t" << "NUMBER"<< "\t" <<"NAME"<< "\t" <<"SEX"<< "\t" <<"SUBCATE"<< "\t" <<"CHINESE"<< "\t" <<	"MATH"<< "\t" <<
	"ENGLISH"<< "\t" <<"GEOLOGY"<< "\t" <<"HISTORY"<< "\t" <<"PHYSICS"<< "\t" <<"CHEMIST"<< "\t" <<"BIOLOGY"<<endl;
	while(p[i])
	{
		DATA *pstud = p[i];
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
		++i;
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
			DATA *pstud1 = m_list.GetAt(pos);
			if(pstud1->nNumb == stud.nNumb)
			{

				cout << "\tNUMB: " << pstud1->nNumb << "\tNAME: "<< pstud1->sName << "\tSEX: " << (pstud1->nSex?"Girl":"Boy")<< endl;
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
		//�ҵ�����ӡ����ѧ����Ϣ��
		POSITION pos = m_list.GetHeadPosition();
		DATA *pOldData = 0;
		DATA *pNewData = 0;
		while(pos)
		{
			pOldData = m_list.GetAt(pos);
			if(pOldData->nNumb == stud.nNumb)
			{
				
				Print(pOldData);		//��ӡ������ĳ��λ�õ���Ϣ
				break;
			}
			m_list.GetNext(pos);
		}
		//ѡ������
		int nType;
		cout << "Please Choose Subject Category[0 For Arts and 1 For Science]:" <<endl;
		cin >> nType;
		if(nType)
		{
			SScn *pSNewData = new SScn;
			pSNewData->Input();
			pNewData = (DATA*)pSNewData;

		}
		else
		{
			SArt *pSNewData = new SArt;
			pSNewData->Input();
			pNewData = (DATA*)pSNewData;
		}
		//ȷ���޸ģ�
		cout << "\tConfirm Modify Above Information To:"<<endl;
		Print(pNewData);
		fflush(stdin);
		affirm = getchar();
		if(affirm != 'y' && affirm !='Y')
			continue;

		
		delete pOldData;
		m_list.SetAt(pos,pNewData);

		cout << endl;
		Print();
		cout << "Going on?[y/n]" << endl;
		fflush(stdin);
		c = getchar();	//ע��˴���getchar ������cin
	}while(c!='n' && c!='N');
	return;

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
	puts("\t\t*******     2.������������             *******");
	puts("\t\t*******     3.�����Ա����             *******");
	puts("\t\t*******     4.�����Ŀ���Ʋ���         *******");
	puts("\t\t*******     5.������ѧ�ɼ�����         *******");
	puts("\t\t*******     6.���ݵ���ɼ�����         *******");
	puts("\t\t*******     7.��������ɼ�����         *******");
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
				FindbyName();
				break;
			case 3:
				FindbySex();
				break;
			case 4:
				FindbySubCate();
				break;
			case 5:
				FindbyMath();
				break;
			case 6:
				FindbyGeog();
				break;
			case 7:
				FindbyPhys();
				break;
			case 0:
				break;
	}
	return i;
}

/**/
DATA** CStudent::MallocArray()
{
	DATA** p = new DATA* [m_list.GetCount()+1];
	p[m_list.GetCount()] = nullptr;
	POSITION pos = m_list.GetHeadPosition();
	int i = 0;
	while (pos)
	{
		p[i] = m_list.GetAt(pos);
		++i;
		m_list.GetNext(pos);
	}
	return p;
}
DATA** CStudent::MallocScnArray()
{
	POSITION position = m_list.GetHeadPosition();
	int n = 0;
	while(position)
	{
		DATA* px = m_list.GetAt(position);
		if(px->nType)
			n += 1;
		m_list.GetNext(position);
	}
	DATA** p = new DATA* [n+1];
	p[n] = nullptr;
	POSITION pos = m_list.GetHeadPosition();
	int i = 0;
	while (pos)
	{
		DATA *pdata = m_list.GetAt(pos);
		if(pdata->nType)
		{
			p[i] = pdata;
			++i;
		}
		m_list.GetNext(pos);
	}
	return p;
}
DATA** CStudent::MallocArtArray()
{
	POSITION position = m_list.GetHeadPosition();
	int n = 0;
	while(position)
	{
		DATA* px = m_list.GetAt(position);
		if(!px->nType)
			n += 1;
		m_list.GetNext(position);
	}
	DATA** p = new DATA* [n+1];
	p[n] = nullptr;
	POSITION pos = m_list.GetHeadPosition();
	int i = 0;
	while (pos)
	{
		DATA *pdata = m_list.GetAt(pos);
		if(!pdata->nType)
		{
			p[i] = pdata;
			++i;
		}
		m_list.GetNext(pos);
	}
	return p;
}

void CStudent::FreeArray(DATA** p)
{
	delete []p;
}



//����ָ��,��������
void CStudent::Sort(funcp fp)
{
	DATA **p = 0;

	if(fp ==byBiol || fp == byPhys || fp == byChem)
		p = MallocScnArray();
	else if(fp == byHist || fp == byGeog)
		p = MallocArtArray();
	else
		p = MallocArray();

	int i = 0,j = 0,min = 0;
	DATA* tmp = 0;
	while (p[i])
	{
		min = i;
		j = i+1;
		while (p[j])
		{
			if((*fp)(p[j],p[min]))
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
	puts("\t\t*******     2.������������             *******");
	puts("\t\t*******     3.�����Ա�����             *******");
	puts("\t\t*******     4.������������             *******");
	puts("\t\t*******     5.������ѧ����             *******");
	puts("\t\t*******     6.������������             *******");
	puts("\t\t*******     7.����Ӣ������             *******");
	puts("\t\t*******     8.���ݵ�������             *******");
	puts("\t\t*******     9.������ʷ����             *******");
	puts("\t\t*******     10.������������            *******");
	puts("\t\t*******     11.���ݻ�ѧ����            *******");
	puts("\t\t*******     12.������������            *******");
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
			Sort(byName);
			break;
		case 3:
			Sort(bySex);
			break;
		case 4:
			Sort(byType);
			break;
		case 5:
			Sort(byMath);
			break;
		case 6:
			Sort(byChin);
			break;
		case 7:
			Sort(byEngl);
			break;
		case 8:
			Sort(byGeog);
			break;
		case 9:
			Sort(byHist);
			break;
		case 10:
			Sort(byPhys);
			break;
		case 11:
			Sort(byChem);
			break;
		case 12:
			Sort(byBiol);
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
	char s[4];
	DATA *pDATA;
	while(fread(s,1,sizeof(int),fp))
	{
		if(s[0] == '0')
		{
			SArt* pData = new SArt;
			fread(pData,1,sizeof(SArt),fp);
			pDATA = (DATA*)pData;
		}
		else
		{
			SScn* pData = new SScn;
			fread(pData,1,sizeof(SScn),fp);
			pDATA = (DATA*)pData;
		}
		m_list.AddTail(pDATA);
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
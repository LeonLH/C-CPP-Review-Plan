#include "Manager.h"
#include <stdio.h>
#include<string.h>


using namespace std;
extern TDATA g_curUser;
CManager::CManager(void)
{
	Load();
	TDATA data = {1000,"admin","admin",0};
	if(!IsExist("admin"))
		m_arr.Add(data);
}

CManager::~CManager(void)
{
	Save();
	m_arr.RemoveAll();
}

bool CManager::IsExist(int nNumb)
{
	int i = 0;
	while (i<m_arr.GetCount())
	{
		if(m_arr[i].nNumb == nNumb)
			break;
		++i;
	}
	if(i==m_arr.GetCount())
		return false;
	else
		return true;
}
bool CManager::IsExist(char * sName)
{
	int i = 0;
	while (i<m_arr.GetCount())
	{
		if(!strcmp(m_arr[i].sName,sName))
			break;
		++i;
	}
	if(i==m_arr.GetCount())
		return false;
	else
		return true;
}
bool CManager::IsPWRight(char *pName,char *pstr)
{
	int i = 0;
	while(i<m_arr.GetCount())
	{
		if(!strcmp(pName,m_arr[i].sName)&& !strcmp(pstr,m_arr[i].sPW))
			break;
		++i;
	}
	if(i==m_arr.GetCount())
		return false;
	else
	{
		g_curUser = m_arr[i];
		return true;
	}
}
int CManager::GetIndexFromNumb(int nNumb)
{//-1 For Not Found!
	int i = 0;
	while(i<m_arr.GetCount())
	{
		if(m_arr[i].nNumb == nNumb)
			break;
		++i;
	}
	if(i == m_arr.GetCount())
		return -1;
	return i;
}
void CManager::PrintNumb(int nNumb)
{
	int i = 0;
	while(i<m_arr.GetCount())
	{
		if(m_arr[i].nNumb == nNumb)
			break;
		++i;
	}
	if(i == m_arr.GetCount())
		return;
	
	cout <<'\t' << "NUMB" <<'\t'<< "NAME" <<'\t'<< "RITHTS" <<endl;
	TDATA data = m_arr[i];
	cout <<'\t' << data.nNumb <<'\t'<< data.sName <<'\t'<< (data.nPrio?"Common":"Senior") <<endl;
}


bool CManager::Login(void)
{//1:'#'For Exiting;2:此处的else if 有待验证

	cout<< "Please Input your Name and PassWord:[Seperated with ' ' And '#' For Exiting!]"<<endl;
	TDATA data;
	fflush(stdin);
	cin >> data.sName >> data.sPW ;
	if(!IsExist(data.sName))
	{
		cout<<"ID Not Exist,Please Try again "<<endl;
		return false;
	}
	else if(IsPWRight(data.sName,data.sPW))
		return true;
	else
	{
		cout<< "Your Password id Not Correct,Please Try again " <<endl;
		return false;	
	}

}
//先用C函数实现功能，再改写成C++函数使用：ifstream()等函数
void CManager::Load(void)
{
	FILE *fp ;
	errno_t err = fopen_s(&fp,"./teac.czy","r");
	if(err)
		return;
	if(!fp)
		return;
	TDATA datatmp;
	while(fread(&datatmp,1,sizeof(TDATA),fp))
		m_arr.Add(datatmp);
	fclose(fp);
}
void CManager::Save(void)
{
	FILE *fp;
	errno_t err = fopen_s(&fp,"./teac.czy","w");
	if(err)
		return;
	int i = 0;
	TDATA datatmp;
	while(i<m_arr.GetCount())
	{
		datatmp = m_arr[i];
		fwrite(&datatmp,1,sizeof(TDATA),fp);
		++i;
	}
	fclose(fp);


}

/*
void CStudent::Load()
{

	FILE *fp ;
	errno_t err = fopen_s(&fp,"./stud.czy","r");
	if(err)
		return;
	DATA Data;
	while(fread(&Data,1,sizeof(DATA),fp))
		g_list.AddTail(Data);
	fclose(fp);

}

void CStudent::Save()
{

	FILE *fp ;
	errno_t err = fopen_s(&fp,"./stud.czy","w");
	if(err)
		return;
	POSITION pos = g_list.GetHeadPosition();
	while(pos)
	{

		DATA data = g_list.GetNext(pos);
		fwrite(&data,1,sizeof(DATA),fp);

	}
	fclose(fp);
	g_list.RemoveAll();
}	

*/

void CManager::ChangePassWord(void)
{

}
int CManager::Menu(void)
{
	system("cls");
	puts("\n\n");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t*******                                *******");
	puts("\t\t*******         1.浏览账号信息         *******");
	puts("\t\t*******         2.添加账号信息         *******");
	puts("\t\t*******         3.删除账号信息         *******");
	puts("\t\t*******         4.修改账号信息         *******");
	puts("\t\t*******         5.查找账号信息         *******");
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
				Add();
				break;
			case 3:
				Delete();
				break;
			case 4:
				Modify();
				break;
			case 5:
			//	while(Find())
				//	;
				break;
			case 0:
				break;
	}
	return i;
}


void CManager::Add(void)
{
	cout<< "Please Input User's ID Number Name Password and Rights(0 For Senior)[Seperated with ' ']"<<endl;
	TDATA data;
	cin >> data.nNumb >> data.sName >> data.sPW >> data.nPrio;
	if(IsExist(data.nNumb))
	{
		cout << "This ID Number is already Exist,Please Try again:"<<endl;
		system("pause");
	}
	else
		m_arr.Add(data);
	

}


void CManager::Delete(void)
{
	cout<< "Please Input User's ID Number"<<endl;
	TDATA data;
	cin >> data.nNumb;
	if(IsExist(data.nNumb))
	{
		int i = GetIndexFromNumb(data.nNumb);
		data = m_arr[i];
		PrintNumb(data.nNumb);
		cout<< "Comfirm Delete it?[y/n]"<<endl;
		fflush(stdin);
		char c = getchar();
		if(c=='y')
		{
			m_arr.RemoveAt(i);
			Print();
			system("pause");
		}
	}
	return;
}

void CManager::Print(void)
{
	int n = m_arr.GetCount();
	int i = 0;
	TDATA data ;
	if(!n)
	{
		cout << "No Data" <<endl;
		return;
	}
	cout <<'\t' << "NUMB" <<'\t'<< "NAME" <<'\t'<< "RITHTS" <<endl;
	while(i<n)
	{
		data = m_arr[i];
		cout <<'\t' << data.nNumb <<'\t'<< data.sName <<'\t'<< (data.nPrio?"Common":"Senior") <<endl;
		++i;
	}

}
void CManager::Browse()
{
	Print();
	system("pause");
}
void CManager::Modify()
{
	int nNumb;
	cout << "Please Input the Number you want to Modify"<<endl;
	TDATA data;
	cin >> data.nNumb;
	nNumb = data.nNumb;
	if(data.nNumb == 1000)
		return;
	if(!IsExist(nNumb))
	{
		cout << "The Number is Not Exist,Please Try again"<<endl;
		system("pause");
		return;
	}
	else
	{

		cout << "Please Input the Name Password and Rights(0 For Senior)[Seperate with ' ']" <<endl;
		cin >> data.sName >> data.sPW >> data.nPrio;
		cout << "Are You Sure to Modify the following information:"<<endl;
		PrintNumb(nNumb);
		cout << "Into[y/n]?:"<<endl;
		cout <<'\t' << "NUMB" <<'\t'<< "NAME" <<'\t'<< "RITHTS" <<endl;
		cout <<'\t' << data.nNumb <<'\t'<< data.sName <<'\t'<< (data.nPrio?"Common":"Senior") <<endl;
		fflush(stdin);
		char c = getchar();
		int i = GetIndexFromNumb(nNumb);
		if(c=='y')
			m_arr.SetAt(i,data);

	}
	return;

}


void CManager::Find(int nNumb)
{

}



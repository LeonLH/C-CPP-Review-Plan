#include "Worker.h"


using namespace std;
CWorker::CWorker(void)
{
	Load();
}


CWorker::~CWorker(void)
{
	Save();
}

void CWorker::Load()
{

	FILE *fp ;
	errno_t err = fopen_s(&fp,"./worker.czy","r");
	if(err)
		return;
	WDATA wdata;
	while (fread(&wdata,1,sizeof(wdata),fp))
		m_Wor.push_back(wdata);
	fclose(fp);

}

void CWorker::Save()
{

	FILE *fp ;
	errno_t err = fopen_s(&fp,"./worker.czy","w");
	if(err)
		return;
	list<WDATA>::iterator i = m_Wor.begin();
	WDATA wdata;
	while(i!=m_Wor.end())
	{
		wdata = *i;
		fwrite(&wdata,1,sizeof(WDATA),fp);
		++i;
	}
	fclose(fp);
	
}	


/*
void CStudent::Load()
{//载入的时候，先读标记，然后再根据标记判断类型，读取数据

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

*/
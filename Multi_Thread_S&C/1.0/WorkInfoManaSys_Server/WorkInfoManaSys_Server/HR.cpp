#include "HR.h"


CHR::CHR(void)
{
	
	Load();
}


CHR::~CHR(void)
{
	Save();
}


void CHR::Load()
{

	FILE *fp ;
	errno_t err = fopen_s(&fp,"./HR.czy","r");
	if(err)
		return;
	HDATA hdata;
	while (fread(&hdata,1,sizeof(hdata),fp))
		m_Hr.push_back(hdata);
	if(m_Hr.empty())
	{
		hdata.nPrior = 0;
		hdata.nNumb =1000;
		strcpy_s(hdata.sName,6,"admin");
		strcpy_s(hdata.sPass,6,"admin");
		m_Hr.push_back(hdata);
	}

	fclose(fp);

}

void CHR::Save()
{

	FILE *fp ;
	errno_t err = fopen_s(&fp,"./HR.czy","w");
	if(err)
		return;
	unsigned int i = 0;
	HDATA hdata;
	while(i<m_Hr.size())
	{
		hdata = m_Hr[i];
		fwrite(&hdata,1,sizeof(hdata),fp);
		++i;
	}
	
	fclose(fp);
	
}	

bool CHR::IsNamePwMatch(HDATA h,HDATA &rh)
{
	int i = 0;
	while(i<m_Hr.size())
	{
		if(!strcmp(m_Hr[i].sName,h.sName))
			if(!strcmp(m_Hr[i].sPass,h.sPass))
			{
				rh = m_Hr[i];
				return true;
			}
		++i;
	}
	return false;
}

bool CHR::IsNamePwMatch(HDATA h)
{
	int i = 0;
	while(i<m_Hr.size())
	{
		if(!strcmp(m_Hr[i].sName,h.sName))
			if(!strcmp(m_Hr[i].sPass,h.sPass))
				return true;
		++i;
	}
	return false;
}

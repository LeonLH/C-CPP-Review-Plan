#pragma once
#include"Header.h"
#include<vector>


using namespace std;



//HRÐÅÏ¢´æ´¢ÈÝÆ÷Îª£ºstd::vector
class CHR
{


	vector <HDATA> m_Hr;

public:
	CHR(void);
	~CHR(void);
	void Load(void);
	void Save(void);
	bool IsNamePwMatch(HDATA h,HDATA &rh );
	bool IsNamePwMatch(HDATA h);
};


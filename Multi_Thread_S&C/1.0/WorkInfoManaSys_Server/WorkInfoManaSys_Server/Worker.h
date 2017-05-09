#pragma once
#include"Header.h"

#include<list>
using namespace std;
//员工信息存储容器为：std::list
class CWorker
{


	list <WDATA> m_Wor;
public:
	CWorker(void);
	~CWorker(void);
	void Load(void);
	void Save(void);
};


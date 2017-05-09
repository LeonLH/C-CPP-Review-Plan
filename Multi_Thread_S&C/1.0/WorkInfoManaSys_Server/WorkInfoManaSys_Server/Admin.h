#pragma once
#include "SockLH.h"
#include"Worker.h"
#include"HR.h"


class CAdmin
{



	CWorker m_Awor;
	CHR m_Ahr;
	CSockLH m_Asock;
	HDATA m_CurUsr;			//此处是否可定义成static静态变量，静态变量有什么作用？
	

public:
	CAdmin(void);
	~CAdmin(void);
	void Run(void);
	bool Login(CSockLH &socka);
	bool OnReceive(int nProt,CSockLH &socka);
	bool Connect(void);

	
};


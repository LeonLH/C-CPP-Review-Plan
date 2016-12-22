#include <stdio.h>
#include "HEAD.h"
//先用C函数实现功能，再改写成C++函数使用：ifstream()等函数
void Load()
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

void Save()
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
}	

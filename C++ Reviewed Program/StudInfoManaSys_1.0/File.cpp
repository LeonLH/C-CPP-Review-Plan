#include <stdio.h>
#include "HEAD.h"
//����C����ʵ�ֹ��ܣ��ٸ�д��C++����ʹ�ã�ifstream()�Ⱥ���
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

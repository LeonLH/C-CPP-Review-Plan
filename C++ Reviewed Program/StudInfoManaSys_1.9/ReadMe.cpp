//�������
//�°汾��Ԥ��ʵ�֣�ѧ����Ϣ���ݵ���չ������DATA������Ϊ��Input,Print,nNumb,sName,nType,nSex��
//1.�������ݴ洢��Ԫ���£�
/*
struct DATA
{
	int nNumb;
	char sName[20];
	int nSex;	//0 For Man,1 For Woman
	int nType;	//0 For �Ŀƣ�1 For ��ơ�	
	void Input();
	void Print();
	float fMath;
	float fChin;
	float fEngl;

};
struct SArt:DATA
{
	float fGeog;
	float fHist;
	void Input();
	void Print();

};
struct SScn:DATA
{
	float fBiol;
	float fPhys;
	float fChem;
	void Input();
	void Print();

};
*/
//2.CList�д洢�Ľڵ���DATA��ΪDATA*���ͣ��������ĺô��ǣ���ΪDATA�ĳ����������ģ�����CList�޷�ģ�廯����DATA*ȴ�Ǵ�С����ġ�ʹ�õ�ʱ����Ҫ�����ʲô���͸���DATA����ı�־����
//�����ǿ��ת������Ҫ��ָ�����ͣ����ø�ָ����в�����
//3.�����������ı䣬�������е��й������ݲ����Ľӿں��������޸ģ���Ҫ˼·�Ǿ����ȷ���DATA����ı�־���ٸ��ݱ�־����ǿ��ת��ָ�����ͣ�����ָ��������ݡ�
//4.��Ҫ����ע��ļ����������£�
//		->����CStudent����ʱһ��Ҫע��ѽڵ�ָ����ָ��Ķ��ϵĿռ�delete��;
//		->Sortʱfunctional pointer�����Ͷ�ΪDATA* ������뺯���ٸ�����Ҫת��DATA*��
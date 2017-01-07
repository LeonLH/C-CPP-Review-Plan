//本软件：
//下版本中预计实现：学生信息数据的扩展，例如DATA将增加为（Input,Print,nNumb,sName,nType,nSex）
//1.扩充数据存储单元如下：
/*
struct DATA
{
	int nNumb;
	char sName[20];
	int nSex;	//0 For Man,1 For Woman
	int nType;	//0 For 文科，1 For 理科。	
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
//2.CList中存储的节点又DATA变为DATA*类型，这样做的好处是：因为DATA的长度是伸缩的，导致CList无法模板化，但DATA*却是大小不变的。使用的时候需要具体的什么类型根据DATA里面的标志再来
//具体的强制转换成想要的指针类型，再用该指针进行操作。
//3.经上述两个改变，几乎所有的有关于数据操作的接口函数都得修改，主要思路是就是先访问DATA里面的标志，再根据标志进行强制转换指针类型，再用指针操作数据。
//4.需要额外注意的几个函数如下：
//		->析构CStudent对象时一定要注意把节点指针所指向的堆上的空间delete掉;
//		->Sort时functional pointer的类型都为DATA* 具体进入函数再根据需要转变DATA*。
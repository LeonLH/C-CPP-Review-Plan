#pragma once
struct DATA
{

};

class MyArray
{

public:
	MyArray(void);
	~MyArray(void);
	int Add(DATA NewElem);
	int Append(const MyArray& src);
};


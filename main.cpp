#include<iostream>

#define list_entry(ptr,type,member)((type*)((char*)(ptr)-(unsigned long)(&((type*)0)->member)))
#define offsetof(type,member)((size_t)&((type*)0)->member)    

#define container_of(ptr, type, member) ({ const typeof(((type*)0)->member)* __mptr = (ptr); (type*)((char*)__mptr - offsetof(type, member)); })
#include"DBL.cpp"
using namespace std;
int main()
{
	CTimeout* cl = new CTimeout;
	DBLinkNode* p = &(cl->node);
	char* ptr = (char*)&(cl->node);
	int offest=offsetof(CTimeout, node);
	cout << offest<<endl;
	cout << list_entry(ptr,CTimeout, node)<<endl;

	cout << container_of(ptr, CTimeout, node) <<endl;
}
// exp2-6.cpp: 定义应用程序的入口点。

// 这题要求实现以单链表的首结点值x为基准，将单链表进行分割，小于x的放左边，大于x的放右边。

#include "linklist.cpp"
using namespace std;

int main()
{
	LinkList* L;
	int arr[] = { 7,8,3,9,5,2,4,91,12,0,4,6};

	int len;
	len = sizeof(arr) / sizeof(arr[0]);

	CreatList(L);

	InitList(L,arr,len);

	//DivisionList(L,true);

	DivisionList(L, false);

	return 0;
}

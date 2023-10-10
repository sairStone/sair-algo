// CMakeList01.cpp: 定义应用程序的入口点。
//

#include "CMakeList01.h"

using namespace std;

int main()
{
	SqList * list; //此时list是一个野指针；没有分配空间内存
	ElemType arr[] = {1,2,3,4,5,6,7,8,9};
	
	int k = 10;
	int* pt;
	pt = &k;


	int arr_len = sizeof(arr) / sizeof(ElemType);

	InitList(list);

	CreateList(list, arr, arr_len);

	ShowList(list, arr_len);

	DestoryList(list);
	return 0;
}

//Q:为什么要用 &L呢？他不是本来就是指针吗？ 
//A：因为 & 是引用，这是在c++中才有的，引用即可以理解一个变量的另外一个名字，相当于给list起了一个别名

//传入的是 Sqlist* 类型的 list   可以这样理解
// （SqList *） &L = list;
//那么对L的操作就相当于对list指针操作是一样的

void InitList(SqList*& L)  //（SqList *） &L 即是一个 SqList *类型的引用，我们对L操作，也就相当于对传入的 SqList 类型的指针进行操作；
{
	L = (SqList*)malloc(sizeof(SqList));
	if (L != NULL) {
		L->length = 0;

	}
}

void CreateList(SqList*& L, ElemType a[], int n)
{
	int i = 0, k = 0;
	L = (SqList*)malloc(sizeof(SqList));
	if (L != NULL) {

		while (i < n) {
			L->data[i] = a[i];
			i++;
			k++;
		}

		L->length = k;
	}
}

void ShowList(SqList*& L, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << L->data[i] << std::endl;
	}
	std::cout << "The list length:" << L->length << std::endl;
}

void DestoryList(SqList* L)
{
	free(L);
	std::cout << "destory List success!";
}

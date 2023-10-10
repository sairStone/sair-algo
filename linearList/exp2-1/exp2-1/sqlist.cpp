#include "sqlist.h"

//创建表就是为了分配内存空间
void CreatList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList)); //由于顺序表为数组存储，所以不需要创建一个乘以MAXSIZE的空间，创建一个就行。
	std::cout << "-----顺序表创建成功！\n";
}

//初始化就是为了让顺序表不为空
void InitList(SqList*& L)
{
	L->length = 0;
	std::cout << "-----顺序表初始化成功！\n";
}

//判断是否为空
bool ListIsEmpty(SqList* L)
{
	if (L->length == 0) {
		return true;
	}
	else {
		return false;
	}
}

//判断是否已满
bool ListIsFull(SqList* L)
{
	//这个写法和上面判断是否为空一样的
	bool flag = L->length == MAXSIZE ? true : false;
	return flag;
}

// 根据题目插入abcde这5个元素到顺序表中
void ListInsert(SqList*& L)
{
	ElemType temp[] = { 'a','b','c','d','a','\0' }; // '\0' 是终止符，因为strlen()是计算'\0'之前的字符数量

	for (size_t i = 0; i < sizeof(temp) / sizeof(temp[0]); i++)
	{
		L->data[i] = temp[i];
		L->length++;
	}
}

// 在指定下标位置插入元素，后面的元素进行后移一位
bool ListInsertByIndex(SqList*& L, unsigned int index, ElemType ch)
{
	//后移元素的话，从后面向前面遍历是最合适的
	for (int i = L->length - 1; i >= index; i--)
	{
		L->data[i + 1] = L->data[i];
	}
	L->data[index] = ch;
	L->length++;  // 顺序表长度加一

	return true;
}

int ListLength(SqList* L)
{
	return L->length;
}

void DispList(SqList* L)
{
	std::cout << "\n开始输出顺序表：\n";

	// 根据顺序表的长度来输出
	for (size_t i = 0; i < L->length; i++)
	{
		std::cout << L->data[i];
		printf_s(":%p", &L->data[i]);
		std::cout << "\n";
	}

	//下面两句测试语句，输出结果后可以很清晰的明白顺序表内存中的存储位置是相邻的，因为是char,所以占据一个字节,而没有元素的值，结果是随机的
	//std::cout << L->data[7] << ":" << sizeof(L->data[7]) << typeid(L->data[7]).name();
	//printf_s(":%p", &L->data[7]);
}

// 输出指定序号（下标）的元素
ElemType GetElemByIndex(SqList* L, unsigned int index)
{
	if (index > L->length) {
		std::cout << "指定序号并没有元素！\n";
		return NULL;
	}
	else {
		return L->data[index];
	}
}

//输出找到元素的下标
int GetElemByValue(SqList* L, ElemType value)
{
	for (size_t i = 0; i < L->length; i++)
	{
		if (value == L->data[i]) {
			//std::cout << "index is " << i;
			return i;
		}
	}
	return -1; // 返回-1，因为下标没有负数，返回为NULL时，就无法判断是下标0（一般来说 0 和 NULL 相等）
}

// 删除指定序号（下标）的元素,其他元素向前移动
ElemType DelElemByIndex(SqList*& L, unsigned int index)
{
	if (index >= L->length) {
		std::cout << "指定序号并没有元素！\n";
		return -1;
	}
	else {
		//保存要删除的元素
		ElemType temp = L->data[index];
		//前移元素，从前面向后面遍历
		while (index < L->length)
		{
			L->data[index] = L->data[index + 1];
			index++;
		}
		L->length--;
		L->data[index] = NULL;

		return temp;
	}


}

// 删除指定的元素
bool DelElemByValue(SqList*& L, ElemType value)
{
	for (size_t i = 0; i < L->length; i++)
	{
		if (value == L->data[i]) {
			int j = i;
			while (j < L->length)
			{
				L->data[j] = L->data[j + 1];
				j++;
			}
			L->length--;
			L->data[j] = NULL;
		}
		else if (i == L->length - 1)
		{
			std::cout << "\n没有要删除的元素了";
		}
	}

	return false;
}

void FreeList(SqList*& L)
{
	free(L);
	std::cout << "顺序表空间已经全部释放！";
}

// 找到最后一个最小元素
int FindMinElem(SqList* L)
{
	ElemType min = L->data[0]; // 假设第一个元素是最小的元素
	int index = 0;
	for (size_t i = 1; i < L->length; i++)
	{
		if (min >= L->data[i]) {
			min = L->data[i];
			index = i;
		}
	}
	return index;
}

// 插入一个值为x的元素在最大元素后面
void InsertAfterMax(SqList*& L, ElemType x)
{
	ElemType max = L->data[0]; // 假设第一个元素是最小的元素
	int index = 0;
	for (size_t i = 1; i < L->length; i++)
	{
		if (max <= L->data[i]) {
			max = L->data[i];
			index = i;
		}
	}
	for (int i = L->length; i > index; i--)
	{
		L->data[i] = L->data[i - 1];
	}
	L->data[index] = x;
	L->length++;
}



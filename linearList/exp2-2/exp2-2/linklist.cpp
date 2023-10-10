#include "linklist.h"

//创建单链表，创建头结点，头结点的数据域为空没有关系，只要头结点的指针域能指向后续的结点就行
void CreateList(LinkList*& L)
{
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;
}

// 以数组内容初始化链表
void InitListByTail(LinkList*& L, ElemType a[])
{
	LinkList* tail, * temp;  //tail代表尾结点；temp 是一个临时的结点，分配完内存，再加上数据后，就添加到链表尾部
	tail = L; // 这时候，整个链表就只有头结点，所有头结点就是尾结点

	for (size_t i = 0; i < strlen(a); i++)
	{
		temp = (LinkList*)malloc(sizeof(LinkList));
		temp->data = a[i];
		tail->next = temp;
		tail = temp;
	}
	tail->next = NULL;

	std::cout << "链表初始化成功！\n";
}

//输出链表
void DispList(LinkList* L)
{
	LinkList* read = L->next;  //因为头结点的数据域是空的，给首结点的地址
	if (!read) {
		std::cout << "单链表中只有头结点！";
		return;
	}
	do
	{
		std::cout << read->data;
		printf_s(" : %p \n", &read->data); // 这是输出地址
		read = read->next;
	} while (read);
}

//输出链表的长度。
//链表不能跟顺序表一样，直接往表中放长度length变量,因为链表每个结点占用的空间都是单独的，多一个length变量，那么每个结点都多消耗一些内存空间。
int ListLength(LinkList* L)
{
	LinkList* read = L->next; // 依然是指向首结点，也就是头结点后面那个
	int count = 0;

	while (read)
	{
		read = read->next;
		count++;
	}
	return count;
}

// 判断是否为空，因为链表是动态分配内存的，所有不需要判断是否已满
bool ListIsEmpty(LinkList* L)
{
	LinkList* read = L->next;
	if (!read) {
		return true; // 表示只有头结点
	}
	else {
		return false;
	}
}

//根据序号获得元素
ElemType GetElemByIndex(LinkList* L, unsigned int index)
{
	LinkList* read = L->next;
	unsigned int count = 0;

	while (read)
	{
		if (count == index) {
			return read->data;
		}
		count++;
		read = read->next;
	}
	std::cout << "链表序号" << index << "没有元素!\n";
	return NULL;
}

//根据序号删除元素
ElemType DelElemByIndex(LinkList*& L, unsigned int index)
{

	LinkList* read = L->next;
	LinkList* front = L; // 始终让front结点再read结点前一个
	unsigned int count = 0;

	while (read)
	{
		// 删除指定的结点
		if (count == index) {

			front->next = read->next;
			ElemType tep;
			tep = read->data;
			free(read);
			return tep;

		}

		count++;
		front = read;
		read = read->next;
	}
	return NULL;
}

//根据值获得元素
ElemType GetElemByValue(LinkList* L, ElemType value)
{	
	LinkList* read = L->next;
	while (read)
	{
		if (read->data == value) {
			ElemType tmp;
			tmp = read->data;
			return tmp;
		}
		read = read->next;
	}
	return NULL;
}

//根据值来删除元素
ElemType DelElemByValue(LinkList*& L, ElemType value)
{
	LinkList* read = L->next;
	LinkList* front = L; // 始终让front结点再read结点前一个

	while (read)
	{
		// 删除指定的结点
		if (value == read->data) {

			front->next = read->next;
			ElemType tep;
			tep = read->data;
			free(read);
			return tep;

		}

		front = read;
		read = read->next;
	}
	return NULL;
}

//获得元素定位，从0开始的
int LocateElem(LinkList* L, ElemType value)
{
	LinkList* read = L->next;
	int count = 0;
	while (read)
	{
		if (read->data == value) {
			return count;
		}
		read = read->next;
		count++;
	}
	return -1; //返回-1表示没有该元素
}

//向尾部插入元素
void InsertElem(LinkList*& L, ElemType value)
{
	LinkList* temp;
	LinkList* read = L;

	temp = (LinkList*)malloc(sizeof(LinkList));
	temp->data = value;
	temp->next = NULL;

	//遍历到尾结点
	while (read->next)
	{
		read = read->next;
	}
	read->next = temp;

}

//向指定位置插入元素
void InsertElem(LinkList*& L, unsigned int index, ElemType value)
{
	LinkList* temp;
	LinkList* read = L;
	unsigned int count = 0;

	temp = (LinkList*)malloc(sizeof(LinkList));
	temp->data = value;
	temp->next = NULL;

	//找到该下标
	while (read->next)
	{
		if (count == index) {
			temp->next = read->next;
			read->next = temp;
			return;
		}
		count++;
		read = read->next;
	}
	read->next = temp; // 下标超出了就添加到链表的末尾
}

//释放整个链表的空间
void FreeList(LinkList*& L)
{
	LinkList* read = L; // 头结点也要释放
	while (read) {
		L = L->next;
		free(read);
		read = L;
	}
}

// 找到最后一个最小元素
int FindMInAtLast(LinkList* L,int temp) {
	LinkList* read = L->next;
	ElemType Min = read->data;
	int index = 0;  // 这是在栈上创建的，这么能够返回呢？
	while (read)
	{	
		if (Min >= read->data) {
			Min = read->data;
			temp = index;
		}
		++index;
		read = read->next; // 别忘记遍历过去
	}

	return temp;

}

bool FindLastElemByIndex(LinkList* L, int k)
{
	int len = ListLength(L);
	LinkList* read = L->next;

	if (k > len) {
		return false;
	}

	for (int i = 0; i < len - k; i++)
	{
		read = read->next;  // 这样就不需要进行比对是否
	}
	std::cout << "find the Elem:" << read->data;

	return true;
}

#include "clinklist.h"



//创建单链表，创建头结点，需要头结点的指针域还是NULL,但后面要与尾结点相连
void CreateList(LinkList*& L)
{
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;
}

// 以数组内容初始化链表
void InitListByTail(LinkList*& L, ElemType a[],int len)
{
	LinkList* tail, * temp;  //tail代表尾结点；temp 是一个临时的结点，分配完内存，再加上数据后，就添加到链表尾部
	tail = L; // 这时候，整个链表就只有头结点，所以头结点就是尾结点
	
	std::cout << sizeof(a)/sizeof(a[0]);

	for (size_t i = 0; i < len; i++)
	{
		temp = (LinkList*)malloc(sizeof(LinkList));
		temp->data = a[i];
		tail->next = temp;
		tail = temp;
	}
	tail->next = L; // 循环，连接到头结点

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
	} while (read != L); // 循环单链表输出的条件要修改，不然就一直循环输出
}

//输出链表的长度。
//链表不能跟顺序表一样，直接往表中放长度length变量,因为链表每个结点占用的空间都是单独的，多一个length变量，那么每个结点都多消耗一些内存空间。
int ListLength(LinkList* L)
{
	LinkList* read = L->next; // 依然是指向首结点，也就是头结点后面那个
	int count = 0;

	while (read != L) // 循环的终止条件，不能等于头结点
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

	while (read != L)
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

	while (read != L)
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
	while (read != L)
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

	while (read != L)
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
	while (read != L)
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
	temp->next = L;

	//遍历到尾结点
	while (read->next != L)
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
	temp->next = L; // 循环单链表，如果添加到了尾结点，指针要指向头结点

	//找到该下标
	while (read->next != L)
	{
		if (count == index) {
			temp->next = read->next;  // 没有添加到尾结点时，就更改指针
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

// 显示正整数的占比
void ShowPositiveIntegerProportion(LinkList* L)
{
	LinkList* read = L->next;
	int posInteger = 0;
	int len = 0;
	len = ListLength(L);

	if (len <= 0) {
		std::cout << "链表为空！";
		return;
	}

	// 这是循环单链表
	while (read!=L)
	{
		if (read->data > 0) {
			posInteger++;
		}
		read = read->next;
	}

	std::cout << "正整数有:" << posInteger << "  ";
	std::cout << "正整数所占比例为：" << (double)(posInteger) / len << std::endl;
}

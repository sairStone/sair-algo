#include "dlinklist.h"

//创建单链表，创建头结点，头结点的数据域为空没有关系，只要头结点的指针域能指向后续的结点就行
void CreateList(LinkList*& L)
{
	L = (LinkList*)malloc(sizeof(LinkList));
	L->prior = NULL;
	L->next = NULL;
}

// 以数组内容初始化链表
void InitListByTail(LinkList*& L, ElemType a[])
{
	LinkList* tail, * temp;  //tail代表尾结点；temp 是一个临时的结点，分配完内存，再加上数据后，就添加到链表尾部
	tail = L; // 这时候，整个链表就只有头结点，所以头结点就是尾结点

	for (size_t i = 0; i < strlen(a); i++)
	{
		temp = (LinkList*)malloc(sizeof(LinkList));
		temp->data = a[i];

		temp->prior = tail; //双向链表prior指针指向上一个结点
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


	//顺序输出
	std::cout << "顺序输出：\n";
	do
	{
		std::cout << read->data;
		printf_s(" : %p \n", &read->data); // 这是输出地址
		if (!read->next) {  // 防止到read指向尾结点的NULL域，read为NULL时，就没有前结点了
			break;
		}
		read = read->next;
	} while (read);

	//逆序输出
	std::cout << "逆序输出：\n";
	while (read->prior)
	{
		std::cout << read->data;
		printf_s(" : %p \n", &read->data); // 这是输出地址
		read = read->prior;
	}
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
			read->next->prior = front;  //删除操作，双向链表就多此一句

			ElemType tep;
			tep = read->data;
			free(read);
			return tep;

		}

		//这里用来一直遍历，为找到对应的下标
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
			read->next->prior = front;  //删除操作，双向链表就多此一句

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
	temp->prior = read;  //相比单链表增加的
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
			read->next->prior = temp;  //相比单链表增加的
			temp->prior = read;  //相比单链表增加的
			read->next = temp;
			return;
		}
		count++;
		read = read->next;
	}
	temp->prior = read;  //相比单链表增加的
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


// 双向链表，向前向后遍历都可以
int FindLastElemByValue(LinkList* L, ElemType value) {
	LinkList* read = L->next; // 此时指向了链表首结点
	int len = ListLength(L);
	int temp = 0;

	while (read->next)
	{
		read = read->next;
	}
	while (read)
	{
		temp++;
		if (read->data == value) {
			std::cout << read->data << "----";
			std::cout << "I find it!";
			return (len-temp);  // 链表结点长度减去从后开始遍历的结点数，就是找到元素的逻辑序号
		}
		read = read->prior;
	}
	return -1;
}
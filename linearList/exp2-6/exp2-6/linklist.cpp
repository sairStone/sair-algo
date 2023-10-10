#include "linklist.h"

void CreatList(LinkList*& L)
{
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;
}

void InitList(LinkList*& L, int a[], int len)
{
	LinkList* read, * temp;
	read = L;

	//len = sizeof(a);  a是传入的数组
	/*
	 因为数组作为形参传入函数后会退化成指针，对一个地址来取大小呢，如果是32位系统的话即为4，如果是64位系统的话为8，
	所以,在函数中sizeof获取的是指针的长度而不是数组的长度。
	  第二呢，在函数中，sizeof的处理时间的在编译期，也就是说对于动态生成的数组大小是不能用sizeof来算出来的
	*/

	for (size_t i = 0; i < len; i++)
	{
		temp = (LinkList*)malloc(sizeof(LinkList));
		temp->data = a[i];
		read->next = temp;
		read = temp;
	}
	temp->next = NULL;

}

// 使用笨方法，开始建表处理
void DivisionList(LinkList*& L, bool flag)
{
	LinkList* read, * stand, * front, * tail;
	read = L->next; // read 指向首结点

	if (flag) {
		stand = L->next;
	}
	while (read)
	{
		std::cout << read->data << "  ";
		// 以最后一个为基准
		if (!flag && !read->next) {
			stand = read;
			tail = stand; //添加尾结点，没有一个大于基准，就添加到尾结点后面
		}
		read = read->next;
	}

	//算法思路，找到一个小于基准的，就接到头结点L 后面
	read = L->next;
	front = L; // front 始终指向read前一个结点

	//以 头结点为基准
	while (flag && read  )
	{
		if (read->data < stand->data) {
			front->next = read->next;
			read->next = L->next;
			L->next = read;
			read = stand;  //表示再次从stand开始遍历
		}
		front = read; // front 始终指向read前一个结点
		read = read->next;
	}


	// 以 wei结点为基准
	while (  !flag &&  read->next != stand)
	{

		if (read->data > stand->data) {
			front->next = read->next;
			tail->next = read;
			tail = read;
			tail->next = NULL;

			read = L->next;
			front = L; // front 始终指向read前一个结点
			continue;
			std::cout << "n";
		}

		front = read; // front 始终指向read前一个结点
		read = read->next;
	}


	


	std::cout << "\n";
	read = L->next;
	while (read)
	{
		if (read->data == stand->data) {
			std::cout << "&";
		}
		std::cout << read->data << "  ";
		read = read->next;

	}
}

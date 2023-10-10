// exp2-11.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>
#include <string>
using namespace std;

typedef struct Employee
{
	int no;
	string name;
	int depno;
	double salary;
}ElemType;

typedef struct MyStruct
{
	ElemType data;
	struct MyStruct* next;
}LinkList;

void createList(LinkList*& L);


// 向链表中插入职工记录
void insertEmployee(LinkList*& L, int no, string name, int depno, double salary);

// 将链表中的职工记录写入文件
void writeToFile(LinkList*& L, const string& filename);

//将文件中的内容读取到链表中
void readFromFile(LinkList*& L, const string& filename);

// 输出链表的内容
void dispList(LinkList* L);

//释放所有链表
void freeList(LinkList*& L);
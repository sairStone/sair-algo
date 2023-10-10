// exp2-2.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

// 单链表 Singly Link List

#pragma once

#include <iostream>

typedef char ElemType;

//每个结点就是一个结构体，包含一个数据域和指针域
typedef struct MyStruct
{
	ElemType data; //数据域
	struct MyStruct* next; //指针域
}LinkList;  // 这是通过typedef关键词起的类型别名


//第一步：创建链表，也就是创建头结点！头结点很有用，强烈建议在链表中使用！
void CreateList(LinkList*& L);

//第二步：尾插法的方式写入数据，将一个数组内的元素写入每个结点，在我看来就是初始化链表
void InitListByTail(LinkList*& L, ElemType a[]);

//第三步：输出链表和获得链表长度
void DispList(LinkList* L);
int ListLength(LinkList* L);

//第四步：判断链表是否为空，因为链表是动态分配内存的，所有不需要判断是否已满
bool ListIsEmpty(LinkList* L);

//第五步：增、删、查的操作(题目暂没要求改)，每删除一个结点，就要记得释放那个结点的空间
ElemType GetElemByIndex(LinkList* L, unsigned int index);
ElemType DelElemByIndex(LinkList*& L, unsigned int index);

ElemType GetElemByValue(LinkList* L, ElemType value);
ElemType DelElemByValue(LinkList*& L, ElemType value);

// 获得结点的序号
int LocateElem(LinkList* L, ElemType value);

// 下面这两个就是面向对象的多态特性
void InsertElem(LinkList*& L, ElemType value); // 直接把在链表尾部添加一个结点，存放元素。
void InsertElem(LinkList*& L, unsigned int index, ElemType value); // 根据index序号进行添加元素。

// 第六步：释放整个链表
void FreeList(LinkList*& L);


// 查找带头结点的非空链表L中最后一个最下结点，返回逻辑序号
int FindMInAtLast(LinkList* L, int temp);


//设计一个尽可能高效的算法，查找链表中倒数第K个位置上的结点（K为正整数）。若查找成功，输出该结点的值，并返回1，否则返回0
//  直接 用链表结点的长度减去 k，得到的就是那个结点元素
bool FindLastElemByIndex(LinkList* L, int k);
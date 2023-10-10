// exp2-6.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>

typedef int ElemType;

typedef struct MyStruct
{
	ElemType data;
	struct MyStruct* next;
}LinkList;

// 创建头结点
void CreatList(LinkList*& L);

// 初始化链表
void InitList(LinkList*& L,int a[], int len);

// 以基准分割链表，falg 为true 表示以头结点为基准，false让尾节点是基准
void DivisionList(LinkList*& L,bool flag);

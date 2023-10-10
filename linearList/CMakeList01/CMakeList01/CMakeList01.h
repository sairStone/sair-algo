// CMakeList01.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。


#pragma once

#include <iostream>
#define MAXSIZE 50

// sequential list  顺序表

typedef int ElemType;

struct MyStruct
{
	ElemType data[MAXSIZE];
	int length;
};
typedef MyStruct SqList; // 这是声明了一个MyStruct的类型名SqList
//typedef MyStruct * SqList; // 通过typedef关键字将MyStruct的指针类型命名为SqList，即SqList为指向MyStruct类型的指针。

void InitList(SqList*& L);

void CreateList(SqList*& L, ElemType a[], int n);

void ShowList(SqList*& L, int n);

void DestoryList(SqList* L);

// TODO: 在此处引用程序需要的其他标头。

// exp2-1.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>

#define MAXSIZE 10   // 顺序表最大的元素存储数量

typedef char ElemType;

struct MyStruct
{
	ElemType data[MAXSIZE];   // 该数组用来存取元素
	int length;   //用来记录该顺序表的长度
};
typedef MyStruct SqList;   //起别名，把这个顺序表起名为SqList

// 第一步： 先整体建表,建表一定成功，返回为void
void CreatList(SqList*& L);   // 解释一下这个声明：*代表是指针调用，这样后面才能这样用L->data[i]; &代表是引用调用，说明 L 是给传过来参数的别名，通过这个可以操作原顺序表

// 第二步：初始化顺序表
void InitList(SqList*& L);

//第三步： 插入和删除元素前，肯定要验证该顺序表是否为空，是否为满，返回值为bool,表示成功与否。（这就叫细节）
bool ListIsEmpty(SqList* L);  // 解释一下：为什么这里不用&引用调用，因为没有打算操作原顺序表。
bool ListIsFull(SqList* L);

//第四步： 插入数据；在指定位置后面插入元素
void ListInsert(SqList*& L);
bool ListInsertByIndex(SqList*& L, unsigned int index, ElemType ch); //bool返回值是表示是否插入成功

//第五步： 获取顺序表的长度；输出整个顺序表
int ListLength(SqList* L);
void DispList(SqList* L);

//第六步： 通过数组下标（也就是序号）获取元素；根据元素值来查找顺序表是否有这个元素；删除指定序号的元素；通过元素值来删除指定元素
ElemType GetElemByIndex(SqList* L, unsigned int index); // index 可不能有负数
int GetElemByValue(SqList* L, ElemType value); //查找到的同时，返回该元素的下标，相当于对元素进行定位（LocateList）

ElemType DelElemByIndex(SqList*& L, unsigned int index); //返回被删除的元素
bool DelElemByValue(SqList*& L, ElemType value);  // 删除后，返回是否成功 

//第八步： 对整个顺序表进行释放(与第一步遥相呼应，有始有终！)
void FreeList(SqList*& L); //释放就是把内存空间、里面的东西全部清除，很简单就做到！


// 查找顺序表L中最后一个最小元素，返回元素的逻辑序号
int FindMinElem(SqList* L);

// 在最后一个最大值元素之后插入一个值为x的元素
void InsertAfterMax(SqList*& L, ElemType x);


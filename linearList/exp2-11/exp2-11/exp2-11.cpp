// exp2-11.cpp: 定义应用程序的入口点。

#include <iostream>
#include <fstream>

#include "linklist.cpp"

int main() {
    LinkList* list;
    createList(list);

    // 向链表中插入职工记录
    //insertEmployee(list, 1, "张三", 101, 5000);
    //insertEmployee(list, 2, "李四", 102, 6000);
    //insertEmployee(list, 3, "王五", 101, 5500);
    
    readFromFile(list, "emp.dat");

    dispList(list);

    // 将链表中的职工记录写入文件
    //writeToFile(list, "emp.dat");


    freeList(list);

    return 0;
}

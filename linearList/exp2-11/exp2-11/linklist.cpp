#include "linklist.h"

// 创建链表
void createList(LinkList*& L)
{
    L = new LinkList;  // 创建头结点
    L->next = nullptr;
}

void insertEmployee(LinkList*& L, int no, string name, int depno, double salary)
{
    LinkList* temp = new LinkList;
    temp->data.no = no;
    temp->data.name = name;
    temp->data.depno = depno;
    temp->data.salary = salary;
    temp->next = nullptr;  //新建一个结点，指针别忘记赋值为空啊！！

    if (L->next == nullptr) {
        L->next = temp;
    }
    else {
        LinkList* read = L;
        while (read->next != nullptr) {
            read = read->next;
        }
        read->next = temp;
    }
    
}

void writeToFile(LinkList*& L, const string& filename)
{
    ofstream outFile(filename);  // ofstream outFile(filename,ios::app)是向文件尾进行追加
    if (!outFile) {
        cout << "无法打开文件！" << endl;
        return;
    }

    LinkList* read = L->next;
    while (read != nullptr) {
        outFile << read->data.no << " " << read->data.name << " " << read->data.depno << " " << read->data.salary << endl;
        read = read->next;
    }
    std::cout << "职工信息已成功写入文件！";
    outFile.close();
}

void readFromFile(LinkList*& L, const string& filename)
{
    ifstream file(filename);
    if (file.is_open()) {
        // 这里定义了一个临时的结构体变量，用来存放从文件中每次读取行的内容
        LinkList* emp = new LinkList;
        emp->next = nullptr;

        while (file >> emp->data.no >> emp->data.name >> emp->data.depno >> emp->data.salary) {
            insertEmployee(L, emp->data.no, emp->data.name, emp->data.depno, emp->data.salary);
        }
        std::cout << "读取文件成功！\n";
        delete emp;
        file.close();
    }
    else {
        cout << "无法打开文件" << endl;
    }
}

void dispList(LinkList* L)
{
    LinkList* read = L->next;  //从首结点开始
    while (read)
    {
        std::cout << read->data.no << "-";
        std::cout << read->data.name << "-";
        std::cout << read->data.depno << "-";
        std::cout << read->data.salary << "\n";
        read = read->next;
    }
}

void freeList(LinkList*& L)
{
    LinkList* read = L;
    while (read)
    {
        LinkList* temp = read;
        read = read->next;
        delete temp;
    }
}




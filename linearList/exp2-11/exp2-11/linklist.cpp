#include "linklist.h"

// ��������
void createList(LinkList*& L)
{
    L = new LinkList;  // ����ͷ���
    L->next = nullptr;
}

void insertEmployee(LinkList*& L, int no, string name, int depno, double salary)
{
    LinkList* temp = new LinkList;
    temp->data.no = no;
    temp->data.name = name;
    temp->data.depno = depno;
    temp->data.salary = salary;
    temp->next = nullptr;  //�½�һ����㣬ָ������Ǹ�ֵΪ�հ�����

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
    ofstream outFile(filename);  // ofstream outFile(filename,ios::app)�����ļ�β����׷��
    if (!outFile) {
        cout << "�޷����ļ���" << endl;
        return;
    }

    LinkList* read = L->next;
    while (read != nullptr) {
        outFile << read->data.no << " " << read->data.name << " " << read->data.depno << " " << read->data.salary << endl;
        read = read->next;
    }
    std::cout << "ְ����Ϣ�ѳɹ�д���ļ���";
    outFile.close();
}

void readFromFile(LinkList*& L, const string& filename)
{
    ifstream file(filename);
    if (file.is_open()) {
        // ���ﶨ����һ����ʱ�Ľṹ�������������Ŵ��ļ���ÿ�ζ�ȡ�е�����
        LinkList* emp = new LinkList;
        emp->next = nullptr;

        while (file >> emp->data.no >> emp->data.name >> emp->data.depno >> emp->data.salary) {
            insertEmployee(L, emp->data.no, emp->data.name, emp->data.depno, emp->data.salary);
        }
        std::cout << "��ȡ�ļ��ɹ���\n";
        delete emp;
        file.close();
    }
    else {
        cout << "�޷����ļ�" << endl;
    }
}

void dispList(LinkList* L)
{
    LinkList* read = L->next;  //���׽�㿪ʼ
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




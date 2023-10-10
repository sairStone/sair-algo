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

	//len = sizeof(a);  a�Ǵ��������
	/*
	 ��Ϊ������Ϊ�βδ��뺯������˻���ָ�룬��һ����ַ��ȡ��С�أ������32λϵͳ�Ļ���Ϊ4�������64λϵͳ�Ļ�Ϊ8��
	����,�ں�����sizeof��ȡ����ָ��ĳ��ȶ���������ĳ��ȡ�
	  �ڶ��أ��ں����У�sizeof�Ĵ���ʱ����ڱ����ڣ�Ҳ����˵���ڶ�̬���ɵ������С�ǲ�����sizeof���������
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

// ʹ�ñ���������ʼ������
void DivisionList(LinkList*& L, bool flag)
{
	LinkList* read, * stand, * front, * tail;
	read = L->next; // read ָ���׽��

	if (flag) {
		stand = L->next;
	}
	while (read)
	{
		std::cout << read->data << "  ";
		// �����һ��Ϊ��׼
		if (!flag && !read->next) {
			stand = read;
			tail = stand; //���β��㣬û��һ�����ڻ�׼������ӵ�β������
		}
		read = read->next;
	}

	//�㷨˼·���ҵ�һ��С�ڻ�׼�ģ��ͽӵ�ͷ���L ����
	read = L->next;
	front = L; // front ʼ��ָ��readǰһ�����

	//�� ͷ���Ϊ��׼
	while (flag && read  )
	{
		if (read->data < stand->data) {
			front->next = read->next;
			read->next = L->next;
			L->next = read;
			read = stand;  //��ʾ�ٴδ�stand��ʼ����
		}
		front = read; // front ʼ��ָ��readǰһ�����
		read = read->next;
	}


	// �� wei���Ϊ��׼
	while (  !flag &&  read->next != stand)
	{

		if (read->data > stand->data) {
			front->next = read->next;
			tail->next = read;
			tail = read;
			tail->next = NULL;

			read = L->next;
			front = L; // front ʼ��ָ��readǰһ�����
			continue;
			std::cout << "n";
		}

		front = read; // front ʼ��ָ��readǰһ�����
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

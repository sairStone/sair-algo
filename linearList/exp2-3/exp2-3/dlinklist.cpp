#include "dlinklist.h"

//��������������ͷ��㣬ͷ����������Ϊ��û�й�ϵ��ֻҪͷ����ָ������ָ������Ľ�����
void CreateList(LinkList*& L)
{
	L = (LinkList*)malloc(sizeof(LinkList));
	L->prior = NULL;
	L->next = NULL;
}

// ���������ݳ�ʼ������
void InitListByTail(LinkList*& L, ElemType a[])
{
	LinkList* tail, * temp;  //tail����β��㣻temp ��һ����ʱ�Ľ�㣬�������ڴ棬�ټ������ݺ󣬾���ӵ�����β��
	tail = L; // ��ʱ�����������ֻ��ͷ��㣬����ͷ������β���

	for (size_t i = 0; i < strlen(a); i++)
	{
		temp = (LinkList*)malloc(sizeof(LinkList));
		temp->data = a[i];

		temp->prior = tail; //˫������priorָ��ָ����һ�����
		tail->next = temp;
		tail = temp;
	}
	tail->next = NULL;

	std::cout << "�����ʼ���ɹ���\n";
}

//�������
void DispList(LinkList* L)
{
	LinkList* read = L->next;  //��Ϊͷ�����������ǿյģ����׽��ĵ�ַ
	if (!read) {
		std::cout << "��������ֻ��ͷ��㣡";
		return;
	}


	//˳�����
	std::cout << "˳�������\n";
	do
	{
		std::cout << read->data;
		printf_s(" : %p \n", &read->data); // ���������ַ
		if (!read->next) {  // ��ֹ��readָ��β����NULL��readΪNULLʱ����û��ǰ�����
			break;
		}
		read = read->next;
	} while (read);

	//�������
	std::cout << "���������\n";
	while (read->prior)
	{
		std::cout << read->data;
		printf_s(" : %p \n", &read->data); // ���������ַ
		read = read->prior;
	}
}

//�������ĳ��ȡ�
//�����ܸ�˳���һ����ֱ�������зų���length����,��Ϊ����ÿ�����ռ�õĿռ䶼�ǵ����ģ���һ��length��������ôÿ����㶼������һЩ�ڴ�ռ䡣
int ListLength(LinkList* L)
{
	LinkList* read = L->next; // ��Ȼ��ָ���׽�㣬Ҳ����ͷ�������Ǹ�
	int count = 0;

	while (read)
	{
		read = read->next;
		count++;
	}
	return count;
}

// �ж��Ƿ�Ϊ�գ���Ϊ�����Ƕ�̬�����ڴ�ģ����в���Ҫ�ж��Ƿ�����
bool ListIsEmpty(LinkList* L)
{
	LinkList* read = L->next;
	if (!read) {
		return true; // ��ʾֻ��ͷ���
	}
	else {
		return false;
	}
}

//������Ż��Ԫ��
ElemType GetElemByIndex(LinkList* L, unsigned int index)
{
	LinkList* read = L->next;
	unsigned int count = 0;

	while (read)
	{
		if (count == index) {
			return read->data;
		}
		count++;
		read = read->next;
	}
	std::cout << "�������" << index << "û��Ԫ��!\n";
	return NULL;
}

//�������ɾ��Ԫ��
ElemType DelElemByIndex(LinkList*& L, unsigned int index)
{

	LinkList* read = L->next;
	LinkList* front = L; // ʼ����front�����read���ǰһ��
	unsigned int count = 0;

	while (read)
	{
		// ɾ��ָ���Ľ��
		if (count == index) {

			front->next = read->next;
			read->next->prior = front;  //ɾ��������˫������Ͷ��һ��

			ElemType tep;
			tep = read->data;
			free(read);
			return tep;

		}

		//��������һֱ������Ϊ�ҵ���Ӧ���±�
		count++;
		front = read;
		read = read->next;
	}
	return NULL;
}

//����ֵ���Ԫ��
ElemType GetElemByValue(LinkList* L, ElemType value)
{
	LinkList* read = L->next;
	while (read)
	{
		if (read->data == value) {
			ElemType tmp;
			tmp = read->data;
			return tmp;
		}
		read = read->next;
	}
	return NULL;
}

//����ֵ��ɾ��Ԫ��
ElemType DelElemByValue(LinkList*& L, ElemType value)
{
	LinkList* read = L->next;
	LinkList* front = L; // ʼ����front�����read���ǰһ��

	while (read)
	{
		// ɾ��ָ���Ľ��
		if (value == read->data) {

			front->next = read->next;
			read->next->prior = front;  //ɾ��������˫������Ͷ��һ��

			ElemType tep;
			tep = read->data;
			free(read);
			return tep;

		}

		front = read;
		read = read->next;
	}
	return NULL;
}

//���Ԫ�ض�λ����0��ʼ��
int LocateElem(LinkList* L, ElemType value)
{
	LinkList* read = L->next;
	int count = 0;
	while (read)
	{
		if (read->data == value) {
			return count;
		}
		read = read->next;
		count++;
	}
	return -1; //����-1��ʾû�и�Ԫ��
}

//��β������Ԫ��
void InsertElem(LinkList*& L, ElemType value)
{
	LinkList* temp;
	LinkList* read = L;

	temp = (LinkList*)malloc(sizeof(LinkList));
	temp->data = value;
	temp->next = NULL;

	//������β���
	while (read->next)
	{
		read = read->next;
	}
	temp->prior = read;  //��ȵ��������ӵ�
	read->next = temp;

}

//��ָ��λ�ò���Ԫ��
void InsertElem(LinkList*& L, unsigned int index, ElemType value)
{
	LinkList* temp;
	LinkList* read = L;
	unsigned int count = 0;

	temp = (LinkList*)malloc(sizeof(LinkList));
	temp->data = value;
	temp->next = NULL;

	//�ҵ����±�
	while (read->next)
	{
		if (count == index) {
			temp->next = read->next;
			read->next->prior = temp;  //��ȵ��������ӵ�
			temp->prior = read;  //��ȵ��������ӵ�
			read->next = temp;
			return;
		}
		count++;
		read = read->next;
	}
	temp->prior = read;  //��ȵ��������ӵ�
	read->next = temp; // �±곬���˾���ӵ������ĩβ
}

//�ͷ���������Ŀռ�
void FreeList(LinkList*& L)
{
	LinkList* read = L; // ͷ���ҲҪ�ͷ�
	while (read) {
		L = L->next;
		free(read);
		read = L;
	}
}


// ˫��������ǰ������������
int FindLastElemByValue(LinkList* L, ElemType value) {
	LinkList* read = L->next; // ��ʱָ���������׽��
	int len = ListLength(L);
	int temp = 0;

	while (read->next)
	{
		read = read->next;
	}
	while (read)
	{
		temp++;
		if (read->data == value) {
			std::cout << read->data << "----";
			std::cout << "I find it!";
			return (len-temp);  // �����㳤�ȼ�ȥ�Ӻ�ʼ�����Ľ�����������ҵ�Ԫ�ص��߼����
		}
		read = read->prior;
	}
	return -1;
}
#include "clinklist.h"



//��������������ͷ��㣬��Ҫͷ����ָ������NULL,������Ҫ��β�������
void CreateList(LinkList*& L)
{
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;
}

// ���������ݳ�ʼ������
void InitListByTail(LinkList*& L, ElemType a[],int len)
{
	LinkList* tail, * temp;  //tail����β��㣻temp ��һ����ʱ�Ľ�㣬�������ڴ棬�ټ������ݺ󣬾���ӵ�����β��
	tail = L; // ��ʱ�����������ֻ��ͷ��㣬����ͷ������β���
	
	std::cout << sizeof(a)/sizeof(a[0]);

	for (size_t i = 0; i < len; i++)
	{
		temp = (LinkList*)malloc(sizeof(LinkList));
		temp->data = a[i];
		tail->next = temp;
		tail = temp;
	}
	tail->next = L; // ѭ�������ӵ�ͷ���

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
	do
	{
		std::cout << read->data;
		printf_s(" : %p \n", &read->data); // ���������ַ
		read = read->next;
	} while (read != L); // ѭ�����������������Ҫ�޸ģ���Ȼ��һֱѭ�����
}

//�������ĳ��ȡ�
//�����ܸ�˳���һ����ֱ�������зų���length����,��Ϊ����ÿ�����ռ�õĿռ䶼�ǵ����ģ���һ��length��������ôÿ����㶼������һЩ�ڴ�ռ䡣
int ListLength(LinkList* L)
{
	LinkList* read = L->next; // ��Ȼ��ָ���׽�㣬Ҳ����ͷ�������Ǹ�
	int count = 0;

	while (read != L) // ѭ������ֹ���������ܵ���ͷ���
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

	while (read != L)
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

	while (read != L)
	{
		// ɾ��ָ���Ľ��
		if (count == index) {

			front->next = read->next;
			ElemType tep;
			tep = read->data;
			free(read);
			return tep;

		}

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
	while (read != L)
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

	while (read != L)
	{
		// ɾ��ָ���Ľ��
		if (value == read->data) {

			front->next = read->next;
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
	while (read != L)
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
	temp->next = L;

	//������β���
	while (read->next != L)
	{
		read = read->next;
	}
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
	temp->next = L; // ѭ�������������ӵ���β��㣬ָ��Ҫָ��ͷ���

	//�ҵ����±�
	while (read->next != L)
	{
		if (count == index) {
			temp->next = read->next;  // û����ӵ�β���ʱ���͸���ָ��
			read->next = temp;
			return;
		}
		count++;
		read = read->next;
	}
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

// ��ʾ��������ռ��
void ShowPositiveIntegerProportion(LinkList* L)
{
	LinkList* read = L->next;
	int posInteger = 0;
	int len = 0;
	len = ListLength(L);

	if (len <= 0) {
		std::cout << "����Ϊ�գ�";
		return;
	}

	// ����ѭ��������
	while (read!=L)
	{
		if (read->data > 0) {
			posInteger++;
		}
		read = read->next;
	}

	std::cout << "��������:" << posInteger << "  ";
	std::cout << "��������ռ����Ϊ��" << (double)(posInteger) / len << std::endl;
}

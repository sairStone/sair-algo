#include "sqlist.h"

//���������Ϊ�˷����ڴ�ռ�
void CreatList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList)); //����˳���Ϊ����洢�����Բ���Ҫ����һ������MAXSIZE�Ŀռ䣬����һ�����С�
	std::cout << "-----˳������ɹ���\n";
}

//��ʼ������Ϊ����˳���Ϊ��
void InitList(SqList*& L)
{
	L->length = 0;
	std::cout << "-----˳����ʼ���ɹ���\n";
}

//�ж��Ƿ�Ϊ��
bool ListIsEmpty(SqList* L)
{
	if (L->length == 0) {
		return true;
	}
	else {
		return false;
	}
}

//�ж��Ƿ�����
bool ListIsFull(SqList* L)
{
	//���д���������ж��Ƿ�Ϊ��һ����
	bool flag = L->length == MAXSIZE ? true : false;
	return flag;
}

// ������Ŀ����abcde��5��Ԫ�ص�˳�����
void ListInsert(SqList*& L)
{
	ElemType temp[] = { 'a','b','c','d','a','\0' }; // '\0' ����ֹ������Ϊstrlen()�Ǽ���'\0'֮ǰ���ַ�����

	for (size_t i = 0; i < sizeof(temp) / sizeof(temp[0]); i++)
	{
		L->data[i] = temp[i];
		L->length++;
	}
}

// ��ָ���±�λ�ò���Ԫ�أ������Ԫ�ؽ��к���һλ
bool ListInsertByIndex(SqList*& L, unsigned int index, ElemType ch)
{
	//����Ԫ�صĻ����Ӻ�����ǰ�����������ʵ�
	for (int i = L->length - 1; i >= index; i--)
	{
		L->data[i + 1] = L->data[i];
	}
	L->data[index] = ch;
	L->length++;  // ˳����ȼ�һ

	return true;
}

int ListLength(SqList* L)
{
	return L->length;
}

void DispList(SqList* L)
{
	std::cout << "\n��ʼ���˳���\n";

	// ����˳���ĳ��������
	for (size_t i = 0; i < L->length; i++)
	{
		std::cout << L->data[i];
		printf_s(":%p", &L->data[i]);
		std::cout << "\n";
	}

	//�������������䣬����������Ժ�����������˳����ڴ��еĴ洢λ�������ڵģ���Ϊ��char,����ռ��һ���ֽ�,��û��Ԫ�ص�ֵ������������
	//std::cout << L->data[7] << ":" << sizeof(L->data[7]) << typeid(L->data[7]).name();
	//printf_s(":%p", &L->data[7]);
}

// ���ָ����ţ��±꣩��Ԫ��
ElemType GetElemByIndex(SqList* L, unsigned int index)
{
	if (index > L->length) {
		std::cout << "ָ����Ų�û��Ԫ�أ�\n";
		return NULL;
	}
	else {
		return L->data[index];
	}
}

//����ҵ�Ԫ�ص��±�
int GetElemByValue(SqList* L, ElemType value)
{
	for (size_t i = 0; i < L->length; i++)
	{
		if (value == L->data[i]) {
			//std::cout << "index is " << i;
			return i;
		}
	}
	return -1; // ����-1����Ϊ�±�û�и���������ΪNULLʱ�����޷��ж����±�0��һ����˵ 0 �� NULL ��ȣ�
}

// ɾ��ָ����ţ��±꣩��Ԫ��,����Ԫ����ǰ�ƶ�
ElemType DelElemByIndex(SqList*& L, unsigned int index)
{
	if (index >= L->length) {
		std::cout << "ָ����Ų�û��Ԫ�أ�\n";
		return -1;
	}
	else {
		//����Ҫɾ����Ԫ��
		ElemType temp = L->data[index];
		//ǰ��Ԫ�أ���ǰ����������
		while (index < L->length)
		{
			L->data[index] = L->data[index + 1];
			index++;
		}
		L->length--;
		L->data[index] = NULL;

		return temp;
	}


}

// ɾ��ָ����Ԫ��
bool DelElemByValue(SqList*& L, ElemType value)
{
	for (size_t i = 0; i < L->length; i++)
	{
		if (value == L->data[i]) {
			int j = i;
			while (j < L->length)
			{
				L->data[j] = L->data[j + 1];
				j++;
			}
			L->length--;
			L->data[j] = NULL;
		}
		else if (i == L->length - 1)
		{
			std::cout << "\nû��Ҫɾ����Ԫ����";
		}
	}

	return false;
}

void FreeList(SqList*& L)
{
	free(L);
	std::cout << "˳���ռ��Ѿ�ȫ���ͷţ�";
}

// �ҵ����һ����СԪ��
int FindMinElem(SqList* L)
{
	ElemType min = L->data[0]; // �����һ��Ԫ������С��Ԫ��
	int index = 0;
	for (size_t i = 1; i < L->length; i++)
	{
		if (min >= L->data[i]) {
			min = L->data[i];
			index = i;
		}
	}
	return index;
}

// ����һ��ֵΪx��Ԫ�������Ԫ�غ���
void InsertAfterMax(SqList*& L, ElemType x)
{
	ElemType max = L->data[0]; // �����һ��Ԫ������С��Ԫ��
	int index = 0;
	for (size_t i = 1; i < L->length; i++)
	{
		if (max <= L->data[i]) {
			max = L->data[i];
			index = i;
		}
	}
	for (int i = L->length; i > index; i--)
	{
		L->data[i] = L->data[i - 1];
	}
	L->data[index] = x;
	L->length++;
}



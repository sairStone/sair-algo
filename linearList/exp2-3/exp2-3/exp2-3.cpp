// exp2-3.cpp: 定义应用程序的入口点。
//

#include "dlinklist.cpp"

using namespace std;

void LogDivider();

int main()
{
	LinkList* list;
	ElemType arr[] = { 'a','b','c','d','e','\0' };  // 这里如果不放\0做为结束符，strlen()的值就不是5了
	int num, len;
	ElemType ch;

	int lastElemIndex = 0;

	LogDivider();
	cout << "下面的1~8数字选项是对应的单链表操作：\n";
	cout << "1.以数组内容初始化链表\n";
	cout << "2.输出链表的所有内容\n";
	cout << "3.输出链表的长度\n";
	cout << "4.获得下标指定的元素\n";
	cout << "5.删除下标指定的元素\n";
	cout << "6.根据输入的元素值获得元素\n";
	cout << "7.根据输入的元素值删除元素\n";
	cout << "8.定位指定元素的序号\n";
	cout << "9.在指定的位置插入元素\n";
	cout << "10.在尾部插入一个元素\n";
	cout << "0.释放整个单链表";
	LogDivider();

	CreateList(list);

	cout << "\n>>>>请输入数字进行操作：";
	cin >> num;

	while (num)
	{
		switch (num)
		{
		case 1:
			InitListByTail(list, arr);
			break;
		case 2:
			DispList(list);
			break;
		case 3:
			len = ListLength(list);
			cout << "链表的长度为：" << len << endl;
			
			lastElemIndex = FindLastElemByValue(list,'d');
			cout << "lat Elem is:" << lastElemIndex;
			break;
		case 4:
			ch = GetElemByIndex(list, 3);
			if (ch) {
				cout << "index of 3 is:" << ch << endl;
			}
			break;
		case 5:
			ch = DelElemByIndex(list, 2);
			if (ch) {
				cout << "delete of 2 is:" << ch << endl;
			}
			break;
		case 6:
			ch = GetElemByValue(list, 'b');
			if (ch) {
				cout << "index of \'b\' is:" << ch << endl;
			}
			break;
		case 7:
			DelElemByValue(list, 'b');
			break;
		case 8:
			int index;
			index = LocateElem(list, 'c');
			if (index >= 0) {
				cout << "c of index is :" << index;
			}
			break;
		case 9:
			InsertElem(list, 3, '#');
			break;
		case 10:
			InsertElem(list, '$');
			break;
		default: break;
		}

		cout << "\n>>>>请继续输入进行操作：";
		cin >> num;
		if (num == 0) {
			return 0;
		}
	}


	return 0;
}

void LogDivider() {
	std::cout << "\n-------------------------------------\n";
}

// exp2-1.cpp: 定义应用程序的入口点。

#include "sqlist.cpp"

using namespace std;

// 输出分割线
void LogDivider();

int main()
{
	SqList* list;
	unsigned int len;
	int choice;

	CreatList(list);
	InitList(list);
	//这一个用来往空的顺序表中写入测试数据，就不判断是否为空了
	ListInsert(list);

	LogDivider();
	std::cout << "\n请输入数字1到8进行数字对应的操作：\n";
	std::cout << "1.输出顺序表的长度\n";
	std::cout << "2.输出顺序表的所有元素\n";
	std::cout << "3.根据下标向顺序表查找元素\n";
	std::cout << "4.向指定下标插入元素\n";
	std::cout << "5.删除指定下标的元素\n";
	std::cout << "6.根据输入的元素查找对应下标\n";
	std::cout << "7.根据输入的元素删除的指定元素\n";
	std::cout << "8.释放整个顺序表（退出操作）\n";
	LogDivider();

	std::cout << "请输入数字1到8：";

	std::cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case 1:
			len = ListLength(list);
			std::cout << "\n顺序表的长度是：" << len << "\n";
			break;
		case 2: DispList(list); break;  //输出顺序表内容
		case 3:
			ElemType find;
			find = GetElemByIndex(list, 3);
			if (find) {
				std::cout << "根据下标3找到的元素为：" << find;
			}
			break;
		case 4:
			//先判断是否为空！
			if (!ListIsFull(list)) {
				ListInsertByIndex(list, 4, 'f');
			}
			else {
				std::cout << "顺序表已经满了！\n";
			}
			break;
		case 5:
			if (!ListIsEmpty) {
				std::cout << "\n顺序表为空，不支持删除元素";
			}
			else {
				ElemType temp;
				temp = DelElemByIndex(list, 2);
				if (temp >= 0) {
					std::cout << "\n删除了下标为2的元素" << temp;
				}
			}
			break;
		case 6: 
			 //临时测试
			/*
			int re_index;
			re_index = FindMinElem(list);
			std::cout << "最后一个最小元素是：" << re_index;
		
			InsertAfterMax(list, 'x');
			*/
			//
			int valueIndex;
			valueIndex = GetElemByValue(list, 'a');
			if (valueIndex >= 0) {
				std::cout << "\n a元素对应的下标为：" << valueIndex;
			}
			break;
		case 7: 
			DelElemByValue(list, 'c');
			break;
		case 8: free(list); return 0;
		}

		LogDivider();
		std::cout << ">>>>请再次输入1到8进行操作：";
		std::cin >> choice;
		if (choice == 8) {
			std::cout << "退出操作!";
			break;
		}
	}


	return 0;
}

void LogDivider() {
	std::cout << "\n-----------------------------------------\n";
}
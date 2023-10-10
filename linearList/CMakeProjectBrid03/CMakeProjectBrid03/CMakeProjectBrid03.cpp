// CMakeProjectBrid03.cpp: 定义应用程序的入口点。
//

#include "CMakeProjectBrid03.h"

using namespace std;

int main()
{
	Rectangle rec1;
	rec1.setHeight(5);
	rec1.setWidth(6);
	
	int area = rec1.getArea();

	int cost = rec1.getCost(area);

	cout << "Area of rec1: " << area << endl;
	cout << "Cost of rec1: " << cost << endl;


	//---------------------
	PrintData pt;
	pt.printd("abcd");
	pt.printd(10.1);


	//---------------------
	//操作符重载
	Box box1;
	Box box2;
	Box box3;

	double volume = 0.0;
	
	box1.setHeight(3);
	box1.setLength(2);
	box1.setWidth(4);

	box2.setHeight(3);
	box2.setLength(2);
	box2.setWidth(4);

	// 总之，因为是二元运算符，所以能通过重载 + 联系起前后两个对象
	box3 = box1 + box2; 
	
	box3.getVolum();

	return 0;
}

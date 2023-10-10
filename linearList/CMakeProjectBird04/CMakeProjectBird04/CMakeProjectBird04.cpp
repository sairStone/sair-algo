// CMakeProjectBird04.cpp: 定义应用程序的入口点。
//

#include "CMakeProjectBird04.h"

using namespace std;

int main()
{
	Shape* shape;
	Retancgle re = Retancgle(10, 20);
	Triangle tr = Triangle(5, 6);

	int r1, t2;
	//r1 = re.getArea();
	//t2 = tr.getArea();


	// 多态，根据调用的子类来实现不同的子类方法
	shape = &re; // 调用Retancgle子类
	r1 = shape->getArea();
	cout << r1 << "\n";

	shape = &tr; // 调用Triangle子类
	t2 = shape->getArea();
	cout << t2;

	return 0;
}

// CMakeProjectBird06.cpp: 定义应用程序的入口点。
//

#include "CMakeProjectBird06.h"

// 演示多线程的CPP程序
// 使用三个不同的可调用对象
#include <iostream>
#include <thread>
using namespace std;

// 一个虚拟函数
void foo(int Z)
{
	for (int i = 0; i < Z; i++) {
		cout << "线程使用函数指针作为可调用参数\n";
	}
}

// 可调用对象
class thread_obj {
public:
	void operator()(int x)  //重载了函数调用运算符 operator()。这意味着我们可以像调用函数一样调用这个类的对象
	{
		for (int i = 0; i < x; i++)
			cout << "线程使用函数对象作为可调用参数\n";
	}
};

int main()
{
	cout << "线程 1 、2 、3 "
		"独立运行" << endl;

	// 函数指针
	thread th1(foo, 3);

	// 函数对象
	thread th2(thread_obj(), 3);
	/*
	我们创建了一个名为 th2 的线程对象。这个线程对象使用 thread_obj 类的一个临时对象作为可调用参数，并将参数值设置为 3。
	也就是说，当我们启动这个线程时，它将会调用 thread_obj 类的 operator() 函数，并传入参数值 3，然后在循环中打印出 “线程使用函数对象作为可调用参数” 这句话 3 次。
	*/

	// 定义 Lambda 表达式（匿名函数），用来创建函数对象
	/*
	[capture list](parameters) -> return_type {
	}

	下面实例是：
	int x=10;
	int y=20;

	auto sum = [x,&y](){
		return x + y;
	}
	std::cout << sum() << std::endl;  // 输出30

	下面的 []的是捕获列表，里面并没有，（int x）是参数，然后括号里就是这个匿名函数主体。 atuo f 是我们建立的函数对象
	*/
	auto f = [](int x) {
		for (int i = 0; i < x; i++)
			cout << "线程使用 lambda 表达式作为可调用参数\n";
	};

	// 线程通过使用 lambda 表达式作为可调用的参数
	thread th3(f, 3);

	// 等待线程完成
	// 等待线程 t1 完成
	th1.join();

	// 等待线程 t2 完成
	th2.join();

	// 等待线程 t3 完成
	th3.join();

	return 0;
}
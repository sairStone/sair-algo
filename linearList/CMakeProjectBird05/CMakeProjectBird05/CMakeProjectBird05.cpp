// CMakeProjectBird05.cpp: 定义应用程序的入口点。
//

#include "CMakeProjectBird05.h"

using namespace std;

//函数模板:template <typename type> ret-type func-name(parameter list)
template <typename T>
inline T const& Max(T const& a, T const& b) {
	if (a > b) {
		return a;
	}
	else
	{
		return b;
	}
}

int main()
{

	int a = 10;
	int b = 20;
	cout << Max(a, b);

	cout << "\n";

	double da = 10.55;
	double db = 9.55;
	cout << Max(da, db);


	try {
		Stack<int> intStack;  // int 类型的栈 
		Stack<string> stringStack;    // string 类型的栈 

		// 操作 int 类型的栈 
		intStack.push(7);
		cout << intStack.top() << endl;

		// 操作 string 类型的栈 
		stringStack.push("hello");
		cout << stringStack.top() << std::endl;
		stringStack.pop();
		stringStack.pop();
	}
	catch (exception const& ex) {
		cerr << "Exception: " << ex.what() << endl;
		return -1;
	}

	return 0;
}

#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

double vals[] = { 10.1, 12.6, 33.1, 24.1, 50.0 };

int* creatArray(int size);
int getRandom();
double& setValues(int i);

int getRandom() {
	srand((unsigned)time(NULL));
	int a = rand() % 10 + 1;
	return a;
}



int* creatArray(int size) {
	//C++ 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量。
	//为了避免以上情况，你可以使用静态数组或者动态分配数组,下面就是动态分配数组，创建在堆上

	static int arr[5];

	//	int* arr = new int[size];  //在堆上动态分配了一个数组，并在函数内部填充了数组。最后，函数返回了指向数组的指针。
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = getRandom();
	}
	return arr;
}


double& setValues(int i)
{
	double& ref = vals[i];
	return ref;   // 返回第 i 个元素的引用，ref 是一个引用变量，ref 引用 vals[i]
}
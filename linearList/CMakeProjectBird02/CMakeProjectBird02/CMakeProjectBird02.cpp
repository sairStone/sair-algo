// CMakeProjectBird02.cpp: 定义应用程序的入口点。
//

#include "CMakeProjectBird02.h"

using namespace std;

int main()
{
	Box box1 = Box(2,4,3);  //  通过类创建一个对象
	SmallBox sbox1 = SmallBox(10);   // 有派生类的话，~Box会运行两次
	SmallBox sbox2 = sbox1;   // 这里用来拷贝构造函数

	double volume = 0.0;  //体积

	box1.def_public = 10;
	box1.setDef_private(10.11);

	box1.set(2, 9, 3);
	//printBox(box1);// 友元函数，不是构造函数，括号里面直接放对象，表示是该对象的友元
	volume = box1.get();

	cout <<  volume ;

	//sbox1.setInfo("aabbcc");
	//sbox1.getInfo();
	

	 display(sbox1);
	 display(sbox2);


	return 0;
}

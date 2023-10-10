// CMakeProjectBrid03.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>

class Shape
{
public:
	void setWidth(int w) {
		width = w;
	}
	void setHeight(int h) {
		height = h;
	}

protected:
	int width;
	int height;
};


class PaintCost
{
public:
	int getCost(int area)
	{
		return area * 70;
	}
};


class Rectangle : public Shape ,public PaintCost  // 继承两个基类
{
public:
	int getArea() {
		return (width * height);
	}

private:

};



// 函数重载，编译器自动选择最合适的
class PrintData
{
public:
	void printd(int n) {
		std::cout << "this is int:" << n;
	}
	void printd(double n) {
		std::cout << "this is double:" << n;
	}
	void printd(std::string n) {
		std::cout << "this is string:" << n;
	}
private:

};



class Box
{
public:
	int getVolum() {
		return (width * height * length);
	}
	void setWidth(int w) {
		width = w;
	}
	void setLength(int l) {
		length = l;
	}
	void setHeight(int h) {
		height = h;
	}
	//重载的运算符是带有特殊名称的函数，函数名是由关键字 operator 和其后要重载的运算符符号构成的。
	//对象作为参数进行传递，对象的属性使用 this 运算符进行访问
	//这个函数的参数是一个常量引用类型的Box对象，表示将要与当前对象相加的另一个Box对象。
	Box operator+(const Box& b) {  //这是以成员函数的方式重载运算符 + 
		Box box;
		box.length = this->length + b.length;
		box.height = this->height + b.height;
		box.width = this->width + b.width;
		return box;
	}
	//这是以非成员函数的方式重载运算符 +
	//friend Box operator+(const Box& a, const Box& b);

private:
	int width;
	int height;
	int length;
};

/* 非成员函数的方式重载运算符 + ,友元方式
Box operator+(const Box& a, const Box& b)
{
	Box box;
	box.length = a.length + b.length;
	box.width = a.width + b.width;
	box.height = a.height + b.height;
	// cout << box.length << "--" << box.breadth << "--" << box.height << endl; 
	return box;
} 
*/
// TODO: 在此处引用程序需要的其他标头。

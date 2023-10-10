// CMakeProjectBird04.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>
using std::cout;


// 多态
class Shape
{
protected:
	int length;
	int width;

public:
	Shape(int l, int w) {
		length = l;
		width = w;
	}
	virtual int getArea() {  // 设置为虚函数后，才能实现多态的调用（也就是动态链接，或后期绑定），不然属于静态链接
		cout << "Parent Class!\n";
		return (length * width);
	}
};

class Retancgle : public Shape
{
public:
	Retancgle(int a = 0, int b = 0) :Shape(a, b) {

	}
	int getArea() {
		cout << "Retancgle Class!\n";
		return (length * width);
	}
private:

};

class Triangle : public Shape
{
public:
	Triangle(int a = 0, int b = 0) :Shape(a, b) {

	}
	int getArea() {
		cout << "Triangle Class!\n";
		return (length * width);
	}
private:

};


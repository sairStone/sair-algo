// CMakeProjectBird02.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>

using namespace std;

class Box
{
public:
    static int objectCount;//静态成员变量,不建议在创建的时候初始化
    double length;   // 长度
    double breadth;  // 宽度
    double height;   // 高度
    double def_public;
    // 成员函数声明
    double get(void);
    void set(double len, double bre, double hei);
    //下面这个是内联函数
    void setDef_private(double value) {
        def_private = value;
    }
    //下面这个是友元函数
    friend void printBox(Box box) {
        /* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
        // 友元函数没有 this 指针，因为友元不是类的成员，只有成员函数才有 this 指针。
         box.set(1, 2, 3);
        cout << "this is friend function!";
    }
	Box();
    Box(double len, double bre, double hei);
	~Box();

private:
    double def_private;

protected:  //派生类可以访问到
    string boxInfo; 
};

//在创建第一个对象时，所有的静态数据都会被初始化为零。我们不能把静态成员的初始化放置在类的定义中，但是可以在类的外部通过使用范围解析运算符 :: 来重新声明静态变量从而对它进行初始化
int Box::objectCount = 0; //静态成员的初始化

Box::Box()
{

}

Box::Box(double len, double bre, double hei) :length(len), breadth(bre), height(hei)  //构造时就初始化
{

}


Box::~Box()
{
    cout << "\n Box开始销毁！";
}

//范围解析运算符 :: 
//下面是使用范围解析符，也可在类里声明实现
double Box::get(void) {
    cout << def_public << endl;
    cout << def_private << endl;
    return (length + breadth) * height;
}

void Box::set(double len, double bre, double hei) {
    length = len;
    height = hei;
    breadth = bre;
}




class SmallBox:public Box  // 派生子类，也是继承(属于public继承)
{
public:
    int num;
    void setInfo(string str) {
        boxInfo = str;
    }
    void getInfo() {
        cout << "\n";
        cout << boxInfo;
    }
    SmallBox(int val); //构造函数,用来初始化很不错
    SmallBox(const SmallBox &obj); //拷贝构造函数
    ~SmallBox(); //析构函数,不会返回任何值，也不能带有任何参数。
    int getLength(void);

private:
    int* ptr;
};
//构造函数可用于为某些成员变量设置初始值
SmallBox::SmallBox(int val)
{
    cout << "Object is being created" << endl;
    cout << "调用构造函数为ptr分配内存:" << endl;
    ptr = new int;
    *ptr = val;
}

// 下面三种会调用拷贝构造函数！ 重点是传递 对象！
//（1）一个对象以值传递的方式传入函数体
//（2）一个对象以值传递的方式从函数返回
//（3）一个对象需要通过另外一个对象进行初始化。
SmallBox::SmallBox(const SmallBox& obj) {
    cout << "调用拷贝构造函数重新为ptr分配内存：\n";
    ptr = new int;
    *ptr = *obj.ptr;

}

SmallBox::~SmallBox()
{
    cout << "\n SmallBox开始销毁！";
    delete ptr;
}
int SmallBox::getLength(void)
{
    return *ptr;
}

void display(SmallBox obj)
{
    cout << "line 大小 : " << obj.getLength() << endl;
}





// TODO: 在此处引用程序需要的其他标头。

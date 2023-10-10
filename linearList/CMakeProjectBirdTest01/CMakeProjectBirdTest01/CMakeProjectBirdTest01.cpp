// CMakeProjectBirdTest01.cpp: 定义应用程序的入口点。
//

#include "CMakeProjectBirdTest01.h"

#include "arr01.cpp"
#include <ctime>

using namespace std;

int main()
{

	//setfill 用来填充空格，setw用来设置字段的宽度
	cout << setfill('*') << setw(14) << "hello" << endl;

	int * arr = creatArray(5);
	
	for (size_t i = 0; i < 5; i++)
	{
		cout << setw(4) << arr[i] ;
	}

	//delete[] arr;  //动态分配完的数组需要释放,以避免内存泄漏,与new要一起使用


	//------------------------
	int len;
	string str1 = "hello";
	string str2 = "world";
	string str3;
	string str = str1 + str2;

	// 复制 str1 到 str3
	str3 = str1;
	cout << "str3 : " << str3 << endl;

	// 连接 str1 和 str2
	str3 = str1 + str2;
	cout << "str1 + str2 : " << str3 << endl;

	// 连接后，str3 的总长度
	len = str3.size();
	cout << "str3.size() :  " << len << endl;

	//------------------------
	// const char * 和 string 区别很大，不能一并使用

	// 这是个指针数组，里面保存的是对应字符串的首地址
	const char * ptr[10] = {
		"abcdefa",
		"asfasfa",
		"Afesef"
	};
	cout << ptr[1];


	//------------------------
	setValues(3) = 2.333; //ref = vals[3]; ref = 2.333;

	cout << vals[3];


	//------------------------
	// 有四个与时间相关的类型：clock_t、time_t、size_t 和 tm。类型 clock_t、size_t 和 time_t 能够把系统时间和日期表示为某种整数。(协调世界时（UTC）也被称为格林尼治标准时间（GMT）)
	//结构类型 tm 把日期和时间以 C 结构的形式保存，tm 结构的定义如下：
	//struct tm {
	//	int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
	//	int tm_min;   // 分，范围从 0 到 59
	//	int tm_hour;  // 小时，范围从 0 到 23
	//	int tm_mday;  // 一月中的第几天，范围从 1 到 31
	//	int tm_mon;   // 月，范围从 0 到 11
	//	int tm_year;  // 自 1900 年起的年数
	//	int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
	//	int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
	//	int tm_isdst; // 夏令时
	//};
	
	// 基于当前系统的当前日期/时间
	time_t now = time(0);

	// 把 now 转换为字符串形式
	char* dt = ctime(&now);

	cout << "\n本地日期和时间：" << dt << endl;

	// 把 now 转换为 tm 结构
	tm* gmtm = gmtime(&now);
	dt = asctime(gmtm);
	cout << "UTC 日期和时间：" << dt << endl;

	tm* ltm = localtime(&now);
	// 输出 tm 结构的各个组成部分
	cout << "年: " << 1900 + ltm->tm_year << endl;
	cout << "月: " << 1 + ltm->tm_mon << endl;
	cout << "日: " << ltm->tm_mday << endl;
	cout << "时间: " << ltm->tm_hour << ":";
	cout << ltm->tm_min << ":";
	cout << ltm->tm_sec << endl;


	//------------------------
	//使用 cerr 流来显示错误消息，而其他的日志消息则使用 clog 流来输出
	char strr[] = "Unable to read....";

	cerr << "Error message : " << strr << endl;
	clog << "Error message : " << strr << endl;

	return 0;

}


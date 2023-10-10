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
	//C++ ��֧���ں����ⷵ�ؾֲ������ĵ�ַ�����Ƕ���ֲ�����Ϊ static ������
	//Ϊ�˱�����������������ʹ�þ�̬������߶�̬��������,������Ƕ�̬�������飬�����ڶ���

	static int arr[5];

	//	int* arr = new int[size];  //�ڶ��϶�̬������һ�����飬���ں����ڲ���������顣��󣬺���������ָ�������ָ�롣
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = getRandom();
	}
	return arr;
}


double& setValues(int i)
{
	double& ref = vals[i];
	return ref;   // ���ص� i ��Ԫ�ص����ã�ref ��һ�����ñ�����ref ���� vals[i]
}
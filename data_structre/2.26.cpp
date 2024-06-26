#include <iostream>
using namespace std;
int main()
{
	//字符串常量作为参数传入，不加const会报错！！
	char ss[] = "sjtu";
	//典型错误：char* ss=“sjtsgdfus” 后面的这个区无法修改  const char*->char
	// 括号后的const保护this指针
	


	//线性表
	//def：一组特征相同数量有限的元素构成的集合，可以空or不空
	//不空的时候有唯一的首尾元素
	//规模或长度：元素个数
	//存储：将元素存在一块连续空间里
	//申请动态数组 要检测是否申请成功
	int s = 10;
	int* a = new int[s];
	if (!a)
	{
		return 0;//throw ....
	}








	return 0;
}
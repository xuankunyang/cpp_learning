#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;
int main()
{
	//大小写转换
	char ch='a';
	if (islower(ch))
		cout << "小写" << endl;
	if (isupper(ch))
		cout << "大写" << endl;
	char s = tolower(ch);//转为小写，若是小写，不进行操作
	char ss = toupper(ch);
	//全排列
	vector <int> num = { 1,3,4,2 };
	sort(num.begin(), num.end());
	//next_permutation() 用于生成当前序列的下一个排列，按照  字典序  进行重新排序，如果存在下一个排列，则将当前序列更改为下一个序列，并返回true，如果已经是最后一个，则将序列改为第一个，并返回false
	//注意前提升序
	do
	{
		for (int i : num)
			cout << i << " ";
	} while (next_permutation(num.begin(), num.end()));
	cout << endl;
	//相反的 prev_permutation 生成的是上一个序列 按照字典序排列 所以 应该是降序 






	return 0;
}
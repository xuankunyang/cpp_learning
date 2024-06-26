#include <iostream>
#include <string>
using namespace std;
int main1()
{
	string str1="nb";
	string str2 = "hello,world!";
	string str3 = str2;
	string str4 = str2.substr(0, 5);//参数一 起始位置 参数二 长度  忽略第二个 自动到末位
	const char* chararray = "hello";
	string str5(chararray);
	string str6(5, 'A');//五个A
	cout << str1 << endl;
	cout << str2<< endl;
	cout << str3 << endl;
	cout << str4 << endl;
	cout << str5 << endl;
	cout << str6 << endl;
	str2.length();// 获取长度
	str1.size();
	string str7 = str2 + str3 + ".";
	str1.append("+").append("goddamn!");
	int pos = str2.find("world");//查找子串位置，返回第一个元素的位置(0起始)，or-1（string::npos）
	cout << pos;
	string str8 = "hello,world!";
	str7.replace(7, 5, "lover!");//参数一 替换的起始位置（0起始）， 参数二 替换子串的长度
	int bijiao = str7.compare(str1);//0 负数 正数
	//更好用的是 < > == 因为已经重载过
	cout << str2[2];//同char
	for (auto i : str2)
	{
		cout << i;//其实是复制
	}
	for (auto &i : str2)
	{
		cout << i;
		i = 'a';
	}//其实可以理解为i就是string中的元素，真就是高度重载
	cout << endl;
	reverse(str7.begin(), str7.end());//转置
	swap(str7[1], str7[8]);//交换两个元素
	string line = "this@ is@ a test string!";
	string line1 = line.replace(line. find('@'), 1, "");//将第一个@位置替换
	string line2 = line.replace(line.begin(), line.begin() + 6, "");//将line从begin替换6个字符
	string substr = "12345";
	string line3 = line.replace(0, 5, substr, substr.find("1"), 3);//替换起始，替换末尾，传入新字符串，新替换起始，新替换末尾
	string line4 = line.replace(0, 5, substr);//替换起始，替换末尾，新替换串
	string line5 = line.replace(0, 9, substr, 4);//替换起始，替换末尾，传入新串，想要替换的长度，类似line3
	string line6 = line.replace(0, 9, 3, 'a');//替换起始，替换末尾，想要替换的重复长度，重复字符

	







	return 0;
}
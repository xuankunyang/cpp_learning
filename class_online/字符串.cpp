#include <iostream>
#include <string>
using namespace std;
int main1()
{
	string str1="nb";
	string str2 = "hello,world!";
	string str3 = str2;
	string str4 = str2.substr(0, 5);//����һ ��ʼλ�� ������ ����  ���Եڶ��� �Զ���ĩλ
	const char* chararray = "hello";
	string str5(chararray);
	string str6(5, 'A');//���A
	cout << str1 << endl;
	cout << str2<< endl;
	cout << str3 << endl;
	cout << str4 << endl;
	cout << str5 << endl;
	cout << str6 << endl;
	str2.length();// ��ȡ����
	str1.size();
	string str7 = str2 + str3 + ".";
	str1.append("+").append("goddamn!");
	int pos = str2.find("world");//�����Ӵ�λ�ã����ص�һ��Ԫ�ص�λ��(0��ʼ)��or-1��string::npos��
	cout << pos;
	string str8 = "hello,world!";
	str7.replace(7, 5, "lover!");//����һ �滻����ʼλ�ã�0��ʼ���� ������ �滻�Ӵ��ĳ���
	int bijiao = str7.compare(str1);//0 ���� ����
	//�����õ��� < > == ��Ϊ�Ѿ����ع�
	cout << str2[2];//ͬchar
	for (auto i : str2)
	{
		cout << i;//��ʵ�Ǹ���
	}
	for (auto &i : str2)
	{
		cout << i;
		i = 'a';
	}//��ʵ�������Ϊi����string�е�Ԫ�أ�����Ǹ߶�����
	cout << endl;
	reverse(str7.begin(), str7.end());//ת��
	swap(str7[1], str7[8]);//��������Ԫ��
	string line = "this@ is@ a test string!";
	string line1 = line.replace(line. find('@'), 1, "");//����һ��@λ���滻
	string line2 = line.replace(line.begin(), line.begin() + 6, "");//��line��begin�滻6���ַ�
	string substr = "12345";
	string line3 = line.replace(0, 5, substr, substr.find("1"), 3);//�滻��ʼ���滻ĩβ���������ַ��������滻��ʼ�����滻ĩβ
	string line4 = line.replace(0, 5, substr);//�滻��ʼ���滻ĩβ�����滻��
	string line5 = line.replace(0, 9, substr, 4);//�滻��ʼ���滻ĩβ�������´�����Ҫ�滻�ĳ��ȣ�����line3
	string line6 = line.replace(0, 9, 3, 'a');//�滻��ʼ���滻ĩβ����Ҫ�滻���ظ����ȣ��ظ��ַ�

	







	return 0;
}
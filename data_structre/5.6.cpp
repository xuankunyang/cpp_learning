#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    //外部查找
	// 建立索引
	// B树：多线程查找树 每个节点的分支数量>=m/2 <=m 
	//查找：O（logm  n）
	//插入：满了以后一分为二 
	//删除：若数量不满足，首先考虑去前后借，还是无法实现，可以选择和前后进行合并！！！在这些过程中，切记保持节点信息之间的大小关系以及数量>=m/2 <=m
	// 
	//



	return 0;
}
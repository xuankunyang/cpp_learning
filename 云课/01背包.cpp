#include <iostream>
using namespace std;
int main()
{
	//二维：
	//dp[i][j]=max(dp[i-1][j],dp[i-1][j-w]+v) 
	//dp[i][j]表示在前i件物品中消耗j能得到的最大value
	//一维：
	//dp[j]=max(dp[j],dp[j-w]+v) 这里需要注意 j应该是从大到小遍历




	return 0; 
}
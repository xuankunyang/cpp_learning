#include <iostream>
#include <algorithm>
using namespace std;

//���������ſ�

int main() 
{
    const int N = 2e4 + 5;
    using ll = long long;
    ll dp17[N];
    int t[N], value[N];
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; i++) 
    {
        cin >> t[i] >> value[i];
        t[i] += 1; // ��Ϊ���������Ʒ���Ի�� t[i]+1 ����Ʒ
        sum = max(sum, t[i]); // �ҵ��ȴ�ʱ��������Ʒ���������Ʒ������������� n+sum
    }
    sum += n;

    for (int i = 1; i <= sum + 1; i++)
        dp17[i] = 1e17;

    for (int i = 1; i <= n; i++) 
    {
        for (int j = sum; j >= t[i]; j--)
        {
            dp17[j] = min(dp17[j], dp17[j - t[i]] + value[i]);
        }
    }

    ll ans = 1e18;
    for (int i = n; i <= sum; i++) // ��Ϊ��Ķ������⼸�����
        ans = min(dp17[i], ans);

    cout << ans << '\n';
    return 0;
}

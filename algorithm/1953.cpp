#include <bits/stdc++.h>
using namespace std;

pair<int, int> partition(vector <int> &a, int pivot) {
    // TODO: implement partition
    vector<int> b;
    for(auto i:a)
    {
        if(i<pivot)b.push_back(i);
    }
    int l = b.size();
    for(auto i:a)
    {
        if(i==pivot)b.push_back(i);
    }
    int r = b.size();
    for(auto i:a)
    {
        if(i>pivot)b.push_back(i);
    }
    a = b;
    return make_pair(l,r);
}

int main() {
    int n, pivot;
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> pivot;
    vector <int> arr;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    auto [l, r] = partition(arr, pivot);
    for (auto i : arr) cout << i << ' ';
    cout << '\n' << l << ' ' << r << '\n';
}
#include <bits/stdc++.h>

using namespace std;

int n, k;
vector <int> a;

// use precise time as random seed
const int RANDOM_SEED = 20050331;
mt19937 rng(RANDOM_SEED); // random number generator

int randint(int l, int r) { // rand in [l, r]
    return int(rng() % (r - l + 1) + l);
}

pair<int, int> partition(vector <int> &v, int pivot) {
    // TODO: implement partition
    vector<int> b;
    for(auto i:v)
    {
        if(i<pivot)b.push_back(i);
    }
    int l = b.size();
    for(auto i:v)
    {
        if(i==pivot)b.push_back(i);
    }
    int r = b.size();
    for(auto i:v)
    {
        if(i>pivot)b.push_back(i);
    }
    v = b;
    return make_pair(l,r);
}

void read_input_data_vector()
{
    int m;
    cin >> n >> k >> m; 
    a.resize(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    unsigned int z = a[m - 1];
    for (int i = m; i < n; i++)
    {
        z ^= z << 13;
        z ^= z >> 17;
        z ^= z << 5;
        a[i] = z & 0x7fffffff;
    }
}

int select(vector<int>& v,int target)
{
    int pivot_index = randint(0,v.size()-1);
    auto [l,r] = partition(v,v[pivot_index]);
    vector<int>left,mid,right;
    if(target<=l)
    {
        left.assign(v.begin(),v.begin()+l);
        return select(left,target);
    }
    else if(target<=r)return v[l];
    else
    {
        right.assign(v.begin()+r,v.end());
        return select(right,target-r);
    }

    
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    read_input_data_vector();

    
    cout<<select(a,k);

    

    return 0;
}
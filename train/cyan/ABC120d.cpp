#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back


class UnionFind{
    public:
        vector<int> uni;
        UnionFind(int s) : uni(s, -1) { }
 
       //頂点aが所属するグループを調べる
        int root(int a)
        {
            if (uni[a] < 0) return a;
            return uni[a] = root(uni[a]);
        }
    
        //頂点aと頂点bを繋ぐ。もともと同じグループの時falseを返す
        bool connect(int a,int b)
        {
            a = root(a);
            b = root(b);
            if (a == b) return false;
    
            if (uni[a] > uni[b])
            {
                a ^= b;
                b ^= a;
                a ^= b;
            }
    
            uni[a] = uni[a] + uni[b];
            uni[b] = a;
            return true;
        }
    
        //頂点a,bが同じグループであるかを調べる
        bool isConnect(int a,int b)
        {
            return root(a) == root(b);
        }
    
        //頂点aを含むグループの頂点数を調べる
        int size(int a)
        {
            return -uni[root(a)];
        }
    
    };


int main(){
    ll n, m; cin >> n >> m;
    vector<ll> alis(m), blis(m);
    vector<ll> ans(m);
    UnionFind un(n+1);
    ans[m-1] = (n * (n-1)) / 2;
    REP(i, 0, m){
        cin >> alis[i] >> blis[i];
    }
    for(int i = m-1; i >= 1; i--){
        int a = alis[i], b = blis[i];
        int f = 0;
        if(!un.isConnect(a, b)){
            f = un.size(a) * un.size(b);
        }
        ans[i-1] = ans[i] - f;
        un.connect(a, b);
    }
    REP(i, 0, m){
        cout << ans[i] << endl;
    }
}
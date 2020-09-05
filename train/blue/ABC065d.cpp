#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
using edge = pair<ll, Pii>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


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
    int n; cin >> n;
    UnionFind un(n+1);
    vector<vector<int> > lis(n, vector<int>(3));
    vector<edge> edges;
    REP(i, 0, n){
        cin >> lis[i][0] >> lis[i][1];
        lis[i][2] = i;
    }
    sort(ALL(lis), [](auto &x, auto &y){return x[0] < y[0];});
    REP(i, 0, n-1){
        edges.pb(edge(lis[i+1][0] - lis[i][0], Pii(lis[i+1][2], lis[i][2])));
    }
    sort(ALL(lis), [](auto &x, auto &y){return x[1] < y[1];});
    REP(i, 0, n-1){
        edges.pb(edge(lis[i+1][1] - lis[i][1], Pii(lis[i+1][2], lis[i][2])));
    }
    sort(ALL(edges));
    ll sum = 0;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if(un.connect(u, v)){
            sum += edges[i].first;
        }
    }
    cout << sum << endl;
}
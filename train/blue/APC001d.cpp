// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

//ordered_set 重複不可
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use set_function + find_by_order(select itr-num)

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

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
    int n, m; cin >> n >> m;
    UnionFind un(n);
    vector<ll> costs(n);
    REP(i,0,n){cin >> costs[i];}
    REP(i,0,m){
        int a, b; cin >> a >> b;
        un.connect(a, b);
    }
    vector<vector<ll> > lis(n);
    REP(i,0,n){
        int a = un.root(i);
        lis[a].pb(costs[i]);
    }
    vector<vector<ll> > lis2;
    REP(i,0,n){
        if(lis[i].size() == 0){
            continue;
        }
        sort(ALL(lis[i]));
        lis2.pb(lis[i]);
    }
    sort(ALL(lis2), [](auto &x, auto &y){return x.size() > y.size();});
    ll ans = 0;
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    int idx = 0;
    REP(i,0,lis2.size()){
        if(lis2[i].size() == 0){
            continue;
        }
        REP(l,0,lis2[i].size()){
            pq.push(lis2[i][l]);
        }
        idx = i;
        break;
    }
    /*
    REP(i,0,lis2.size()){
        REP(l,0,lis2[i].size()){
            cout << lis2[i][l] << " ";
        }
        cout << endl;
    }
    */
    REP(i,0,lis2.size()){
        if(idx == i){
            continue;
        }
        if(pq.empty()){
            cout << "Impossible" << endl;
            return 0;
        }
        ll a = pq.top();
        pq.pop();
        ans += a + lis2[i][0];
        //cout << a << " " << lis[i][0] << endl;
        REP(l,1,lis2[i].size()){
            pq.push(lis2[i][l]);
        }
    }
    cout << ans << endl;
}
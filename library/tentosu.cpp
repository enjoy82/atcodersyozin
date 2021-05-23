//ARC120

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


 // 1-indexedなので注意。
 struct BIT {
  private:
   vector<int> bit;
   int N;
 
  public:
   BIT(int size) {
     N = size;
     bit.resize(N + 1);
   }
 
   // 一点更新です
   void add(int a, int w) {
     for (int x = a; x <= N; x += x & -x) bit[x] += w;
   }
 
   // 1~Nまでの和を求める。
   int sum(int a) {
     int ret = 0;
     for (int x = a; x > 0; x -= x & -x) ret += bit[x];
     return ret;
   }
 };

bool check(vector<ll> alis, vector<ll> blis){
    sort(ALL(alis));
    sort(ALL(blis));
    REP(i,0,alis.size()){
        if(alis[i] != blis[i]){
            return true;
        }
    }
    return false;
}

int main(){
    int n; cin >> n;
    vector<ll> alis(n), blis(n);
    REP(i,0,n){cin >> alis[i]; alis[i]+=i;}
    REP(i,0,n){cin >> blis[i]; blis[i]+=i;}
    if(check(alis, blis)){
        cout << -1 << endl;
        return 0;
    }

    map<int, vector<ll> > mp;
    map<int, int> idx;
    BIT b(n); 
    REP(i,0,n){
        mp[blis[i]].pb(i);
    }
    vector<ll> s(n);
    REP(i,0,n){
        s[i] = mp[alis[i]][idx[alis[i]]] + 1;
        idx[alis[i]]++;
    }
    ll ans = 0;
    REP(i,0,n){
        ans += i - b.sum(s[i]);
        b.add(s[i], 1);
    }
    cout << ans << endl;
}
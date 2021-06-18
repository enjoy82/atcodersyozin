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

ll Pow(ll  x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return Pow(x * x, n / 2);
  else
    return x * Pow(x, n - 1);
}


int main(){
    ll n, k; cin >> n >> k;
    vector<vector<ll> > doubling(1e5, vector<ll>(100, 0));

    //make double
    REP(i,0,1e5){
        ll cp = i;
        ll add = 0;
        REP(l,0,5){
            add += cp % 10;
            cp /= 10;
        }
        doubling[i][0] = (i + add) % 100000;
    }
    REP(i,1,100){
        REP(l,0,1e5){
            doubling[l][i] = doubling[doubling[l][i-1]][i-1];
        }
    }

    REP(i,0,90){
        if(k & 1 == 1){
            n = doubling[n][i];
        }
        k = (k >> 1);
    }
    cout << n << endl;
}
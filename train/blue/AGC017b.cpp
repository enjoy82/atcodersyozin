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

int main(){
    ll n, a, b, c, d; cin >> n >> a >> b >> c >> d;
    ll mmin = -1 * d, mmax = -1 * c, pmin = c, pmax = d;
    vector<ll> mmin_r(n+1, 0), mmax_r(n+1, 0), pmin_r(n+1, 0), pmax_r(n+1, 0);
    REP(i,0,n){
        mmin_r[i+1] = mmin_r[i] + mmin;
        mmax_r[i+1] = mmax_r[i] + mmax;
        pmin_r[i+1] = pmin_r[i] + pmin;
        pmax_r[i+1] = pmax_r[i] + pmax;
    }
    ll dif = abs(a-b);
    int f = 0;
    REP(i,0,n){
        ll left = mmin_r[n-1-i] + pmin_r[i];
        ll right = mmax_r[n-1-i] + pmax_r[i];
        if(left <= dif && dif <= right){
            f = 1;
        }
    }
    if(f){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
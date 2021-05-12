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

void solve(){
    ll n; cin >> n;
    vector<ll> lis(2*n);
    map<ll, ll> mp;
    REP(i,0,2*n){
        cin >> lis[i];
        mp[lis[i]]++;
    }
    for(auto x:mp){
        if(x.second % 2 != 0){
            cout << "NO" << endl;
            return;
        }
    }
    sort(ALL(lis), [](auto &x, auto &y){
        return abs(x) > abs(y);
    });
    ll sum = 0;
    if(lis[0] % (2*n) != 0){
        cout << "NO" << endl;
        return;
    }
    map<ll, ll>mp2;
    sum = lis[0] / (2*n);
    ll pre = lis[0] / (2*n);
    for(ll i = 2; i < 2*n; i+= 2){
        ll c = lis[i] - 2*sum;
        if((c % (2*n - i) != 0) || (c / (2*n-i) <= 0) || (c / (2*n-i) >= pre)){
            cout << "NO" << endl;
            return;
        }else{
            sum += (c / (2*n-i));
            pre = c / (2*n-i);
        }
    }
    cout << "YES" << endl;
}

int main(){
    int t; cin >> t;
    REP(i,0,t){solve();}
}
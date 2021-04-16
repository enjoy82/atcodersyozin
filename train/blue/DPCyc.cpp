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

int n;
string s;

void solve(){
    int k; cin >> k;
    ll d = 0, m = 0, dm = 0, ans = 0, dloss = 0, mloss = 0, dmloss = 0;
    REP(i,0,n){
        if(i - k >= 0){
            if(s[i-k] == 'D'){
                dloss++;
            }
            if(s[i-k] == 'M'){
                mloss++;
                dmloss+=dloss; 
            }
        }
        if(s[i] == 'D'){
            d++;
        }
        if(s[i] == 'M'){
            m++;
            dm+= d;
        }
        ll nd = d - dloss, nm = m - mloss;
        ll ndm = dm - dmloss - dloss * nm;
        if(s[i] == 'C'){
            //cout << ndm << endl;
            ans += ndm;
        }
    }
    cout << max(ans,0ll) << endl;
}

int main(){
    cin >> n >> s;
    int q; cin >> q;
    REP(i,0,q){solve();}
}
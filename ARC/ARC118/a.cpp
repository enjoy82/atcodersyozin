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
    ld t;
    ll n; cin >> t >> n;
    vector<ll> loop;
    ll pre = 0;
    REP(i,1,101){
        ll c = (ld)i * ((100.0 + t) / 100.0);
        if(pre + 1 != c){
            REP(l,pre+1, c){
                loop.pb(l);
            }
        }
        pre = c;
    }
    /*
    REP(i,0,loop.size()){
        cout << loop[i] << endl;
    }
    */
    ll ss = n /loop.size();
    ll div = n % loop.size();
    ll l1 = 0;
    REP(i,0,loop.size()-1){
        l1 += loop[i+1] - loop[i];
    }
    l1 += loop[0] + (100 * ((100.0 + t) / 100.0)) - loop.back();
    ll ans;
    if(div-1 >= 0){
        ans = loop[div-1];
        ans += ss * l1;
        cout << ans << endl;
    }else{
        ans = loop[loop.size()-1];
        ans += (ss-1) * l1;
        cout << ans << endl;
    }
    
}
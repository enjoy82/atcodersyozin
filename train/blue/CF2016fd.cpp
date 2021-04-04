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
    int n, m; cin >> n >> m;
    vector<ll> modlis(m), maxsamenum(m, 0), flag(1e6, 0), odd(1e6, 0);
    REP(i,0,n){
        int a; cin >> a;
        modlis[a%m]++;
        flag[a]++;
    }
    REP(i,0,1e6){
        odd[i%m] += flag[i] % 2;
        maxsamenum[i%m] += flag[i] - (flag[i] % 2);
    }
    ll ans = modlis[0] / 2;
    REP(i,1,m){
        if(i == m-i){
            ans += modlis[i] / 2;
            modlis[i] -= (modlis[i] / 2) * 2;
            continue;
        }
        ll mid1 = min(modlis[i], modlis[m-i]);
        modlis[i] = 0;
        modlis[m-i] = 0;
        ll mid11 = mid1 + ((maxsamenum[i] - max(0ll, (mid1 - odd[i]))) / 2) + ((maxsamenum[m-i] - max(0ll, (mid1 - odd[m-i]))) / 2);
        maxsamenum[i] = 0;
        maxsamenum[m-i] = 0;
        odd[i] = 0;
        odd[m-i] = 0;
        ans += mid11;
    }
    cout << ans << endl;
}
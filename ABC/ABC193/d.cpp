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

const ll MOD = 1e9+7;

ll Pow(ll  x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return Pow(x * x % MOD, n / 2);
  else
    return x * Pow(x, n - 1) % MOD;
}


int main(){
    int k; cin >> k;
    vector<int> lis(10, k);
    string s, t; cin >> s >> t;
    map<ll, ll> smp, tmp;
    REP(i, 1, 10){
        smp[i] = 0;
        tmp[i] = 0;
    }
    REP(i, 0, 4){
        lis[s[i]-'0']--;
        lis[t[i]-'0']--;
        smp[s[i]-'0']++;
        tmp[t[i]-'0']++;
    }
    ld ans = 0;
    REP(i, 1, 10){ //T
        if(lis[i] == 0){
            continue;
        }
        ld aa = ((lis[i] * 1.0) / (9 * k * 1.0 - 8.0));
        lis[i]--;
        smp[i]++;
        ll tscore = 0;
        for(auto x:smp){
            tscore += x.first * Pow(10, x.second);
        }
        //cout << i << endl;
        //cout << "Tscore" << tscore << endl;
        ld mid = 0;
        REP(l, 1, 10){ //A
            if(lis[l] == 0){
                continue;
            }
            ld bb = ((lis[l] * 1.0) / (9 * k * 1.0 - 9.0));
            tmp[l]++;
            ll sscore = 0;
            for(auto x:tmp){
                sscore += x.first * Pow(10, x.second);
            }
            if(tscore > sscore){
                mid += bb;
            }else{
                //cout << i << " " << l << endl;
                //cout << tscore << " " << sscore << endl;
                //cout << "NG" << endl;
            }
            tmp[l]--;
        }
        //cout << aa << mid << endl;
        ans += aa * mid;
        lis[i]++;
        smp[i]--;
    }
    cout << std::fixed << std::setprecision(15) << ans << endl;
}
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

ll n;

ll solve(ll k, vector<int>flag, vector<vector<ll> >&lis){
    if(k == 1 || k == 0){
        if(k==1)
            flag[0] = 1;
        /*
        REP(i, 0, 5){
            cout << flag[i] << " ";
        }
        cout << endl;
        */
        ll ans = 0;
        REP(i, 0, n){
            ll a = lis[i][0];
            int f = 1;
            REP(l, 0, 31){
                if(a & (1<<l)){
                    if(flag[l]){
                    }else{
                        f = 0;
                    }
                }
            }
            if(f){
                ans += lis[i][1];
            }
        }
        return ans;
    }
    ll mid = 1;
    ll count = 0;
    while(mid * 2 <= k){
        mid *= 2;
        count++;
    }
    flag[count] = 1;

    ll ans1 = solve(k-mid, flag, lis);
    flag[count] = 0;
    REP(i, 0, count){
        flag[i] = 1;
    }
    /*
    REP(i, 0, 5){
        cout << flag[i] << " ";
    }
    cout << endl;
    */
    ll ans = 0;
    REP(i, 0, n){
        ll a = lis[i][0];
        int f = 1;
        REP(l, 0, 31){
            if(a & (1<<l)){
                if(flag[l]){
                }else{
                    f = 0;
                }
            }
        }
        if(f){
            ans += lis[i][1];
        }
    }
    return max(ans, ans1);
}

int main(){
    ll k; cin >> n >> k;
    vector<vector<ll> > lis(n, vector<ll>(2));
    REP(i, 0, n){
        cin >> lis[i][0] >> lis[i][1];
    }
    vector<int> flag(31, 0);
    cout << solve(k, flag, lis) << endl;
}
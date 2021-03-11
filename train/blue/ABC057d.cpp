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

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
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

ll combination(int a, int b){
    //cout << a << b << endl;
    ll ans = 1;
    map<ll, ll> mp;
    REP(i, 0, b){
        mp[a-i]++;
    }
    ll k = 1;
    REP(l, 1, b+1){
        ll cp = l;
        for(auto &x:mp){
            if(cp == 1)
                break;
            if(x.second <=0)
                continue;
            ll c = gcd(cp, x.first);
            ll xcp = x.first;
            while(c != 1){
                mp[xcp]--;
                mp[xcp/c]++;
                cp /= c;
                xcp /= c;
                c = gcd(cp, xcp);
            }
        }
        k *= cp;
    }
    for(auto &x:mp){
         if(x.second <=0)
                continue;
        REP(i, 0, x.second){
            ans *= x.first;
        }
    }
    return ans/k;
}

int main(){
    int n, a, b; cin >> n >> a >> b;
    vector<ll> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    sort(ALL(lis), greater<>());
    if(lis[0] != lis[a-1]){
        if(lis[a-1] != lis[a]){
            double mid = 0;
            REP(i, 0, a){
                mid += lis[i];
            }
            cout << std::fixed << std::setprecision(15) << (mid*1.0) / a << endl << 1 << endl;
        }else{
            map<ll, int> mp;
            int idx = -1;
            REP(i, 0, n){
                if(idx == -1 && lis[i] == lis[a-1])
                    idx = i;
                mp[lis[i]]++;
            }
            ll ans = combination(mp[lis[a-1]], a-idx);
            double mid = 0;
            REP(i, 0, a){
                mid += lis[i];
            }
            cout << std::fixed << std::setprecision(15) << (mid*1.0) / a << endl << ans << endl;
        }
    }else{
        map<ll, int> mp;
        REP(i, 0, n){
            mp[lis[i]]++;
        }
        int num = mp[lis[0]];
        ll ans = 0;
        REP(i, a, b+1){
            if(lis[0] != lis[i-1])
                break;
            ans += combination(num, i);
        }
        ll mid = 0;
        REP(i, 0, a){
            mid += lis[i];
        }
        cout << std::fixed << std::setprecision(15) << (mid*1.0) / a << endl << ans << endl;
    }
}

// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

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

const ll mod = 998244353;
int main(){
    ll n, kk; cin >> n >> kk;
    vector<vector<ll> > lis(n, vector<ll>(n));
    REP(i, 0, n){
        REP(l, 0, n){
            cin >> lis[i][l];
        }
    }
    dsu tate(n), yoko(n);
    REP(i, 0, n-1){
        REP(l, i+1, n){
            int f = 1;
            REP(k, 0, n){
                if(lis[i][k] + lis[l][k] > kk){
                    f = 0;
                }
            }
            if(f){
                tate.merge(i, l);
            }
        }
    }
    REP(i, 0, n-1){
        REP(l, i+1, n){
            int f = 1;
            REP(k, 0, n){
                if(lis[k][i] + lis[k][l] > kk){
                    f = 0;
                }
            }
            if(f){
                yoko.merge(i, l);
            }
        }
    }
    vector<int> flagt(n), flagy(n);
    ll ans = 1;
    REP(i, 0, n){
        int k = tate.leader(i);
        if(flagt[k] == 0){
            flagt[k] = 1;
            ll c = tate.size(k);
            REP(l, 1, c+1){
                ans *= l;
                ans %= mod;
            } 
        }
    }
    REP(i, 0, n){
        int k = yoko.leader(i);
        if(flagy[k] == 0){
            flagy[k] = 1;
            ll c = yoko.size(k);
            REP(l, 1, c+1){
                ans *= l;
                ans %= mod;
            } 
        }
    }
    cout << ans << endl;
}
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

const ll mod = 1e9 + 7;

int main(){
    int n, q; cin >> n >> q;
    vector<vector<vector<ll> > > bitlis(60, vector<vector<ll> >(q, vector<ll>(4)));
    ll ans = 1;
    REP(i,0,q){
        int x, y, z; cin >> x >> y >> z;
        x--; y--; z--;
        ll w; cin >> w;
        REP(l,0,60){
            bitlis[l][i][0] = x;
            bitlis[l][i][1] = y;
            bitlis[l][i][2] = z;
            bitlis[l][i][3] = ((w>>l) & 1);
        }
    }
    REP(i,0,60){
        ll mid = 0;
        REP(l,0,(1<<n)){
            vector<ll> arr(n);
            REP(k,0,n){
                arr[k] = (l >> k) & 1;
            }
            int f = 1;
            REP(k,0,q){
                int f2;
                if(bitlis[i][k][3] == 1){
                    f2 = 0;
                    REP(m,0,3){
                        if(arr[bitlis[i][k][m]] == bitlis[i][k][3]){
                            f2 = 1;
                            break;
                        }
                    }
                }else{
                    f2 = 1;
                    REP(m,0,3){
                        if(arr[bitlis[i][k][m]] == 1){
                            f2 = 0;
                            break;
                        }
                    }
                }
                if(f2 == 0){
                    f = 0;
                    break;
                }
            }
            mid += f;
        }
        ans *= mid;
        ans %= mod;
    }
    cout << ans << endl;
}
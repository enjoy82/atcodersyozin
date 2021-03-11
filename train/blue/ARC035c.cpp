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

#define MAX_V 1000

int d[MAX_V][MAX_V];
int V; //頂点数

void warshall_floyd(){
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int l = 0; l < V; l++){
                d[i][l] = min(d[i][l], d[i][k] + d[k][l]);
            }
        }
    }
}

int main(){
    int m; cin >> V >> m;
    REP(i, 0, V){
        REP(l, 0, V){
            d[i][l] = 1e7;
        }
        d[i][i] = 0;
    }
    REP(i, 0, m){
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        d[a][b] = c;
        d[b][a] = c;
    }
    warshall_floyd();
    ll sum = 0;
    REP(i, 0, V){
        REP(l, i+1, V){
            sum += d[i][l];
        }
    }
    int k; cin >> k;
    REP(i, 0, k){
        int x, y, z;  cin >> x >> y >> z;
        x--; y--;
        if(d[x][y] > z){
            ll mid = 0;
            d[x][y] = z;
            d[y][x] = z;
            REP(l, 0, V){
                REP(j, 0, V){
                    d[l][j] = min({d[l][j], d[l][x] + d[y][j] + z, d[l][y] + d[x][j] + z});
                }
            }
            REP(l, 0, V){
                REP(k, l+1, V){
                    mid += d[l][k];
                }
            }
            sum = mid;
        }
        cout << sum << endl;
    }
}
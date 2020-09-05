#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<vector<ll> > d;

void warshall_floyd(int n) {
  for (int k = 0; k < n; k++){       // 経由する頂点
    for (int i = 0; i < n; i++) {    // 始点
      for (int j = 0; j < n; j++) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

const ll INF = 1e12;

int main(){
    int n, m; cin >> n >> m;
    d = vector<vector<ll> >(n, vector<ll>(n, INF));
    REP(i, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        d[a-1][b-1] = c;
        d[b-1][a-1] = c;
    }
    REP(i, 0, n){
        d[i][i] = 0;
    }
    warshall_floyd(n);
    ll min = 1e12, ans;
    REP(i, 0, n){
        ll mid = 0;
        REP(l, 0, n){
            chmax(mid, d[i][l]);
        }
        chmin(min, mid);
    }
    cout << min << endl;
}
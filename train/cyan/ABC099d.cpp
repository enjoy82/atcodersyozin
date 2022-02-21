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

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int n, c; cin >> n >> c;
    vector<vector<int> > d(c+1, vector<int>(c+1));
    REP(i, 0, c){
        REP(l, 0, c){cin >> d[i+1][l+1];}
    }
    vector<vector<int> > lis(n+1, vector<int>(n+1));
    REP(i, 0, n){
        REP(l, 0, n){cin >> lis[i+1][l+1];}
    }
    vector<vector<int> > color(3, vector<int>(c+1, 0));
    REP(i, 1, n+1){
        REP(l, 1, n+1){
            color[(i+l)%3][lis[i][l]]++;
        }
    }
    ll ans = 1e17;
    REP(i, 1, c+1){
        REP(l, 1, c+1){
            if(i == l){continue;}
            REP(j, 1, c+1){
                if(i == j || j == l){continue;}
                ll mid = 0;
                REP(k, 1, c+1){
                    mid += (color[0][k] * d[k][i]) + (color[1][k] * d[k][l]) + (color[2][k] * d[k][j]);
                }
                ans = min(ans, mid);
            }
        }
    }
    cout << ans << endl;
}
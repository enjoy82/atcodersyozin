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
    int w, h, n; cin >> w >> h >> n;
    vector<vector<int> > lis(w, vector<int>(h, 0));
    REP(i, 0, n){
        int x, y, a; cin >> x >> y >> a;
        if(a == 1){
            REP(l, 0, w){
                REP(j, 0, h){
                    if(l < x){
                        lis[l][j] = 1;
                    }
                }
            }
        }else if(a == 2){
            REP(l, 0, w){
                REP(j, 0, h){
                    if(l >= x){
                        lis[l][j] = 1;
                    }
                }
            }
        }else if(a == 3){
            REP(l, 0, w){
                REP(j, 0, h){
                    if(j < y){
                        lis[l][j] = 1;
                    }
                }
            }
        }else if(a == 4){
            REP(l, 0, w){
                REP(j, 0, h){
                    if(j >= y){
                        lis[l][j] = 1;
                    }
                }
            }
        }
    }
    int ans = w * h;
    REP(l, 0, w){
        REP(j, 0, h){
            ans -= lis[l][j];
        }
    }
    cout << ans << endl;
}
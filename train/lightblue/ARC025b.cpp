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
    int h, w; cin >> h >> w;
    vector<vector<int> > blis(h+1, vector<int>(w+1, 0)), wlis(h+1, vector<int>(w+1, 0));
    REP(i, 0, h){
        REP(l, 0, w){
            if((i + l) % 2 == 0){
                cin >> blis[i+1][l+1];
            }else{
                cin >> wlis[i+1][l+1];
            }
        }
    }
    REP(i, 0, h+1){
        REP(l, 0, w){
            blis[i][l+1] += blis[i][l];
            wlis[i][l+1] += wlis[i][l];
        }
    }
    REP(l, 0, w+1){
        REP(i, 0, h){
            blis[i+1][l] += blis[i][l];
            wlis[i+1][l] += wlis[i][l];
        }
    }
    /*REP(i, 0, h+1){
        REP(l, 0, w+1){
            cout << blis[i][l];
        }
        cout << endl;
    }*/
    int ans = 0;
    REP(y, 0, w){
        REP(x, 0, h){
            REP(dy, y+1, w+1){
                REP(dx, x+1, h+1){
                    int black = blis[x][y] + blis[dx][dy] - blis[dx][y] - blis[x][dy];
                    int white = wlis[x][y] + wlis[dx][dy] - wlis[dx][y] - wlis[x][dy];
                    if(black == white){
                        ans = max(ans, (dx-x) * (dy-y));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
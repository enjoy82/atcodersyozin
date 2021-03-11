// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

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

int main(){
    int h, w, n, m; cin >> h >> w >> n >> m;
    vector<vector<int> > grid(h, vector<int>(w, 0)), grid2(h, vector<int>(w, 0));
    vector<vector<int> > right(n, vector<int>(2));
    REP(i, 0, n){
        int a, b; cin >> a >> b;
        a--; b--;
        grid[a][b] = 1;
    }
    REP(i, 0, m){
        int a, b; cin >> a >> b;
        a--; b--;
        grid[a][b] = -1;
    }
    int ans = 0;
    REP(i, 0, h){
        int mid = 0;
        int flag = 0;
        int s = 0;
        REP(l, 0, w){
            if(grid[i][l] == 1){
                flag = 1;
                mid++;
            }else if(grid[i][l] == 0){
                mid++;
            }else if(grid[i][l] == -1){
                if(flag == 1){
                    ans += mid;
                    REP(k, s, l){
                        if(grid[i][k] != -1){
                            grid2[i][k] = 1;
                        }
                    }
                }
                mid = 0;
                flag = 0;
                s = l;
            }
        }
        if(flag == 1){
            ans += mid;
            REP(k, s, w){
                if(grid[i][k] != -1){
                    grid2[i][k] = 1;
                }
            }
        }
    }
    /*
    REP(i, 0, h){
        REP(l, 0, w){
            cout << grid2[i][l];
        }
        cout << endl;
    }
    */
    
    REP(i, 0, w){
        int mid = 0;
        int flag = 0;
        int s = 0;
        REP(l, 0, h){
            if(grid[l][i] == 1){
                flag = 1;
                if(grid2[l][i] == 0){
                    mid++;
                }
            }else if(grid[l][i] == 0 && grid2[l][i] == 0){
                mid++;
            }else if(grid[l][i] == -1){
                if(flag == 1){
                    ans += mid;
                    REP(k, s, l){
                        if(grid[k][i] != -1){
                            grid2[k][i] = 1;
                        }
                    }
                }
                mid = 0;
                flag = 0;
                s = l;
            }
        }
        if(flag == 1){
            ans += mid;
            REP(k, s, h){
                if(grid[k][i] != -1){
                    grid2[k][i] = 1;
                }
            }
        }
    }
    /*
    REP(i, 0, h){
        REP(l, 0, w){
            cout << grid2[i][l];
        }
        cout << endl;
    }
    */
    int ans2 = 0;
    REP(i, 0, h){
        REP(l, 0, w){
            ans2 += grid2[i][l];
        }
    }
    cout << ans2 << endl;
}
#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct zahyo{
    int x; int y;
};

int h, w, t;
vector<string>lis;

int main(){
    cin >> h >> w >> t;
    int sx, sy, gx, gy;
    lis = vector<string>(h);
    REP(i, 0, h){cin >> lis[i];}
    REP(i, 0, h){
        REP(l, 0, w){
            if(lis[i][l] == 'S'){
                sx = i; sy = l;
            }else if(lis[i][l] == 'G'){
                gx = i; gy = l;
            }
        }
    }
    ll r = 1, l = 1e9;
    while(l-r > 0){
        ll mid = (l + r)/2;
        //cout << mid << endl;
        vector<vector<ll> > dp(h, vector<ll>(w, 1e15));
        dp[sx][sy] = 0;
        queue<zahyo> q;
        q.push({sx, sy});
        while(!q.empty()){
            zahyo pos = q.front();
            q.pop();
            int x = pos.x, y = pos.y;
            REP(i, 0, 4){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >=0 && ny >=0 && nx < h && ny < w){
                    //cout << nx << ny << endl;
                    if(lis[nx][ny] == '.'){
                        if(dp[nx][ny] > dp[x][y]+1){
                            dp[nx][ny] = dp[x][y]+1;
                            q.push({nx, ny});
                        }
                    }else if(lis[nx][ny] == '#'){
                        if(dp[nx][ny] > dp[x][y]+mid){
                            dp[nx][ny] = dp[x][y]+mid;
                            q.push({nx, ny});
                        }
                    }else if(lis[nx][ny] == 'G'){
                        if(dp[nx][ny] > dp[x][y]+1){
                            dp[nx][ny] = dp[x][y]+1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        //cout << dp[gx][gy] << endl;
        //cout << r << l << endl;
        if(dp[gx][gy] <=t){
            if(mid == r)
                break;
            r = mid;
        }else{
            if(mid == l)
                break;
            l = mid;
        }
    }
    cout << r << endl;
}
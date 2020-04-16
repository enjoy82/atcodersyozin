#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct zahyo{
    int x;
    int y;
};

int main(){
    int h, w, sx, sy, gx, gy; cin >> h >> w >> sx >> sy >> gx >> gy;
    sy--; sx--; gy--; gx--;
    vector<string> lis(h);
    vector<vector<int> > flag(h, vector<int>(w, 0));
    REP(i, 0, h){cin >> lis[i];}
    queue<zahyo> q;
    q.push({sx, sy});
    while(!q.empty()){
        zahyo t = q.front();
        q.pop();
        int xx = t.x, yy = t.y;
        //cout << xx << yy << endl;
        REP(i, 0, 4){
            int nx = xx + dx[i], ny = yy + dy[i];
            if(nx >= 0 && ny >= 0 && nx < h && ny < w && lis[nx][ny] == '.' && flag[nx][ny] == 0){
                flag[nx][ny] = flag[xx][yy] + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << flag[gx][gy] << endl;
}
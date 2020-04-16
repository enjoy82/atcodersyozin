#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb puah_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

vector<string> lis;
int ma = 0;
int h, w;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct zahyo{
    int x;
    int y;
};

void solve(int x, int y){
    vector<vector<int> > flag(h, vector<int>(w, -1));
    flag[x][y] = 0;
    queue<zahyo> q;
    q.push({x,y});
    while(!q.empty()){
        zahyo z = q.front();
        q.pop();
        REP(i, 0, 4){
            int nx = z.x + dx[i];
            int ny = z.y + dy[i];
            if((nx >= 0) && (ny >= 0) && (nx < h) && (ny < w)){
                if(lis[nx][ny] == '.' && flag[nx][ny] == -1){
                    flag[nx][ny] = flag[z.x][z.y] + 1;
                    q.push({nx, ny});
                    ma = max(ma, flag[nx][ny]);
                }
            }
        }
    }
}

int main(){
    cin >> h >> w;
    lis = vector<string>(h);
    REP(i, 0, h){cin >> lis[i];}
    REP(i, 0, h){
        REP(l, 0, w){
            if(lis[i][l] == '.'){
                solve(i, l);
            }
        }
    }
    cout << ma << endl;
}
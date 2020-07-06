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

int dx[6] = {-1, 1, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 1, 1};

int INF = 1e9;

int main(){
    int n, gx, gy; cin >> n >> gx >> gy;
    gx += 250; gy += 250;
    vector<vector<int> > lis(501, vector<int>(501, INF));
    vector<vector<int> > ch(501, vector<int>(501, 0));
    lis[250][250] = 0;
    REP(i, 0, n){
        int a, b; cin >> a >> b;
        a += 250; b+=250;
        ch[a][b]++;
    }
    queue<Pii> q;
    q.push({250, 250});
    while(!q.empty()){
        Pii c = q.front();
        q.pop();
        int x = c.first, y = c.second;
        REP(i, 0, 6){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx <= 500 && ny <= 500 && ch[nx][ny] == 0 && lis[nx][ny] > lis[x][y]+1){
                lis[nx][ny] = lis[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    if(lis[gx][gy] == INF){
        cout << -1 << endl;
        return 0;
    }
    cout << lis[gx][gy] << endl;
    return 0;
}
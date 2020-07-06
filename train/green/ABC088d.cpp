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

vector<string> lis;
vector<vector<int> > dp;
int h, w;

int main(){
    cin >> h >> w;
    lis = vector<string>(h);
    dp = vector<vector<int> >(h, vector<int>(w, 1e9));
    REP(i, 0, h){cin >> lis[i];}
    dp[0][0] = 0;
    queue<Pii> q;
    q.push({0, 0});
    int count = 0;
    REP(i, 0, h){
        REP(l, 0, w){
            if(lis[i][l] == '#'){
                count++;
            }
        }
    }
    while(!q.empty()){
        Pii a = q.front();
        q.pop();
        int x = a.first, y = a.second;
        REP(i, 0, 4){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < h && ny < w && lis[nx][ny] == '.' && dp[nx][ny] > dp[x][y]+1){
                dp[nx][ny] = dp[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
    if(dp[h-1][w-1] == 1e9){
        cout << -1 << endl;
        return 0;
    }
    cout << h*w - (dp[h-1][w-1]+1) - count << endl;
}
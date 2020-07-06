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
    vector<string> lis(h);
    vector<vector<int> > flag(h, vector<int>(w, 1e9));
    queue<Pii> q;
    REP(i, 0, h){cin >> lis[i];}
    REP(i, 0, h){
        REP(l, 0, w){
            if(lis[i][l] == '#'){
                flag[i][l] = 0;
                q.push({i, l});
            }
        }
    }
    while(!q.empty()){
        Pii A = q.front();
        q.pop();
        int x = A.first, y = A.second;
        REP(i, 0, 4){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < h && ny < w && flag[nx][ny] == 1e9){
                flag[nx][ny] = flag[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    int ma  = 0 ;
    REP(i, 0, h){
        REP(l, 0, w){
            ma = max(ma, flag[i][l]);
        }
    }
    cout << ma << endl;
}
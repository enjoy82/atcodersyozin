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

int dx[4] = {-1, 0, -1};
int dy[4] = {0, -1, -1};

const ll mod = 1e9 + 7;
int h,w;
vector<vector<ll> > lis;
vector<vector<vector<ll> > > up;

vector<string> grid;

ll solve(int x, int y){
    ll mid = 0;
    if(lis[x][y] != -1){
        return lis[x][y];
    }
    int f = 0;
    REP(i, 0, 3){
        int sx = x + dx[i], sy = y + dy[i];
        if(sx >= 0 && sy >= 0 && grid[sx][sy] != '#'){
            f++;
            if(lis[sx][sy] == -1){
                solve(sx, sy);
            }
            mid += up[sx][sy][i] + lis[sx][sy];
            up[x][y][i] = lis[sx][sy] + up[sx][sy][i];
        }
    }
    lis[x][y] = mid % mod;
    return mid % mod;
}

int main(){
    cin >> h >> w;
    grid = vector<string>(h);
    lis = vector<vector<ll> >(h, vector<ll>(w, -1));
    up = vector<vector<vector<ll> > >(h, vector<vector<ll >>(w, vector<ll>(3, 0)));
    lis[0][0] = 1;
    REP(i, 0, h){cin >> grid[i];}
    cout << solve(h-1, w-1) << endl;
}
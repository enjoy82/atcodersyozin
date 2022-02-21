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

int dx[3] = {1, 1, 0};
int dy[3] = {0, 1, 1};

int h, w;
vector<string> lis;
vector<vector<int> > memo;

int solve(int x, int y){
    if(x >= h || y >= w || lis[x][y] == '#'){
        return 1;
    }
    if(memo[x][y] != -1){
        return memo[x][y];
    }
    int res = 0;
    REP(i, 0, 3){
        if(solve(x + dx[i], y + dy[i]) == 0){
            res = 1;
        }
    }
    memo[x][y] = res;
    return res;
}


int main(){
    cin >> h >> w;
    lis = vector<string>(h);
    memo = vector<vector<int> >(h+10, vector<int>(w+10, -1));
    REP(i, 0, h){cin >> lis[i];}
    cout << (solve(0, 0)? "First" : "Second") << endl;
}
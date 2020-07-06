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

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {1, 0};
int dy[4] = {0, 1};

int main(){
    int r, c, d; cin >> r >> c >> d;
    vector<vector<int> > lis(r, vector<int>(c));
    vector<int> tako(r + c + 10, 0);
    REP(i, 0, r){
        REP(l, 0, c){
            cin >> lis[i][l];
        }
    }
    //cout << "OK" << endl;
    queue<Pii> que;
    vector<vector<int> > flag(r, vector<int>(c, 0));
    flag[0][0] = 1;
    que.push(Pii(0, 0));
    while(!que.empty()){
        Pii now = que.front();
        que.pop();
        int x = now.first, y = now.second;
        //cout << x << y << endl;
        tako[x+y] = max(tako[x+y], lis[x][y]);
        REP(i, 0, 2){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < r && ny < c && flag[nx][ny] == 0){
                flag[nx][ny] = 1;
                que.push(Pii(nx, ny));
            }
        }
    }
    int ans = 0;
    REP(i, 0, tako.size()-1){
        if(d-i < 0){
            break;
        }
        if((d-i) % 2 == 0){
            ans = max(ans, tako[i]);
        }else{
            continue;
        }
    }
    cout << ans << endl;
}
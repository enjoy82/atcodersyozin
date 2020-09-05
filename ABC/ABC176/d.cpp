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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int h, w; cin >> h >> w;
    int x, y, gx, gy; cin >> x >> y >> gx >> gy;
    x--; y--; gx--; gy--;
    vector<string> lis(h);
    vector<vector<int> > anslis(h, vector<int>(w, 1e9)), flag(h, vector<int>(w, 0));
    anslis[x][y] = 0;
    REP(i, 0, h){cin >> lis[i];}
    queue<Pii> que;
    queue<Pii> subq;
    que.push(Pii(x, y));
    while(!(subq.empty() && que.empty())){
        while(!que.empty()){
            Pii a = que.front();
            que.pop();
            int nx = a.first, ny = a.second;
            int f = 0;
            REP(i, 0, 4){
                int xx = nx + dx[i], yy = ny + dy[i];
                if(xx < h && xx >= 0 && yy >= 0 && yy < w && anslis[xx][yy] > anslis[nx][ny] && lis[xx][yy] == '.'){
                    anslis[xx][yy] = anslis[nx][ny];
                    que.push(Pii(xx, yy));
                }else if(xx < h && xx >= 0 && yy >= 0 && yy < w && lis[xx][yy] == '#' && flag[nx][ny] == 0){
                    f = 1;
                    flag[nx][ny] = 1;
                }
            }
            if(f){
                subq.push(Pii(nx, ny));
            }
        }
        if(anslis[gx][gy] != 1e9){
            cout << anslis[gx][gy] << endl;
            return 0;
        }
        while(!subq.empty()){
            Pii a = subq.front();
            subq.pop();
            int nx = a.first, ny = a.second;
            REP(i, -2, 3){
                REP(l, -2, 3){
                    int xx = nx + i, yy = ny + l;
                    if(xx < h && xx >= 0 && yy >= 0 && yy < w && anslis[xx][yy] > anslis[nx][ny]+1  && lis[xx][yy] == '.'){
                        anslis[xx][yy] = anslis[nx][ny] + 1;
                        que.push(Pii(xx, yy));
                    }
                }
            }
        }
        if(anslis[gx][gy] != 1e9){
            cout << anslis[gx][gy] << endl;
            return 0;
        }
    }
    if(anslis[gx][gy] == 1e9){
        cout << -1 << endl;
        return 0;
    }else{
        cout << anslis[gx][gy] << endl;
    }
}

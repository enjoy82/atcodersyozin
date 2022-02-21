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
    ll h, w; cin >> h >> w;
    vector<string> lis(h);
    vector<vector<ll> > flag(h, vector<ll>(w, 0));
    vector<vector<ll> > tree(h*w+1);
    REP(i, 0, h){
        cin >> lis[i];
    }
    REP(i, 0, h){
        REP(l, 0, w){
            ll x = i, y = l;
            flag[x][y] = 1;
            REP(j, 0, 4){
                ll nx = x + dx[j], ny = y + dy[j];
                if(nx >= 0 && ny >= 0 && nx < h && ny < w && flag[nx][ny] == 0){
                    if((lis[x][y] == '.' && lis[nx][ny] == '#') || (lis[x][y] == '#' && lis[nx][ny] == '.')){
                        tree[w*x+y+1].pb(w*nx+ny+1);
                        tree[w*nx+ny+1].pb(w*x+y+1);
                    }
                }
            }
        }
    }
    vector<ll> flag1(h*w+1, 0);
    queue<ll> q;
    ll ans = 0;
    REP(i, 1, h*w+1){
        if(flag1[i] != 0){continue;}
        ll bc = 0;
        ll wc = 0;
        q.push(i);
        flag1[i]++;
        while(!q.empty()){
            ll now = q.front();
            ll xx = (now-1)/w;
            ll yy = (now-1) % w;
            if(lis[xx][yy] == '.'){
                wc++;
            }else{
                bc++;
            }
            q.pop();
            flag1[now]++;
            REP(i, 0, tree[now].size()){
                ll next = tree[now][i];
                if(flag1[next] == 0){
                    q.push(next);
                    flag1[next]++;
                }
            }
        }
        ans += bc * wc;
    }
    cout << ans << endl;
}
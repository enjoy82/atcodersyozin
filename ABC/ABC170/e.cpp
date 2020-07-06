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
    int n, q; cin >> n >> q;
    vector<vector<int> > lis(2e5+100);
    map<int, int> mpval, mppos;
    REP(i, 0, n){
        int a, b; cin >> a >> b;
        mpval[i+1] = a;
        mppos[i+1] = b;
        lis[b].pb(a);
    }
    REP(i, 0, 2e5+100){
        if(lis[i].size() > 0){
            sort(ALL(lis[i]));
        }
    }
    int ans = 1e9, ansidx = 0;
    REP(i, 0, 2e5+100){
        if(lis[i].size() > 0){
            if(chmin(ans, lis[i].back())){
                ansidx = i;
            }
        }
    }
    //cout << ans << endl;
    REP(i, 0, q){
        int x, y; cin >> x >> y;
        int val = mpval[x];
        int pos = mppos[x];
        for(auto it = lis[pos].begin(); it != lis[pos].end();){
            if(*it == val){
                it = lis[pos].erase(it);
            }else{
                ++it;
            }
        }
        mppos[x] = y;
        lis[y].pb(val);
        sort(ALL(lis[pos]));
        sort(ALL(lis[y]));
        if(y == ansidx || pos == ansidx){
            if(lis[pos].back() < lis[y].back()){
                ansidx = pos;
            }else{
                ansidx = y;
            }
            ans = min(lis[pos].back(), lis[y].back());
        }else{
            if(ans > lis[pos].back() && lis[pos].back() < lis[y].back()){
                ansidx = pos;
            }else if(ans > lis[y].back() && lis[y].back() < lis[pos].back()){
                ansidx = y;
            }
            ans = min({ans, lis[pos].back(), lis[y].back()});
        }
        cout << ans << endl;
    }
}
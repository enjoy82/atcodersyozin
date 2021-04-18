// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

//ordered_set 重複不可
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use set_function + find_by_order(select itr-num)

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

vector<vector<Pll> > graph;
ll n, m, l;

bool check(Pll next, Pll now, int ff, ll cost){
    if(ff){
        now.first = now.first + 1;
        now.second = l - cost;
    }else{
        now.second = now.second - cost;
    }
    if(now.first < next.first){
        return true;
    }
    if(now.first > next.first){
        return false;
    }
    if(now.second > next.second){
        return true;
    }else{
        return false;
    }
}

vector<Pll> solve(int s){
    queue<int> que;
    que.push(s);
    vector<Pll> d(n, Pll(1e18, -1));
    d[s] = Pll(0,l);
    vector<int> mp(1e4, 0);
    mp[s] = 1;
    while(!que.empty()){
        int now = que.front();
        que.pop();
        mp[now] = 0;
        REP(i,0,graph[now].size()){
            ll next = graph[now][i].first;
            ll cost = graph[now][i].second;
            ll ff = 0;
            if(d[now].second - cost < 0){ //残り
                ff = 1;
            }
            if(check(d[next], d[now], ff, cost)){
                d[next].first = d[now].first + ff;
                if(ff)
                    d[next].second = l - cost;
                else
                    d[next].second = d[now].second - cost;
                if(mp[next] == 0){
                    mp[next] = 1;
                    que.push(next);
                }
            }else{
                continue;
            }
        }
    }
    return d;
}

int main(){
    cin >> n >> m >> l;
    graph = vector<vector<Pll> >(n);
    REP(i,0,m){
        ll a, b, c; cin >> a >> b >> c;
        if(c > l){
            continue;
        }
        a--; b--;
        graph[a].pb(Pll(b,c));
        graph[b].pb(Pll(a,c));
    }
    int q; cin >> q;
    vector<vector<Pll> > anslis(n);
    REP(i,0,n){
        anslis[i] = solve(i);
    }
    REP(i,0,q){
        int s, t; cin >> s >>  t;
        s--; t--;
        if(anslis[s][t].first == 1e18){
            cout << -1 << endl;
        }else{
            cout << anslis[s][t].first << endl;
        }
    }
}
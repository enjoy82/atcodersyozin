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

int main(){
    int n; cin >> n;
    vector<map<int, ll>> graph(n);
    map<int, Pii> pairmp;
    REP(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a][b] = 0;
        graph[b][a] = 0;
        pairmp[i] = Pii(a, b);
    }
    int q; cin >> q;
    vector<int> num(n, -1);
    num[0] = 0;
    queue<int> que1;
    que1.push(0);
    while(!que1.empty()){
        int now = que1.front();
        que1.pop();
        for(auto &x: graph[now]){
            int next = x.first;
            if(num[next] == -1){
                num[next] = num[now] + 1;
                que1.push(next);
            }
        }
    }
    vector<ll> anslis(n, 0), flag(n, -1);
    REP(i, 0, q){
        ll t, e, x; cin >> t >> e >> x;
        if(t == 1){
            Pii P = pairmp[e-1];
            int from = P.first, to = P.second;
            if(num[from] < num[to]){
                for(auto &xx: graph[0]){
                    xx.second += x;
                }
                anslis[0] += x;
                graph[from][to] -= x;
            }else{
                anslis[from] += x;
                for(auto &xx: graph[from]){
                    if(xx.first != to){
                        xx.second += x;
                    }
                }
            }
        }else{
            Pii P = pairmp[e-1];
            int from = P.second, to = P.first;
            if(num[from] < num[to]){
                for(auto &xx: graph[0]){
                    xx.second += x;
                }
                anslis[0] += x;
                graph[from][to] -= x;
            }else{
                anslis[from] += x;
                for(auto &xx: graph[from]){
                    if(xx.first != to){
                        xx.second += x;
                    }
                }
            }
        }
        //cout << anslis[0] << endl;
    }
    queue<Pll> que;
    que.push(Pll(0, 0));
    flag[0] = 0;
    while(!que.empty()){
        Pll P = que.front();
        int now = P.first;
        ll cost = P.second;
        anslis[now] += cost;
        que.pop();
        for(auto &x: graph[now]){
            int next = x.first;
            if(flag[next] == -1){
                flag[next] = 0;
                que.push(Pll(next, cost+graph[now][next]));
            }
        }
    }
    REP(i, 0, n){
        cout << anslis[i] << endl;
    }
}
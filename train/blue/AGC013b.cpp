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

int n, m;

int main(){
    cin >> n >> m;
    vector<vector<int> > graph(n);
    REP(i,0,m){
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    deque<int> dq;
    dq.push_front(0);
    dq.push_back(graph[0][0]);
    vector<int> path(1e6, 0);
    path[0] = 1;
    path[graph[0][0]] = 1;
    while(1){
        int front = dq.front();
        int back = dq.back();
        int f = 1, f1 = 1;
        int nk;
        REP(i,0,graph[front].size()){
            int next = graph[front][i];
            if(path[next] == 0){
                f = 0;
                nk = next;
            }
        }
        REP(i,0,graph[back].size()){
            int next = graph[back][i];
            if(path[next] == 0){
                f1 = 0;
                nk = next;
            }
        }
        if(f == 1 && f1 == 1){
            vector<int> ans;
            while(!dq.empty()){
                ans.pb(dq.front());
                dq.pop_front();
            }
            cout << ans.size() << endl;
            REP(i,0,ans.size()){
                cout << ans[i] + 1 << " ";
            }
            cout << endl; 
            break;
        }
        path[nk] = 1;
        if(f1 == 0){
            dq.push_back(nk);
            continue;
        }else if(f == 0){
            dq.push_front(nk);
        }
    }
}
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

template <class T>
inline vector<T> make_vec(size_t a, T val) {
    return vector<T>(a, val);
}
template <class... Ts>
inline auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec(ts...))>(a, make_vec(ts...));
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示
struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;

const long long LINF = 1LL << 60;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int> > graph(2*n+2);
    vector<int> check(n+1, 0);
    REP(i,0,m){
        int k; cin >> k;
        int pre = 0;
        REP(l,0,k){
            int a; cin >> a;
            if(check[a] != 0)
                a += n+1;
            check[a % (n+1)]++;
            graph[pre].pb(a);
            pre = a;
        }
    }
    queue<int> que;
    que.push(0);
    int count = 0;
    vector<int> used(n+1, 0);
    used[0] = 2;
    while(!que.empty()){
        int now = que.front();
        //cout << now << endl;
        que.pop();
        if(used[now % (n+1)] >= 2){
            REP(i,0,graph[now].size()){
                int next = graph[now][i];
                used[next % (n+1)]++;
                if(used[next % (n+1)] == 2){
                    que.push(next % (n+1));
                    que.push((next % (n+1)) + (n+1));
                }
            }
        }
    }

    int f = 1;
    REP(i,0,n+1){
        if(used[i] != 2)
            f = 0;
    }
    if(f)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
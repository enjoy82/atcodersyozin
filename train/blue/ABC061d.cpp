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
    int n, m; cin >> n >> m;
    vector<vector<Pll> > G(n);
    REP(i, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        G[a].pb(Pll(b, c));
    }
    queue<ll> que;
    que.push(0LL);
    int count = 0;
    vector<ll> score(n, -1e16), flag(n, 0);
    score[0] = 0;
    flag[0] = 1;
    while(!que.empty()){
        if(count >= 3e6){
            break;
        }
        int now = que.front();
        que.pop();
        REP(i, 0, G[now].size()){
            int next= G[now][i].first;
            if(chmax(score[next], score[now] + G[now][i].second)){
                flag[next]++;
                que.push(next);
                count++;
            }else if(flag[next] == 0){
                flag[next]++;
                score[next] = score[now] + G[now][i].second;
                que.push(next);
                count++;
            }
        }
    }
    if(flag[n-1] >= 1000){
        cout << "inf" << endl;
    }else{
        cout << score[n-1] << endl;
    }
}
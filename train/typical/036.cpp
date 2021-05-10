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


/*
int main(){
    int n, q; cin >> n >> q;
    vector<Pll> lis(n);
    REP(i,0,n){
        ll a, b; cin >> a >> b;
        lis[i] = Pll(a, b);
    }
    ll pdismax = 0, pdismin = 1e18, mdismax = 0, mdismin = 1e18;
    REP(i,0,n){
        chmax(pdismax, lis[i].first + lis[i].second);
        chmin(pdismin, lis[i].first + lis[i].second);
        chmax(mdismax, lis[i].first - lis[i].second);
        chmin(mdismin, lis[i].first - lis[i].second);
    }
    REP(i,0,q){
        int idx; cin >> idx;
        idx--;
        ll pdis = max(abs(pdismax - (lis[idx].first + lis[idx].second)), abs(pdismin - (lis[idx].first + lis[idx].second)));
        ll mdis = max(abs(mdismax - (lis[idx].first - lis[idx].second)), abs(mdismin - (lis[idx].first - lis[idx].second)));
        cout << max(pdis, mdis) << endl;
    }
}*/


int main(){
    int n, q; cin >> n >> q;
    vector<vector<ll> > lis(n, vector<ll>(2));
    vector<ll> pidx(n), midx(n);
    iota(ALL(pidx), 0);
    iota(ALL(midx), 0);
    REP(i,0,n){
        cin >> lis[i][0] >> lis[i][1];
    }
    sort(ALL(pidx), [&](auto &l, auto &r){
        return ((ll)lis[l][0] + (ll)lis[l][1]) < ((ll)lis[r][0] + (ll)lis[r][1]);
    });
    sort(ALL(midx), [&](auto &l, auto &r){
        return ((ll)lis[l][0] - (ll)lis[l][1]) < ((ll)lis[r][0] - (ll)lis[r][1]);
    });
    REP(i,0,q){
        int idx; cin >> idx;
        idx--;
        ll pdis = max(abs((lis[pidx[n-1]][0] + lis[pidx[n-1]][1]) - (lis[idx][0] + lis[idx][1])), abs((lis[pidx[0]][0] + lis[pidx[0]][1]) - (lis[idx][0] + lis[idx][1])));
        ll mdis = max(abs((lis[midx[n-1]][1] - lis[midx[n-1]][1]) - (lis[idx][0] - lis[idx][1])), abs((lis[midx[0]][0] - lis[midx[0]][1]) - (lis[idx][0] - lis[idx][1])));
        cout << max(pdis, mdis) << endl;
    }
}
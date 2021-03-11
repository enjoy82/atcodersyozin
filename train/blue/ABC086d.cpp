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
    int n, k; cin >> n >> k;
    k *= 2;
    vector<vector<int> > bgrid(k+1, vector<int>(k+1, 0)), wgrid(k+1, vector<int>(k+1, 0));
    REP(i, 0, n){
        int x, y; cin >> x >> y;
        char c; cin >> c;
        if(c == 'W'){
            wgrid[(x%k)+1][(y%k)+1]++;
        }else{
            bgrid[(x%k)+1][(y%k)+1]++;
        }
    }
    REP(i, 0, k+1){
        REP(l, 0, k){
            wgrid[i][l+1] += wgrid[i][l];
            bgrid[i][l+1] += bgrid[i][l];
        }
    }
    REP(i, 0, k){
        REP(l, 0, k+1){
            wgrid[i+1][l] += wgrid[i][l];
            bgrid[i+1][l] += bgrid[i][l];
        }
    }
    int ans = 0;
    int len = k / 2;
    REP(i, 0, len+1){
        REP(l, 0, len+1){
            int w_count = 0;
            w_count += wgrid[i][l];
            w_count += wgrid[i][k] - wgrid[i][k-(len-l)];
            w_count += wgrid[i+len][l+len] + wgrid[i][l] - wgrid[i+len][l] - wgrid[i][l+len];
            w_count += wgrid[k][l] - wgrid[k-(len-i)][l];
            w_count += wgrid[k][k] - wgrid[k-(len-i)][k] - wgrid[k][k-(len-l)] + wgrid[k-(len-i)][k-(len-l)];
            int w_count2 = wgrid[k][k] - w_count;
            int b_count = 0;
            b_count += bgrid[i][l];
            b_count += bgrid[i][k] - bgrid[i][k-(len-l)];
            b_count += bgrid[i+len][l+len] + bgrid[i][l] - bgrid[i+len][l] - bgrid[i][l+len];
            b_count += bgrid[k][l] - bgrid[k-(len-i)][l];
            b_count += bgrid[k][k] - bgrid[k-(len-i)][k] - bgrid[k][k-(len-l)] + bgrid[k-(len-i)][k-(len-l)];
            int b_count2 = bgrid[k][k] - b_count;
            
            chmax(ans, max(w_count+b_count2, w_count2+b_count));
        }
    }
    cout << ans << endl;
}
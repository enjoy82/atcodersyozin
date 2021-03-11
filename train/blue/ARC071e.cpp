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
    string s, t; cin >> s >> t;
    vector<int> sarui(s.size()+1, 0), sbrui(s.size()+1, 0);
    vector<int> tarui(t.size()+1, 0), tbrui(t.size()+1, 0);
    REP(i, 0, s.size()){
        if(s[i] == 'A'){
            sarui[i+1]++;
        }else{
            sbrui[i+1]++;
        }
        sarui[i+1] += sarui[i];
        sbrui[i+1] += sbrui[i];
    }
    REP(i, 0, t.size()){
        if(t[i] == 'A'){
            tarui[i+1]++;
        }else{
            tbrui[i+1]++;
        }
        tarui[i+1] += tarui[i];
        tbrui[i+1] += tbrui[i];
    }
    int q; cin >> q;
    REP(i, 0, q){
        int a, b, c, d; cin >> a >> b  >> c >> d;
        int sa = sarui[b] - sarui[a-1], sb = sbrui[b] - sbrui[a-1];
        int ta = tarui[d] - tarui[c-1], tb = tbrui[d] - tbrui[c-1];
        int sacount = sb*2 + sa, sbcount = sa*2 + sb;
        int tacount = tb*2 + ta, tbcount = ta*2 + tb;
        if( (sacount % 3 == tacount % 3) && (sbcount % 3 == tbcount % 3)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
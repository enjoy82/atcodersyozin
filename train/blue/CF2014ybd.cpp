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

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
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
    set<int> se, rse;
    int n; cin >> n;
    vector<vector<int> > lis(1e5+10);
    REP(i, 0, n){
        int a; cin >> a;
        lis[a].pb(i);
    }
    vector<int> anslis(n, 0);
    for(int i = 1e5+5; i >= 0; i--){
        if(lis[i].size() >= 1){
            vector<int> pu;
            REP(l, 0, lis[i].size()){
                int pos = lis[i][l];
                auto it = se.lower_bound(pos);
                int right;
                if(it == se.end())
                    right = n;
                else
                    right = *it;
                auto itleft = rse.lower_bound(pos*-1);
                int left;
                if(itleft == rse.end())
                    left = -1;
                else
                    left = abs(*itleft);
                //cout << left << right << endl;
                anslis[pos] = (right - 1 - pos) + (pos - left-1);
                pu.pb(pos);
            }
            REP(l, 0, pu.size()){
                se.insert(pu[l]);
                rse.insert(-1*pu[l]);
            }
        }else{
            continue;
        }
    }
    REP(i, 0, n){
        cout << anslis[i] << endl;
    }
}
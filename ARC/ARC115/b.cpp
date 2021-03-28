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
    vector<vector<ll> > grid(n, vector<ll>(n));
    REP(i,0,n){
        REP(l,0,n){
            cin >> grid[i][l];
        }
    }
    int f = 1;
    vector<ll> aans(n, 0), bans(n,0);
    REP(i,1,n){
        int key = grid[0][i] - grid[0][i-1];
        REP(l,0,n){
            int mid = grid[l][i] - grid[l][i-1];
            if(mid != key){
                f = 0;
            }
        }
        aans[i] = key;
    }
    REP(i,1,n){
        int key = grid[i][0] - grid[i-1][0];
        REP(l,0,n){
            int mid = grid[i][l] - grid[i-1][l];
            if(mid != key){
                f = 0;
            }
        }
        bans[i] = key;
    }
    bans[0] = 1e15;
    ll up = 1e15;
    REP(i,1,n){
        bans[i] = bans[i-1] + bans[i];
        chmin(up, bans[i]);
    }
    REP(i,0,n){
        bans[i] -= up;
    }
    REP(i,0,n){
        aans[i] = grid[0][i] - bans[0];
        if(aans[i] < 0){
            f = 0;
        }
    }
    if(f){
        cout << "Yes" << endl;
        REP(i,0,n){
            cout << bans[i] << " ";
        }
        cout << endl;
        REP(i,0,n){
            cout << aans[i] << " ";
        }
        cout << endl;
    }else{
        cout << "No" << endl;
    }
}
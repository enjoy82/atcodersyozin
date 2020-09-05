#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

ll ans = 0;
vector<vector<int> > tree;
vector<ll> alis, blis;
vector<ll> anslis1, anslis2;

ll solve(int num){
    ll plus = 0;
    REP(i, 0, tree[num].size()){
        int next = tree[num][i];
        plus += solve(next);
    }
    if(plus + alis[num] >= 0){
        ans += plus + alis[num];
        anslis1.pb(num+1);
        return plus + alis[num];
    }else{
        ans += plus + alis[num];
        anslis2.pb(num+1);
        return 0;
    }
}

int main(){
    int n; cin >> n;
    alis = vector<ll>(n);
    blis = vector<ll>(n);
    tree = vector<vector<int> >(n);
    REP(i, 0, n){
        cin >> alis[i];
    }
    REP(i, 0, n){
        cin >> blis[i];
        blis[i]--;
        if(blis[i] >= 0){
           tree[blis[i]].pb(i);
        }
    }
    REP(i, 0, n){
        if(blis[i] == -2){
            solve(i);
        }
    }
    cout << ans << endl;
    REP(i, 0, anslis1.size()){
        cout << anslis1[i] << " ";
    }
    REP(i, 0, anslis2.size()){
        cout << anslis2[anslis2.size() - 1 -i] << " ";
    }
    cout << endl;
}
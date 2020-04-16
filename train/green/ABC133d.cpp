#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb puah_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int n; cin >> n;
    vector<ll> lis(n);
    ll sum = 0;
    REP(i, 0, n){cin >> lis[i]; sum += lis[i];}
    vector<ll> anslis(n);
    ll mid = 0;
    for(int i = 1; i < n; i += 2){
        mid += 2 * lis[i];
    }
    anslis[0] = sum - mid;
    
    REP(i, 1, n){
        anslis[i] = 2 * lis[i-1] - anslis[i-1];
    }
    REP(i, 0, n){cout << anslis[i] << " ";}
}
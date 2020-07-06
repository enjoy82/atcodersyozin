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

void solve(){
    int n, m, k; cin >> n >> m >> k;
    int c = min(n/k, m);
    int d = m - c;
    int e;
    if(d % (k-1) == 0){
        e = d/(k-1); 
    }else{
        e = d/(k-1) + 1; 
    }
    cout << c-e << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve(){
    ll a, b; cin >> a >> b;
    ll mid = b - a;
    if(mid == 0){
        cout << 0 << endl;
    }else if(mid < 0){
        if(mid % 2 == 0){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
    }else{
        if(mid % 2 == 0){
            cout << 2 << endl;
        }else{
            cout << 1 << endl;
        }
    }
}

int main(){
    int t; cin >> t;
    REP(q, 0, t){
        solve();
    }
}
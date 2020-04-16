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

int main(){
    ll n; cin >> n;
    vector<ll> lis(5);
    REP(i, 0, 5){cin >> lis[i];}
    sort(ALL(lis));
    ll k = lis[0];
    if(n % k == 0){
        cout << n/k + 4 << endl;
    }else{
        cout << n/k+ 5 << endl;
    }
}
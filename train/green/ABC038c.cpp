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
    int n; cin >> n;
    vector<ll> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    ll ans = 0;
    ll pre = 0, count = 0;
    REP(i, 0, n){
        if(pre < lis[i]){
            pre = lis[i];
            count++;
        }else{
            ans += ((count+1) * count) / 2;
            pre = lis[i];
            count = 1;
        }
    }
    ans += ((count+1) * count) / 2;
    cout << ans << endl;
}
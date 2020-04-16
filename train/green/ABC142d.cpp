#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb puah_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    ll a, b; cin >> a >> b;
    int ans = 1;
    ll i = 2;
    vector<int> lis(2e7, 0), lis2(2e7, 0);
    while(a >= i * i){
        if(a % i == 0){
            a /= i;
            lis[i] = 1;
        }else{
            i++;
        }
    }
    if(a < 2e7){
        lis[a] = 1;
    }
    i = 2;
    while(b >= i * i){
        if(b % i == 0){
            b /= i;
            lis2[i] = 1;
        }else{
            i++;
        }
    }
    if(b < 2e7){
        lis[b] = 1;
    }
    REP(i, 2, 2e6){
        if(lis[i] == 1 && lis2[i] == 1){
            ans++;
        }
    }
    cout << ans << endl;
}
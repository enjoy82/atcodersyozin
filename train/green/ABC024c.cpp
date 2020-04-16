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
    ll n, d, k; cin >> n >> d >> k;
    vector<ll> llis(d), rlis(d);
    REP(i, 0, d){cin >> llis[i] >> rlis[i];}
    REP(i, 0, k){
        ll now, goal; cin >> now >> goal;
        if(now < goal){
            int l = 0;
            for(;(l < d) && (now < goal); l++){
                if(llis[l] <= now && rlis[l] >= now){
                    now = rlis[l];
                }
            }
            cout << l << endl;
        }else{
            int l = 0;
            for(;(l < d) && (now > goal); l++){
                if(llis[l] <= now && rlis[l] >= now){
                    now = llis[l];
                }
            }
            cout << l << endl;
        }
    }
}
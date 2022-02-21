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
    ll n, m, v, p; cin >> n >> m >> v >> p;
    vector<ll> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    sort(ALL(lis), greater<>());
    ll mid = m*(v-p);
    int r = p-1, l = n-1;
    while(l - r > 1){
        int ind = (r + l) / 2;
        int f = 0;
        ll ch = lis[ind] + m;
        ll sum = 0;
        REP(i, p, n){
            if(i == ind){
                continue;
            }
            sum += min(ch - lis[i], m);
            if(ch-lis[i] < 0){
                f = 1;
                break;
            }
        }
        if(sum < mid || f == 1){
            l = ind;
        }else{
            r = ind;
        }
    }
    cout << n - l << endl;
}
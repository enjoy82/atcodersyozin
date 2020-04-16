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
    ll n, m, x, y; cin >> n >> m >> x >> y;
    vector<ll> alis(n), blis(m);
    REP(i, 0, n){cin >> alis[i];}
    REP(i, 0, m){cin >> blis[i];}
    ll time = 0, count = 0;
    sort(ALL(blis));
    sort(ALL(alis));
    int i = 0, l = 0, f = 1;
    while(i < n && l < m){
        if(f == 1){
            for(; i < n; i++){
                if(time <= alis[i]){
                    time = alis[i] + x;
                    f *= -1;
                    break;
                }
            }
        }else{
            for(; l < m; l++){
                if(time <= blis[l]){
                    time = blis[l] + y;
                    f *= -1;
                    count++;
                    break;
                }
            }
        }
    }
    cout << count << endl;
}
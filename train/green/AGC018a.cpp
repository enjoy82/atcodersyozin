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

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    sort(ALL(lis));
    if(lis[n-1] < k){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    if(n == 1){
        if(lis[0] == k){
            cout << "POSSIBLE" << endl;
            return 0;
        }
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    REP(i, 0, n-1){
        if(lis[i+1] != lis[i]){
            lis.pb(lis[i+1]-lis[i]);
        }
    }
    sort(ALL(lis));
    int f = 0;
    REP(i, 1, lis.size()){
        if(lis[i] % lis[0] != 0){
            f = 1;
            break;
        }
    }
    if(f == 1){
        cout << "POSSIBLE" << endl;
    }else{
        ll mid = lis[0];
        REP(i, 1, lis.size()){
            mid = gcd(mid, lis[i]);
        }
        if(k % mid == 0){
            cout << "POSSIBLE" << endl;
        }else{
            cout << "IMPOSSIBLE" << endl;
        }
    }
}
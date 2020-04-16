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
    ll n, a, b, k; cin >> n >> a >> b >> k;
    ll c = a + b;
    vector<ll> anslis(n);
    REP(i, 0, n){
        ll mid; cin >> mid;
        if(mid % c != 0){
            mid = mid % c;
        }else{
            mid = c;
        }
        anslis[i] = max(0LL, mid-1) / a;
        //cout << anslis[i] << endl;
    }
    sort(ALL(anslis));
    REP(i, 0, n){
        k -= anslis[i];
        if(k < 0){
            cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;
}
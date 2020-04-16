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
    ll mid, mid1, sum = 0, sum1 = 0;
    vector<ll> lis(n);
    REP(i, 0, n){
        ll c; cin >> c;
        lis[i] = c-(i+1);
    }
    sort(ALL(lis));
    if(n % 2 == 1){
        mid = lis[n/2];
        REP(i, 0, n){
            sum += abs(lis[i] - mid);
        }
    }else{
        mid = (lis[n/2] + lis[n/2-1]) / 2;
        mid1 = (lis[n/2] + lis[n/2-1] + 1) / 2;
        REP(i, 0, n){
            sum += abs(lis[i] - mid);
            sum1 += abs(lis[i] - mid1);
        }
        sum = max(sum, sum1);
    }
    cout << sum << endl;
}
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
    ll c = n % 30;
    vector<int> lis = {1, 2, 3, 4, 5, 6};
    REP(i, 0, c){
        ll x = lis[i%5]; lis[i%5] = lis[i%5+1]; lis[i%5+1] = x;
    }
    REP(i, 0, 6){
        cout << lis[i];
    }
    cout << endl;
}
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

void solve(){
    ll n, p, k; cin >> n >> p >> k;
    vector<ll> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    sort(ALL(lis));
    ll sum = lis[k-1];
    ll c = k;
    vector<ll> ruiseki(n, 0);
    ruiseki[k-1] = lis[k-1];
    REP(i, k, n){
        ruiseki[i] = ruiseki[i-k] + lis[i];
    }
    while(sum <= p){
        k += c;
        if(k-1 >= n){break;}
        sum += lis[k-1];
    }
    k -= c;
    ll mid = lis[0];
    for(int i = 1; i + k - 1 < n; i++){
        if(mid + ruiseki[k-1+i] - ruiseki[i-1] > p){
            cout << k + i - 1 << endl;
            return;
        }
        mid += lis[i];
    }
    cout << n << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
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
    int n, k; cin >> n >> k;
    vector<ll> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    vector<int> imos(n, 0), flag(n, 0);
    REP(i, 1, n-1){
        if(lis[i] > lis[i-1] && lis[i] > lis[i+1]){
            imos[i]++;
            flag[i]++;
        }
    }
    REP(i, 1, n){
        imos[i] = imos[i] + imos[i-1];
    }
    int max = 0, l = 0;
    for(int i = 0; i+k-1 < n; i++){ 
        int p = imos[i+k-2] - imos[i];
        if(max < p){
            max = p;
            l = i;
        }
    }
    cout << max+1 << " " <<  l+1 << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
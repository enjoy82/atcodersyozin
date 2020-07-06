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
    int size = 0;
    vector<int> lis(n);
    map<int, int> mp;
    REP(i, 0, n){cin >> lis[i]; size = max(size, lis[i]);}
    vector<int> imosp(size+k+10, 0), imosm(size+k+10, 0), imos(size+k+10, 0);
    REP(i, 0, n/2){mp[lis[i]+lis[n-i-1]]++;}
    REP(i, 0, n/2){
        int a = min(lis[i], lis[n-i-1]), b = max(lis[i], lis[n-i-1]);
        imosp[a+1]++;
        imosm[b+k]++;
    }
    int ma = 0;
    REP(i, 1, size+10+k){
        imos[i] = imos[i-1] + imosp[i] - imosm[i-1];
        ma = max(ma, imos[i]);
    }

    int ans = 1e9;
    for(auto &x: mp){
        int mid = (imos[x.first]-x.second) + (n/2-imos[x.first])*2;
        ans = min(ans, mid);
    }
    cout << min(ans, ma+(n/2-ma)*2) << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
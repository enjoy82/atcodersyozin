#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int n; cin >> n;
    vector<int> lis(n, 0), flagpos(n+1, 0), flagnum(n+1, 0);
    REP(i, 0, n){cin >> lis[i];}
    priority_queue<pair<ll, pair<ll, ll> > > pq;
    REP(i, 0, n){
        REP(l, 0, n){
            ll k = lis[i] * abs(l-i);
            pair<ll, ll> po = {i, l};
            pq.push({k, po});
        }
    }
    int count = 0;
    ll ans = 0;
    while(count != n){
        pair<ll, pair<ll, ll> > p = pq.top();
        pq.pop();
        //cout << p.first << endl;
        //cout << flagpos[p.second.first] << flagnum[p.first / abs(p.second.first - p.second.second)] << endl;
        if(flagpos[p.second.first] == 0 & flagnum[p.second.second] == 0){
            flagpos[p.second.first] = 1;
            flagnum[p.second.second] = 1;
            ans += p.first;
            count++;
        }
    }
    cout << ans << endl;
}
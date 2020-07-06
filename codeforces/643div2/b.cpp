#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve(){
    ll n; cin >> n;
    vector<ll> lis(n);
    REP(i, 0, n){
        cin >> lis[i];
    }
    vector<ll> anslis;
    sort(ALL(lis));
    ll f = 0;
    ll latest;
    REP(i, 0, n){
        ll c = lis[i];
        ll count = 1;
        while(count < c){
            i++;
            if(i == n){
                f = 1;
                break;
            }
            c = lis[i];
            count++;
        }
        if(f == 0){
            anslis.pb(count);
            latest = i+1;
        }
    }
    cout << anslis.size() << endl;
    /*ll key = lis[n-1];
    ll ans = anslis.size()+1;
    
    sort(ALL(anslis));
    ll check = n - latest;
    ll i = anslis.size()-1;
    while(check < key){
        check += anslis[i];
        i--;
        ans--;
    }
    cout << ans << endl;*/
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
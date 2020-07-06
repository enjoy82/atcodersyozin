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

int main(){
    ll n; cin >> n;
    ll q; cin >> q;
    int t = 1;
    vector<ll> tate(n), yoko(n);
    REP(i, 0, n){
        tate[i] = i;
        yoko[i] = i;
    }
    vector<ll> ans;
    REP(i, 0, q){
        int a; cin >> a;
        if(a == 1){
            if(t == 1){
                ll b, c; cin >> b >> c;
                b--; c--;
                ll x = tate[b]; tate[b] = tate[c]; tate[c] = x;
            }else{
                ll b, c; cin >> b >> c;
                b--; c--;
                ll x = yoko[b]; yoko[b] = yoko[c]; yoko[c] = x;
            }
        }else if(a == 2){
            if(t == -1){
                ll b, c; cin >> b >> c;
                b--; c--;
                ll x = tate[b]; tate[b] = tate[c]; tate[c] = x;
            }else{
                ll b, c; cin >> b >> c;
                b--; c--;
                ll x = yoko[b]; yoko[b] = yoko[c]; yoko[c] = x;
            }
        }else if(a == 3){
            t *= -1;
        }else{
            if(t == 1){
                ll b, c; cin >> b >> c;
                b--; c--;
                ans.pb(tate[b]*n + yoko[c]);
            }else{
                ll b, c; cin >> b >> c;
                b--; c--;
                ans.pb(tate[c]*n + yoko[b]);
            }
        }
    }
    REP(i, 0, ans.size()){
        cout << ans[i] << endl;
    }
}
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
    string s; cin >> s;
    int n = s.size();
    ll k; cin >> k;
    if(n == 1){
        cout << k/2 << endl;
        return 0;
    }
    int f = 0;
    REP(i, 1, n){
        if(s[0] != s[i]){
            f = 1;
        }
    }
    if(f == 0){
        cout << (n*k)/2  << endl;
        return 0;
    }
    s = s + s;
    ll ans = 0;
    REP(i, 0, s.size()-1){
        if(s[i] == s[i+1]){
            s[i+1] = '1';
        }
    }
    REP(i, 0, n){
        if(s[i] == '1'){
            ans++;
        }
    }
    REP(i, n, s.size()){
        if(s[i] == '1'){
            ans += k-1;
        }
    }
    cout << ans << endl;
}
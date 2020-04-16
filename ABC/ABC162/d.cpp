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
    string s; cin >> s;
    ll r = 0, g = 0, b = 0;
    REP(i, 0, n){
        if(s[i] == 'R'){
            r++;
        }else if(s[i] == 'G'){
            g++;
        }else{
            b++;
        }
    }
    ll ans = r * g * b;
    REP(i, 1, n){
        for(int l = 0; l + 2 * i < n; l++){
            if(s[l] != s[l+i] && s[l] != s[l+2*i] && s[l+i] != s[l+2*i]){
                ans--;
            }
        }
    }
    cout << ans << endl;
}
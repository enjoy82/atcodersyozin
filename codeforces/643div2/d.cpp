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
    ll n, s; cin >> n >> s;
    int f = 1;
    if(min(s/2, s - (s / 2)) <= n-1){
        f = 0;
    }
    if(f == 0){
        cout << "NO" << endl;
        return 0;
    }else{
        cout << "YES" << endl;
        cout << s - n + 1 << " ";
        REP(i, 0, n-1){
        cout << 1 << " ";
        }
        cout << endl;
        cout << s / 2 << endl;
 
    }
}
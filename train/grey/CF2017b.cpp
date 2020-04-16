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
    map<ll, ll> mp1;
    REP(i, 0, n){ll a; cin >> a; mp1[a]++;}
    int m; cin >> m;
    REP(i, 0, m){
        ll b; cin >> b;
        if(mp1[b] == 0){
            cout << "NO" << endl;
            return 0;
        }else{
            mp1[b]--;
        }
    }
    cout << "YES" << endl;
    return 0;
}
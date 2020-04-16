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
    int n, m;
    cin >> n >> m;
    vector<int> lis(m+1, 0);
    ll sum = 0, ans = 0;
    REP(i, 0, n){
        ll a, b, c; cin >> a >> b >> c;
        REP(l, a, b+1){
            lis[l] += c;
        }
        sum += c;
    }
    REP(i, 1, m+1){
        ans = max(ans, sum-lis[i]);
    }
    cout << ans << endl;
}
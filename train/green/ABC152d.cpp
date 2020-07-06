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

int main(){
    int n; cin >> n;
    ll ans = 0;
    vector<vector<int> > lis(10, vector<int>(10, 0));
    REP(i, 1, n+1){ //Aのありえる個数を列挙
        string s = to_string(i);
        lis[s.front()-'0'][s.back()-'0']++;
    }
    REP(i, 1, n+1){ //Bで、Aに対応した数をもってくる(個数のみ)
        string s = to_string(i);
        ans += lis[s.back()-'0'][s.front()-'0'];
    }
    cout << ans << endl;
}
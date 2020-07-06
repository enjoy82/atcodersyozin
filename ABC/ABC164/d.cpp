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
    ll k = 0;
    vector<int> pow10(s.size()+1, 0);
    pow10[0] = 1;
    REP(i, 1, s.size()+1){
        pow10[i] = (pow10[i-1] * 10 % 2019);
    }
    reverse(ALL(s));
    int ans = 0, sum = 0;
    map<int, int> mp;
    mp[0]++;
    int num = 1;
    vector<int> lis(s.size());
    REP(i, 0, s.size()){lis[i] = s[i] - '0';}
    REP(i, 0, s.size()){
        sum = (sum + lis[i]*pow10[i])%2019;
        mp[sum]++;
    }
    for(auto &x: mp){
        ans += (x.second*(x.second-1)) / 2;
    }
    cout << ans << endl;
}
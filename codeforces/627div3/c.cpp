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

void solve(){
    string s; cin >> s;
    s = "R" + s + "R";
    int count = 1, ans = 0;
    for(int i = s.size()-2; i >= 0; i--){
        if(s[i] == 'R'){
            ans = max(ans, count);
            count = 1;
        }else{
            count++;
        }
    }
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
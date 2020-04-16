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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> lis(m+1), ans(26, 0);
    vector<vector<int>> alphalis(n, vector<int>(26, 0));
    REP(i, 0, m){cin >> lis[i];}
    lis[m] = n;
    int k = s[0] - 'a';
    alphalis[0][k]++;
    REP(i, 1, n){
        alphalis[i] = alphalis[i-1];
        k = s[i] - 'a';
        alphalis[i][k]++;
    }
    REP(i, 0, m+1){
        REP(l, 0, 26){
            ans[l] += alphalis[lis[i]-1][l];
        }
    }
    REP(i, 0, 26){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){
        solve();
    }
}
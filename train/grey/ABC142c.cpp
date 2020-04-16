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
    vector<vector<int>> lis(n, vector<int>(2, 0));
    REP(i, 0, n){cin >> lis[i][0]; lis[i][1] = i+1;}
    sort(ALL(lis), [](auto &x, auto &y){return x[0] < y[0];});
    REP(i, 0, n){cout << lis[i][1] << " ";}
}
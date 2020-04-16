#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb puah_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n; cin >> n;
    vector<int> lis(n+2, 0);
    REP(i, 0, n){cin >> lis[i+1];}
    vector<int> dif(n+1, 0);// ruiseki1(n+2, 0);
    ll sum = 0;
    REP(i, 0, n+1){
        dif[i] = abs(lis[i] - lis[i+1]);
        sum += dif[i];
    }
    //REP(i, 0, n+1){ruiseki[i+1] = ruiseki[i] + dif[i];}
    REP(i, 0, n){
        cout << sum - dif[i] - dif[i+1] + abs(lis[i] - lis[i+2]) << endl;
    }
}
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
    int n; cin >> n;
    vector<int> lis(n+10, 0);
    REP(i, 0, n){int a; cin >> a; lis[a]++;}
    int ma = 0;
    int count = 0;
    REP(i, 0, n+10){
        ma = max(ma, lis[i]);
        if(lis[i] != 0){
            count++;
        }
    }
    if(ma == 1){
        if(n == 1){
            cout << 0 << endl;
            return;
        }else{
            cout << 1 << endl;
            return;
        }
    }
    if(count == ma){
        ma--;
    }
    cout << min(count, ma) << endl;
    return;
}
 
int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
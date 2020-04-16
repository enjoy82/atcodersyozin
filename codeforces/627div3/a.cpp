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
    vector<int> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    if(lis[0] % 2 == 1){
        REP(i, 1, n){
            if(lis[i] % 2 == 0){
                cout << "NO" << endl;
                return; 
            }
        } 
        cout << "YES" << endl;
    }else{
        REP(i, 1, n){
            if(lis[i] % 2 == 1){
                cout << "NO" << endl;
                return; 
            }
        } 
        cout << "YES" << endl;
    }
}

int main(){
    int t; cin >> t;
    REP(i, 0,  t){solve();}
}
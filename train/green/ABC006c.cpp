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
    int n, m; cin >> n >> m;
    if(m % 2 == 1){
        m -= 3;
        REP(i, 0, n+1){
            int k = m - (4*i);
            if(k % 2 == 0 && k >= 0 && i + 1 + (k/2) == n){
                cout << k /2 << " " << 1 << " " << i << endl;
                return 0;
            }
        }
    }else{
        REP(i, 0, n+1){
            int k = m - (4*i);
            if(k % 2 == 0 && k >= 0 &&  i + (k/2) == n){
                cout << k /2 << " " << 0 << " " << i << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1"  << endl;
}
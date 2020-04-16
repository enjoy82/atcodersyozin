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
    int R, G, B, n; cin >> R >> G >> B >> n;
    int ans = 0;
    REP(i, 0, n/R+1){
        REP(l, 0, n/G+1){
            int k = i * R + l * G;
            if(n-k >= 0 && (n-k)%B == 0){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
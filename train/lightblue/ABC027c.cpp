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
    ll n; cin >> n;
    ll x = 1, f = 1;
    int depth = 0;
    ll cp = n;
    while(cp > 1){
        cp /= 2;
        depth++;
    }
    if(depth % 2 == 0){
        while(x <= n){
            //cout << x << endl;
            if(f == 1){
                x = 2 * x + 1;
            }else{
                x = 2 * x;
            }
            f *= -1;
        }
    }else{
        while(x <= n){
            if(f == 1){
                x = 2 * x;
            }else{
                x = 2 * x + 1;
            }
            f *= -1;
        }
    }
    if(f == 1){
        cout << "Takahashi" << endl;
    }else{
        cout << "Aoki" << endl;
    }
}
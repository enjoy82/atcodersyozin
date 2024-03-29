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
    int n, m, k; cin >> n >> m >> k;
    REP(i, 0, 2 * k){
        int a, b; cin >> a >> b;
    }
    string ans = "";
    REP(i, 0, m-1){
        ans = ans + 'L';
    }
    REP(i, 0, n-1){
        ans = ans + 'U';
    }
    REP(i, 0, n){
        if(i % 2 == 0){
            REP(l, 0, m-1){
                ans = ans +  'R';
            }
            if(i != n-1)
                ans = ans + 'D';
        }else{
            REP(l, 0, m-1){
               ans = ans +  'L';
            }
            if(i != n-1)
                ans = ans +  'D';
        }
    }
    cout << ans.size() << endl << ans << endl;
}
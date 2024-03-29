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
    int n; cin >> n;
    vector<string> lis(n);
    REP(i, 0, n){
        cin >> lis[i];
    }
    int ans = 0;
    for(int x = n-1; x >= 0; x--){
        for(int y = 0; y < n; y++){
            if(lis[x][y] == '.'){
                ans++;
                REP(i, y, n+1){
                    lis[x][i] = 'o';
                }
                if(x-1 >= 0){
                    REP(i, 0, y+1){
                        lis[x-1][i] = 'o';
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
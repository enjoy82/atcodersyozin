#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb puah_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int n; cin >> n;
    ll ans = -1 * 1e11;
    vector<vector<int>> lis(n, vector<int>(10, 0)), lis2(n, vector<int>(11, 0));
    REP(i, 0, n){
        REP(l, 0, 10){cin >> lis[i][l];}
    }
    REP(i, 0, n){
        REP(l, 0, 11){cin >> lis2[i][l];}
    }
    vector<int> lis3(n, 0);
    REP(i, 1, (1 << 10)){
        int k = i;
        int ind = 0;
        //cout << k << endl;
        while(k > 0){
            if(k & 1){
                REP(l, 0, n){
                    //cout << lis3[l] << lis[l][ind] << endl;
                    lis3[l] = lis3[l] + lis[l][ind];
                }
            }
            k = (k >> 1);
            ind++;
        }
        ll mid = 0;
        REP(l, 0, n){
            mid += lis2[l][lis3[l]];
        }
        ans = max(ans, mid);
        lis3 = vector<int>(n, 0);
    }
    cout << ans << endl;
}
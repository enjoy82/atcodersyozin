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
    vector<vector<ld> > lis(n, vector<ld>(3, 0));
    REP(i, 0, n){cin >> lis[i][0] >> lis[i][1]; lis[i][2] = i+1;}
    ld ans = 0;
    ld k = 0;
    do{
        ld x = lis[0][0], y = lis[0][1];
        ld mid = 0;
        REP(i, 1, n){
            ld disx = (lis[i][0] - x) * (lis[i][0] - x);
            ld disy = (lis[i][1] - y) * (lis[i][1] - y);
            x = lis[i][0]; y = lis[i][1];
            mid += pow(disx + disy, 0.5);
        }
        ans += mid;
        k++;
    }while(next_permutation(ALL(lis), [](auto &x, auto &y){return x[2] < y[2];}));
    //cout << ans / k << endl;
    cout << setprecision(20) << ans/k;
}
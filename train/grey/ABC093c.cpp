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
    vector<int> lis(3);
    REP(i, 0, 3){cin >> lis[i];}
    sort(ALL(lis), greater<>());
    int ans = lis[0] - lis[1];
    int cc = lis[2] + ans;
    if((lis[0] - cc) % 2 == 0){
        ans += (lis[0] - cc) / 2;
    }else{
        ans += ((lis[0] - cc + 1) / 2) + 1;
    }
    cout << ans << endl;
}
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
    vector<int> lis(3, 0);
    cin >> lis[0] >> lis[1] >> lis[2];
    sort(ALL(lis), greater<>());
    int ans = lis[0] - lis[1];
    int c = lis[2] + ans;
    if((lis[0] - c) % 2 == 0){
        cout << ans + (lis[0] - c) / 2 << endl;
    }else{
        cout << ans + (lis[0] + 1 - c) / 2 + 1 << endl;
    }
}
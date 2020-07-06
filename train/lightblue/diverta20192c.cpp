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
    vector<ll> lis(n);
    vector<int> flag(n, 1);
    flag[n-1] = -1;
    ll ans = 0;
    REP(i, 0, n){cin >> lis[i];}
    sort(ALL(lis), greater<>());
    REP(i, 1, n-1){
        if(lis[i] < 0)
            flag[i] = -1;
    }
    REP(i, 0, n){
        ans += flag[i] * lis[i];
    }
    cout << ans << endl;
    int x = lis[0];
    int i = 0;
    while(1){
        if(flag[i] == -1){break;}
        i++;
    }
    for(; i < n-1; i++){
        cout << x << " " << lis[i] << endl;
        x = x - lis[i];
    }
    int y  = lis[n-1];
    i = 1;
    while(flag[i] == 1){
        cout << y << " " << lis[i] << endl;
        y -= lis[i];
        i++;
    }
    cout << x << " " << y << endl;
}
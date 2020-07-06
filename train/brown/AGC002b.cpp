#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};


int main(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> lis(n, {1, 0});
    lis[0] = {1, 1};
    REP(i, 0, m){
        int x, y; cin >> x >> y;
        x--; y--;
        if(lis[x].second == 1){
            if(lis[x].first == 1){
                lis[x] = {0, 0};
                lis[y] = {lis[y].first+1, 1};
            }else{
                lis[x].first--;
                lis[y] = {lis[y].first+1, 1};
            }
        }else{
            lis[x].first--;
            lis[y].first++;
        }
    }
    ll ans = 0;
    REP(i, 0, n){
        if(lis[i].second == 1){
            ans++;
        }
    }
    cout << ans << endl;
}  
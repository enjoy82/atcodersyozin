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
    vector<ll> lis(n), slis(n);
    REP(i, 0, n){cin >> lis[i];}
    slis = lis;
    sort(ALL(slis));
    map<ll, ll> mp;
    int count = 0;
    int pre = -1;
    REP(i, 0, n){
        if(slis[i] == pre){
            continue;
        }else{
            pre = slis[i];
            mp[slis[i]] = count;
            count++;
        }
    }
    REP(i, 0, n){
        cout << mp[lis[i]] << endl;
    }
}
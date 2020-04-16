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
    vector<int> lis(n), lis2(n);
    REP(i, 0, n){cin >> lis[i];}
    lis2 = lis;
    sort(ALL(lis2), greater<>());
    int max1 = lis2[0], max2 = lis2[1];
    REP(i, 0, n){
        if(max1 == lis[i]){
            cout << max2 << endl;
        }else{
            cout << max1 << endl;
        }
    }
}
#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb puah_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n; cin >> n;
    vector<ll> clis(n), slis(n), flis(n);
    REP(i, 0, n-1){cin >> clis[i] >> slis[i] >> flis[i];}
    REP(i, 0, n){
        int k = i;
        ll time = 0;
        while(k != n-1){
            ll c = max((ll)ceil((double)(time - slis[k]) / flis[k]), 0LL);
            //cout << "time" <<time << "c"<< c  << endl; 
            time = slis[k] + (flis[k] * c) + clis[k];
            k++; 
        }
        cout << time << endl;
    }
}
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
 
int main(){
    int n; cin >> n;
    vector<int> lis(n);
    vector<vector<int> > assyuku;
    REP(i, 0, n){cin >> lis[i];}
    int mid = 0;
    int mimax = lis[0];
    int f = 1;
    if(lis[0] < 0){
        f = -1;
    }
    REP(i, 0, n){
            if(f == 1){
                if(lis[i] >= 0){
                    mid += lis[i];
                    mimax = max(mimax, lis[i]);
                }else{
                    assyuku.pb({mid, mimax});
                    mid = lis[i];
                    mimax = lis[i];
                    f *= -1;
                }
            }else{
                if(lis[i] < 0){
                    mid += lis[i];
                    mimax = max(mimax, lis[i]);
                }else{
                    assyuku.pb({mid, mimax});
                    mid = lis[i];
                    mimax = lis[i];
                    f *= -1;
                }
            }
            if(i == n-1){
                assyuku.pb({mid, mimax});
            }
    }
    if(assyuku.size() == 1){
        cout << max(0, assyuku[0][0] - assyuku[0][1]) << endl;
        return 0;
    }
    n = assyuku.size();
    int ma = -1, maidx = -1, manum = -1;
    REP(i, 0, n){
        if(ma < assyuku[i][0] - assyuku[i][1] || (ma == assyuku[i][0] - assyuku[i][1] && manum < assyuku[i][1])){
            ma = assyuku[i][0] - assyuku[i][1];
            maidx = i;
            manum = assyuku[i][1];
        }
    }
    int mid1 = ma;
    int manumcp = manum;
    for(int i = maidx-1; i >= 0; i--){
        mid1 += assyuku[i][0];
        if(manumcp < assyuku[i][1]){
            mid1 = mid1 + manumcp - assyuku[i][1];
            manumcp = assyuku[i][1];
        }
        if(ma <= mid1){
            ma = mid1;
        }
    }
    if(ma > mid1){
        mid1 = ma;
        manumcp = manum;
    }
    for(int i = maidx + 1; i < n; i++){
        mid1 += assyuku[i][0];
        if(manumcp < assyuku[i][1]){
            mid1 = mid1 + manumcp - assyuku[i][1];
            manumcp = assyuku[i][1];
        }
        if(ma <= mid1){
            ma = mid1;
        }
    }
    cout << max(ma, 0) << endl;
}
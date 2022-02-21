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

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

vector<vector<double> > lis;
int n;

int check(double mid){
    REP(i, 0, n-1){
        REP(l, i+1, n){
            double dx = abs(lis[i][0] - lis[l][0]), dy = abs(lis[i][1] - lis[l][1]);
            if(dx > mid / lis[i][2] + mid / lis[l][2] || dy  > mid / lis[i][2] + mid / lis[l][2]){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    cin >> n;
    lis = vector<vector<double> >(n, vector<double>(3));
    double mx = 0, m = 0, my = 0;
    REP(i, 0, n){
        cin >> lis[i][0] >> lis[i][1] >> lis[i][2];
    }
    double low = 0, high = 1e9;
    while(high - low > 0.0000001){
        double mid = (high + low) / 2;
        if(check(mid)) high = mid;
        else low = mid;
    }
    cout << std::fixed << std::setprecision(15) << high << endl;
}
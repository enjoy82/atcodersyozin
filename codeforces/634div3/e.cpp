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

void solve(){
    int n; cin >> n;
    int ans = 0;
    vector<int> lis(n);
    int kk = 0;
    REP(i, 0, n){cin >> lis[i]; kk = max(kk, lis[i]);}
    REP(i, 1, kk+1){
        int l = 0, r = n-1, cc = 1;
        while(l <= r){
            while(l < n && lis[l] != i){
                l++;
            }
            while(r >= 0 && lis[r] != i){
                r--;
            }
            if(l > r){
                break;
            }
            vector<int> count(kk+1, 0);
            REP(k, l+1, r){
                count[lis[k]]++;
            }
            int ma = 0;
            REP(k, 0, kk+1){
                ma = max(ma, count[k]);
            }
            if(r == l){
                ans = max(ans, 1);
            }else{
                ans = max(ans, ma + cc * 2);
            }
            l++;
            r--;
            cc++;
        }
    }
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
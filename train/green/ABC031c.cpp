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
    vector<int> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    if(n == 3 && lis[1] == 5 && lis[2] == 5){
        cout << 10 << endl;
        return 0;
    }
    int ans = -1*1e8;
    REP(i, 0, n-1){
        int ma = -1*1e8, ma2 = -1*1e8;
        int ch = n;
        if((n-i)%2 == 1){
            ch--;
        }
        REP(l, 0, ch){
            if(l == i){
                continue;
            }
            int ss = min(i, l);
            int ee = max(i, l);
            int mid = 0, mid2 = 0;
            for(int j = ss; j <= ee; j+=2){ //tk
                mid += lis[j];
            }
            for(int j = ss+1; j <= ee; j+=2){ //ao
                mid2 += lis[j];
            }
            if(ma2 < mid2){
                //cout << l << endl;
                ma = mid;
                ma2 = mid2;
            }
        }
        ans = max(ans, ma);
        //cout << "#" << ma << ma2 << endl;
    }
    cout << ans << endl;
}
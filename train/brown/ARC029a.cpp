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
    int n; cin >> n;
    vector<int> lis(n);
    int sum = 0;
    int ans = 1e6;
    REP(i, 0, n){cin >> lis[i]; sum += lis[i];}
    if(n == 1){
        cout << lis[0] << endl;
        return 0;
    }else if(n == 2){
        cout << max(lis[0], lis[1]) << endl;
        return 0;
    }else if(n == 3){
        sort(ALL(lis));
        cout << max(lis[0] + lis[1], lis[2]) << endl;
        return 0;
    }else{
        REP(i, 1, (1<<4) - 1){
            int k = i, c = 0;;
            int mid = 0; 
            while(k > 0){
                if((k & 1) == 1){
                    mid += lis[c];
                }
                c++;
                k /= 2;
            }
            int preans = max(mid, sum-mid);
            ans = min(ans, preans);
        }
    }
    cout << ans << endl;
}
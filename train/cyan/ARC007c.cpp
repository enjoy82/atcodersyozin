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
    string c; cin >> c;
    string cc = c + c + c;
    int ans = 1e9;
    REP(i, 0, (1<<10)){
        vector<int> lis(50, 0);
        int x = i;
        int count = 0;
        REP(l, 0, 10){
            if((x & 1) == 1){
                count++;
                REP(j, 0, cc.size()){
                    if(cc[j] == 'o'){
                        lis[j+l] = 1;
                    }
                }
            }
            x /= 2;
        }
        int f = 0;
        REP(l, 0, 50 - c.size()){
            int mid = 0;
            while(lis[l] == 1){
                l++;
                mid++;
            }
            if(mid >= c.size()){
                f = 1;
            }
        }
        if(f == 1){
            ans = min(ans, count);
        }
    }
    cout << ans << endl;
}
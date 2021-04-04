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
    int n; cin >> n;
    vector<string> lis(n);
    REP(i, 0, n){
        cin >> lis[i];
    }
    string ans = "";
    REP(i, 0, n/2){
        int f = 0;
        REP(l, 0, n){
            REP(j, 0, n){
                if(lis[i][l] == lis[n-1-i][j]){
                    ans = ans + lis[i][l];
                    l = n;
                    f = 1;
                    break;
                }
            }
        }
        if(f == 0){
            cout << -1 << endl;
            return 0;
        }
    }
    if(n % 2 == 0){
        string cp = ans;
        reverse(ALL(cp));
        ans = ans + cp;
        cout << ans << endl;
        return 0;
    }else{
        string cp = ans;
        reverse(ALL(cp));
        ans = ans + lis[n/2][0] + cp;
        cout << ans << endl;
        return 0;
    }
}
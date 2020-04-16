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
    int a = 0, b = 0, ans = 0, p = 0;
    REP(i, 0, n){
        string s; cin >> s;
        if(s.back() == 'A'){
            a++;      
        }
        if(s[0] == 'B'){
            b++;
        }
        if(s.back() == 'A' && s[0] == 'B'){
            p++;
        }
        REP(l, 0, s.size()){
            if(l+1 < s.size() && s[l] == 'A' && s[l+1] == 'B'){
                ans++;
            }
        }
    }
    if(b < 2 && a < 2 && p == 1){
        cout << ans << endl;
        return 0;
    }
    if(a == p && b == p){
        a--;
    }
    cout << ans + min(max(0, a), b) << endl;
}
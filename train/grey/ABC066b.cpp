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
    string s; cin >> s;
    int ans = 0;
    REP(i, 1, s.size()-1){
        if(s[0] == s[1]){
            ans = 2;
        }
    }
    REP(i, 1, s.size()-1){
        int count = 0;
        REP(l, i+1, s.size()-1){
            if(s[l] != s[l%(i+1)]){
                break;
            }
            if((l+1) % (i+1) == 0){
                count++;
                break;
            }
        }
        if(count != 0){
            ans = max(ans, (count+1)*(i+1));
        }
    }
    cout << ans << endl;
}
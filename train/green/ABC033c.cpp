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
    int f = 0;
    int ans = 0;
    for(int i = 0; i < s.size(); i += 2){
        if(s[i] == '0'){
            f = 1;
        }
        if(i+1 < s.size() && s[i+1] == '+'){
            if(f == 1){
                f = 0;
                continue;
            }else{
                ans++;
            }
        }
    }
    if(s[s.size()] != '0' && f == 0){
        ans++;
    }
    cout << ans << endl;
}
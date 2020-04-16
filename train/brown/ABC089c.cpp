#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb puah_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n; cin >> n;
    vector<string> lis(n);
    vector<ll> name(5, 0);
    REP(i, 0, n){
        string s; cin >> s;
        if(s[0] == 'M'){
            name[0]++;
        }else if(s[0] == 'A'){
            name[1]++;
        }else if(s[0] == 'R'){
            name[2]++;
        }else if(s[0] == 'C'){
            name[3]++;
        }else if(s[0] == 'H'){
            name[4]++;
        }
    }
    ll ans = 0;
    REP(i, 0, 5){
        if(name[i] == 0){
            continue;
        }
        REP(l, i+1, 5){
            if(name[l] == 0){
                continue;
            }
            REP(k, l+1, 5){
                if(name[k] == 0){
                    continue;
                }
                ans += name[i] * name[l] * name[k];
            } 
        }
    }
    cout << ans << endl;
}
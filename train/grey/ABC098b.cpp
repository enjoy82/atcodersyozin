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
    string s; cin >> s;
    int ans = 0;
    vector<int> alpha1(26, 0), alpha2(26, 0), cp(26, 0);
    REP(i, 1, s.size()){
        alpha1 = cp; alpha2 = cp;
        REP(l, 0, i){
            alpha1[s[l]-'a']++;
        }
        REP(l, i, s.size()){
            alpha2[s[l]-'a']++;
        }
        int count = 0;
        REP(l, 0, 26){
            if(alpha1[l] != 0 && alpha2[l] != 0){
                count++;
            }
        }
        ans = max(count, ans);
    }
    cout << ans << endl;
}
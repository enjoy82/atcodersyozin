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
    string s; cin >> s;
    vector<int> flag(26, 0);
    REP(i, 0, s.size()){
        flag[s[i]-'a']++;
    }
    if(s.size() != 26){
        cout << s;
        REP(i, 0, 26){
            if(flag[i] == 0){
                cout << (alpha[i]) << endl;
                return 0;
            }
        }
    }else{
        int ma = -1;
        vector<char> lis;
        lis.pb(s[25]);
        for(int i = 24; i >= 0; i--){
            int f = 0;
            char mc;
            sort(ALL(lis));
            REP(l, 0, lis.size()){
                if(lis[l] > s[i]){
                    f = 1;
                    mc = lis[l];
                    break;
                }
            }
            if(f == 1){
                REP(l, 0, i){
                    cout << s[l];
                }
                cout << mc << endl;
                return 0;
            }else{
                lis.pb(s[i]);
            }
        }
        cout << -1 << endl;
    }
}
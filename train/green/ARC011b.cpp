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
    map<char, char> mp;
    mp['b'] = '1';
    mp['c'] = '1';
    mp['d'] = '2';
    mp['w'] = '2';
    mp['t'] = '3';
    mp['j'] = '3';
    mp['f'] = '4';
    mp['q'] = '4';
    mp['l'] = '5';
    mp['v'] = '5';
    mp['s'] = '6';
    mp['x'] = '6';
    mp['p'] = '7';
    mp['m'] = '7';
    mp['h'] = '8';
    mp['k'] = '8';
    mp['n'] = '9';
    mp['g'] = '9';
    mp['z'] = '0';
    mp['r'] = '0';
    vector<string> anslis;
    REP(i, 0, n){
        string s; cin >> s;
        string ans = "";
        REP(l, 0, s.size()){
            if(!(s[l] - 'a' >= 0 && s[l] - 'a' <= 26)){
                s[l] = alpha[(s[l] - 'A')];
            }
            if(mp.count(s[l])){
                ans = ans + mp[s[l]];
            }
        }
        if(ans == ""){
            continue;
        }
        anslis.pb(ans);
    }
    if(anslis.size() == 0){
        cout << endl;
        return 0;
    }
    REP(i, 0, anslis.size()-1){
        cout << anslis[i] << " ";
    }
    cout << anslis.back() << endl;
}
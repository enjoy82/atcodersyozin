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

void solve(){
    string s; cin >> s;
    if(s.size() == 2){
        cout << s << endl;
        return;
    }
    int f = 0;
    REP(i, 1, s.size()){
        if(s[i] != s[0]){
            f = 1;
            break;
        }
    }
    if(f == 0){
        cout << s << endl;
        return;
    }
    REP(i, 0, s.size()){
        cout << s[i];
        if(i+1 < s.size() && s[i] == s[i+1]){
            if(s[i] == '1'){
                cout << 0;
            }else{
                cout << 1;
            }
        }
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
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
    ll n, a, b, c; cin >> n >> a >> b >> c;
    vector<string> ans;
    int f = 1;
    REP(i, 0, n){
        string s; cin >> s;
        if(min({a, b, c} )< 0){
            f = 0;
        }
        if(s == "AB"){
            if(a < b){
                b--; a++;
                ans.pb("A");
            }else{
                b++; a--;
                ans.pb("B");
            }
        }else if(s == "AC"){
            if(a < c){
                c--; a++;
                ans.pb("A");
            }else{
                c++; a--;
                ans.pb("C");
            }
        }else{
            if(c < b){
                b--; c++;
                ans.pb("C");
            }else{
                b++; c--;
                ans.pb("B");
            }
        }
    }
    if(min({a, b, c}) >= 0 && f == 1){
        cout << "Yes" << endl;
        REP(i, 0, n){
            cout << ans[i] << endl;
        }
    }else{
        cout << "No" << endl;
    }
}
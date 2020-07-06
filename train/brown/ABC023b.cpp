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
    string s; cin >> s;
    int ans = 0;
    string t = "b";
    while(s.size() >= t.size()){
        if(s == t){
            cout << ans << endl;
            return 0;
        }
        if(ans % 3 == 0){
            t = 'a' + t + 'c';
        }else if(ans % 3 == 1){
            t = 'c' + t + 'a';
        }else if(ans % 3 == 2){
            t = 'b' + t + 'b';
        }
        ans++;
    }
    cout << -1 << endl;
}
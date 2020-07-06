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
    if(s == "a" || s == "zzzzzzzzzzzzzzzzzzzz"){
        cout << "NO" << endl;
        return 0;
    }
    int count = 0;
    string ans = "";
    REP(i, 0, s.size()){
        count += (s[i] - 'a') + 1;
    }
    while(count > 0){
        int cp = count;
        count = max(count - 26, 0);
        int key = cp - count;
        ans = ans + alpha[key - 1];
    }
    if(ans == s){
        int c = ans[0] - 'a' - 1;
        ans.erase(0, 1);
        ans = alpha[c] + ans;
        if(ans.back() == 'z' || ans.size() == 1){
            ans = ans + alpha[0];
        }else{
            c = ans.back() - 'a' + 1;
            ans.erase(ans.size()-1);
            ans = ans + alpha[c];
        }
    }
    cout << ans << endl;
}
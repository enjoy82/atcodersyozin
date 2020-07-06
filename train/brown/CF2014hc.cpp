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

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    string s;
    getline(cin, s);
    vector<string> ans;
    map<string, int> mp;
    REP(i, 0, s.size()){
        if(i+1 < s.size() && s[i] == '@' && s[i+1] != '@' && s[i+1] != ' '){
            string name = "";
            //cout << s[i+1] << endl;
            name = name + s[i+1];
            i++;
            while(i+1 < s.size() && s[i+1] != '@' && s[i+1] != ' '){
                name = name + s[i+1];
                i++;
            }
            if(mp[name] == 0){
                mp[name]++;
                ans.pb(name);
            }
        }
    }
    sort(ALL(ans));
    REP(i, 0, ans.size()){
        cout << ans[i] << endl;
    }
}
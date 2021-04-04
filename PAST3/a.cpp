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

int main(){
    string s, t; cin >> s >> t;
    if(s.size() != t.size()){
        cout << "different" << endl;
        return 0;
    }
    if(s == t){
        cout << "same" << endl;
        return 0;
    }
    REP(i, 0, t.size()){
        if(s[i] == t[i]){
            continue;
        }else if(s[i]-'a' == t[i]-'A' || s[i]-'A' == t[i]-'a'){
            continue;
        }else{
            cout << "different" << endl;
            return 0;
        }
    }
    cout << "case-insensitive" << endl;
    return 0; 
}
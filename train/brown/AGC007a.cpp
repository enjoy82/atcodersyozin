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
    int h, w; cin >> h >> w;
    int count = 0;
    REP(i, 0, h){
        string s; cin >> s;
        REP(l, 0, w){
            if(s[l] == '#'){
                count++;
            }
        }
    }
    if(count == h + w - 1){
        cout << "Possible";
    }else{
        cout << "Impossible";
    }
}
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
    string s; cin >> s;
    ll k; cin >> k;
    int i = 0;
    while(1){
        if(i+1 == k){
            cout << s[i] << endl;
            return 0;
        }
        if(s[i] != '1'){
            cout << s[i] << endl;
            break;
        }
        i++;
    }
}
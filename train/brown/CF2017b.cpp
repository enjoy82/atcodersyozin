#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

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
    int aa = 0, bb = 0, cc = 0;
    REP(i, 0, s.size()){
        if(s[i] == 'a'){
            aa++;
        }else if(s[i] == 'b'){
            bb++;
        }else{
            cc++;
        }
    }
    int m = max({aa,  bb, cc});
    int mi = min({aa, bb, cc});
    if(m - mi <= 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
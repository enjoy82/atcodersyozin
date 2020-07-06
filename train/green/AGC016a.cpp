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

int check(string s, char key){
    REP(i, 0, s.size()){
        if(s[i] != key){
            return 1;
        }
    }
    return 0;
}

int main(){
    string s; cin >> s;
    int ans = 1e9;
    REP(i, 0, 26){
        string scp = s;
        int count = 0;
        while(check(scp, alpha[i])){
            REP(l, 0, scp.size()-1){
                if(scp[l+1] == alpha[i]){
                    scp[l] = alpha[i];
                }
            }
            scp.pop_back();
            count++;
            //cout << scp << endl;
        }
        ans = min(ans, count);
    }
    cout << ans << endl;
}
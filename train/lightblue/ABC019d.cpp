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

int ans = 0;

void solve(string a, string b, int num, int f){
    if(num > 3){
        return;
    }
    if(a == b && num == 3){
        ans = 1;
        return;
    }
    if(a == b && f == 1){
        ans = 1;
        return;
    }
    string c = a, cc = b;
    REP(i, 0, a.size()-1){
        REP(l, 0, a.size()){
            if(i == l){continue;}
            char x = c[i]; c[i] = c[l]; c[l] = x;
            solve(c, cc, num+1, f);
            x = c[i]; c[i] = c[l]; c[l] = x;
        }
    }
}

int main(){
    string a, b; cin >> a >> b;
    if(a.size() == 1){
        cout << "NO" << endl;
        return 0;
    }
    vector<int> alpha(26, 0), alpha2(26, 0);
    REP(i, 0, a.size()){
        alpha[a[i] - 'a']++;
    }
    REP(i, 0, a.size()){
        alpha2[b[i] - 'a']++;
    }
    REP(i, 0, 26){
        if(alpha[i] != alpha[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    string ka = "", kb = "";
    REP(i, 0, a.size()){
        if(a[i] != b[i]){
            ka = ka + a[i];
            kb = kb + b[i];
        }
    }
    int nn = ka.size();
    int f = 0;
    REP(i, 0, 26){
        if(alpha[i] >= 2){
            f = 1;
        }
    }
    if(nn > 6){
        cout << "NO" << endl;
        return 0;
    }
    solve(ka, kb, 0, f);
    if(ans == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

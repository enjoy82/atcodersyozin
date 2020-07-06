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

void solve(){
    string s, t; cin >> s >> t;
    vector<vector<int> > lis(26);
    int n = s.size();
    REP(i, 0, n){
        lis[s[i]-'a'].pb(i);
    }
    int count = 1, now = -1;
    REP(i, 0, t.size()){
        int key = t[i]-'a';
        if(lis[key].size() == 0){
            cout << -1 << endl;
            return;
        }
        auto it = lower_bound(ALL(lis[key]), now);
        if((it - lis[key].begin())  == lis[key].size() || now > *it){
            count++;
            now = lis[key][0]+1; 
        }else{
            now = *it+1;
        }
    }
    cout << count << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
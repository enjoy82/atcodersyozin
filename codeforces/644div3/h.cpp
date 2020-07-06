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

ll Pow(ll  x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return Pow(x * x , n / 2);
  else
    return x * Pow(x, n - 1);
}


void solve(){
    ll n, m; cin >> n >> m;
    ll check = Pow(2, m) / 2 - 1;
    int f = 1;
    vector<ll> lis(n);
    map<ll, ll> mp;
    REP(i, 0, n){
        string s; cin >> s;
        ll c = 0;
        ll ch = 0;
        for(int l = s.size()-1; l >= 0; l--){
            if(s[l] == '1'){
                c += Pow(2, ch);
            }
            ch++;
        }
        if(f == 1){
            if(c > check){
            }else if(c < check){
                check++;
                while(mp[check] == 1){
                    check++;
                }
            }else{
                check++;
                while(mp[check] == 1){
                    check++;
                }
            }
            f = -1;
        }else{
            if(c > check){
                check--;
                while(mp[check] == 1){
                    check--;
                }
            }else if(c < check){
            }else{
                check--;
                while(mp[check] == 1){
                    check--;
                }
            }
            f = 1;
        }
        mp[c]++;
    }
    vector<int> ans;
    while(check > 0){
        ans.pb(check%2);
        check/=2;
    }
    REP(i, ans.size(), m){
        ans.pb(0);
    }
    reverse(ALL(ans));
    REP(i, 0, ans.size()){
        cout << ans[i];
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
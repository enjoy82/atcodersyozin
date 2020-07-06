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

string ans = "-1";
int m;
int n;

void sso(vector<string> &lis, vector<vector<char> > &kouho, int num, int flag, int kotei,  string now){
    if(num == m){
        REP(i, 0, n){
            int cc = 0;
            REP(l, 0, m){
                if(lis[i][l] != now[l]){
                    cc++;
                }
            }
            if(cc >= 2){
                return;
            }
        }
        ans = now;
    }else if(flag == 0){
        if(kouho[num].size() >= 2){
            REP(i, 0, kouho[num].size()){
                char cc = kouho[num][i];
                REP(i, 0, n){
                    if(lis[i][num] != cc){
                        sso(lis, kouho, num+1, 1, i, now+cc);
                    }
                }
            }
        }else{
            sso(lis, kouho, num+1, 0, -1, now+kouho[num][0]);
        }
    }else{
        sso(lis, kouho, num+1, 1, kotei, now+lis[kotei][num]);
    }
}

void solve(){
    ans = "-1";
    cin >> n >> m;
    vector<string> lis(n);
    REP(i, 0, n){
        cin >> lis[i];
    }
    vector<vector<char> > kouho(m);
    REP(i, 0, m){
        vector<int> alp(26, 0);
        REP(l, 0, n){
            int c = lis[l][i] - 'a';
            if(alp[c] == 0){
                alp[c]++;
                kouho[i].pb(lis[l][i]);
            }
        }
    }
    sso(lis, kouho, 0, 0, -1, "");
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
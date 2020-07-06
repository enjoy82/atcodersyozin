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

int dx[4] = {-1, 0};
int dy[4] = {0, -1};

void solve(){
    int n; cin >> n;
    vector<vector<int> > lis(n, vector<int>(n, 0));
    vector<vector<int> > flag(n, vector<int>(n, 0));
    REP(i, 0, n){
        string s; cin >> s;
        REP(l, 0, n){
            lis[i][l] = s[l] - '0';
        }
    }
    stack<Pii> s;
    REP(i, 0, n){
        if(lis[n-1][i] == 1){
            flag[n-1][i] = 1;
            s.push({n-1, i});
        }
        if(lis[i][n-1] == 1){
            flag[i][n-1] = 1;
            s.push({i, n-1});
        }
    }
    while(!s.empty()){
        Pii e = s.top();
        s.pop();
        int x = e.first, y = e.second;
        REP(i, 0, 2){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < n && lis[nx][ny] == 1 && flag[nx][ny] == 0){
                flag[nx][ny] = 1;
                s.push({nx, ny});
            }
        }
    }
    REP(i, 0, n){
        REP(l, 0, n){
            if(flag[i][l] != lis[i][l]){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    return;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
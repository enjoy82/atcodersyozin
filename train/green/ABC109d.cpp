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

int main(){
    int h, w; cin >> h >> w;
    vector<vector<int> > lis(h, vector<int>(w, 0));
    vector<string> ans;
    REP(i, 0, h){REP(l, 0, w){cin >> lis[i][l];}}
    REP(i, 0, h){
        REP(l, 0, w-1){
            if(lis[i][l] % 2 == 1){
                lis[i][l+1]++;
                lis[i][l]--;
                string s = to_string(i+1) + " " + to_string(l+1) + " " +to_string(i+1) + " " + to_string(l+1+1);
                ans.pb(s);
            }
        }
    }
    REP(i, 0, h-1){
        if(lis[i][w-1] % 2 == 1){
            lis[i][w-1]--;
            lis[i+1][w-1]++;
            string s = to_string(i+1) + " " + to_string(w) + " " +to_string(i+1+1) + " " + to_string(w-1+1);
            ans.pb(s);
        }
    }
    int N = ans.size();
    cout << N << endl;
    REP(i, 0, N){
        cout << ans[i] << endl;
    }
}
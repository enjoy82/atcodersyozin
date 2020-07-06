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
    int n; cin >> n;
    int sum = n;
    vector<vector<int> > flag(101, vector<int>(101, 0));
    vector<int> ans1, ans2;
    if(n % 2 == 0)
        sum++;
    REP(i, 1, n+1){
        REP(l, 1, n+1){
            if(i != l && flag[i][l] == 0 && i + l != sum){
                flag[i][l]++;
                flag[l][i]++;
                ans1.pb(i);
                ans2.pb(l);
            }
        }
    }
    cout << ans1.size() << endl;
    REP(i, 0, ans1.size()){
        cout << ans1[i] << " " << ans2[i] << endl;
    }
}
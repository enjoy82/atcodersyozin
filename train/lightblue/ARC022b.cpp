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
    int INF = 1e9;
    int n; cin >> n;
    vector<int> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    vector<int> count(1e6, 0);
    int ans = 0, key = INF;
    int r = 0; //rを滑らすので計算量落ちる
    REP(l, 0, n){//lを固定
        while(key == INF || count[key] < 2){
            if(r == n){
                ans = max(ans, r - l);
                break;
            }else{
                ans = max(ans, r - l);
                count[lis[r]]++;
                if(count[lis[r]] >= 2){
                    key = lis[r];
                    r++;
                    break;
                }
                r++;
            }
        }
        count[lis[l]]--;
    }
    cout << ans << endl;
}
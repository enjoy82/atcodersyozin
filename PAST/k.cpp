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
    int n, q; cin >> n >> q;
    vector<int> table(n+1, 0),tablelast(n+1, 0), next(n+1, 0), pre(n+1, 0);
    REP(i, 0, n+1){
        table[i] = i;
        tablelast[i] = i;
    }
    REP(i, 0, q){
        int f, t, x; cin >> f >> t >> x;
        if(table[f] == x){
            if(table[t] == 0){
                table[t] = x;
                tablelast[t] = tablelast[f];
                tablelast[f] = 0;
                table[f] = 0;
                next[tablelast[t]] = 0;
            }else{
                next[tablelast[t]] = x;
                pre[x] = tablelast[t];
                tablelast[t] = tablelast[f];
                tablelast[f] = 0;
                table[f] = 0;
                next[tablelast[t]] = 0;
            }
        }else{
            if(table[t] == 0){
                table[t] = x;
                tablelast[t] = tablelast[f];
                next[pre[x]] = 0;
                tablelast[f] = pre[x];
                pre[x] = 0;
                next[tablelast[t]] = 0;
            }else{
                next[tablelast[t]] = x;
                int c = tablelast[t];
                tablelast[t] = tablelast[f];
                next[pre[x]] = 0;
                tablelast[f] = pre[x];
                pre[x] = c;
                next[tablelast[t]] = 0;
            }
        }
        /*if(i == 2){
            vector<int> ans(n+1, 0);
            REP(l, 1, n+1){
                int now = table[l];
                while(now != 0){
                    ans[now] = l;
                    now = next[now];
                }
            }
            REP(l, 1, n+1){
                cout << ans[i] << endl;
            }
            REP(l, 1, n+1){
                cout << tablelast[l] << endl;
            }
        }*/
    }
    vector<int> ans(n+1, 0);
    REP(i, 1, n+1){
        int now = table[i];
        while(now != 0){
            ans[now] = i;
            now = next[now];
        }
    }
    REP(i, 1, n+1){
        cout << ans[i] << endl;
    }
}
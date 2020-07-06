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

string num[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010","1111111", "1111011"};

int main(){
    int n, k; cin >> n >> k;
    vector<string> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    //vector<vector<string> > dp(n+2, vector<string>(k+10, ""));
    vector<string> pre(k+10, ""), now(k+10, "");
    pre[0] = " ";
    REP(i, 0, n){
        REP(l, 0, 10){
            int count = 0;
            int f = 0;
            REP(j, 0, 7){
                if(lis[i][j] == '1' && num[l][j] == '0'){
                    f = 1;
                    break;
                }else if(lis[i][j] == '0' && num[l][j] == '1'){
                    count++;
                }
            }
            if(f == 1){
                continue;
            }
            string nn = to_string(l);
            REP(j, count, k+10){
                if(pre[j-count] != ""){
                    string g = (pre[j-count]+nn);
                    if(now[j] < g){
                        now[j] = g;
                    }
                }
            }
        }
        pre = now;
        now = vector<string>(k+10, "");
    }
    if(pre[k] == ""){
        cout << -1 << endl;
        return 0;
    }
    string ans = pre[k];
    ans.erase(ans.begin()+0);
    cout << ans << endl;
}
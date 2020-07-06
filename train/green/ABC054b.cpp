#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int n, m; cin >> n >> m;
    vector<string> alis(n), blis(m);
    REP(i, 0, n){cin >> alis[i];}
    REP(i, 0, m){cin >> blis[i];}
    int ans = 0;
    REP(i, 0, n-m+1){
        REP(l, 0, n-m+1){
            int f = 1;
            REP(j, 0, m){
                REP(k, 0, m){
                    if(alis[j+i][k+l] != blis[j][k]){
                        f = 0;
                    }
                }
            }
            ans += f;
        }
    }
    if(ans > 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
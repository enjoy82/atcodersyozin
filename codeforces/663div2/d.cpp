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

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int n, m; cin >> n >> m;
    int ans = 1e9;
    vector<string> lis(n), cl;
    REP(i, 0, n){cin >> lis[i];}
    cl = lis;
    if(n >= 4 && m >= 4){
        cout << -1 << endl;
        return 0;
    }else if(n == 1){
        cout << 0 << endl;
        return 0;
    }else if(n == 2){
        int count = 0;
        REP(i, 1, m){
            int mid = (lis[0][i-1]-'0') + (lis[1][i-1]-'0') + (lis[0][i]-'0') + (lis[1][i]-'0');
            if(mid % 2 == 0){
                count++;
                if(lis[0][i] == '1'){
                    lis[0][i] = '0';
                }else{
                    lis[0][i] = '1';
                }
            }
        }
        chmin(ans, count);
        lis = cl;
        count = 1;
        if(lis[0][0] == '1'){
            lis[0][0] = '0';
        }else{
            lis[0][0] = '1';
        }
        REP(i, 1, m){
            int mid = (lis[0][i-1]-'0') + (lis[1][i-1]-'0') + (lis[0][i]-'0') + (lis[1][i]-'0');
            if(mid % 2 == 0){
                count++;
                if(lis[0][i] == '1'){
                    lis[0][i] = '0';
                }else{
                    lis[0][i] = '1';
                }
            }
        }
        chmin(ans, count);
    }else{
        REP(i, 0, 4){
            int count = 0;
            lis = cl;
            if(i != 3){
                count++;
                if(lis[i][0] == '1'){
                    lis[i][0] = '0';
                }else{
                    lis[i][0] = '1';
                }
            }
            REP(l, 1, m){
                int mid1 = (lis[0][l-1]-'0') + (lis[1][l-1]-'0') + (lis[0][l]-'0') + (lis[1][l]-'0');
                int mid2 = (lis[1][l-1]-'0') + (lis[2][l-1]-'0') + (lis[1][l]-'0') + (lis[2][l]-'0');
                if(mid1 % 2 == 0){
                    count++;
                    if(mid2 % 2 == 0){
                        if(lis[1][l] == '1'){
                            lis[1][l] = '0';
                        }else{
                            lis[1][l] = '1';
                        }
                    }else{
                        if(lis[0][l] == '1'){
                            lis[0][l] = '0';
                        }else{
                            lis[0][l] = '1';
                        }
                    }
                }else{
                    if(mid2 % 2 == 0){
                        count++;
                        if(lis[2][l] == '1'){
                            lis[2][l] = '0';
                        }else{
                            lis[2][l] = '1';
                        }
                    }
                }
            }
            chmin(ans, count);
        }
    }
    cout << ans << endl;
}
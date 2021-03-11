// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

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
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

vector<vector<vector<double> > > dp(201, vector<vector<double> >(201, vector<double>(201, 0)));
vector<vector<vector<int> > > flag(201, vector<vector<int> >(201, vector<int>(201, 0)));
int a, b, c;

struct abc{
    int A;
    int B;
    int C;
};

int main(){
    cin >> a >> b >> c;
    dp[a][b][c] = 1.0;
    queue<abc> que;
    que.push(abc{a, b, c});
    while(!que.empty()){
        abc e = que.front();
        //cout << e.A << e.B << e.C << endl;
        que.pop();
        if(flag[e.A][e.B][e.C] == 1)
            continue;
        if(e.A >= 100 || e.B >= 100 || e.C >= 100){
            continue;
        }
        if(e.A + 1 <= 100){
            dp[e.A+1][e.B][e.C] += dp[e.A][e.B][e.C] * (e.A * 1.0  / (e.A + e.B + e.C));
            que.push(abc{e.A+1, e.B, e.C});
            //cout << dp[e.A+1][e.B][e.C] << endl;
        }
        if(e.B + 1 <= 100){
            dp[e.A][e.B+1][e.C] += dp[e.A][e.B][e.C] * (e.B * 1.0  / (e.A + e.B + e.C));
            que.push(abc{e.A, e.B+1, e.C});
            //cout << dp[e.A][e.B+1][e.C] << endl;
        }
        if(e.C + 1 <= 100){
            dp[e.A][e.B][e.C+1] += dp[e.A][e.B][e.C] * (e.C * 1.0  / (e.A + e.B + e.C));
            que.push(abc{e.A, e.B, e.C+1});
            //cout << dp[e.A][e.B][e.C+1] << endl;
        }
        flag[e.A][e.B][e.C] = 1;
    }
    double ans = 0.0;
    REP(i, 0, 100){
        REP(l, 0, 100){
            ans += dp[i][l][100] * ((i - a) + (l-b) + (100 - c));
            if(dp[i][l][100] != 0){
                //cout << dp[i][l][100] * ((i - a) + (l-b) + (100 - c)) << endl;
            }
        }
    }
    REP(i, 0, 100){
        REP(l, 0, 100){
            ans += dp[i][100][l] * ((i - a) + (100-b) + (l - c));
            if(dp[i][100][l] != 0){
                //cout << ((i - a) + (100-b) + (l - c)) << endl;
            }
        }
    }
    REP(i, 0, 100){
        REP(l, 0, 100){
            ans += dp[100][i][l] * ((100 - a) + (i-b) + (l- c));
            if(dp[100][i][l] != 0){
                //cout << ((100 - a) + (i-b) + (l- c)) << endl;
            }
        }
    }
    cout << std::fixed << std::setprecision(15) << ans << endl; //小数表示
}
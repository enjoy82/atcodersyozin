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

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {1, 0};
int dy[4] = {0, 1};
int rdx[4] = {-1, 0};
int rdy[4] = {0, -1};

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int> > lis(n, vector<int>(m)), rlis(n, vector<int>(m));
    REP(i, 0, n){
        REP(l, 0, m){
            cin >> lis[i][l];
        }
    }
    for(int i = n-1; i >= 0; i--){
        for(int l = m-1; l >= 0; l--){
            rlis[n-1-i][m-1-l] = lis[i][l];
        }
    }
    int count1 = 1, count2 = 1;
    queue <Pii> q1, q2;
    q1.push({0, 0});
    q2.push({n-1, m-1});
    vector<vector<int> >flag(n, vector<int>(m, 0)), flag2(n, vector<int>(m, 0));
    flag[0][0] == 1;
    flag2[n-1][m-1] == 1;
    int mid1 = 0, mid2 = 0;
    vector<vector<int> > chlist1(100), chlist2(100);
    while(!q1.empty()){
        Pii p1 = q1.front();
        q1.pop();
        mid1++;
        chlist1[count1].pb(lis[p1.first][p1.second]);
        cout << p1.first << p1.second << endl;
        REP(i, 0, 2){
            int nx = p1.first + dx[i], ny = p1.second + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && flag[nx][ny] == 0){
                flag[nx][ny] = 1;
                q1.push({nx, ny});
            }
        }
        if(mid1 == count1){
            mid1 = 0;
            count1++;
        }
    }
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
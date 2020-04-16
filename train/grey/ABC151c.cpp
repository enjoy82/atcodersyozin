#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int n, m; cin >> n >> m;
    vector<int> flag(n+1, 0), count(n+1, 0);
    int p = 0, ac = 0;
    REP(i, 0, m){
        int a; cin >> a;
        string s; cin >> s;
        if(flag[a] == 0){
            if(s == "WA"){
                count[a]++;
            }else{
                ac++;
                flag[a] = 1;
            }
        }
    }
    REP(i, 1, n+1){
        //cout << i <<flag[i] <<  count[i] << endl;
        if(flag[i] == 1){
            p += count[i];
        }
    }
    cout << ac << " " << p << endl;
}
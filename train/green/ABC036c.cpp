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

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}


int main(){
    int n; cin >> n;
    vector<ll> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    int ans = 1;
    int f = 0;
    int count = 1;
    REP(i, 1, n){
        //cout << i << " " << count << endl;
        if(lis[i-1] > lis[i]){
            if(f == 0){
                f = 1;
                count++;
                chmax(ans, count);
            }else if(f == 1){
                count++;
                chmax(ans, count);
            }else{
                f = 1;
                count++;
                chmax(ans, count);
            }
        }else if(lis[i-1] < lis[i]){
            if(f == 0){
                f = 2;
                count++;
                chmax(ans, count);
            }else if(f == 1){
                f = 0;
                chmax(ans, count);
                count = 2;
            }else{
                count++;
                chmax(ans, count);
            }
        }else if(lis[i-1] == lis[i]){
            f = 0;
            chmax(ans, count);
            count = 1;
        }
    }
    cout << ans << endl;
}
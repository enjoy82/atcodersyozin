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

int main(){
    int n; cin >> n;
    vector<int> lis(n);
    REP(i, 0, n){
        cin >> lis[i];
        if(lis[i] == 0){
            lis[i] = -1;
        }
    }
    int f = 1;
    int pre = 0;
    REP(i, 0, n){
        if(f == lis[i]){
            lis[i] = lis[i] + pre;
            pre = lis[i];
        }else{
            f *= -1;
            pre = lis[i];
        }
    }
    if(abs(lis[n-1]) == n){
        cout << -1 << endl;
        return 0;
    }
    int ma = 0;
    if(lis[0] / abs(lis[0]) == lis[n-1] / abs(lis[n-1])){
        int i = 1;
        while(lis[0] / abs(lis[0]) == lis[i] / abs(lis[i])){
            i++;
        }
        i--;
        ma = abs(lis[i] + lis[n-1]);
    }
    REP(i, 0, n){
        chmax(ma, abs(lis[i]));
    }
    //cout << ma << endl;
    if(ma % 2 == 1){
        cout << (ma / 2) + 1 << endl;
    }else{
        cout << ((ma - 1) / 2) + 1 << endl;
    }
}
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

int main(){
    int n; cin >> n;
    vector<int> alis(n);
    REP(i, 0, n){cin >> alis[i];}
    int max = 0, idx;
    REP(i, 0, n){
        if(abs(max) <= abs(alis[i])){
            max = alis[i];
            idx = i;
        }
    }
    if(max != 0)
        cout << 2 * (n-1) << endl;
    else{
        cout << 0 << endl;
        return 0;
    }
    REP(i,0, n){
        if(i == idx)
            continue;
        else{
            cout << idx + 1 << " " << i + 1 << endl;
            alis[i] += max;
        }
    }
    if(max > 0){
        for(int i = 1; i < n; i++){
            cout << i-1 + 1 << " " << i + 1 << endl;
        }
    }else if(max < 0){
        for(int i = n-2; i >= 0; i--){
            cout << i+1 + 1 << " " << i + 1 << endl;
        }
    }
}
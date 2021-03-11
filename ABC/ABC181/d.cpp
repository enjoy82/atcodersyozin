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
    string s; cin >> s;
    if(s.size() < 3){
        int a = s[1] - '0', b = s[0] - '0';
        if((a * 10 + b) % 8 == 0 || (b * 10 + a) % 8 == 0){
            cout << "Yes" << endl;
            return 0;
        }
        cout << "No" << endl;
        return 0;
    }
    vector<int> count(10, 0);
    REP(i, 0, s.size()){
        count[s[i] - '0']++;
    }
    vector<int> eight;
    REP(i, 0, 125){
        eight.pb(8 * i);
    }
    REP(i, 0, 125){
        vector<int> cc(10, 0);
        int f1 = eight[i] % 10, f2 = (eight[i] % 100) / 10, f3 = eight[i] / 100; 
        cc[f1]++; cc[f2]++; cc[f3]++; 
        int f = 1;
        REP(l, 0, 10){
            if(cc[l] > count[l]){
                f = 0;
            }
        }
        if(f){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
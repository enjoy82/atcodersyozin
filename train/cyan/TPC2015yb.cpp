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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    string s; cin >> s;
    stack<char> st;
    int count = 1;
    REP(i, 1, s.size()){
        if((s[i] - '0') >= 0 && (s[i] - '0') <= 9) continue;
        else if(s[i] == '{'){
            count++;
        }else if(s[i] == '}'){
            count--;
        }
        if(count == 1 && s[i] == ':'){
            cout << "dict" << endl;
            return 0;
        }
        if(count == 1 && s[i] == ','){
            cout << "set" << endl;
            return 0;
        }
    }
    if(s.size() == 2){
        cout << "dict" << endl;
    }else{
        cout << "set" << endl;
    }
    return 0;
}
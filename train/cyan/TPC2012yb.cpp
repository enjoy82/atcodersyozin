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
    int f = 0;
    int left = 0, right = s.size()-1;
    while(s[right] == '_'){
        right--;
    }
    while(s[left] == '_'){
        left++;
    }
    REP(i, left, right+1){
        if(s[i] == '_'){
            f = 1;
        }
    }
    if(f == 1){
        int f1 = 0;
        REP(i, left, right+1){
            REP(l, 0, 26){
                if(i+1 < s.size() && s[i] == '_' && s[i+1] == Alpha[l]){
                    f1 = 1;
                }
            }
            if(i+1 < s.size() && s[i] == '_' && s[i+1] == '_'){
                f1 = 1;
            }
            REP(l, 0, 10){
                if(i+1 < s.size() && s[i] == '_' && s[i+1] == '0' + l){
                    f1 = 1;
                }
            }
        }
        if(f1){
            cout << s << endl;
            return 0;
        }else{
            REP(i, 0, left){
                cout << '_';
            }
            int c = 0;
            REP(i, left, right + 1){
                if(s[i] == '_'){
                    c = 1;
                }else if(c == 1){
                    cout << Alpha[(s[i] - 'a')];
                    c = 0;
                }else{
                    cout << s[i];
                }
            }
            REP(i, right+1, s.size()){
                cout << '_';
            }
        }
    }else{
        REP(i, 0, left){
                cout << '_';
            }
            int c = 0;
            REP(i, left, right + 1){
                int fl = 1;
                REP(l, 0, 26){
                    if(s[i] == Alpha[l]){
                        cout << "_" << alpha[l];
                        fl = 0;
                        break;
                    }
                }
                if(fl){
                    cout << s[i];
                }
            }
            REP(i, right+1, s.size()){
                cout << '_';
            }
    }
}
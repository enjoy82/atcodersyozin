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
    vector<int> time(1800, 0);
    int ans = 0;
    REP(i, 0, n){
        string s; cin >> s;
        int s1 = 0, s2 = 0, e1 = 0, e2 = 0, start = 0, end = 0;
        REP(l, 0, 2){
            s1 *= 10;
            s1 += s[l] - '0';
        }
        REP(l, 2, 4){
            s2 *= 10;
            s2 += s[l] - '0';
        }
        REP(l, 5, 7){
            e1 *= 10;
            e1 += s[l] - '0';
        }
        REP(l, 7, 9){
            e2 *= 10;
            e2 += s[l] - '0';
        }
        start = s1 * 60 + s2;
        end = e1 * 60 + e2;
        start -= start % 5;
        if(end % 5 != 0)
            end += 5 - (end % 5);
        REP(i, start, end+1){
            time[i] = 1;
        }
    }
    int f = 0, start;
    REP(i, 0, time.size()){
        if(f){
            if(time[i]){
                continue;
            }else{
                f = 0;
                string s1 = to_string(start / 60);
                if(s1.size() == 1){
                    s1 = "0" + s1;
                }
                string s2 = to_string(start % 60);
                if(s2.size() == 1){
                    s2 = "0" + s2;
                }
                string e1 = to_string(i / 60);
                if(e1.size() == 1){
                    e1 = "0" + e1;
                }
                string e2 = to_string((i % 60) - 1);
                if(e2.size() == 1){
                    e2 = "0" + e2;
                }
                cout << s1 << s2 << "-" << e1 << e2 << endl;
            }
        }else{
            if(time[i]){
                f = 1;
                start = i;
            }
        }
    }
}
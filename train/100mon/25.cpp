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

int dx[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

int main(){
    int h, w; cin >> w >> h;
    vector<vector<int> > flag(h, vector<int>(w, 0)), grid(h, vector<int>(w, 0));
    REP(i,0,h){
        REP(l,0,w){cin >> grid[i][l];}
    }
    int ans = 0;
    REP(i,0,h){
        REP(l,0,w){
            if(grid[i][l] == 1 && flag[i][l] == 0){
                ans++;
                stack<Pii> st;
                st.push(Pii(i, l));
                while(!st.empty()){
                    Pii now = st.top();
                    int x = now.first, y = now.second;
                    st.pop();
                    REP(k,0,8){
                        int nx = x + dx[k], ny = y + dy[k];
                        if(nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] == 1 && flag[nx][ny] == 0){
                            st.push(Pii(nx, ny));
                            flag[nx][ny] = 1;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
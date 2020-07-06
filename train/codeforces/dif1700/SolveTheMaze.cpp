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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve(){
    int n, m; cin >> n >> m;
    vector<string> lis(n);
    vector<Pii> pos;
    REP(i, 0, n){
        cin >> lis[i];
        REP(l, 0, m){
            if(lis[i][l] == 'G'){
                pos.pb(Pii(i, l));
            }
        }
    }
    REP(i, 0, n){
        REP(l, 0, m){
            if(lis[i][l] == 'B'){
                REP(k, 0, 4){
                    int nx = i + dx[k], ny = l + dy[k];
                    //cout << nx << ny << endl;
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                        if(lis[nx][ny] == 'B' || lis[nx][ny] == '#'){
                            continue;
                        }else if(lis[nx][ny] == 'G'){
                            cout << "No" << endl;
                            return;
                        }else{
                            //cout << nx <<ny << endl;
                            lis[nx].replace(ny, 1, "#");
                        }
                    }
                }
            }
        }
    }
    if(pos.size() == 0){
        cout << "Yes" << endl;
        return;
    }
    /*REP(i, 0, n){
        REP(l, 0, m){
            cout << lis[i][l];
        }
        cout << endl;
    }*/
        int sx = n-1, sy = m-1;
        vector<vector<int> > flag(n, vector<int>(m, 0));
        flag[sx][sy] = 1;
        if(lis[sx][sy] == '#'){
            cout << "No" << endl;
            return;
        }
        stack<Pii> st;
        st.push(Pii(sx, sy));
        int count = 0;
        while(!st.empty()){
            int x = st.top().first, y = st.top().second;
            if(lis[x][y] == 'G'){
                count++;
            }
            //cout << x << y << endl;
            st.pop();
            REP(l, 0, 4){
                int nx = x + dx[l], ny = y + dy[l];
                //cout << nx << ny << endl;
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && flag[nx][ny] == 0 && (lis[nx][ny] == '.' || lis[nx][ny] == 'G')){
                    flag[nx][ny] = 1;
                    st.push(Pii(nx, ny));
                }
            }
        }
    if(count == pos.size()){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
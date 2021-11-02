// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

//ordered_set 重複不可
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use set_function + find_by_order(select itr-num)

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}

template <class T>
inline vector<T> make_vec(size_t a, T val) {
    return vector<T>(a, val);
}
template <class... Ts>
inline auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec(ts...))>(a, make_vec(ts...));
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

void calc_pos(vector<vector<int> > &grid, vector<Pii> &pos, int num, vector<vector<ll> > &dist){
    int h = grid.size(), w = grid[0].size();
    vector<vector<ll> > grid_num(h, vector<ll>(w, 1e12));
    int x = pos[num].first, y = pos[num].second;
    grid_num[x][y] = 0;
    queue<Pii> que;
    que.push(pos[num]);
    while(!que.empty()){
        Pii a = que.front();
        que.pop();
        int nowx = a.first, nowy = a.second;
        REP(i,0,4){
            int nextx = nowx + dx[i], nexty = nowy + dy[i];
            if(nextx < h && nexty < w && nextx >= 0 && nexty >= 0 && grid[nextx][nexty] != -1){
                if(chmin(grid_num[nextx][nexty], grid_num[nowx][nowy] + 1)){
                    que.push(Pii(nextx, nexty));
                }
            }
        }
    }
    REP(i,0,pos.size()){
        if(i == num)
            continue;
        dist[i][num] = grid_num[pos[i].first][pos[i].second];
        dist[num][i] = grid_num[pos[i].first][pos[i].second];
    }
    return;
}

int main(){
    int w;
    while(cin >> w){
        int h; cin >> h;
        if(h == 0 && w == 0){
            break;
        }
        vector<string> sgrid(h);
        REP(i,0,h){cin >> sgrid[i];}
        vector<vector<int> > grid(h, vector<int>(w, 0));
        vector<Pii> pos;
        int sx, sy;
        int count = 0;
        REP(i,0,h){
            REP(l,0,w){
                if(sgrid[i][l] == '*'){
                    pos.pb(Pii(i, l));
                    grid[i][l] = count;
                    count++;
                }
                if(sgrid[i][l] == 'x'){
                    grid[i][l] = -1;
                }
                if(sgrid[i][l] == 'o'){
                    sx = i;
                    sy = l;
                }
            }
        }
        pos.pb(Pii(sx, sy));
        grid[sx][sy] = count;
        vector<vector<ll> > dist(pos.size(), vector<ll>(pos.size(), 1e12));
        REP(i,0,pos.size()){
            calc_pos(grid, pos, i, dist);
        }
        /*
        REP(i,0,pos.size()){
            REP(l,0,pos.size()){
                cout << dist[i][l] << " ";
            }
            cout << endl;
        }
        */
        vector<int> idx(pos.size()-1);
        iota(ALL(idx), 0);
        ll ans = 1e12;
        do{
            ll mid = dist[pos.size()-1][idx[0]];
            REP(i,1,idx.size()){
                mid += dist[idx[i-1]][idx[i]];
            }
            chmin(ans, mid);
        }while(next_permutation(ALL(idx)));
        if(ans >= 1e12)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}
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


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[2] = {-1, 0};
int dy[2] = {0, -1};


//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

int main(){
    int h, w; cin >> h >> w;
    vector<string> grid(h);
    REP(i,0,h){cin >> grid[i];}
    queue<Pii> que;
    que.push(Pii(h-1, w-1));
    vector<vector<int> > gridflag(h, vector<int>(w, 0));
    vector<vector<Pii> > score(h, vector<Pii>(w));
    gridflag[h-1][w-1] = 1;

    int kk;
    if(grid[h-1][w-1] == '-'){
        kk = -1;
    }else{
        kk = 1;
    }
    if((h+w-2) % 2 == 0){
        score[h-1][w-1] = Pii(0, kk);
    }else{
        score[h-1][w-1] = Pii(kk, 0);
    }
    while(!que.empty()){
        Pii now = que.front();
        que.pop();
        int nx = now.first, ny = now.second;
        int kk;
        if(grid[nx][ny] == '-'){
            kk = -1;
        }else{
            kk = 1;
        }
        if(!(nx == h-1 && ny == w-1)){
            if((nx + ny) % 2 == 0){ //Tのターン
                int mid = -1e9;
                Pii k = Pii(0, 0);
                REP(i,0,2){
                    int x = nx + -1*dx[i], y = ny + -1*dy[i];
                    if(x >= 0 && x < h && y >= 0 && y < w){
                        if(chmax(mid, score[x][y].first - score[x][y].second)){
                            k = score[x][y];
                        }
                    }
                }
                score[nx][ny] = k;
                score[nx][ny].second += kk;
            }else{//Tのターン
                int mid = -1e9;
                Pii k = Pii(0, 0);
                REP(i,0,2){
                    int x = nx + -1*dx[i], y = ny + -1*dy[i];
                    if(x >= 0 && x < h && y >= 0 && y < w){
                        if(chmax(mid, score[x][y].second - score[x][y].first)){
                            k = score[x][y];
                        }
                    }
                }
                score[nx][ny] = k;
                score[nx][ny].first += kk;
            }
        }
        REP(i,0,2){
            int nex = nx + dx[i], ney = ny + dy[i];
            if(nex >= 0 && nex < h && ney >= 0 && ney < w && gridflag[nex][ney] == 0){ //OK
                que.push(Pii(nex, ney));
                gridflag[nex][ney] = 1;
            }
        }
    }
    /*
    REP(i,0,h){
        REP(l,0,w){
            cout << score[i][l].first << " " << score[i][l].second <<  "   ";
        }
        cout << endl;
    }
    */

    int xx = 0, yy = 0;
    int mid = -1e9;
    Pii k = Pii(0,0);
    REP(i,0,2){
        int x = xx + -1*dx[i], y = yy + -1*dy[i];
        if(x >= 0 && x < h && y >= 0 && y < w){
            if(chmax(mid, score[x][y].first - score[x][y].second)){
                k = score[x][y];
            }
        }
    }   
    if(mid == -1e9){
        cout << "Draw" << endl;
        return 0;
    }
    if(mid > 0){
        cout << "Takahashi" << endl;
    }else if(mid == 0){
        cout << "Draw" << endl;
    }else{
        cout << "Aoki" << endl;
    }
}
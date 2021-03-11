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

int n, s;

vector<vector<int> > ans;

void solve(int num, vector<int> lis, int idx){
    if(idx == -1){
        if(num == 0){
            ans.pb(lis);
            return;
        }
        return;
    }
    int pre = 1e9;
    if(idx != n-1){
        pre = lis[idx+1];
    }
    REP(i, 0, num+1){
        vector<int> cp = lis;
        cp[idx] += i;
        if(cp[idx] > pre){
            break;
        }
        solve(num-i, cp, idx-1);
    }
    return;
}

int main(){
    cin >> n >> s;
    int k = s - n;
    vector<int> lis(n, 1);
    solve(k, lis, n-1);
    if(n >= 50);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[49] < beta[49];});
    if(n >= 49);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[48] < beta[48];});
    if(n >= 48);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[47] < beta[47];});
    if(n >= 47);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[46] < beta[46];});
    if(n >= 46);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[45] < beta[45];});
    if(n >= 45);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[44] < beta[44];});
    if(n >= 44);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[43] < beta[43];});
    if(n >= 43);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[42] < beta[42];});
    if(n >= 42);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[41] < beta[41];});
    if(n >= 41);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[40] < beta[40];});
    if(n >= 40);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[39] < beta[39];});
    if(n >= 39);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[38] < beta[38];});
    if(n >= 38);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[37] < beta[37];});
    if(n >= 37);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[36] < beta[36];});
    if(n >= 36);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[35] < beta[35];});
    if(n >= 35);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[34] < beta[34];});
    if(n >= 34);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[33] < beta[33];});
    if(n >= 33);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[32] < beta[32];});
    if(n >= 32);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[31] < beta[31];});
    if(n >= 31);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[30] < beta[30];});
    if(n >= 30);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[29] < beta[29];});
    if(n >= 29);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[28] < beta[28];});
    if(n >= 28);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[27] < beta[27];});
    if(n >= 27);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[26] < beta[26];});
    if(n >= 26);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[25] < beta[25];});
    if(n >= 25);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[24] < beta[24];});
    if(n >= 24);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[23] < beta[23];});
    if(n >= 23);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[22] < beta[22];});
    if(n >= 22);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[21] < beta[21];});
    if(n >= 21);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[20] < beta[20];});
    if(n >= 20);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[19] < beta[19];});
    if(n >= 19);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[18] < beta[18];});
    if(n >= 18);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[17] < beta[17];});
    if(n >= 17);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[16] < beta[16];});
    if(n >= 16);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[15] < beta[15];});
    if(n >= 15);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[14] < beta[14];});
    if(n >= 14);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[13] < beta[13];});
    if(n >= 13);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[12] < beta[12];});
    if(n >= 12);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[11] < beta[11];});
    if(n >= 11);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[10] < beta[10];});
    if(n >= 10);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[9] < beta[9];});
    if(n >= 9);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[8] < beta[8];});
    if(n >= 8);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[7] < beta[7];});
    if(n >= 7);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[6] < beta[6];});
    if(n >= 6);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[5] < beta[5];});
    if(n >= 5);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[4] < beta[4];});
    if(n >= 4);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[3] < beta[3];});
    if(n >= 3);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[2] < beta[2];});
    if(n >= 2);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[1] < beta[1];});
    if(n >= 1);
    sort(ans.begin(),ans.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[0] < beta[0];});

    REP(i, 0, ans.size()){
        REP(l, 0, ans[i].size()){
            cout << ans[i][l] << " ";
        }
        cout << endl;
    }
}
#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<vector<int> > lis;
int n, k;
int flag = 0;

void solve(int x, int y, int num){
    if(x == n){
        if(num == 0){
            flag = 1;
        }
        return;
    }
    if(num == 0){
        num = lis[x][y];
    }else{
        num = num ^ lis[x][y];
    }
    REP(i, 0, k){
        solve(x+1, i, num);
    }
    return;
}

int main(){
    cin >> n >> k;
    lis = vector<vector<int>>(n, vector<int>(k));
    REP(i, 0, n){
        REP(l, 0, k){
            cin >> lis[i][l];
        }
    }
    REP(i, 0, k){
        solve(0, i, 0);
    }
    if(flag == 1){
        cout << "Found" << endl;
    }else{
        cout << "Nothing" << endl;
    }
}
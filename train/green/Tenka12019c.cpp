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

int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int> > lis(s.size()+2, vector<int>(2, 0));
    REP(i, 0, s.size()){
        if(s[i] == '.'){
            lis[i+1][0] = lis[i][0]+1;
            lis[i+1][1] = lis[i][1];
        }else{
            lis[i+1][0] = lis[i][0];
            lis[i+1][1] = lis[i][1]+1;
        }
    }
    lis[s.size()+1] = lis[s.size()];
    int ans = 1e9;
    REP(i, 0, s.size()+1){
        int mid = lis[i][1] + (lis[s.size()+1][0] - lis[i][0]);
        ans = min(ans, mid);
    }
    cout << ans << endl;
}
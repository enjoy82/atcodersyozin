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
    vector<int> lis(3);
    REP(i, 0, 3){
        cin >> lis[i];
        if(lis[i] == n){
            cout << "NO" << endl;
            return 0;
        }
    }
    sort(ALL(lis));
    int c = 0;
    int x = 0;
    while(c < n){
        if(c+3 != lis[0] && c+3 != lis[1] && c+3 != lis[2]){
            c += 3;
        }else if(c+2 != lis[0] && c+2 != lis[1] && c+2 != lis[2]){
            c += 2;
        }else if(c+1 != lis[0] && c+1 != lis[1] && c+1 != lis[2]){
            c += 1;
        }else{
            cout << "NO" << endl;
            return 0;
        }
        x++;
    }
    if(x <= 100){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
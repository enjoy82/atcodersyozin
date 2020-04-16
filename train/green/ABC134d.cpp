#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb puah_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n; cin >> n; 
    vector<int> lis(n+1), anslis(n+1, 0);
    REP(i, 1, n+1){cin >> lis[i];}
    for(int i = n; i >= 1; i--){
        int k = 0;
        int c = 2 * i;
        while(c < n+1){
            if(anslis[c] == 1){
                k++;
            }
            c += i;
        }
        k %= 2;
        if(lis[i] == 1){
            if(k == 1){
                anslis[i] = 0;
            }else{
                anslis[i] = 1;
            }
        }else{
            if(k == 1){
                anslis[i] = 1;
            }else{
                anslis[i] = 0;
            }
        }
    }
    int m = 0;
    REP(i, 1, n+1){
        if(anslis[i] == 1) m++;
    }
    cout << m << endl;
    REP(i, 1, n+1){
        if(anslis[i] == 1){
            cout << i << " ";
        }
    }
}
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

char In[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main(){
    vector<char> strong(10);
    REP(i, 0, 10){cin >> strong[i];}
    int n; cin >> n;
    vector<string> lis(n);
    vector<vector<int> > flag(1000, vector<int>(1000, 0));
    REP(i, 0, n){cin >> lis[i];}
    REP(i, 0, 10){
        REP(l, 0, lis.size()){
            REP(k, 0, lis[l].size()){
                if(lis[l][k] == strong[i] && flag[l][k] == 0){
                    lis[l][k] = In[i];
                    flag[l][k] = 1;
                }
            }
        }
    }
    vector<int> chlis(n);
    REP(i, 0, n){
        chlis[i] = atoi(lis[i].c_str());
    }
    sort(ALL(chlis));
    REP(i, 0, n){
        lis[i] = to_string(chlis[i]);
    }
    vector<vector<int> > flag2(1000, vector<int>(1000, 0));
    REP(i, 1, 10){
        REP(l, 0, lis.size()){
            REP(k, 0, lis[l].size()){
                if(lis[l][k] == In[i] && flag2[l][k] == 0){
                    lis[l][k] = strong[i];
                    flag2[l][k] = 1;
                }
            }
        }
    }
    REP(i, 0, n){
        cout << lis[i] << endl;
    }
}
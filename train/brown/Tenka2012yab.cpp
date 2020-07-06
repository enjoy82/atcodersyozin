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

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    string s;
    getline(cin, s);
    vector<string> lis;
    string a = "";
    REP(i, 0, s.size()){
        while(i < s.size() && s[i] != ' '){
            a = a + s[i];
            i++;
        }
        lis.pb(a);
        a = "";
    }
    int num = lis.size();
    int n; cin >> n;
    vector<string> ng(n);
    REP(i, 0, n){
        cin >> ng[i];
    }
    int ans = 0;
    REP(i, 0, num){
        REP(l, 0, n){
            if(ng[l].size() == lis[i].size()){
                int kk = 1;
                REP(k, 0, ng[l].size()){
                    if(ng[l][k] == '*'){
                        continue;
                    }else if(ng[l][k] != lis[i][k]){
                        kk = 0;
                        break;
                    }
                }
                if(kk){
                    REP(k, 0, lis[i].size()){
                        lis[i][k] = '*';
                    }
                }
            }
        }
    }
    REP(i, 0, lis.size()){
        cout << lis[i] << " ";
    }
    cout << endl;
}
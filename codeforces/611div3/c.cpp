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


int main(){
    int n; cin >> n;
    int count = 0;
    vector<int> lis(n, 0), flag(n, 0);
    REP(i, 0, n){cin >> lis[i]; flag[(lis[i]-1)] = 1;}
    queue<int> q;
    int mid = 0;
    int f = 0;
    REP(i, 0, n){
        if(lis[i] == 0){f = 1;}
        if(lis[i] == 0 && flag[i] == 0){
            count++;
            flag[i] = -1;
            lis[i] = -1;
            q.push(i);
            mid = i;
        }
    }
    if(count == 1){
        int cc;
        REP(i, 0, n){
            if(flag[i] == 0){
                cc = i;
            }
        }
        REP(i, 0, n){
            if(lis[i] > 0){
                cout << lis[i] << " ";
            }else if(lis[i] == 0){
                cout << mid+1 << " ";
            }else{
                cout << cc+1 << " ";
            }
        }
        return 0;
    }else if(count == 0 && f == 0){
        REP(i, 0, n){
            cout << lis[i] << " ";
        }
        return 0;
    }else{
        if(count != 0){
            int c = q.front();
            q.push(c);
            q.pop();
        }
        int r = 0;
        REP(i, 0, n){
            if(lis[i] > 0){
                cout << lis[i] << " ";
            }else if(lis[i] == 0){
                while(r < n && flag[r] != 0){
                    r++;
                }
                flag[r]++;
                cout << r+1 << " ";
            }else{
                cout << q.front()+1 << " ";
                q.pop();
            }
        }
    }
    return 0;
}
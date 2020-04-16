#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb puah_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
     int n; cin >> n;
     vector<int> lis(n);
     REP(i, 0, n){cin >> lis[i];}
     sort(ALL(lis));
     ll ans = 0;
     for(int i = n-1; i >= 2; i--){
         for(int l = i - 1; l >= 1; l--){
             int a = lis[i], b = lis[l];
             int rr = lis[0], ll = lis[l-1];
             //cout << rr << ll << endl;
             while(ll - rr != 0){
                 int c = (ll + rr) / 2;
                 if(a < b + c){
                     if(ll == c){break;}
                     ll = c;
                 }else{
                     if(rr == c){break;}
                     rr = c;
                 }
                 if(rr > ll){
                     int x = rr; rr = ll; ll = x;
                 }
             }
             //cout << ll << rr << endl;
             int check;
             if(a < b + ll){
                 check = ll;
             }else{
                 check = rr;
             }
             if(!(a < b + check)){continue;}
             //cout << check << endl;
            auto it = lower_bound(ALL(lis), check);
            //cout << a << b << "check" <<  check << "num" << it - lis.begin()<< endl;
            ans += l -  (it - lis.begin());
         }
     }
     cout << ans << endl;
}
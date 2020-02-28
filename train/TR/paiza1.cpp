#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int t, b, u, d, l, r, n; cin >> t >> b >> u >> d >> l >> r >> n;
    int lis[n];
    for(int i =  0; i < n; i++){
        cin >> lis[i];
    }
    int now = t;
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(now == t){
            if(lis[i] == t){
                continue;
            }else if(lis[i] == b){
                ans += 2;
                now = b;
            }else{
                ans++;
                now = lis[i];
            }
        }else if(now == b){
            if(lis[i] == t){
                continue;
            }else if(lis[i] == t){
                ans += 2;
                now = t;
            }else{
                ans++;
                now = lis[i];
            }
        }else if(now == u){
            if(lis[i] == t){
                continue;
            }else if(lis[i] == d){
                ans += 2;
                now = d;
            }else{
                ans++;
                now = lis[i];
            }
        }else if(now == d){
            if(lis[i] == t){
                continue;
            }else if(lis[i] == u){
                ans += 2;
                now = u;
            }else{
                ans++;
                now = lis[i];
            }
        }else if(now == r){
            if(lis[i] == t){
                continue;
            }else if(lis[i] == l){
                ans += 2;
                now = l;
            }else{
                ans++;
                now = lis[i];
            }
        }else if(now == l){
            if(lis[i] == t){
                continue;
            }else if(lis[i] == r){
                ans += 2;
                now = r;
            }else{
                ans++;
                now = lis[i];
            }
        }
    }
    cout << ans << endl;
}
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int a, b; cin >> a >> b;
    int ans = 0;
    if(a == 1 && b == 1){
        ans += 400000;
    }
        if(a == 1){
            ans += 300000;
        }else if(a == 2){
            ans += 200000;
        }else if(a == 3){
            ans += 100000;
        }
        if(b == 1){
            ans += 300000;
        }else if(b == 2){
            ans += 200000;
        }else if(b == 3){
            ans += 100000;
        }
    cout << ans << endl;
    return 0;
}
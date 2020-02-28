#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int a,b,c; cin >> a >> b;
    int ans = 1;
    c = a;
    if(b == 1){cout << 0 << endl; return 0;}
    while(1){
        if(c >= b){
            break;
        }
        c += a-1;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int a, b, c; cin >> a >> b >> c;
    int d = max(a, b);
    int ans = 1;
    int e = d;
    while(1){
        if(c <= e){break;}
        e += d;
        ans++;
    }
    cout << ans << endl;
}
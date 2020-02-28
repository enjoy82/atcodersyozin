#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int h, a; cin >> h >> a;
    int ans = 0;
    while(h > 0){
        h -= a;
        ans++;
    }
    cout << ans << endl;
}
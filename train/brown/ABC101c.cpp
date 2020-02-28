#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        int mid; cin >> mid;
    }
    int ans = 1;
    n -= k;
    while(1){
        if(n <= 0) break;
        n -= (k-1);
        ans++;
    }
    cout << ans << endl;
}
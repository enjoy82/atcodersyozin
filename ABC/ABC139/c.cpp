#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    int ans = 0;
    int b = 0;
    int c = 0;
    for(int i = 0; i < n; i++){
        int mid; cin >> mid;
        if(mid <= c){
            b++;
        }else{
            ans = max(ans, b);
            b = 0;
        }
        c = mid;
    }
    ans = max(ans, b);
    cout << ans << endl;
}
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n, ans, a, b; cin >> n >> ans;
    a =  ans;
    for(int i = 0; i < n-2; i++){
        cin >> b;
        ans += min(a, b);
        a = b;
    }
    cout << ans+a << endl;
    return 0;
}
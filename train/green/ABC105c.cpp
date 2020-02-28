#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    string ans = "";
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
    while(n != 0){
        if(n % 2 != 0){
            n -= 1;
            ans = "1" + ans;
        }else{
            ans = "0" + ans;
        }
        n = n / (-2);
    }
    cout << ans << endl;
}
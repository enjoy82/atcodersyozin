#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    string a, b;cin >> a >> b;
    int ans = 0;
    for(int i = 0; i < 3; i++){
        if(a[i] == b[i]){
            ans++;
        }
    }
    cout << ans << endl;
}
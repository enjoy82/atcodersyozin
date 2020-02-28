#include<bits/stdc++.h>
using namespace std;

int main(){
    int a; cin >> a;
    int ans = 0;
    for(int i = 1; i <= a; i++){
        int b = i;
        int keta = 0;
        while(b!=0){
            b /= 10;
            keta++;
        }
        if(keta%2 == 1){
            ans++;
        }
    }
    cout << ans << endl;
}
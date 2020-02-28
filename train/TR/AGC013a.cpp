#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    int j = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int pre = a[0];
    for(int i = 1; i < n; i++){
        if(j == 0){
            if(pre < a[i]){
                j = 1;
            }else if(pre > a[i]){
                j = 2;
            }
        }else if(j == 1){
            if(pre == a[i]){
                j = 1;
            }else if(pre < a[i]){
                j = 1;
            }else if(pre > a[i]){
                j = 0;
                ans++;
            }
        }else if(j == 2){
            if(pre == a[i]){
                j = 2;
            }else if(pre < a[i]){
                j = 0;
                ans++;
            }else if(pre > a[i]){
                j = 2;
            }
        }
        pre = a[i];
    }
    cout << ans+1 << endl;
}
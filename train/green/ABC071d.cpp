#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define div 1000000007

int main(){
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    int f = 0;
    ll ans;
    for(int i  = 0; i < n; i++){
        if(s1[i] == s2[i]){
            if(f == 0){
                ans = 3;
            }else if(f == 1){
                ans = (ans * 2) % div;
            }else if(f == 2){
                //
            }
            f = 1;
        }else if(s1[i] == s1[i+1]){
            if(f == 0){
                ans = 6;
            }else if(f == 1){
                ans  = (ans *2) % div;
            }else if(f == 2){
                ans = (ans * 3) % div;
            }
            f = 2;
            i++;
        }
        //cout  << i << " " << f << " " << ans << endl;
    }
    cout << ans << endl;
}
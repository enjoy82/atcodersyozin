#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    string s, ans = ""; cin >> s;
    int a = 0, b = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            a++;
            ans = ans + '(';
        }else{
            b++;
            ans = ans + ')';
            if(b > a){
                ans = '(' + ans;
                a++;
            }
        }
    }
    for(int i = 0; i < max(0, a-b); i++){
        ans = ans + ')';
    }
    cout << ans << endl;
}
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    string s; cin >> s;
    if(s[0] == s[1] && s[1]  == s[2]){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}
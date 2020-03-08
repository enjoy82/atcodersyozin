#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main(){
    string s; cin >> s;
    if(s.size() % 2 == 1){
        cout << "No" << endl;
        return 0;
    }else{
        for(int i = 0; i < s.size(); i+=2){
            if(s[i] == 'h' && s[i+1] == 'i'){
                continue;
            }else{
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
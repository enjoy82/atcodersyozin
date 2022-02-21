#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    string s; cin >> s;
    int g = 0, p = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'g'){
            g++;
        }else{
            p++;
        }
    }
    int ap = s.size() / 2;
    int ag = s.size() - ap;
    cout << min(g, ap) - min(p, ag) << endl;
}
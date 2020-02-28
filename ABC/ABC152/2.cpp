#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int a, b; cin >> a >> b;
    string c = "", d = "", e, f;
    e = to_string(a);
    f = to_string(b);
    for(int i = 0; i < b; i++){
        c = c + e;
    }
    for(int i = 0; i < a; i++){
        d = d + f;
    }
    if(c > d){
        cout << d << endl;
    }else{
        cout << c << endl;
    }
}
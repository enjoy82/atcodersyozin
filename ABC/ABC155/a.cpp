#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int a, b, c; cin >> a >> b >> c;
    if(a == b && b != c){
        cout << "Yes" << endl;
    }else if(b == c && b != a){
        cout << "Yes" << endl;
    }else if(a == c && b != c){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
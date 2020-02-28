#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    string a; cin >> a;
    int b = 0, c = 0, f = 0;
    char pre = '2';
    for(int i = 0; i < a.size(); i++){
        if(a[i] == '0'){
            if(pre == '1'){f = 1;}
            b++; pre = '0';
        }
        else{
            if(pre = '0'){f = 1;}
            c++; pre = '1';
        }
    }
    if(f == 0){
        cout << 0 << endl;
    }else{
        cout << a.size() - abs(b-c) << endl;
    }
}
#include<iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int max = 0;
    int min = 100001;
    for(int i=0; i<m; i++){
        int a, b;cin >> a >> b;
        if(a > max){max = a;}
        if(b < min){min = b;}
    }
    if(min < max){
        cout << 0 << endl;
    }else{
        cout << min-max+1 << endl;
    }
}
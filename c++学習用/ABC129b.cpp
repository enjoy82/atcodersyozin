#include<iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int w[n+1];
    for(int i = 0; i < n; i++){
        int mid;cin >> mid;
        w[mid] = w[mid] + 1;
    }
    int ans = 1000;
    for(int l = 1; l < n+1; l++){
        int a = 0;
        int b = 0;
        for(int m = 1; m < l; m++){
            a = a + m*w[m];
            b = b + (n-m)*w[n-m]
        }
    int sub = b - a;
    if(ans > b-a)
    }
}
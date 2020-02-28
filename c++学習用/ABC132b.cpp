#include<iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;cin >> n;
    int p[n];
    for(int i = 0; i<n; i++){
        cin >>p[i];
    }
    int count = 0;
    for(int l = 0; l < n-2;l++){
        if(p[l] > p[l+1] && p[l+1] > p[l+2]){
            count++;
        }
        if(p[l] < p[l+1] && p[l+1] < p[l+2]){
            count++;
        }
    } 
    cout << count << endl;
}
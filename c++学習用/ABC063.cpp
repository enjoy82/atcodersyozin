#include<bits/stdc++.h>
using namespace std;

int main(){
   int n, a, b;cin >> n >> a >> b;
   vector<int> alis(n);
   for(int i =0; i<n; i++){
       cin >> alis[i];
   }
   int count = 0;
   while(true){
        int maxi;
        int max = 0;
        for(int l=0; l<n; l++){
            if(max < alis[l]){
                max = alis[l];maxi = l;
            }
        }
        int jcou = 0;
        for(int i=0; i<n;i++){
            if(i == maxi){
                alis[i] -=a;
                if(alis[i] <= 0){
                    jcou++;
                }
            }
            else{
                alis[i] -= b;
                if(alis[i] <= 0){
                    jcou++;
                }
            }
        }
        count++;
        if(jcou == n){break;}
    }
    cout << count << endl;
}
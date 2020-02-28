#include<iostream>
#include <algorithm>
#include<string>
#include <stdio.h>
using namespace std;
int ctoi(char c) {
	switch (c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}

int main(){
    string a;cin >> a;
    while(a[0] != '0'){
        int list[5001];
        int size = a.length();
        for(int i = 0;i < size; i++){
            list[i] = ctoi(a[i]);
        }
        long long int dp[5001] = {0} ;
        dp[0] = 1;
        if(list[0]*10 + list[1] < 27 && list[1] != 0){
            dp[1] = 2;
        }else{
            dp[1] = 1;
        }
        for(int l = 2; l<size; l++){
            if(list[l] == 0){
                dp[l] = dp[l-2];dp[l-1] = dp[l-2];
            }else if(list[l-1]*10+list[l] < 27 && list[l]!=0 && list[l-1]!=0){
                dp[l] = dp[l-1] + dp[l-2];
            }else{
                dp[l] = dp[l-1];
            }
        }
        cout << dp[size-1] << endl;
        cin >> a;
    }
    return 0;
}
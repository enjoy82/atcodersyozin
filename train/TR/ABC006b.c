#include <stdio.h>
int a[1000000];
int n,i;
int main (void){
	scanf("%d", &n);
	a[0] = 0;a[1] = 0;a[2] = 1;
	for(i = 3; i < n; i++){
		a[i] = (a[i-1] + a[i-2] + a[i -3])%10007;
	}
	printf("%d", a[n-1]);
}
	
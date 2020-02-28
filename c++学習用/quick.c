#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

static void iswap(int *a, int i, int j) {
  int x = a[i]; a[i] = a[j]; a[j] = x;
}
void qs(int *a, int i, int j) {
  if(j <= i) { return; }
  int p = rand()%(j-i)+i;
  int s = i, pivot = a[p];
  iswap(a, p, j);
  for(int k = i; k < j; ++k) {
    if(a[k] < pivot) { iswap(a, s++, k); }
  }
  iswap(a, j, s); 
  qs(a, i, s-1); qs(a, s+1, j);
}
void quicksort(int *a, int n) { qs(a, 0, n-1); }

void expect_sort_iarray(int n, void (*f)(int *a, int n), char *msg) {
  int c = 0, *a = (int*)malloc(n * sizeof(int));
  srand(time(NULL));
  for(int i = 0; i < n; ++i) { a[i] = rand()%10000; }
  struct timespec tm1, tm2;
  clock_gettime(CLOCK_REALTIME, &tm1);
  (*f)(a, n);
  clock_gettime(CLOCK_REALTIME, &tm2);
  for(int i = 1; i < n; ++i) {
    if(a[i-1] <= a[i]) { continue; } // correct order
    if(++c < 5) {
      printf("  wrong order at %d: %d > %d\n", i-1, a[i-1], a[i]);
    } else if(c == 5) {
      printf("  more wrong place omitted.\n");
    }
  }
  double dt = (tm2.tv_sec-tm1.tv_sec) + 1e-9*(tm2.tv_nsec-tm1.tv_nsec);
 // for(int i =0; i<n; i++){printf("%d ",a[i]);}
  printf("%s time=%.4f %s\n", c==0?"OK":"NG", dt, msg); free(a);
}

void expect_sort_iarray2(int n, void (*f)(int *a, int n), char *msg) {
  int c = 0, *a = (int*)malloc(n * sizeof(int));
  srand(time(NULL));
  for(int i = 0; i < n; ++i) { a[i] = i; }
  struct timespec tm1, tm2;
  clock_gettime(CLOCK_REALTIME, &tm1);
  (*f)(a, n);
  clock_gettime(CLOCK_REALTIME, &tm2);
  for(int i = 1; i < n; ++i) {
    if(a[i-1] <= a[i]) { continue; } // correct order
    if(++c < 5) {
      printf("  wrong order at %d: %d > %d\n", i-1, a[i-1], a[i]);
    } else if(c == 5) {
      printf("  more wrong place omitted.\n");
    }
  }
  double dt = (tm2.tv_sec-tm1.tv_sec) + 1e-9*(tm2.tv_nsec-tm1.tv_nsec);
  //for(int i =0; i<n; i++){printf("%d ",a[i]);}
  printf("%s time=%.4f %s\n", c==0?"OK":"NG", dt, msg); free(a);
}

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  expect_sort_iarray(n, quicksort, "quicksort");
  expect_sort_iarray2(n, quicksort, "quicksort2");
  return 0;
}
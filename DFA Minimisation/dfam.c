#include <stdio.h>

 struct node {
  int a, b, f, flag;
 }a[10];

 int n, j, i, k, l, m, c, ch;
 void replace(int x, int y) {
  for (i = 0; i < n; i++) {
    if (a[i].flag == 1) {
      if (a[i].a == y)
        a[i].a = x;
      if (a[i].b == y)
        a[i].b = x;
    }
  }
 }
 void minimize() {
  do {
    ch = 0;
 for (i = 0; i < n; i++) {
      if (a[i].flag == 1) {
        k = a[i].a;
        l = a[i].b;
        m = a[i].f;
        for (j = i + 1; j < n; j++) {
          if (a[j].flag == 1) {
            if (a[j].a == k && a[j].b == l && a[j].f == m) {
              a[j].flag = 0;
              replace(i, j);
              ch = 1;
            }
          }
        }
      }
    }
  } while (ch == 1);
 }
 void unreachable() {
  do {
    ch = 0;
    for (i = 1; i < n; i++) {
      if (a[i].flag == 1) {
        c = 0;
        for (j = 0; j < n; j++) {
          if (i != j && a[j].flag == 1) {
            if (a[j].a == i || a[j].b == i) {
              c = 1;
              break;
            }
          }
        }
        if (c == 0) {
          a[i].flag = 0;
          ch = 1;
        }
      }
    }
  } while (ch == 1);
 }
 int main() {
  printf("Enter the no of states:");
  scanf("%d", & n);
  printf("\n Enter the transition table for DFA\nState\ta\tb\n");
  for (i = 0; i < n; i++) {
    scanf("%d%d%d", & j, & k, & l);
    a[j].a = k;
    a[j].b = l;
    a[j].flag = 1;
    a[j].f = 0; // is a final state or not
  }
  printf("\nEnter the no of Final states:");
  scanf("%d", & m);
  printf("Enter the final states:");
  for (i = 0; i < m; i++) {
    scanf("%d", & j);
    a[j].f = 1;
  }
  unreachable();
  minimize();
  printf("\nMinimized DFA\n");
  printf("State\ta\tb\n");
  for (i = 0; i < n; i++) {
    if (a[i].flag == 1)
      printf("%d\t%d\t%d\n", i, a[i].a, a[i].b);
  }

    return 0;
}  
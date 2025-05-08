 #include <stdlib.h>

 int *f1() {
 int *ip = malloc(sizeof(int));

 *ip = 3;
 return ip;
 }

 int f2() {
 int *internal = f1();

 return *internal;
 }

 int main() {
 int i = f2();
 return i;
 }
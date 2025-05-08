 #include <stdlib.h>

 int *f1() {
 int *ip = malloc(sizeof(int));

 *ip = 3;
 return ip;
 }

 int f2() {
 int *internal = f1();

 int left = internal[0];
 int right = internal[2];
 free(internal);

 return left + right / 2;
 }
 int main() {
 int i = f2();
 return i;
 }
/*Uninitialized Values Sample Program*/
 #include <stdlib.h>

 int *f1() {
 int *ip = malloc(sizeof(int));

 return ip;
 }

 int f2() {
 int *internal = f1();
 int other = 3;

 if(*internal < 5) {
 other = *internal;
 }

 free(internal);

 return other;
 }

 int main() {
 int i = f2();
 return i;
 }
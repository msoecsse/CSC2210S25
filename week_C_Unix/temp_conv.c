#include <stdio.h>
#include <stdlib.h>
int main(void)
{
int fahrenheit, celsius;
printf("Fahrenheit -> Celsius\n\n");
fahrenheit = 0;
while(fahrenheit <= 100)
{
celsius = (fahrenheit-32)*5/9;
printf("%3d %3d\n", fahrenheit, celsius);
fahrenheit = fahrenheit + 10;
}
return EXIT_SUCCESS;
}

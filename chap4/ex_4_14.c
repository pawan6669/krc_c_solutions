/***************
  * Program to swap two variables taking type.
  *
  *
  *
  ***************/

#include<stdio.h>

#define swap(t,x,y)  do {t  t##swap##x##y; t##swap##x##y = x; x = y; y = t##swap##x##y;} while(0);


int main() {
int x = 10, y =15;
	
printf("The values x:%d, y=%d \n",x,y);
swap(double,x,y);
printf("The values x:%d, y=%d \n",x,y);
int z=100;
for (int sleep=0;sleep<100;sleep++)
		;
printf("The values of z:%d \n",z);
}

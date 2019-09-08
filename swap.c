#include <stdio.h>


void swap_two_number(int *xp, int *yp) {
	if (xp == yp)
		return;
	*xp = *xp ^ *yp;
	*yp = *xp ^ *yp;
	*xp = *xp ^ *yp;
}


void swap_three_number(int *xp, int *yp, int *zp) {
	*xp = *xp ^ *yp ^ *zp; 
	*yp = *xp ^ *yp ^ *zp;
	*zp = *xp ^ *yp ^ *zp;
	*xp = *xp ^ *yp ^ *zp;
}

int main(int argc, char const *argv[])
{
	int a = 10, b = 20;
	printf("Before swap | a = %d, b = %d \n",a, b);
	swap_two_number(&a, &b);
	printf("After swap | a = %d, b = %d \n",a, b);

	int x = 1, y = 2, z = 3;
	printf("Before swap | x = %d, y = %d, z = %d\n",x, y, z);
	swap_three_number(&x, &y, &z);
	printf("After swap | x = %d, y = %d, z = %d\n",x, y, z);
	return 0;
}
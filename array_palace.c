#include <stdio.h>

int M = 5;
int N = 3;

void print_array(int n, int m, int a[][m]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("\n");
}

void print_array_v1(int n, int a[][M]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < M; j++)
			printf("%ld ", (char*)&a[i][j]);
		printf("\n");
	}
	printf("\n");
}

void print_array_v2(int a[N][M]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("(%ld) ", (char*)&a[i][j]);
			printf("%d ",a[i][j] );
		}
		printf("\n");
	}
	printf("\n");
}


void print_array_v3(int *a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("(%ld) ", (char*)((a+i*m) + j));
			printf("%d ", *((a+i*m) + j));
		}
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int a[][5] = {
					{1,12,3,4,5},
					{11,12,13,14,15},
					{21,22,23,24,25}
				};
	print_array(3, 5, a);
	print_array_v1(3,a);
	print_array_v2(a);
	print_array_v3((int*)a, 3, 5);


	

	return 0;
}
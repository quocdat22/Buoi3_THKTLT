#include "BaiTap.h"
#include<stdio.h>
#include <stdlib.h>


void khoiTaoMang2Chieu(int a[][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % (100 + 1);
		}
	}
}
void xuatMang2Chieu(int a[][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}


void bai1() {
	int m = 5;
	int n = 5;
	int a[100][100];

	khoiTaoMang2Chieu(a, m, n);

	printf("Mang 2 chieu duoc khoi tao ngau nhien: \n");
	xuatMang2Chieu(a, m, n);

	return;
}
#include "BaiTap.h"
#include<stdio.h>
#include <stdlib.h>


void khoiTaoMang2ChieuBai2(int a[][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % (100 + 1);
		}
	}
}

void xuatMang2ChieuBai2(int a[][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}


void bai2() {
	int m, n;
	int a[100][100];

	do {
		printf("Nhap so cap cua ma tran vuong: ");
		scanf_s("%d", &n);
	} while (n < 5);

	m = n;


	khoiTaoMang2ChieuBai2(a, m, n);
	xuatMang2ChieuBai2(a, m, n);
	
	

	




}
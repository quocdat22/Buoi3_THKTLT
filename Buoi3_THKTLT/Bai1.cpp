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

void tinhTongTungDong(int a[][100], int m, int n) {
	//m dong , n cot
	
	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += a[i][j];
		}
		printf("Tong gia tri cua phan tu tai dong %d: %d\n", i, sum);
	}
}

void xuatGiaTriLonNhatMoiCot(int a[][100], int m, int n) {
	for (int j = 0; j < n; j++)
	{
		int max = a[0][j];
		for (int i = 0; i < m; i++) {
			if(max < a[i][j])
				max = a[i][j];
		}
		printf("Gia tri lon nhat tai cot %d la %d\n", j, max);
	}
}


void bai1() {
	int m = 5;
	int n = 5;
	int a[100][100];

	khoiTaoMang2Chieu(a, m, n);

	printf("Mang 2 chieu duoc khoi tao ngau nhien: \n");
	xuatMang2Chieu(a, m, n);

	//tinhTongTungDong(a, m, n);

	xuatGiaTriLonNhatMoiCot(a, m, n);


	return;
}
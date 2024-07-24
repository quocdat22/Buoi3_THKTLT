#include "BaiTap.h"
#include<stdio.h>
#include <stdlib.h>
#include <time.h>


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

//Xuất các phần tử thuộc các đường biên trên, dưới, trái và phải của ma trận
void xuatPhanTuDuongBien(int a[][100], int m, int n) {
	printf("Cac phan tu thuoc duong bien cua ma tran la: \n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
				printf("%5d", a[i][j]);
			}
			else {
				printf("     ");
			}
		}
		printf("\n");
	}
}


//xuất các phần tử cực đại
int timCucDai(int a[][100], int soDong, int soCot) {
	int max = a[0][0];

	for (int i = 0; i < soDong; i++) {
		for (int j = 0; j < soCot; j++) {
			// Kiểm tra nếu a[i][j] là phần tử cực đại
			int isCucDai = 1;

			// Kiểm tra các phần tử lân cận
			if (i > 0 && a[i][j] < a[i - 1][j]) isCucDai = 0; // Phía trên
			if (i < soDong - 1 && a[i][j] < a[i + 1][j]) isCucDai = 0; // Phía dưới
			if (j > 0 && a[i][j] < a[i][j - 1]) isCucDai = 0; // Bên trái
			if (j < soCot - 1 && a[i][j] < a[i][j + 1]) isCucDai = 0; // Bên phải
			if (i > 0 && j > 0 && a[i][j] < a[i - 1][j - 1]) isCucDai = 0; // Đường chéo trên trái
			if (i > 0 && j < soCot - 1 && a[i][j] < a[i - 1][j + 1]) isCucDai = 0; // Đường chéo trên phải
			if (i < soDong - 1 && j > 0 && a[i][j] < a[i + 1][j - 1]) isCucDai = 0; // Đường chéo dưới trái
			if (i < soDong - 1 && j < soCot - 1 && a[i][j] < a[i + 1][j + 1]) isCucDai = 0; // Đường chéo dưới phải

			// Nếu a[i][j] là phần tử cực đại, kiểm tra giá trị max
			if (isCucDai && a[i][j] > max) {
				max = a[i][j];
			}
		}
	}

	return max;
}



void bai1() {
	srand(time(NULL));
	int m = 5;
	int n = 5;
	int a[100][100];

	khoiTaoMang2Chieu(a, m, n);

	printf("Mang 2 chieu duoc khoi tao ngau nhien: \n");
	xuatMang2Chieu(a, m, n);

	//tinhTongTungDong(a, m, n);

	//xuatGiaTriLonNhatMoiCot(a, m, n);

	//xuatPhanTuDuongBien(a, m, n);

	int cucDai = timCucDai(a, m, n);
	printf("Phan tu cuc dai trong mang la: %d\n", cucDai);

	return;
}
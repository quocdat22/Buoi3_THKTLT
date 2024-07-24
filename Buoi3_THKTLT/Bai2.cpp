#include "BaiTap.h"
#include<stdio.h>
#include <stdlib.h>
#include <time.h>


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

//Xuất các phần tử trên đường chéo chính
void xuatDuongCheoChinhBai2(int a[][100], int m, int n) {
	printf("Cac phan tu tren duong cheo chinh la: ");
	
	//cach1
	/*for(int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				printf("%5d", a[i][j]);
			}
		}
	}*/

	//cach2
	for (int i = 0; i < m; i++) {
		printf("%5d", a[i][i]);
	}
	printf("\n");
}

//Xuất các phần tử thuộc đường chéo song song với đường chéo chính.
void xuatDuongCheoSongSongChinh(int a[][100], int soDong, int soCot) {
	// Xuất các đường chéo song song với đường chéo chính ở phía trên (bao gồm đường chéo chính)
	printf("Duong cheo phia tren: \n");
	for (int k = 0; k < soCot; k++) {
		int i = 0, j = k;
		while (i < soDong && j < soCot) {
			printf("%d ", a[i][j]);
			i++;
			j++;
		}
		printf("\n");
	}

	// Xuất các đường chéo song song với đường chéo chính ở phía dưới
	printf("Duong cheo phia duoi: \n");
	for (int k = 1; k < soDong; k++) {
		int i = k, j = 0;
		while (i < soDong && j < soCot) {
			printf("%d ", a[i][j]);
			i++;
			j++;
		}
		printf("\n");
	}
}

//Tìm phần tử max thuộc tam giác trên của đường chéo chính.
int timMaxTamGiacTrenDuongCheoChinh(int a[][100], int soDong, int soCot) {
	int max = a[0][0];
	for (int i = 0; i < soDong; i++) {
		for (int j = i + 1; j < soCot; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
	}
	return max;
}

void bai2() {
	srand(time(NULL));
	int m, n;
	int a[100][100];

	do {
		printf("Nhap so cap cua ma tran vuong: ");
		scanf_s("%d", &n);
	} while (n < 5);

	m = n;


	khoiTaoMang2ChieuBai2(a, m, n);
	xuatMang2ChieuBai2(a, m, n);
	
	

	//xuatDuongCheoChinhBai2(a, m, n);

	//xuatDuongCheoSongSongChinh(a, m, n);

	printf("Phan tu lon nhat tren tam giac tren cua duong cheo chinh la: %d", timMaxTamGiacTrenDuongCheoChinh(a, m, n));


}
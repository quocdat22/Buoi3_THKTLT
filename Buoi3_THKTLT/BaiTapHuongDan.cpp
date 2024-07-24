#include<stdio.h>
#include <stdlib.h>
#include "BaiTap.h"

void khoiTaoMaTran(int a[][100], int soDong, int soCot) {
	for (int i = 0; i < soDong; i++) {
		for (int j = 0; j < soCot; j++) {
			a[i][j] = rand() % (100 + 1);
		}
	}
}

void xuatMaTran(int a[][100], int soDong, int soCot) {
	for (int i = 0; i < soDong; i++) {
		for (int j = 0; j < soCot; j++) {
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}

void xuatCacPhanTuDuongCheoChinh(int a[][100], int soDong, int soCot) {
	printf("Phan tu tren duong cheo chinh: ");
	for (int i = 0; i < soDong; i++) {
		for (int j = 0; j < soCot; j++) {
			if(i == j)
				printf("%5d", a[i][j]);
		}
	}
}

void xuatTamGiacDuoiCuaDuongCheoChinh(int a[][100], int soDong, int soCot) {
	printf("Tam giac duoi cua duong cheo chinh:");
	for (int i = 0; i < soDong; i++) {
		for (int j = 0; j < soCot; j++) {
			if (i > j)
				printf("%5d", a[i][j]);
			else
				printf("%5c", " ");
		}
		printf("\n");
	}
}

void xuatTamGiacTrenCuaDuongCheoChinh(int a[][100], int soDong, int soCot) {
	printf("Tam giac tren cua duong cheo chinh: \n");
	for (int i = 0; i < soDong; i++) {
		for (int j = 0; j < soCot; j++) {
			if (i < j)
				printf("%5d", a[i][j]);
			else
				printf("%5c", " ");
		}
		printf("\n");
	}
}

void xuatCacPhanTuDuongCheoPhu(int a[][100], int soDong, int soCot) {
	printf("Phan tu tren duong cheo phu: \n");
	for (int i = 0; i < soDong; i++) {
		for (int j = 0; j < soCot; j++) {
			if (i + j == soDong - 1)
				printf("%5d", a[i][j]);
		}
	}
}




void baiTapHuongDan() {
	int soDong = 5, soCot = 5;
	int a[100][100];

	khoiTaoMaTran(a, soDong, soCot);

	xuatMaTran(a, soDong, soCot);

	xuatCacPhanTuDuongCheoChinh(a, soDong, soCot);
	printf("\n");
	//xuatTamGiacDuoiCuaDuongCheoChinh(a, soDong, soCot);
	xuatTamGiacTrenCuaDuongCheoChinh(a, soDong, soCot);
	printf("\n");
	//xuatCacPhanTuDuongCheoPhu(a, soDong, soCot);

}

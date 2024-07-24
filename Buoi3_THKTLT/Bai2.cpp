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
//Sắp xếp ma trận tăng dần theo kiểu zic-zắc (tăng từ trái qua phải và từ trên xuống dưới)
// Hàm hoán đổi hai số nguyên
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Hàm sắp xếp mảng một chiều
void sapXepMang(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

// Hàm sắp xếp ma trận theo kiểu zic-zắc
void sapXepMaTranZicZac(int a[][100], int soDong, int soCot) {
	int n = soCot * soDong;
	int arr[100];
	int index = 0;

	// Chuyển đổi ma trận thành mảng một chiều
	for (int i = 0; i < soDong; i++) {
		for (int j = 0; j < soCot; j++) {
			arr[index++] = a[i][j];
		}
	}

	// Sắp xếp mảng một chiều
	sapXepMang(arr, n);

	// Chuyển đổi mảng đã sắp xếp trở lại thành ma trận theo kiểu zic-zắc
	index = 0;
	for (int i = 0; i < soDong; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < soCot; j++) {
				a[i][j] = arr[index++];
			}
		}
		else {
			for (int j = soCot - 1; j >= 0; j--) {
				a[i][j] = arr[index++];
			}
		}
	}
}


// Hàm sắp xếp đường chéo chính tăng dần
void sapXepDuongCheoChinh(int a[][100], int soDong, int soCot) {
	int n = soDong;
	int arr[100];

	// Lưu các phần tử của đường chéo chính vào mảng
	//c1
	/*for (int i = 0; i < n; i++) {
		arr[i] = a[i][i];
	}*/
	//c2
	for (int i = 0; i < soDong; i++) {
		for (int j = 0; j < soCot; j++) {
			if (i == j) {
				arr[i] = a[i][j];
			}
		}
	}

	// Sắp xếp mảng một chiều
	sapXepMang(arr, n);

	// Gán lại các phần tử đã sắp xếp vào đường chéo chính
	for (int i = 0; i < n; i++) {
		a[i][i] = arr[i];
	}
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

	//printf("Phan tu lon nhat tren tam giac tren cua duong cheo chinh la: %d", timMaxTamGiacTrenDuongCheoChinh(a, m, n));

	/*sapXepMaTranZicZac(a, m, n);
	printf("Ma tran sau khi sap xep theo zic zac la: \n");
	xuatMang2ChieuBai2(a, m, n);*/

	/*sapXepDuongCheoChinh(a, m, n);
	printf("Ma tran sau khi sap xep duong cheo chinh la: \n");
	xuatMang2ChieuBai2(a, m, n);*/

	sapXepDuongCheoChinh(a,m, n);
	printf("Ma tran sau khi sap xep duong cheo chinh la: \n");
	xuatMang2ChieuBai2(a, m, n);

}
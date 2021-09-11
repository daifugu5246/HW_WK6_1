#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	int num[50][50];
	int sum[100];
	int size, sumarr, r, c,x,y,temp1,temp2,i = 0;
	int TF;
	printf("Enter square size : ");
	scanf("%d", &size);
	sumarr = (size * 2) + 2;
	r = size - 1;
	c = size - 1;
	//Input Number
	for (int x = 0; x <= r; x++) {
		for (int y = 0; y <= c; y++) {
			scanf("%d", &num[x][y]);
		}
	}
	//Sum of Horizontal
	for (int x = 0; x <= r; x++) {
		sum[i] = 0;
		for (int y = 0; y <= c; y++) {
			sum[i] += num[x][y];
		}
		i++;
	}
	//Sum of Vertical
	for (int y = 0; y <= r; y++) {
		sum[i] = 0;
		for (int x = 0; x <= c; x++) {
			sum[i] += num[x][y];
		}
		i++;
	}
	//Sum of Daigonal
	sum[i] = 0;
	for (int xy = 0; xy <= r; xy++) {
		sum[i] += num[xy][xy];
	}
	i++;
	sum[i] = 0;
	x = 0;
	y = c;
	while (y>=0) {
		sum[i] += num[x][y];
		x++;
		y--;
	}
	x = 0;
	y = 0;
	//Same number check
	while (x < r) {
		while (y < c) {
			temp1 = num[x][y];
			for (int r = x; r < size - 1; r++) {
				for (int c = y + 1; c < size - 1; c++) {
					temp2 = num[r][c];
					if (temp1 == temp2) {
						TF = 0;
					}
					else {
						TF = 1;
					}
				}
			}
			y++;
		}
		y = 0;
		x++;
	}
	x = 0;
	y = 0;
	//Magiccheck
	for (int j = 0; j < sumarr - 1; j++) {
		if (sum[j] == sum[j + 1] && TF != 0) {
			TF = 1;
		}
		else {
			TF = 0;
		}
	}
	if (TF == 1) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	return 0;
}
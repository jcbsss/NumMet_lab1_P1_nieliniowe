//This is the program created on the Numerical Methods lab on Warsaw University on Technology in March2023
//This is Problem 1 from lab1. You can find the description here http://ccfd.github.io/courses/metnum_lab1.html

#define _CRT_SECURE_NO_WARNINGS

#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void init_matrix(int N, double** A) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			A[i][j] = 0.;

	A[0][0] = 1.;  A[0][3] = 1.;
	A[1][1] = 1.;  A[1][4] = 1.;
	A[2][2] = 1.;  A[2][3] = -4.;  A[2][4] = 3.;
	A[3][3] = -1.; A[3][5] = 1.;
	A[4][4] = -1.; A[4][6] = 1.;
	A[5][5] = -3.; A[5][6] = 4.;
	A[6][5] = -1.; A[6][7] = 1.;
	A[7][6] = -1.; A[7][8] = 1.;
	A[8][7] = 7.;  A[8][8] = 2.;
}

void init_vector(int N, double* b) {
	b[0] = 0;
	b[1] = 25;
	b[2] = 37.5;
	b[3] = 0;
	b[4] = 16;
	b[5] = 32;
	b[6] = 0;
	b[7] = 53;
	b[8] = 53;
}

void print_vector(int N, double* b) {
	for (int i = 0; i < N; i++)
		printf("%lf \n", b[i]);
}

int main() {
	int N = 9;
	double** A, * A_row;

	A = (double**)malloc(N * sizeof(double*));
	A_row = (double*)malloc(N * N * sizeof(double));
	for (int i = 0; i < N; i++) {
		A[i] = &A_row[i * N];
	}
	init_matrix(N, A);
	
	double* b;
	b = (double*)malloc(N * sizeof(double));
	init_vector(N, b);

	double* x;
	x = (double*)malloc(N * sizeof(double));

	gauss(N, A, x, b);

	print_vector(N, x);

	return 0;
}
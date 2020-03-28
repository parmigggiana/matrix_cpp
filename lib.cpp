#include "matrix.h"
#include <iostream>

void stampaMatrice (int** m, int M, int N) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << m[i][j] << "  ";
		}
		std::cout << "\n";
	}

	return;
}

void stampaMatrice (int*** m, int M) {
	
	for (int y = 0; y < M; y++) {
		std::cout << "\nMatrice " << y << "\n";
		for (int i = 0; i < M-1; i++) {
			for (int j = 0; j < M-1; j++) {
				std::cout << m[y][i][j] << "  ";
			}
			std::cout << "\n";
		}
		std::cout << "\n\n";
	}

	return;
}

bool isValid (int M, int N) {
	bool state = true;

	if (M != N) 
		state = false;

	return state;
}

int calcolaDelta (int** m, int M) {
	int delta = 0;
	
	if (M == 1) {
		delta = m[0][0];
	}

	else if (M == 2) {
		delta = m[0][0] * m[1][1] - m[0][1] * m[1][0];
	}

	else if (M > 2) {
		delta = laplace(m, M);
	}

	return delta;
}

int laplace (int** m, int M) {
	int*** mat;
	int disc = 0;

	mat = new int**[M];
	for (int i = 0; i < M; i++) {
		mat[i] = new int*[M-1];
		for (int j = 0; j < M-1; j++) {
			mat[i][j] = new int[M-1];
			for (int y = 0; y < M-1; y++) {
				if (j < i) {
					mat[i][j][y] = m[j][y+1];
				}
				else {
					mat[i][j][y] = m[j+1][y+1];
				}
			}
		}
	}

	for (int i = 0; i < M; i++) {
		if (i%2 == 0) {
			disc += m[i][0] * calcolaDelta(mat[i], M-1);
		}
		else {
			disc -= m[i][0] * calcolaDelta(mat[i], M-1);
		}
	}


	return disc;
}

void clear () {
	#ifdef __unix__
	system("clear");
	#else
	system("CLS");
	#endif
}

bool checkProd (int N1, int M2) {
	if (N1 == M2)
		return true;
	else
		return false;
}

void prodMat (int** a, int** b, int** ab, int M1, int N1, int M2, int N2) {
	int M3 = M1;
	int N3 = N2;

	if (N1 == M2) {
		for (int i = 0; i < M3; i++) {
			for (int j = 0; j < N3; j++) {
				for (int y = 0; y < N1; y++) {
					ab[i][j] += a[i][y] * b[y][j];
				}
			}
		}
	}

	return;
}
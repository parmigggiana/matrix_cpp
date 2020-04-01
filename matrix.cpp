// g++ /home/basile/OneDrive/C++/Matrix/matrix.cpp /home/basile/OneDrive/C++/Matrix/lib.cpp -o /home/basile/OneDrive/C++/Matrix/matrix && /home/basile/OneDrive/C++/Matrix/matrix

#include <iostream>
#include "matrix.h"

using namespace std;

void clear () {
        #ifdef __unix__
        system("clear");
        #else
        system("CLS");
        #endif
}

int main () {
	
	char flush[0];
	int M, N = 1;
	int** mat;
	int M2, N2 = 1;
	int** mat2;
	int** prod;
	int det = 0;
	cout << "*** Matrix Solver ***\n\n";
	char sel = 'y';

	while(sel == 'y' || sel == 'Y') {
		//WHAT: Allocazione mat [M][N]

		cout << "Insert the rows' number: ";
		cin >> M;
		cout << "Insert the columns' number: ";
		cin >> N;
		mat = new int* [M];
		for (int i = 0; i < M; i++) {
			mat[i] = new int [N];
		}
		
		for (int i = M-1; i >= 0; i--) {
			for (int j = N-1; j >= 0; j--) {
				mat[i][j] = 0;
			}
		}
		
		//WHAT: Inserimento valori 
		clear();
		printMatrix(mat, M, N);
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cout << "\nInsert " << i+1 << "x" << j+1 << ": ";
				cin >> mat[i][j];
				clear();
				printMatrix(mat, M, N);
			}
		}

		//WHAT: Se possibile, calcola il determinante
		if (isValid(M, N)) {
			det = delta(mat, M);
			cout << "\nThe determinant is: " << det << ".";
		}
		else 
			cout << "\nIt is not possible to calculate the determinant of a non-square matrix.";


		cout << "\nInsert the second matrix rows' number: ";
		cin >> M2;
		cout << "\nInsert the second matrix columns' number: ";
		cin >> N2;

		mat2 = new int* [M2];
		for (int i = 0; i < M2; i++) {
			mat2[i] = new int [N2];
		}
		for (int i = M2-1; i >= 0; i--) {
			for (int j = N2-1; j >= 0; j--) {
				mat2[i][j] = 0;
			}
		}
		
		clear();
		printMatrix(mat2, M2, N2);
		for (int i = 0; i < M2; i++) {
			for (int j = 0; j < N2; j++) {
				cout << "\nInsert " << i+1 << "x" << j+1 << ": ";
				cin >> mat2[i][j];
				clear();
				printMatrix(mat2, M2, N2);
			}
		}

		if(!checkProd(N, M2)) {
			cout << "\nIt's not possible to multiply these two matrixes.";
		}
		else {
			prod = new int* [M];
			for (int i = 0; i < M; i++) {
				prod[i] = new int [N2];
			}
			prodMat(mat, mat2, prod, M, N, M2, N2);

			cout << "\nThe product is: \n";
			printMatrix(prod, M, N2);
		}


		cout << "\n\nDo you want to start again? (y/n): ";
		cin >> sel;

		for (int i = M-1; i >= 0; i--) {
			delete mat[i];
			delete prod[i];
		} 
		for (int i = M2-1; i >= 0; i--) {
			delete mat2[i];
		}
		delete mat;
		delete prod;
		delete mat2;
		

		clear();
	}

	return 0;
}

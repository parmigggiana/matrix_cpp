// g++ /home/basile/OneDrive/C++/Matrix/matrix.cpp /home/basile/OneDrive/C++/Matrix/lib.cpp -o /home/basile/OneDrive/C++/Matrix/matrix && /home/basile/OneDrive/C++/Matrix/matrix

#include <iostream>
#include "matrix.h"

using namespace std;

int main () {
	
	char flush[0];
	int M, N = 1;
	int** mat;
	int M2, N2 = 1;
	int** mat2;
	int** prod;
	int det = 0;
	cout << "*** Benvenuto nel risolutore di matrici ***\n\n";
	char sel = 'y';

	while(sel == 'y' || sel == 'Y') {
		//WHAT: Allocazione mat [M][N]

		cout << "Inserisci il numero di righe: ";
		cin >> M;
		cout << "Inserisci il numero di colonne: ";
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
		//TODO: Implementa la libreria che disse ivan per i cursori
		clear();
		stampaMatrice(mat, M, N);
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cout << "\nInserisci " << i+1 << "x" << j+1 << ": ";
				cin >> mat[i][j];
				clear();
				stampaMatrice(mat, M, N);
			}
		}

		//WHAT: Se possibile, calcola il determinante
		if (isValid(M, N)) {
			det = calcolaDelta(mat, M);
			cout << "\nIl determinante della matrice è " << det << ".";
		}
		else 
			cout << "\nNon è possibile calcolare il determinante di una matrice non quadrata.";


		cout << "\nInserisci il numero di righe della seconda matrice: ";
		cin >> M2;
		cout << "\nInserisci il numero di colonne della seconda matrice: ";
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
		stampaMatrice(mat2, M2, N2);
		for (int i = 0; i < M2; i++) {
			for (int j = 0; j < N2; j++) {
				cout << "\nInserisci " << i+1 << "x" << j+1 << ": ";
				cin >> mat2[i][j];
				clear();
				stampaMatrice(mat2, M2, N2);
			}
		}

		if(!checkProd(N, M2)) {
			cout << "\nNon è possibile svolgere il prodotto di queste due matrici.";
		}
		else {
			prod = new int* [M];
			for (int i = 0; i < M; i++) {
				prod[i] = new int [N2];
			}
			prodMat(mat, mat2, prod, M, N, M2, N2);

			cout << "\nIl prodotto delle due matrici è: \n";
			stampaMatrice(prod, M, N2);
		}


		cout << "\n\nVuoi ricominciare? (y/n): ";
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
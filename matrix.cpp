// g++ /home/basile/OneDrive/C++/Matrix/matrix.cpp /home/basile/OneDrive/C++/Matrix/lib.cpp -o /home/basile/OneDrive/C++/Matrix/matrix && /home/basile/OneDrive/C++/Matrix/matrix

#include <iostream>
#include "matrix.h"

using namespace std;

int main () {
	
	char flush[0];
	int M = 1;
	int N = 1;
	int** mat;
	int disc = 0;
	cout << "*** Benvenuto nel risolutore di matrici ***\n\n";
	char sel = 'y';

	while(sel != 'n' && sel != 'N') {
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

		//WHAT: Se possibile, calcola il discriminante
		if (isValid(M, N)) {
			disc = calcolaDelta(mat, M);
			cout << "\nIl discriminante della matrice è " << disc << ".";
		}
		else 
			cout << "\nNon è possibile calcolare il discriminante di una matrice non quadrata.";

		cout << "\n\nVuoi calcolare il discriminante di un'altra matrice? (Y/n): ";
		cin >> sel;

		for (int i = M-1; i >= 0; i--) {
			delete mat[i];
		} 
		delete mat;
		clear();
	}

	return 0;
}
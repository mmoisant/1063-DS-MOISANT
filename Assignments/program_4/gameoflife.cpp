/**
* @ProgramName: Program-4
* @Author: Marcus Moisant
* @Description:
*     This program plays the game of life with
*	an endless board and ends game when board is stable.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 01 05 2017
*/
#include <iostream>
#include <string>
#include <fstream>

//#ifdef __cplusplus__
//#include <cstdlib>
//#else
//#include <stdlib.h>
//#endif

#include<time.h>

using namespace std;

class GameOfLife{
private:
	int **Board;
	int **Board2;
	int Rows;
	int Cols;
public:
	GameOfLife(string filename){
		string line;
		char ch;
		ifstream fin;
		fin.open(filename);
		fin >> Rows >> Cols;
		InitBoardArray(Board);
		InitBoardArray(Board2);
		for (int i = 0; i < Rows; i++){
			for (int j = 0; j < Cols; j++){
				fin.get(ch);
				if (ch == 10){
					continue;
				}
				Board[i % Rows][j % Cols] = int(ch) - 48;
			}
		}
	}

	GameOfLife(int r, int c){
		Rows = r;
		Cols = c;
		InitBoardArray(Board);
		InitBoardArray(Board2);
		PrintBoard();
	}

	void InitBoardArray(int **&b){
		b = new int*[Rows];
		for (int i = 0; i < Rows; i++){
			b[i] = new int[Cols];
		}
		ResetBoardArray(b);
	}

	void ResetBoardArray(int **&b){
		for (int i = 0; i < Rows; i++){
			for (int j = 0; j < Cols; j++){
				b[i][j] = 0;
			}
		}
	}

	void PrintBoard(){
		for (int i = 0; i < Rows; i++){
			for (int j = 0; j < Cols; j++){
				if (Board[i][j] == 1)
					cout << char('X');
				else
					cout << "_";
			}
			cout << endl;
		}
	}

	int CountNeighbors(int row, int col){
		int neighbors = 0;
		if (Board[row % Rows][col % Cols] == 1){
			neighbors--;
		}
		for (int i = row - 1; i <= row + 1; i++){
			for (int j = col - 1; j <= col + 1; j++){
				if (OnBoard(i % Rows, j % Cols)){
					neighbors += Board[i % Rows][j % Cols];
				}
			}
		}
		return neighbors;
	}

	bool OnBoard(int row, int col){
		return (row >= 0 && row < Rows && col >= 0 && col < Cols);
	}

	void RandomPopulate(int num){
		int r = 0;
		int c = 0;
		for (int i = 0; i < num; i++){
			r = rand() % Rows;
			c = rand() % Cols;
			Board[r % Rows][c % Cols] = 1;
		}
	}

	void SetCell(int r, int c, int val){
		int infRow = r % Rows;
		int infCol = c % Cols;
		Board[infRow][infCol] = val;
	}

	void AddGens(){
		for (int i = 0; i < Rows; i++){
			for (int j = 0; j < Cols; j++){
				Board[i][j] += Board2[i][j];
			}
		}
		ResetBoardArray(Board2);
	}

	void clear_screen(int lines){
		for (int i = 0; i < lines; i++){
			cout << endl;
		}
	}

	void Run(int generations = 99999){
		int neighbors = 0;
		int g = 0;
		int killer = 0;
		int sumB2 = 0;
		while (g < generations){
			killCorners();
			for (int i = 0; i < Rows; i++){
				for (int j = 0; j < Cols; j++){
					neighbors = CountNeighbors(i, j);
					if (Board[i][j] == 1 && (neighbors < 2 || neighbors > 3)){
						Board2[i][j] = -1;
						sumB2++;
					}
					if (Board[i][j] == 0 && neighbors == 3){
						Board2[i][j] = 1;
						sumB2++;
					}

				}

			}
			killer++;
			if (sumB2 == 0){
				AddGens();
				pause(250);
				clear_screen(30);
				PrintBoard();
				g += (generations-killer - 3);
				pause(1000);

			}
			else{
				AddGens();
				pause(200);
				clear_screen(30);
				PrintBoard();
				g++;
			}


		}

	}

	void killCorners()
	{
		if (Board[0][0] == 1){
			Board2[0][0] == -1;
			
		}
		if (Board[Rows - 1][0] == 1){
			Board2[Rows - 1][0] == -1;
			
		}
		if (Board[0][Cols - 1] == 1){
			Board2[0][Cols - 1] == -1;
			
		}
		if (Board[Rows - 1][Cols - 1] == 1){
			Board2[Rows - 1][Cols - 1] == -1;
			
		}

	}




	void gliderGun()
	{
		SetCell(5, 1, 1);
		SetCell(5, 2, 1);
		SetCell(6, 1, 1);
		SetCell(6, 2, 1);
		SetCell(5, 11, 1);
		SetCell(6, 11, 1);
		SetCell(7, 11, 1);
		SetCell(4, 12, 1);
		SetCell(8, 12, 1);
		SetCell(3, 13, 1);
		SetCell(3, 14, 1);
		SetCell(9, 13, 1);
		SetCell(9, 14, 1);
		SetCell(6, 15, 1);
		SetCell(4, 16, 1);
		SetCell(8, 16, 1);
		SetCell(5, 17, 1);
		SetCell(6, 17, 1);
		SetCell(7, 17, 1);
		SetCell(6, 18, 1);
		SetCell(3, 21, 1);
		SetCell(4, 21, 1);
		SetCell(5, 21, 1);
		SetCell(3, 22, 1);
		SetCell(4, 22, 1);
		SetCell(5, 22, 1);
		SetCell(2, 23, 1);
		SetCell(6, 23, 1);
		SetCell(1, 25, 1);
		SetCell(2, 25, 1);
		SetCell(6, 25, 1);
		SetCell(7, 25, 1);
		SetCell(3, 35, 1);
		SetCell(4, 35, 1);
		SetCell(3, 36, 1);
		SetCell(4, 36, 1);

	}

	void pause(int MilliSeconds)
	{
		clock_t t;
		t = clock();
		int sum = 0;

		while ((clock() - t) < MilliSeconds)
		{
			sum++;
		}
	}
};

int main(){
	GameOfLife G(15, 75);

	//GameOfLife G("gen_one.txt");

	G.gliderGun();

	//G.RandomPopulate(60);


	G.Run(100);
	return 0;
}

#include<iostream>
#include<cmath>
using namespace std;

bool canPlace(int board[][10],int i,int j,int n,int no){
	//check for row and column
	for(int x=0;x<n;x++){
		if(board[x][j]==no or board[i][x]==no){
			return false;
		}
	}

	//subgrid
	int rn = int(sqrt(n));	
	int sx = (i/rn)*rn;
	int sy = (j/rn)*rn;

	for(int x=sx;x<sx+rn;x++){
		for(int y=sy;y<sy+rn;y++){
			if(board[x][y]==no){
				return false;
			}
		}
	}
	return true;
}



bool solveSudoku(int board[][10],int i,int j,int n){
	//base case
	if(i==n){
		//print the board
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;
	}
	if(j==n){
		 return solveSudoku(board,i+1,0,n);
	}
	if(board[i][j]!=0){
		return solveSudoku(board,i,j+1,n);
	}
	//rec case
	for(int no=1;no<=n;no++){
		if(canPlace(board,i,j,n,no)){
			board[i][j] = no;
			
			bool aageKaSolveHua = solveSudoku(board,i,j+1,n);
			if(aageKaSolveHua){
				return true;
			}
		}
	}
	board[i][j] = 0; //backtracking!
	return false;
}


int main(){

	int n;
	cin>>n;
	int board[10][10];

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>board[i][j];
		}
	}
	solveSudoku(board,0,0,n);

	5;
	x+4;
	true;



	return 0;
}
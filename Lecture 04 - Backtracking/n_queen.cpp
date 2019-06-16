#include<iostream>
using namespace std;

bool canPlace(int board[][10],int i,int j,int n){
	//column 
	for(int x=0;x<i;x++){
		if(board[x][j]==1){
			return false;
		}
	}
	//diag 
	int x=i,y=j;
	//left diag 
	while(x>=0 and y>=0){
		if(board[x][y]==1){
			return false;
		}
		x--; y--;
	}
	x=i,y=j;
	//right diag 
	while(x>=0 and y<n){
		if(board[x][y]==1){
			return false;
		}
		x--; y++;
	}
	return true;
}

int nQueen(int board[][10],int i,int n){
	if(i==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return 1;
	}
	//rec case
	int cnt=0;
	for(int j=0;j<n;j++){
		if(canPlace(board,i,j,n)){
			board[i][j] =1;
			cnt += nQueen(board,i+1,n);
			board[i][j] = 0;
		}
	}
	return cnt;
}

int main(){
	int board[10][10]={0};
	int n;
	cin>>n;

	cout<< nQueen(board,0,n);




	return 0;
}
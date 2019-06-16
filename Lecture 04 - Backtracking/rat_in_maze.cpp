#include<iostream>
using namespace std;

bool ratInMaze(char maze[][10],int i,int j,int m,int n){
	//base case
	if(i==m and j==n){
		return maze[i][j]=='0'?true:false;
	}
	if(i>m or j>n){
		return false;
	}
	if(maze[i][j]=='X'){
		return false;
	}
	//rec case
	bool rightSeRastaHai = ratInMaze(maze,i,j+1,m,n);
	if(rightSeRastaHai){
		return true;
	}
	//downSeRasta
	return ratInMaze(maze,i+1,j,m,n);
}

int ratInMaze1(char maze[][10],int i,int j,int m,int n){
	//base case
	if(i==m and j==n){
		return maze[i][j]=='0'?1:0;
	}
	if(i>m or j>n){
		return 0;
	}
	if(maze[i][j]=='X'){
		return 0;
	}
	//rec case
	return  ratInMaze1(maze,i,j+1,m,n) +ratInMaze1(maze,i+1,j,m,n);

}	

bool ratInMaze2(char maze[][10],int i,int j,int m,int n){
	//base case
	if(i==m and j==n){
		//print maze
		 maze[i][j] = '1';
		for(int i=0;i<=m;i++){
			for(int j=0;j<=n;j++){
				cout<<maze[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		maze[i][j] ='0';
		return maze[i][j]=='0'?true:false;
	}
	if(i>m or j>n){
		return false;
	}
	if(maze[i][j]=='X'){
		return false;
	}
	//rec case
	maze[i][j] ='1';
	bool rightSeRastaHai = ratInMaze2(maze,i,j+1,m,n);
	bool downSeRastaHai =  ratInMaze2(maze,i+1,j,m,n);
	maze[i][j] = '0'; //backtracking
	return rightSeRastaHai or downSeRastaHai;

}

int main(){
	
	char maze[][10] = {
		"0000X",
		"00X0X",
		"X00XX",
		"0X000",
		"0XX00",
	};
	if(ratInMaze(maze,0,0,4,4)){
		cout<<"Rasta Hai!";
	}
	else{
		cout<<"Nahi hai!";
	}
	cout<<ratInMaze1(maze,0,0,4,4)<<endl;
	ratInMaze2(maze,0,0,4,4);

}
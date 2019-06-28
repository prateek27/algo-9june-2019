#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void printHeap(priority_queue<int, vector<int> ,greater<int> > h){
	while(!h.empty()){
		cout<<h.top()<<" ";
		h.pop();
	}
}
int main(){	

	priority_queue<int, vector<int> ,greater<int> > h;

	int no;
	int cnt=0;
	int k = 3;
	while(scanf("%d",&no)!=EOF){
		if(no==-1){
			//Query 
			printHeap(h);

		}
		else{
			if(cnt<k){
				h.push(no);
				cnt++;
			}
			else{
				if(no>h.top()){
				h.pop();
				h.push(no);
				}
			}
		}

	}


	return 0;
}
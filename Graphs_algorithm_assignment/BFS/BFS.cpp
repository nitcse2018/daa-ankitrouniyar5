#include <iostream>
#include <queue>
#define N 6
using namespace std;

class node{
	public:
		int value;
		int status;    //visited or not 
};


int graph [N][N]={
	{0, 1, 1, 1, 0, 0},
	{1, 0, 0, 1, 1, 0},
	{1, 0, 0, 1, 0, 1},
	{1, 1, 1, 0, 1, 1},
	{0, 1, 0, 1, 0, 1},
	{0, 0, 1, 1, 1, 0}
};

breadthFirstSearch(node * vertices,node s){
	node u;
	queue<node> que;
	for (int i =0;i<N;i++){
		vertices[i].status = 0;//making each of the vertices not visited initially
	}
	vertices[s.value].status=1;//making start vertices visited
	
	que.push(s);
	
	while (!que.empty()){
		
		u=que.front();
		que.pop();
		
		cout <<u.value<<" ";
		for (int i=0;i<N;i++){
			
			if (graph[i][u.value]){
				if (vertices[i].status==0)
				{
					vertices[i].status=1;//making the vertices visited
					que.push(vertices[i]);
				}
			}
		}
		u.status= -1;
		
	}
}
	
	int main () {
		
		node vertices[N];
		node start;
		
		for (int i=0;i<N;i++){
			vertices[i].value=i;
		}
		
	start.value = 1;
    breadthFirstSearch(vertices, start);
    
}
		

	
	
	
	
	
	
	



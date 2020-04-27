#include <iostream>
#include <stack>
#define N 6
using namespace std;

class node{
	public:
	int value;
	int status;// visited or not
};


int graph[N][N]={
   {0, 1, 1, 1, 0, 0},
   {1, 0, 0, 1, 1, 0},
   {1, 0, 0, 1, 0, 1},
   {1, 1, 1, 0, 1, 1},
   {0, 1, 0, 1, 0, 1},
   {0, 0, 1, 1, 1, 0}


};

void depthFirstSearch (node * vertices,node s){ 
	int i,j;
	
	node u;
	stack<node> stack;
	
	
	for (i=0;i<N;i++){
		vertices[i].status = 0;//making each node not visited initially.
		
	}
	stack.push(s);
	
	
	while(!stack.empty()){
			
			u=stack.top();
			stack.pop();
			cout<<u.value<<" ";
			
			
			if (u.status!=1){
				u.status=1;
				vertices[u.value].status=1;
				
				for (i=0;i<N;i++){
					
					if( graph[i][u.value]){
						if(vertices[i].status==0){
							stack.push(vertices[i]);
							vertices[i].status=  1 ;
							}
						}
					}
				}
			}}
int main() {
	int i;
	node vertices[N];
	node start;
	
	for(i=0;i<N;i++){
		vertices[i].value=i;
	}
	
	start.value = 2;
	depthFirstSearch(vertices,start);
	
}

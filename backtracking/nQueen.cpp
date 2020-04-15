/*

Solving the nQueen problem using Back tracking
BY -- Ankit Kr. Rouniyar.
   --Cse 2nd year.. Roll number-181210011
   

The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other. 


INPUT::4


OUTPUT:
 _ Q _ _
 _ _ _ Q
 Q _ _ _
 _ _ Q _



*/


#include <iostream>
using namespace std;



//to check the colomn ,upper left and right diagonal for the queen
bool isSafe(int board[][10],int i ,int j, int n )
{
	for (int row = 0; row<i ; row ++)
	{
		if (board[row][j]==1)
		{
			return false;
		}
	}
	
	
	int x = i;
	int y = j;
	while (x>=0 && y>+0)
	{
		if (board[x][y]==1)
		{
			return false;
		}
		x--;
		y--;
	}
	x=i;y=j;
	while (x>=0  && y<n )
	{
		if (board[x][y]==1)
		{
			return false;
		}
		x--;
		y++;
	}
	return true;
}



bool solveQueen(int board[][10],int i , int n )

{
	if (i==n)//base case for the recursion part
	{
		for (i=0;i<n;i++)
		   {
		   	for (int j=0;j<n;j++)
		   	{
		   		if (board[i][j]==1)
		   		{
		   			cout<< " Q";
				}
				else 
				{
					cout<<" _";
				}
				
			}
			cout<<endl;
		   }
		//when all the queen are placed safely
		return true;
		
	}
	for (int j=0;j<n;j++)
	{
		if (isSafe(board,i,j,n))
		{
			board[i][j]=1;
		 bool nextMove = solveQueen (board,i+1,n);//solving the next subproblem by recursion
		
		 	if (nextMove){
		 		return true;
			 }
			//when the next placement of queen is not possible
			 board[i][j]=0;//backtracking
		 }
		 
		 
	}
	return false;
	
}





int main() {
	
	int n;
	int board[10][10]={0}; 
	cin>>n;
	solveQueen(board,0,n);
	
	return 0;
}

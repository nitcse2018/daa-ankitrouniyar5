
/*
Solving the KnapSack problem using Dynamic programming
BY -- Ankit Kr. Rouniyar.
   --Cse 2nd year.. Roll number-181210011
   
   
   Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
   In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. 
   Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of 
   this subset is smaller than or equal to W. 
   You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
   
   INPUT:
  Enter the no. of items 3
  Enter the weight and price of all items
  10 60
  20 100
  30 120
  enter the capacity of knapsack  50
  
  
  OUTPUT::
The maximum value of items that can be put into knapsack is 220
   
The overall time complexity of the solution is O(n*W)   ,n-->no of items
														W-->total capacity of the knapsack
*/


#include<bits/stdc++.h>
using namespace std;
 
int knapSack_dp(int n, int M , int w [], int p[])
{
    //matrix to memoize the values using dynamic programming
    int knapSack[n+1][M+1];
 
    //knapsack[i][j] denotes the max  attainable value of items in knpaSack with i available items and capacity of knapSck being j
 		int i,j;
    //initializing knapsack[0][j]=0 for 0<=j<=M ecause if there is no item, no value can be attained
    for(j=0;j<=M;j++)
        knapSack[0][j]=0;
 
    //initializing knapsack[i][0]=0 for 0<=i<=n,because in a bag of zero capacity, no item can be placed
    for(i=0;i<=n;i++)
        knapSack[i][0]=0;
 
    //now, filling the matrix in bottom up manner
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=M ;j++)
        {
            //check if the weight of current item i is less than or equal to the capacity of sack,
            //take maximum of once including the current item and once not including
            if(w [i-1]<=j)
            {
                knapSack[i][j]=max(knapSack[i-1][j],knapSack[i-1][j-w[i-1]] + p[i-1]);
            }
 
            //can not include the current item in this case
            else
            {
                knapSack[i][j]=knapSack[i-1][j];
            }
        }
    }
 		return knapSack[n][M];
}
 
int main()
{
    int i;
    int n;  //fot thenumber of items
    int M ;  //for maximum capacity of knapsack
 
    cout<<"Enter the no. of items ";
    cin>>n;
 
    int w [n];  //weight of items
    int p [n];  //profit of individual items
 
    cout<<"Enter the weight and price of all items"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>w [i]>>p[i];
    }
 
    cout<<"enter the capacity of knapsack  ";
    cin>>M ;
 
 
    int res=knapSack_dp(n, M ,w , p);
 		cout<<"The maximum value of items that can be put into knapsack is "<<res;
 
    return 0;
}

/*
KnapSack problem usinng branch bound 
BY -- Ankit Kr. Rouniyar.
   --Cse 2nd year.. Roll number-181210011

Given two integer arrays val[0..n-1] and wt[0..n-1] that represent values and weights associated with n items respectively.
Find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to Knapsack capacity W.

You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

INPUT::

			weigth and price 
			{10   , 60}, 
			{20  , 100 },
 			{30  , 120 }
 			 
oUTPUT::
The maximum value of items that can be put into knapsack is 220


*/
#include <bits/stdc++.h>


using namespace std; 

// Structure for Item which store weight and its value of Item 
struct Item 
{ 
	double weight; 
	int value; 
}; 

// Node structure to store information of decision tree 
struct Node 
{ 

	int level, profit, bound; 
	double weight; 
}; 

// a function to sort item in terms of ratios of val/weight 
bool cmp(Item a, Item b) 
{ 
	double r1 = a.value / a.weight; 
	double r2 = b.value / b.weight; 
	return r1 > r2; 
} 

// Returns bound of profit in subtree rooted with u. 
// This function mainly uses Greedy solution to find 
// an upper bound on maximum profit. 
int bound(Node u, int n, int W, Item arr[]) 
{ 
	// if weight overcomes the knapsack capacity, return 
	// 0 as expected bound 
	if (u.weight >= W) 
		return 0; 

	// initialize bound on profit by current profit 
	int profit_bound = u.profit; 

	// start including items from index 1 more to current 
	// item index 
	int j = u.level + 1; 
	int totweight = u.weight; 

	// checking index condition and knapsack capacity condition 
	while ((j < n) && (totweight + arr[j].weight <= W)) 
	{ 
		totweight += arr[j].weight; 
		profit_bound += arr[j].value; 
		j++; 
	} 

	// If k is not n, include last item partially for 
	// upper bound on profit 
	if (j < n) 
		profit_bound += (W - totweight) * arr[j].value / arr[j].weight; 

	return profit_bound; 
} 

// Returns maximum profit we can get with capacity W 
int knapsack(int W, Item arr[], int n) 
{ 
	sort(arr, arr + n, cmp); // sorting the Itemss 
		////\queue for traversing the node 
	queue<Node> Q; 
	Node u, v; 

	// dummy node at starting 
	u.level = -1; 
	u.profit = u.weight = 0; 
	Q.push(u); 
	int maxProfit = 0; 
	while (!Q.empty()) 
	{ 
		// Dequeue a node 
		u = Q.front(); 
		Q.pop(); 

		// If it is starting node, assign level 0 
		if (u.level == -1) 
			v.level = 0; 

		// If there is nothing on next level 
		if (u.level == n-1) 
			continue; 

		// Else if not last node, then increment level,and compute profit of children nodes. 
		v.level = u.level + 1; 

		// Taking current level's item add current level's weight and value to node u's weight and value 
		v.weight = u.weight + arr[v.level].weight; 
		v.profit = u.profit + arr[v.level].value; 

			if (v.weight <= W && v.profit > maxProfit) 
			maxProfit = v.profit; 

		// Get the upper bound on profit to decide 
		// whether to add v to Q or not. 
		v.bound = bound(v, n, W, arr); 

		// If bound value is greater than profit,then only push into queue for further consideration 
		if (v.bound > maxProfit) 
			Q.push(v); 
		//without items in knapsack
		v.weight = u.weight; 
		v.profit = u.profit; 
		v.bound = bound(v, n, W, arr); 
		if (v.bound > maxProfit) 
			Q.push(v); 
	} 
     return maxProfit; 
} 

 
int main() 
{ 
	int W = 50; // Weight of knapsack 
	Item arr[] = {{10, 60}, {20, 100}, {30, 120}}; 
	int n = 3; 
	int res ;
	cout << "The maximum value of items that can be put into knapsack is ";
	res =  knapsack(W, arr, n); 
	cout<<res; 

	return 0; 
} 


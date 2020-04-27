/*
Job Sequencing problem using greedy method 
BY -- Ankit Kr. Rouniyar.
   --Cse 2nd year.. Roll number-181210011
   
   Given an array of jobs where every job has a deadline and a profit. Profit can be earned only if the job is finished before the deadline. 
   It is also given that every job takes a single unit of time, so the minimum possible deadline for any job is 1. 
   How to maximize total profit if only one job can be scheduled at a time. Print the sequence of jobID order to maximize total profit.
   
   INPUT::
   jobid deadline profit
    {'a',  2 , 20},
	{'b',  2 , 15}, 
	{'c',  1 , 10}, 
    {'d',  3 , 5}, 
	{'e',  3 , 1}
	
	
 	OUTPUT::
 	the sequence of the job for maximum profit is :: b a d
	And the profit is 40
  
	The overall timeComplexity for this solution is O(n^2)

*/


#include<iostream> 
#include<algorithm> 
using namespace std; 
 
 
 
 //class for the job
class Job 
{ 
public:
char id;   
int deadLine; 
int profit; 
}; 
int totalProfit=0;// to store total profit

bool compare(Job a, Job b) // This function is used for sorting all the jobs according to the profit  
{ 
  return (a.profit > b.profit); 
} 


void jobSchedule(Job arr[], int n) 
{ 
  // Sorting the given jobs according to decreasing order of profit 
  sort(arr, arr+n, compare); 
  

  int result[n]; // To store result 
  bool slot[n];  
  
  
  
  // Initialize all slots to be free 
  for (int i=0; i<n; i++) 
    {
    	slot[i] = false; 
	}	
    
  for (int i=0; i<n; i++) 
  { 
  // Find a free slot for this job where we start from the last possible slot) 
  for (int j=min(n, arr[i].deadLine)-1; j>=0; j--) 
  { 
    //  if free slot found 
    if (slot[j]==false) 
    { 
      result[j] = i; // Add this job to result 
      slot[j] = true; // Make this slot occupied 
      totalProfit += arr[i].profit ;//Adding profit in total profit..
      break; 
    } 
    
  } 
  } 
  // Print the result 
  for (int i=0; i<n; i++) 
  if (slot[i]) 
    cout << arr[result[i]].id << " "; 
} 
int main() 
{ 
  Job arr[] = { {'a', 2, 20}, {'b', 2, 15}, {'c', 1, 10}, 
        {'d', 3, 5}, {'e', 3, 1}}; 
  int n = 5; 
  cout << "the sequence of the job for maximum profit is :: "; 
  jobSchedule(arr, n); 
   cout<<endl<<"And the profit is "<<totalProfit<<endl;
} 

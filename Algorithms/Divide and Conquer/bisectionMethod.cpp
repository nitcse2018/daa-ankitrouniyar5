
/*
findinding the square root using divide and conquer 
BY -- Ankit Kr. Rouniyar.
   --Cse 2nd year.. Roll number-181210011
   
   Given a function f(x) = x^3 -x^2 + 2  on floating number x and two numbers ‘a’ and ‘b’ such that f(a)*f(b) < 0 and f(x) is continuous in [a, b]. 
   Here f(x) represents algebraic equation. Find root of function in interval [a, b] 
   INPUT::
   a = -200,b=300;
   
   
   OUTPUT::
   The value of a is -200
	The value of b is 300
	The root of the equation is -1.0025
	The number of iteration was 16
   

*/

#include <iostream>
 using namespace std;

double functionVal (double x)
{
	return x*x*x -x*x + 2;
}
double c;//mid-point o f the interval[a,b]
int x=0;//to count the number of iteration

void bisection(double a, double b)
{
	
	if (functionVal(a)*functionVal(b)>=0)
	{
		cout<<"The values of a and b is incorrect..";
		return;
		
		
	}
	
	while (b-a >= 0.01)
	{
		x++;
		c = (a+b)/2;
		
		if (functionVal(c)*functionVal(b)<0)//if square root lies b/w b & c
	     {
	     	a=c;
	     	
	     }
	    else if (functionVal(a)*functionVal(c)<0){//if square root lies b/w a & c
		
	     	b=c;
	     	
	     }
	    else//if c is the root
		 {
	     	break;
	     }
	}
}


int main() {
	
	double a = -200,b=300;
	cout <<"The value of a is " << a <<endl;
	cout <<"The value of b is " << b <<endl;
	bisection(a, b);
	cout <<"The root of the equation is " << c <<endl;
	cout<<"The number of iteration was " << x;
	
	return 0;
}

/*
Largest Concatenate Problem

Compile the largest number by concatenating the
given numbers.
--------------------------------------------------------------------------------------------------------------------
Input: A sequence of positive inte-
gers.
--------------------------------------------------------------------------------------------------------------------
Output: The largest number that
can be obtained by concatenating
the given integers in some order.
--------------------------------------------------------------------------------------------------------------------
Input format. The first line of the input contains an integer n. The second
line contains integers a(1), . . . , a(n).
Output format. The largest number that can be composed out of a1, . . . , an.
Constraints. 1 ≤ n ≤ 100; 1 ≤ a(i) ≤ 10^3 for all 1 ≤ i ≤ n.
--------------------------------------------------------------------------------------------------------------------
Sample 1.
Input:
2
21 2
Output:
221
--------------------------------------------------------------------------------------------------------------------
Sample 2.
Input:
5
9 4 6 1 9
Output:
99641
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>


int digits(int p){
	int count=0;
	while(p!=0){
		p=p/10;
		count++;
	}
	return count;
}

int reverse(int p){
	int s=0,t;
	while(p!=0){
		t=p%10;
		s=s*10+t;
		p=p/10;
	}
	return s;
}
/*
int Pow(double x,double y){
	int s=1;
	for(int i=1;i<=y;i++)
	{
		s=s*x;
	}
	return s;
}
*/
int compare(const void *p, const void *q){
	int x=*(int*)p;
	int y=*(int*)q;
	if(x==y)
		return 0;
	int d1=digits(x);
	int d2=digits(y);
	
	int sal1=(x*(int)(pow(10.0,(double)d2))) + y;
	int sal2=(y*(int)(pow(10.0,(double)d1))) + x;
	
	return sal1>sal2?-1:1;
}

void maxSalary(int nos[],int n){
	qsort(nos,n,sizeof(int),compare);
}			
			
int main(void){
	int n,n1;
	scanf("%d",&n);
	int nos[n];		
	for(int i=0;i<n;i++)
		scanf("%d",&nos[i]);
		
	maxSalary(nos,n);
	
	for(int i=0;i<n;i++)
		printf("%d",nos[i]);
	printf("\n");
	return 0;
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

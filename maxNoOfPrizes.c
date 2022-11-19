/*
Distinct Summands Problem
Represent a positive integer as the sum of the
maximum number of pairwise distinct positive
integers.
--------------------------------------------------------------------------------------------------------------------
Input: A positive integer n.
--------------------------------------------------------------------------------------------------------------------
Output: The maximum k such
that n can be represented as the
sum a1 + · · · + ak of k distinct pos-
itive integers.
--------------------------------------------------------------------------------------------------------------------
8
1 2 5
--------------------------------------------------------------------------------------------------------------------
Input format. An integer n.
Output format. In the first line, output the maximum number k such
that n can be represented as the sum of k pairwise distinct positive in-
tegers. In the second line, output k pairwise distinct positive integers
that sum up to n (if there are multiple such representations, output
any of them).
Constraints. 1 ≤ n ≤ 109.
*/

#include<stdio.h>

int noOfPrizes(long n,int k){
	if(n==0)
		return 0;
	if((n-k)<=k){
		//prizes[k-1]=n;
		return 0;
	}
	//prizes[k-1]=k;
	return 1+noOfPrizes((n-k),k+1);
}

int main(void){
	long n;
	scanf("%ld",&n);
	//int prizes[2];
	
	int k=noOfPrizes(n,1);
	printf("%d\n",(k+1));
	for(int i=1;i<=k;i++)
		printf("%d ",i);
	printf("%d ",(n-((k*(k+1))/2)));
	printf("\n");
	
	return 0;
}

/*
Maximum Product of Two Sequences Prob-
lem
Find the maximum dot product of two sequences
of numbers.
--------------------------------------------------------------------------------------------------------------------
Input: Two sequences of n posi-
tive integers: price(1), . . . , price(n) and
clicks(1), . . . , clicks(n).
--------------------------------------------------------------------------------------------------------------------
Output: The maximum value
of price(1) * c(1) + · · · + price(n) * c(n),
where c(1), . . . , c(n) is a permutation of
clicks(1), . . . , clicks(n). 
--------------------------------------------------------------------------------------------------------------------
Input format. The first line contains an integer n, the second one con-
tains a sequence of integers price1, . . . , pricen, the third one contains
a sequence of integers clicks1, . . . , clicksn.
Output format. Output the maximum value of (price1 · c1 + · · · + pricen · cn),
where c(1), . . . , c(n) is a permutation of clicks(1), . . . , clicks(n).
Constraints. 1 ≤ n ≤ 103; 0 ≤ price(i) , clicks(i) ≤ 105 for all 1 ≤ i ≤ n.
*/

#include<stdio.h>
#include<stdlib.h>

int compare(const void *p, const void *q){
	if( *(long*)p < *(long*)q)
		return -1;
	if( *(long*)p > *(long*)q)
		return 1;
	return 0;
}

long maxRevenue(int n,long price[n],long clicks[n]){
	
	long *ptr=price;
	qsort(ptr,n,sizeof(long),compare);
	
	ptr=clicks;
	qsort(ptr,n,sizeof(long),compare);
	
	long prod=0;
	for(int i=0;i<n;i++){
		prod=prod+(price[i] * clicks[i]);
	}
	return prod;
}

int main(void){
	int n;
	scanf("%d",&n);
	long price[n],clicks[n];
	
	for(int i=0;i<n;i++) 
		scanf("%ld",&price[i]);
	for(int i=0;i<n;i++)
		scanf("%ld",&clicks[i]);

	printf("%ld\n",maxRevenue(n,price,clicks));
	return 0;
}
	

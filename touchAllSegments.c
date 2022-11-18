/*
Covering Segments by Points Problem
Find the minimum number of points needed to
cover all given segments on a line.
--------------------------------------------------------------------------------------------------------------------
Input: A sequence of n segments
[l1, r1], . . . , [ln, rn] on a line.
--------------------------------------------------------------------------------------------------------------------
Output: A set of points of mini-
mum size such that each segment
[li , ri ] contains a point, i.e., there ex-
ists a point x from this set such that
li ≤ x ≤ ri .
--------------------------------------------------------------------------------------------------------------------
Input format. The first line of the input contains the number n of seg-
ments. Each of the following n lines contains two integers li and ri
(separated by a space) defining the coordinates of endpoints of the
i-th segment.
--------------------------------------------------------------------------------------------------------------------
Output format. The minimum number k of points on the first line and the
integer coordinates of k points (separated by spaces) on the second
line. You can output the points in any order. If there are multiple
such sets of points, you can output any of them.
--------------------------------------------------------------------------------------------------------------------
Constraints. 1 ≤ n ≤ 100; 0 ≤ li ≤ ri ≤ 109 for all i.

*/
#include<stdio.h>
#include<stdlib.h>

int n;//size of arrray of structures

struct segments{
	long x;
	long y;
};

int compare(const void *p,const void *q){
	if( ((struct segments*)p)->y < ((struct segments*)q)->y)
	   return -1;
	if( ((struct segments*)p)->y > ((struct segments*)q)->y)
	   return 1;
	return 0;
}

void delete(struct segments s[n],int pos){
	for(int i=pos;i<n-1;i++){
		s[i]=s[i+1];
	}
	n--;
}

int touchAllSegments(struct segments s[],int intersection[]){
	qsort(s,n,sizeof(struct segments),compare);
	
	long pos=0;
	int count=0;
	while(n!=0){
		pos=s[0].y;
		delete(s,0);
		for(int i=0;i<n && n!=0;i++){
			if(pos>=s[i].x || pos>=s[i].y){
				delete(s,i);
				i--;
			}
		}
		intersection[count]=pos;
		count++;
	}
	return count;
}

int main(void){

	int intersection[100];
	scanf("%d",&n);
	
	struct segments s[n];
	for(int i=0;i<n;i++){
		scanf("%ld",&s[i].x);
		scanf("%ld",&s[i].y);
	}
	
	int k= touchAllSegments(s,intersection);
	printf("%d\n",k);
	for(int i=0;i<k;i++)
		printf("%d ",intersection[i]);
	printf("\n");
	return 0;
}

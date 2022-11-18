#include<stdio.h>

int n;

void delete(int stops[]){
	for(long i=0;i<n-1;i++){
		stops[i]=stops[i+1];
	}
	n--;
}

int pitStop(int d,int m,int stops[],int location){
	if( (location+m)>=d )
		return 0;
	if( n==0 || (location+m)<stops[0] )
		return -d;
	int lastStop=location;
	for(int i=0;n!=0 && (location+m)>=stops[0] ;){
		lastStop=stops[0];
		delete(stops);
	}
	return 1+pitStop(d,m,stops,lastStop);
}

int main(void){
	int m,d;
	scanf("%d",&d);
	scanf("%d",&m);
	scanf("%d",&n);
	
	int stops[n+1];
	
	for(int i=0;i<n;i++){
		scanf("%d",&stops[i]);
	}
	
	int noStop=pitStop(d,m,stops,0);
	if(noStop<0)
		printf("-1\n");
	else
		printf("%d\n",noStop);
	return 0;
}

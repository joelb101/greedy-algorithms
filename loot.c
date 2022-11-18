#include<stdio.h>

long n;

void delete(float weight[],float cost[],int m){
	for(long i=m;i<n-1;i++){
		weight[i]=weight[i+1];
		cost[i]=cost[i+1];
	}
	n--;
}

int max(float cost[],float weight[]){
	int pos=0;
	for(long i=0;i<n;i++){
		if( (cost[pos]/weight[pos]) < (cost[i]/weight[i]) ){
			pos=i;
		}
	}
	return pos;
}
	
double maxLoot(long W,float weight[],float cost[]){
	if(W==0 || n==0)
		return 0;
	int m=max(cost,weight);
	float amt= weight[m]>W?W:weight[m];
	double val=cost[m]*(amt/weight[m]);
	delete(weight,cost,m);
	return val + maxLoot(W-amt,weight,cost);
}


int main(void){
	long W;
	scanf("%ld%ld",&n,&W);
	float cost[n],weight[n];
	for(long i=0;i<n;i++){
		scanf("%f",&cost[i]);
		scanf("%f",&weight[i]);
	}
	
	printf("%.4lf\n",maxLoot(W,weight,cost));
	return 0;
}

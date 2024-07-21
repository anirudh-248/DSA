#include<stdio.h>
int n,m,p[10],w[10];

void greedy_knapsack() {
    float max, profit=0, x[10]={0}, con_flag=1;
    int k=0,i,j;
    for (i=0;i<n;i++) {
        max=0;
	    //choose the item which has highest price to weight ratio
        for (j=0;j<n;j++) {
            if (((float)p[j])/w[j] > max) {
                k=j;
                max=((float)p[j])/w[j];
            }
        }
	    //kth element has highest price to weight ratio
	    if (w[k]<=m) {
			x[k]=1.0;
            m = m - w[k];
            profit=profit+p[k];
		} 
		else { //unable fit item k into knapsack
	    	if (con_flag) { //continuous knapsack is not solved
				x[k]=((float)m)/w[k]; //taking fraction part of kth item
	    		printf("-----------------------------\n");
    			printf("Continuous Knapsack Solution:\n");
    			printf("Items included are:\n");
    			for(j=0;j<n;j++)
    				if(x[j])
    					printf("Item %d, Portion selected %f\n",j+1,x[j]);
				printf("profit = %f\n",profit + x[k] * p[k]);
            	con_flag=0;
            	x[k]=0; //Revert to continue with discrete knapsack
        	}
		}
        p[k]=0; //Not to select item k for the next iteration
    }
    printf("-----------------------\n");
    printf("Discrete Knapsack Solution:\n");
    printf("Items included are:\n");
    for (j=0;j<n;j++)
    	if (x[j])
    		printf("%d ",j+1);
    printf("\nprofit = %f\n",profit);
}
        
int main() {
    int i;
	printf("Enter the no. of items: ");
    scanf("%d",&n);
    printf("Enter the weights of n items: ");
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);
    printf("Enter the prices of n items: ");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    printf("Enter the capacity of Knapsack: ");
    scanf("%d",&m);
    greedy_knapsack();       
}
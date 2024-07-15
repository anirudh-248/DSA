/*7. Design and implement C/C++ Program to solve discrete Knapsack and continuous Knapsack
problems using greedy approximation method.*/

#include<stdio.h>

int n,m,p[10],w[10];
void greedy_knapsack()
{
    float max, profit=0, x[10]={0};
    int k=0,i,j;
    for(i=0;i<n;i++)
    {
        max=0;
	    //choose the item which has highest price to weight ratio
        for(j=0;j<n;j++)
        {
            if(((float)p[j])/w[j] > max)
            {
                k=j;
                max=((float)p[j])/w[j];
            }
        }
	    //kth element has highest price to weight ratio
        if(w[k] <= m )
        {
			x[k]=1.0;
            m = m - w[k];
            profit=profit+p[k];
            p[k]=0;
        }
        else
        {
            x[k]=((float)m)/w[k];//unable fit item k into knapsack
            break;
    	}
    }
    printf("-----------------------\n");
    printf("Discrete Knapsack Solution:\n");
    printf("Items included are:\n");
    for(i=0;i<n;i++)
    	if(x[i]==1.0)
    		printf("%d ",i+1);
    printf("\nprofit = %f\n",profit);
    printf("-----------------------------\n");
    printf("Continuous Knapsack Solution:\n");
    printf("Items included are:\n");
    for(i=0;i<n;i++)
    	if(x[i])
    		printf("Item %d, Portion selected %f\n",i+1,x[i]);
	profit = profit + x[k] * p[k];
    printf("profit = %f\n",profit);
}
        
int main() 
{
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
#include<stdio.h>
#include<conio.h>
void main()
{
	int n;
	printf("enter no of processes:");
	scanf("%d",&n);
	int bt[n],p[n],wt[n],tat[n],sumtat=0,sumwt=0,avgwt,avgtat,i;
	for(i=0;i<n;i++)
	p[i]=i;
	for(i=0;i<n;i++)
	{
		printf("enter burst time for P%d:",i);
		scanf("%d",&bt[i]);
	}
	wt[0]=0;
	tat[0]=bt[0];
	for(i=1;i<n;i++)
	{
		wt[i]=bt[i-1]+wt[i-1];
		tat[i]=wt[i]+bt[i];
	}
	for(i=0;i<n;i++)
	{
		sumwt+=wt[i];
		sumtat+=tat[i];
	}
	printf("process_id\tburst time\twaiting time\ttat time\n\n");
	for(i=0;i<n;i++)
	{
	   printf("P%d\t\t%d\t\t%d\t\t%d\n",i,bt[i],wt[i],tat[i]);
	}
	avgtat=sumtat/n;
	avgwt=sumwt/n;
	printf("average wt=%d\naverage tat=%d",avgwt,avgtat);
	getch();
}

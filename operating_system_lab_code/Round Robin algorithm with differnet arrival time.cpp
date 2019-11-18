
#include <iostream>
#include <vector>

using namespace std;
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,remain,flag=0,time_quantum;
   double wait_time=0,turnaround_time=0;

    cout<<"Enter Total Process:\t ";
    cin>>n;
    remain=n;

    int at[n];
    int bt[n];
    int rt[n];
    int tt[n];
    int wt[n];

    for(int i=0; i<n; i++)
    {
        cout<<"Enter Arrival Time and Burst Time for Process Process Number "<<i+1 <<": ";
        cin>>at[i];
        cin>>bt[i];
        rt[i]=bt[i];
    }

    cout<<"Enter Time Quantum:\t";
    cin>>time_quantum;

    int time=0;
    for(int i=0; remain!=0;)
    {
        if(rt[i]<=time_quantum && rt[i]>0)
        {
            time+=rt[i];
            rt[i]=0;
            flag=1;
        }
        else if(rt[i]>0)
        {
            rt[i]-=time_quantum;
            time+=time_quantum;
        }
        if(rt[i]==0 && flag==1)
        {
            remain--;
            tt[i] = time-at[i];
            wt[i] = time-at[i]-bt[i];
            //printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);
            wait_time+=wt[i];
            turnaround_time+=tt[i];
            flag=0;
        }
        if(i==n-1)
            i=0;
        else if(at[i+1]<=time)
            i++;
        else
            i=0;
    }
    cout<<"\n\nProcess\t|Turnaround Time|Waiting Time\n\n";
    for(int i=0; i<n; i++)
        printf("P[%d]\t|\t%d\t|\t%d\n",i+1,tt[i],wt[i]);

    cout<<"\nAverage Waiting Time= ",wait_time/n;
    cout<<"\nAvg Turnaround Time = ",turnaround_time/n;

    return 0;
}

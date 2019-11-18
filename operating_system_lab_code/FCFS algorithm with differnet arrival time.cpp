#include<bits/stdc++.h>
using namespace std;
struct Process
{
    int pid,bt,at;
};
bool com(Process a, Process b)
{
    return a.at<b.at;
}
int main()
{
    int p;
    cout<<"Enter Number of process: ";
    cin>>p;
    Process poc[p];
    int ct[p];
    int wt[p];
    int tt[p];
    double totalwt = 0,totaltt=0;

    for(int i=0; i<p; i++)
    {
        cout<<" At and Bt for P"<<i+1<<": ";
        poc[i].pid = i+1;
        cin>>poc[i].at>>poc[i].bt;
    }
    sort(poc,poc+p,com);
    wt[0]=0;
    ct[0] = 0;
    for(int i=1; i<p; i++)
    {
        ct[i] = ct[i-1] +poc[i-1].bt;
        wt[i] = ct[i] -poc[i].at;
        if(wt[i]<0)
            wt[i]=0;
        totalwt+=wt[i];
    }
    for(int i=0; i<p; i++)
    {
        tt[i] = wt[i]+poc[i].bt;
        totaltt+=tt[i];
    }

    cout<<"process |"
        <<" Arrival time |"
        <<" Burst time |"
        <<" Waiting time |"
        <<" Turnaround time\n";

    for(int i=0; i<p; i++)
    {
        cout<<poc[i].pid<<"\t"
            <<poc[i].at<<"\t\t"
            <<poc[i].bt<<"\t\t"
            <<wt[i]<<"\t\t"
            <<tt[i]<<"\n";
    }
    cout<<"AVG waiting Time : "<<totalwt/p;
    cout<<"\nAVG Turnaround Time : "<<totaltt/p;
}

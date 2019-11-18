#include<bits/stdc++.h>
using namespace std;
struct P{
    int pid;
    int at,bt,ct,tt,wt,btt;
};
bool com(P a, P b){
    return a.at<b.at;
}
bool com1(P a, P b){
    return a.bt<b.bt;
}
bool com2(P a, P b){
return a.pid<b.pid;}

int main()
{
    int n,i,j,pcom;
    cout<<"Enter the number of Process::";
    cin>>n;
    P pro[n];
    cout<<"Enter the arrival time burst time :::\n";
    for(i=0; i<n; i++)
    {
        pro[i].pid = i ;
        cin>>pro[i].at;
        cin>>pro[i].bt;
        pro[i].btt=pro[i].bt;
    }
    sort(pro,pro+n,com);
    i=0;
    pcom=0;
    while(pcom<n)
    {
        for(j=0; j<n; j++)
        {
            if(pro[j].at>i)
                break;
        }
        sort(pro,pro+j,com1);
        if(j>0)
        {
            for(j=0; j<n; j++)
            {
                if(pro[j].bt!=0)
                    break;
            }
            if(pro[j].at>i)
            {
                i=pro[j].at;
            }
            pro[j].ct=i+1;
            pro[j].bt--;
        }
        i++;
        pcom=0;
        for(j=0; j<n; j++)
        {
            if(pro[j].bt==0)
                pcom++;
        }
    }
    for(i=0; i<n; i++)
    {
        pro[i].tt=pro[i].ct-pro[i].at;
        pro[i].wt=pro[i].tt-pro[i].btt;
    }
    sort(pro,pro+n,com2);
    cout<<"ProID\tAtime\tBtime\tCtime\tTtime\tWtime\n";
    for(int i=0;i<n;i++)
    cout<<pro[i].pid<<"\t"<<pro[i].at
        <<"\t"<<pro[i].btt<<"\t"<<pro[i].ct
        <<"\t"<<pro[i].tt<<"\t"<<pro[i].wt<<endl;
    return 0;
}



#include<bits/stdc++.h>
using namespace std;
int ab;
typedef struct schedule
{
	int pro_id;
	int at,bt,ct,ta,wt;
}schedule;

bool compare(schedule a,schedule b)
{
	return a.at < b.at;
}

bool compare2(schedule a,schedule b)
{
	return a.bt < b.bt && a.at <= ab;
}
bool com2(schedule a, schedule b){
return a.pro_id<b.pro_id;}
int main()
{
	int n,i,j;
	cout<<"Enter the number of schedule::";
	cin>>n;
	schedule pro[10];
	cout<<"Enter the arrival time burst time :::\n";

	for(i=0;i<n;i++)
	{
		pro[i].pro_id=i+1;
		cin>>pro[i].at;
		cin>>pro[i].bt;
	}
	sort(pro,pro+n,compare);
	// initial values
	pro[0].ct=pro[0].bt+pro[0].at;
	pro[0].ta=pro[0].ct-pro[0].at;
	pro[0].wt=pro[0].ta-pro[0].bt;

	for(i=1;i<n;i++)
	{
		ab=pro[i-1].ct;
		sort(pro+i,pro+n,compare2);
		if(pro[i-1].ct<pro[i].at)
		{
			pro[i].ct=pro[i-1].ct+pro[i].bt+(pro[i].at-pro[i-1].ct);
		}
		else
		{
			pro[i].ct=pro[i-1].ct+pro[i].bt;
		}
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].bt;
	}
sort(pro,pro+n,com2);
    cout<<"ProID\tAtime\tBtime\tCtime\tTtime\tWtime\n";
    for(int i=0;i<n;i++)
    cout<<pro[i].pro_id<<"\t"<<pro[i].at
        <<"\t"<<pro[i].bt<<"\t"<<pro[i].ct
        <<"\t"<<pro[i].ta<<"\t"<<pro[i].wt<<endl;
	return 0;
}

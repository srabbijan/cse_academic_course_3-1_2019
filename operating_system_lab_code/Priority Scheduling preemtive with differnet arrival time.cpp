#include<bits/stdc++.h>
using namespace std;
typedef struct proccess
{
	int at,bt,ct,ta,wt,btt,pr;
	int pro_id;
}schedule;

bool compare(schedule a,schedule b)
{
	return a.at<b.at;
}

bool compare2(schedule a,schedule b)
{
	return a.pr<b.pr;
}

int main()
{

	int n,i,j,pcom;

	cout<<"Enter the number of process::";
	cin>>n;
	schedule pro[n];
	cout<<"Enter the arrival time, burst time and priority :::\n";
	for(i=0;i<n;i++)
	{
		pro[i].pro_id = i+1;
		cin>>pro[i].at;
		cin>>pro[i].bt;
		pro[i].btt=pro[i].bt;
		cin>>pro[i].pr;
	}

	sort(pro,pro+n,compare);

	i=0;
	pcom=0;
	while(pcom<n)
	{
		for(j=0;j<n;j++)
		{
			if(pro[j].at>i)
			break;
		}
		sort(pro,pro+j,compare2);
		if(j>0)
		{
			for(j=0;j<n;j++)
			{
				if(pro[j].bt!=0)
				break;
			}
			if(pro[j].at>i)
			i+=pro[j].at-i;
			pro[j].ct=i+1;
			pro[j].bt--;
		}

		i++;
		pcom=0;
		for(j=0;j<n;j++)
		{
			if(pro[j].bt==0)
			pcom++;
		}
	}

cout<<"ProID\tAtime\tBtime\tCtime\tTtime\tWtime\tPriority\n";
	for(i=0;i<n;i++)
	{
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].btt;
		//before executing make it in one statement
		cout<<pro[i].pro_id<<"\t"<<pro[i].at<<"\t"<<pro[i].btt<<"\t"<<pro[i].ct<<"\t"<<pro[i].ta<<"\t"<<pro[i].wt<<"\t"<<pro[i].pr;
		cout<<endl;
	}

	return 0;
}


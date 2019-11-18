#include<bits/stdc++.h>
using namespace std;
typedef struct proccess
{
	int at,bt,pr,ct,ta,wt;
	int pro_id;
}process;

bool compare(process a,process b)
{
	return a.at<b.at;
}

bool compare2(process a,process b)
{
	return a.pr>b.pr;
}

int main()
{

	int n,i,j;
	cout<<"Enter the number of process::";
	cin>>n;
	process pro[n];
	cout<<"Enter the arrival time, burst time and priority :::\n";

	for(i=0;i<n;i++)
	{
		pro[i].pro_id = i+1;
		cin>>pro[i].at;
		cin>>pro[i].bt;
		cin>>pro[i].pr;
	}
	sort(pro,pro+n,compare);
	pro[0].ct=pro[0].bt+pro[0].at;
	pro[0].ta=pro[0].ct-pro[0].at;
	pro[0].wt=pro[0].ta-pro[0].bt;
	i=1;

	while(i<n-1)
	{
		for(j=i;j<n;j++)
		{
			if(pro[j].at>pro[i-1].ct)
			break;
		}
		sort(pro+i,pro+i+(j-i),compare2);
		pro[i].ct=pro[i-1].ct+pro[i].bt;
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].bt;
		i++;
    }
		pro[i].ct=pro[i-1].ct+pro[i].bt;
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].bt;
cout<<"ProID\tAtime\tBtime\tCtime\tTtime\tWtime\n";
	for(i=0;i<n;i++)
	{
		cout<<pro[i].pro_id<<"\t"<<pro[i].at<<"\t"<<pro[i].bt<<"\t"<<pro[i].ct<<"\t"<<pro[i].ta<<"\t"<<pro[i].wt<<"\t"<<pro[i].pr;
		cout<<endl;
	}
	return 0;
}


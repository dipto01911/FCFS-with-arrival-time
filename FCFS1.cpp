#include<iostream>
using namespace std;
int At[20],Bt[20],Ct[20],Tat[50],Wt[20],order[20];
int max(int a,int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int n,i,j,temp;
	float avwt=0,avtt=0;
	cout<<"enter the number of process"<<endl;
	cin>>n;
	for(i=1;i<=n;i++){
		printf("Process number P%d Arrival time and Burst time\n",i);
		cin>>At[i]>>Bt[i];
		order[i]=i;
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(At[order[i]]>At[order[j]]){
			swap(order[i],order[j]);
			}
		}
	}
	for(i=1;i<=n;i++){
	Ct[order[i]]=max(Ct[order[i-1]],At[order[i]])+Bt[order[i]];
	
	}
	for(i=1;i<=n;i++){
		int id=order[i];
		Tat[id]=Ct[id]-At[id];
		Wt[id]=Tat[id]-Bt[id];
		avwt=avwt+Wt[id];
		avtt=avtt+Tat[id];
	}
	printf("Pid....Arrival .....Burst time......Turnaround......waiting.....completion\n");
	for(i=1;i<=n;i++){
		int id=order[i];
	printf("P%d\t %d\t\t %d\t\t %d\t\t %d\t %d\n",id,At[id],Bt[id],Tat[id],Wt[id],Ct[id]);	
	}
	cout<<"Average waiting time"<<avwt/n<<endl;
	cout<<"Average turnaround time"<<avtt/n<<endl;
	return 0;
}
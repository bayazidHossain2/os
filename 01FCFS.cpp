#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("001input.txt","r",stdin);
    freopen("001output.txt","w",stdout);
    #endif
    

    int n;
    // cout<<"Enter No. of process : ";
    cin>>n;
    int pid[n],at[n],bt[n],ct[n],tat[n],wt[n];

    // Input all process arrival time and Burst time 
    for(int i=0;i<n;i++){
    	// cout<<"Enter "<<i+1<<"th process AT and BT : ";
    	cin>>at[i]>>bt[i];
    }
    ct[0]=at[0]+bt[0];
    // completion time calculation
    for(int i=1;i<n;i++){
    	ct[i]=max(at[i],ct[i-1])+bt[i];
    }
    int ttat=0,twt=0;
    // Turn Around time and Waiting time Calculation 
    for(int i=0;i<n;i++){
    	tat[i]=ct[i]-at[i];
    	ttat+=tat[i];
    	wt[i]=tat[i]-bt[i];
    	twt+=wt[i];
    }

    // Printing in tabular form 
    cout<<"AT"<<'\t'<<"BT"<<'\t'<<"CT"<<'\t'<<"TAT"<<'\t'<<"WT"<<endl;
    cout<<"-----------------------"<<endl;
    for(int i=0;i<n;i++){
    	cout<<at[i]<<'\t'<<bt[i]<<'\t'<<ct[i]<<'\t'<<tat[i]<<'\t'<<wt[i]<<endl;
    }cout<<endl;
    cout<<"Total : "<<"\t"<<ttat<<'\t'<<twt<<endl;
    
    // Result showing
    cout<<"Average Tarn Around Time : "<<ttat/(n+0.0)<<endl;
    cout<<"Average Waiting Time : "<<twt/(n+0.0)<<endl;

    return 0;
}
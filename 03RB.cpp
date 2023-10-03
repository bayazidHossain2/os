#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("03RB input.txt","r",stdin);
    freopen("001output.txt","w",stdout);
    #endif
    

    int n;
    // cout<<"Enter No. of process : ";
    cin>>n;
    int pid[n],at[n],bt[n],rbt[n],ct[n],tat[n],wt[n];
    int timeQuantam = 5;

    // Input all process arrival time and Burst time 
    for(int i=0;i<n;i++){
    	// cout<<"Enter "<<i+1<<"th process AT and BT : ";
    	cin>>at[i]>>bt[i];
    	rbt[i]=bt[i];
    }
    ct[0]=at[0]+bt[0];
    // completion time calculation
    int ttat=0,twt=0,complete = 0;
    queue<int> que;
    que.push(0);
    int time=at[0],last_arrive=1;
    while(complete < n){
    	int exe_ind = que.front();
        que.pop();
        bool f=false;
        cout<<"P"<<exe_ind+1<<endl;

    	if(rbt[exe_ind]<=timeQuantam){
    		ct[exe_ind] = time+rbt[exe_ind];
    		time = ct[exe_ind];
    		complete++;
    	}else{
    		rbt[exe_ind]-=timeQuantam;
    		time+=timeQuantam;
            f=true;
    	}
    	while(last_arrive<n&&at[last_arrive]<=time){
    		que.push(last_arrive);
    		last_arrive++;
    	}
        if(f){
            que.push(exe_ind);
        }
    }
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
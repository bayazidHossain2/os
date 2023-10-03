#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("04 PS input.txt","r",stdin);
    freopen("001output.txt","w",stdout);
    #endif

    int n;
    // cout<<"Enter No. of process : ";
    cin>>n;
    int pr[n],at[n],bt[n],rbt[n],ct[n],tat[n],wt[n];
    int timeQuantam = 2,time = 0;
    int numberOfCompleteProcess = 0;

    // Input all process arrival time and Burst time.
    // Data must be sorted by arrival time.
    for(int i=0;i<n;i++){
        // cout<<"Enter "<<i+1<<"th process Pr, AT and BT : ";
        cin>>pr[i]>>at[i]>>bt[i];
        rbt[i]=bt[i];
    }

    priority_queue<pair<int,int>> pqu;
    // completion time calculation
    int last_arrive=0;
    while(at[last_arrive]<=at[0]){
        pqu.push({pr[last_arrive],last_arrive});
        last_arrive++;
    }
    
    while(numberOfCompleteProcess<n){
        while(last_arrive<n&&at[last_arrive]<=time){
            pqu.push({pr[last_arrive],last_arrive});
            last_arrive++;
        }
        if(pqu.empty()){
            if(last_arrive<n){
                pqu.push({pr[last_arrive],last_arrive});
                time = at[last_arrive];
                last_arrive++;
            }else{
                break;
            }
        }

        int cur_exe = pqu.top().second;
        cout<<"P "<<cur_exe+1<<endl;
        
        if(rbt[cur_exe] <= timeQuantam){
            ct[cur_exe] = time + rbt[cur_exe];
            time = ct[cur_exe];
            numberOfCompleteProcess++;
            pqu.pop();
        }else{
            rbt[cur_exe]-=timeQuantam;
            time += timeQuantam;
        }
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

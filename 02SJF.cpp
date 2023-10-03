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

    priority_queue<pair<int,pair<int,int>>> pqu;
    // completion time calculation
    int last_arrive=0;
    while(at[last_arrive]<=at[0]){
        pqu.push({-bt[last_arrive],{at[last_arrive],last_arrive}});
        last_arrive++;
    }
    int pre_com=pqu.top().second.second;
    ct[pre_com]=pqu.top().second.first+(-pqu.top().first);
    pqu.pop();
    for(int i=1;i<n;i++){
        while(last_arrive<n&&at[last_arrive]<=ct[pre_com]){
            pqu.push({-bt[last_arrive],{at[last_arrive],last_arrive}});
            last_arrive++;
        }
        if(pqu.empty()){
            if(last_arrive<n){
                pqu.push({-bt[last_arrive],{at[last_arrive],last_arrive}});
                last_arrive++;
            }else{
                break;
            }
        }
        int cur_com = pqu.top().second.second;
        ct[cur_com]=max(ct[pre_com],pqu.top().second.first)+(-pqu.top().first);
        pre_com = cur_com;
        pqu.pop();
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

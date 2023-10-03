#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("001input.txt","r",stdin);
    freopen("001output.txt","w",stdout);
    #endif
    

    int n;
    cin>>n;
    int at[n],bt[n],ct[n],tat[n],wt[n];
    int first_arrival_id=0;
    for(int i=0;i<n;i++){
    	cin>>at[i];
    	if(at[first_arrival_id]>at[i]){
    		first_arrival_id=i;
    	}
    }cout<<first_arrival_id<<endl;
    priority_queue<pair<int,int>> pqu;
    for(int i=0;i<n;i++){
    	cin>>bt[i];
    	if(at[i]==at[first_arrival_id]){
    		pqu.push({-bt[i],i});
    	}
    }


    int com, pre_com;
    pre_com = pqu.top().second;
    cout<<pre_com<<endl;




    return 0;
}
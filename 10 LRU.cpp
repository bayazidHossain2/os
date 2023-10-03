#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("10 input.txt","r",stdin);
    freopen("001output.txt","w",stdout);
    #endif
    

    int nof;
    cout<<"Enter Number of frame: ";
    cin>>nof;
    int nop;
    cout<<"Enter Number of Page: ";
    cin>>nop;
    int page[nop+1];
    for(int i=1;i<=nop;i++){
    	cin>>page[i];
    }
    int ff = 1;
    int frame[nof+1];
    cout<<endl<<"\t\t";
    for(int i=1;i<=nof;i++) {
    	frame[i]=-1;
    	cout<<"F"<<i<<"\t";
    }
    cout<<endl;

    int noh=0;
	for(int i=1;i<=nop;i++){
		cout<<"P"<<page[i]<<"-";
    	bool find=false;
    	for(int p=1;p<ff;p++){
    		if(frame[p]==page[i]){
    			find=true;
    			break;
    		}
    	}

    	if(find){
    		cout<<"H -> ";
    		noh++;
    	}else{
    		cout<<"M -> ";
    		if(ff<=nof){
	    		frame[ff++]=page[i];
	    	}else{
	    		//Find less future demand
	    		int l_f_d=-1,id=1;
	    		for(int j=1;j<=nof;j++){
	    			bool find=false;
	    			for(int k=i-1;k>0;k--){
	    				// cout<<frame[j]<<' '<<page[k]<<endl;
	    				if(frame[j]==page[k]){
	    					find=true;
	    					// cout<<l_f_d<<" "<<k-i<<endl;
	    					if(l_f_d<(i-k)){
	    						l_f_d = i-k;
	    						id=j;
	    					}
	    					break;
	    				}
	    			}
	    			if(!find){
	    				id=j;
	    				// cout<<frame[j]<<" is not find"<<endl;
	    				break;
	    			}
	    		}
	    		frame[id]=page[i];
	    	}
    	}
    	for(int i=1;i<ff;i++){
    		cout<<frame[i]<<"\t";
    	}cout<<endl;
    }

    cout<<"\n\nTotal number of hit is : "<<noh<<endl;
    cout<<"Total number of miss is : "<<nop-noh<<endl;
	cout<<"\n\nHit ratio is : "<<(noh/(nop+0.0)*100)<<"%"<<endl;
    cout<<"Miss ratio is : "<<((nop-noh)/(nop+0.0)*100)<<"%"<<endl;

    return 0;
}
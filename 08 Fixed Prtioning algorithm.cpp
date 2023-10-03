  #include<bits/stdc++.h>
using namespace std;
const int N = 1e4;

int par_sz[N],pro_sz[N],par_holds[N],enternal_farg[N];
int no_par,no_pro; //Number of partitions and numbero of precess

void FirstFit(){
	for(int i=1;i<=no_pro;i++){
		for(int j=1;j<=no_par;j++){
			if(enternal_farg[j]==-1 && pro_sz[i]<=par_sz[j]){
				enternal_farg[j] = par_sz[j]-pro_sz[i];
				par_holds[j]=i;
				break;
			}
		}
	}
}

void BestFit(){
	for(int i=1;i<=no_pro;i++){
		int best_id=-1;
		for(int j=1;j<=no_par;j++){
			if(enternal_farg[j]==-1 && pro_sz[i]<=par_sz[j]){
				if(best_id==-1){
					best_id=j;
				}else{
					if((par_sz[best_id]-pro_sz[i])>(par_sz[j]-pro_sz[i])){
						best_id=j;
					}
				}
			}
		}
		if(best_id!=-1){
			enternal_farg[best_id] = par_sz[best_id]-pro_sz[i];
			par_holds[best_id]=i;
		}
	}
}
void WorstFit(){
	for(int i=1;i<=no_pro;i++){
		int worst_id=-1;
		for(int j=1;j<=no_par;j++){
			if(enternal_farg[j]==-1 && pro_sz[i]<=par_sz[j]){
				if(worst_id==-1){
					worst_id=j;
				}else{
					if((par_sz[worst_id]-pro_sz[i])<(par_sz[j]-pro_sz[i])){
						worst_id=j;
					}
				}
			}
		}
		if(worst_id!=-1){
			enternal_farg[worst_id] = par_sz[worst_id]-pro_sz[i];
			par_holds[worst_id]=i;
		}
	}
}


void print_par(){
	int total_En_F=0;
	for(int i=1;i<=no_par;i++){
		if(enternal_farg[i]==-1){
			cout<<"F"<<i<<" is empty."<<endl;
		}else{
			cout<<"F"<<i<<" holds P"<<par_holds[i]<<" with En.F. : "<<enternal_farg[i]<<endl;
			total_En_F+=enternal_farg[i];
		}
	}
	cout<<"Total Enternal Fragmentation is : "<<total_En_F<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("08 input.txt","r",stdin);
    freopen("001output.txt","w",stdout);
    #endif
    
    cout<<"Enter number of Partition: ";
    cin>>no_par;
    cout<<"Enter number of Process: ";
    cin>>no_pro;
    for(int i=1;i<=no_par;i++){
    	cout<<"Enter "<<i<<"th partition size: ";
    	cin>>par_sz[i];
    	enternal_farg[i]=-1;
    }
    for(int i=1;i<=no_pro;i++){
    	cout<<"Enter "<<i<<"th Process size: ";
    	cin>>pro_sz[i];
    }

    while(true){
    	cout<<"Enter choice \n 1 -> For First Fit\n 2 -> For Best Fit \n 3 -> For Worst Fit \n 4 -> For Exit\n";
    	int choice;
    	cin>>choice;
    	// cout<<"YOUR cchoic is : "<<choice<<endl;
    	switch(choice){
    	case 1:
    		FirstFit();
    		break;
    	case 2:
    		BestFit();
    		break;
    	case 3:
    		WorstFit();
    		break;
    	case 4:
    		exit(1);
    		break;
    	default:
    		cout<<"Wrong choice. Try again.\n";
    	}
    	print_par();
    	break;
    }

    return 0;
}
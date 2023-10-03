#include<bits/stdc++.h>
using namespace std;


int main(){
    #ifndef ONLINE_JUDGE
    freopen("001input.txt","r",stdin);
    freopen("001output.txt","w",stdout);
    #endif
    
	int n;
    cout <<"Enter the buffer size : "<<endl;
    cin >> n;
    cout<<"For produce item enter 1\nFor consume item enter 2\nFor exit enter 3"<<endl;
    int item = 0;
    while(1){
        int choice;
        cin >> choice;
        switch(choice){
          case 1:
          	if(item+1 > n){
                cout <<"Buffer overflow"<<endl;
            }else{
       	        item ++;
          	    cout << "producer produce and item: "<<item << endl;
            }break;
          case 2:
            if(item > 0){
               cout <<"consumer consume and item : "<<item<<endl;
               item --;
            }else{
               cout <<"buffer underflow"<<endl;
            }break;
       	  default:
            exit(0);
       }
   }
   return 0;
}
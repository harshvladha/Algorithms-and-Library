#include <bits/stdc++.h>
using namespace std;
int main() {
    while(true){
    	int n;
    	cin>>n;
    	if(n==0)
    		break;
    	vector<int> coming;
    	stack<int> arrived;
    	stack<int> side;

    	int count = 0;
    	for(int i=0;i<n;i++){
    		int a;
    		cin>>a;
    		coming.push_back(a);
    	}

    	for(vector<int>::iterator it = coming.begin(); it!=coming.end(); it++){
    		if(count == 0 && *it == 1){
    			arrived.push(*it);
    			count++;
    		}else if(count == 0 && *it != 1){
    			side.push(*it);
    		}else if(count > 0 && (*it == (arrived.top() + 1))){
    			arrived.push(*it);
    			count++;
    		}else if(count > 0 && (*it != (arrived.top() + 1))){	
    			side.push(*it);
    		}

    		while(!side.empty() && !arrived.empty()){
    			if((side.top() == (arrived.top()+1))){
	    			arrived.push(side.top());
	    			side.pop();
    			 }else{
    			 	break;
    			 }
    		}
    	}
    	int prev = -1;
    	bool flag = true;
    	while(!side.empty()){
    		if(prev == -1){
    			prev = side.top();
    		}else{
    			if(side.top() < prev){
    				flag = false;
    				break;
    			}else{
    				prev = side.top();
    			}
    		}
    		side.pop();
    	}
    	if(flag){
    		prev = -1;
    		while(!arrived.empty()){
	    		if(prev == -1){
	    			prev = arrived.top();
	    		}else{
	    			if(arrived.top() > prev){
	    				flag = false;
	    				break;
	    			}else{
	    				prev = arrived.top();
	    			}
	    		}
	    		arrived.pop();
	    	}
    	}

    	if(flag){
    		cout<<"yes"<<endl;
    	}else{
    		cout<<"no"<<endl;
    	}

    }
    return 0;
}
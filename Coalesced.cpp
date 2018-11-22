#include<iostream>
#include<list>
using namespace std;
int null=-9999;
int del=-99;
class Coalesced{
	
	protected:
		list<int> *table;
		
	public:
		int size;
		void insert(int);
		void deleted(int);
		int search(int);
		void print();
		Coalesced(int);
		~Coalesced();
};

Coalesced::Coalesced(int size){
	
	this->size=size;
	table=new list<int>[size];
	
}

void Coalesced::insert(int key){
	int i,j;
	int pos=key%size;
	if(table[pos].empty()){
		
		table[pos].push_back(key);
		table[pos].push_back(null);
	}
	
	else{
		
		for(i=size-1;i>=0;i--){
			
			if(table[i].empty()){
				
				table[i].push_back(key);
				table[i].push_back(null);
				
			if(table[pos].back()==null){
				table[pos].push_back(i);
				break;
			}
			
			
			else{
			j=pos;
			while(table[j].back()!=null){
				
				j=table[j].back();
				if(table[j].back()==null){
					table[j].back()=i;
					break;
				}
			}
			break;
		}
			}
		}
	}
}

int Coalesced::search(int key){
	int temp;
	int pos=key%size;
	if(table[pos].front()==key)
	return pos;
	
	else{
	
	   temp=pos;
	   while(temp!=null){
	   	
	   	 if(table[temp].front()==key)
	   	   return temp;
	   	   
	   	temp=table[temp].front();
	   	 
	   }	
		
	}
	
	return -1;
}

void Coalesced::deleted(int key){
	int flag=1,i;
	for(i=0;i<size;i++){
		if(table[i].front()==key){
			flag=1;
			break;
		}
		
		else
		flag=0;
	}
	
	if(flag==0){
		cout<<"Not found"<<endl;
		return ;
	}
	int pos=key%size,temp;
	if(table[pos].front()==key){
	   temp=table[pos].back();
	   while(temp!=null){
	   	temp=table[pos].back();
	   	if(temp==null)
	   	break;
	   	table[pos].front()=table[temp].front();
	   	table[temp].front()=del;
	   	pos=temp;
	   	
	   }
	}
	
	else{
		temp=table[pos].back();
		while(temp!=null){
			
			if(table[temp].front()==key){
				table[temp].front()=del;
				table[pos].back()=table[temp].back();
				table[temp].back()=null;
				
				break;
			}
			
			temp=table[temp].back();
		}
	}
	
	cout<<"Deleted "<<key<<endl;
}

void Coalesced::print(){
	cout<<"===================================="<<endl;
	int i;
	for(i=0;i<size;i++){
		if(table[i].front()==del)
		cout<<"-"<<endl;
		
		else
		cout<<table[i].front()<<endl;
	}
	
}

Coalesced::~Coalesced(){
	
	int i;
	for(i=0;i<size;i++)
	table[i].clear();
}
int main(){
	cout<<"Enter the size"<<endl;
	int sz;
	cin>>sz;
	Coalesced c(sz);
	int i;
	cout<<"Enter the values"<<endl;
	int val;
	for(i=0;i<sz;i++){
		
		cin>>val;
		c.insert(val);
	}
	
	c.print();
	c.deleted(37);
	c.deleted(35);
	c.print();
	return 0;
    c.~Coalesced();
}

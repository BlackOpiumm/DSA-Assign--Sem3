#include<bits/stdc++.h>
using namespace std;
struct student
{
int roll_no;
string name;
float sgpa;
};

void linearsearch(float x,int i,student *s[]){
	bool flag=1;
	for(int j=0;j<i;j++){
		if(s[j]->sgpa==x){
			cout<<s[j]->name<<" "<<s[j]->roll_no<<" "<<s[j]->sgpa<<endl;
			flag=0;
		}
	}
	if(flag){
		cout<<"NO STUDENT PRESENT"<<endl;
	}

}
void bubble_sort(student *s[],int n){
	bool flag=0;
	for(int i=0;i<n-1;i++){
	flag=0;
		for(int j=0;j<n-i-1;j++){
			if((s[j]->roll_no)>s[j+1]->roll_no)
			{
				//swap(s[j],s[j+1]);
				student *temp=new student;
					temp=s[j];
					s[j]=s[j+1];
					s[j+1]=temp;
				flag=1;
			}	
		}
	if(flag==0)break;
	}
	
}
void insertion_sort(student *s[],int n){
      for(int i=1;i<n;i++){
	for(int j=i;j>0;j--){
		if((s[j-1]->name)>s[j]->name){
			//swap(s[j],s[j-1]);
			student *temp=new student;
					temp=s[j];
					s[j]=s[j-1];
					s[j-1]=temp;
	
		}
	}
      }
}
int lomuto(student *s[],int l,int h){
	float pivot=s[h]->sgpa;
	int i=l-1;
	//c(pivot);
	for(int j=l;j<h;j++){
		//c(s[j]);
		if((s[j]->sgpa)>pivot){
			i++;
			swap(s[i],s[j]);
		}
	}//c(i);
	swap(s[i+1],s[h]);
	return (i+1);
}
void qsort(student *s[],int l,int h){
	if(l<h){
		int p=lomuto(s,l,h);
		qsort(s,l,p-1);
		qsort(s,p+1,h);

	}
}


void binarysearch(string s1,int i,student *s[]){

	int st=0;
	int en=i-1;
	int mid=(st+en)/2;
	bool flag=1;
	while(st<=en){
		//cout<<mid<<endl;
		if(s[mid]->name==s1){

			cout<<s[mid]->name<<" "<<s[mid]->roll_no<<" "<<s[mid]->sgpa<<endl;
			flag=0;
			return ;
		}else if(s[mid]->name>s1){
			en=mid-1;
		}else{
			st=mid+1;
		}
		mid=(st+en)/2;
	}
	if(flag)cout<<"NO STUDENT FOUND"<<endl;


}

void display(student *s[],int i){
	for(int j=0;j<i;j++){
		cout<<s[j]->name<<" "<<s[j]->roll_no<<" "<<s[j]->sgpa<<endl;
 	}
}
int main(){
 student *s[60];
 int i=0;
 int n;
 do{
	s[i]=new student;
	cout<<"ENTER THE ROLL NO"<<endl;
	cin>>s[i]->roll_no;
	cout<<"ENTER THE NAME"<<endl;
	cin>>s[i]->name;
	cout<<"ENTER THE SGPA"<<endl;
	cin>>s[i]->sgpa;
	i++;
	cout<<"DO YOU WANT TO CONTINUE"<<endl;
	cin>>n;
 }while(n==1);


 int p;
 		
do{	
	cout<<"press 1 for dispay"<<endl<<"press 2 for linear"<<endl<<"press 3 for binary search"<<endl<<"press 4 for bubble sort"<<endl<<"press 5 for insertion sort"<<endl<<"press 6 for quick sort"<<endl;
        int q;cin>>q;
        
       switch(q){
	     case 1:
			{display(s,i);
			break;}
	     case 2:    
			{cout<<"ENTER THE SGPA"<<endl;
			float x;cin>>x;
			linearsearch(x,i,s);
			break;}
	     case 3:    
			{cout<<"ENTER THE NAME "<<endl;
			string s1;cin>>s1;
			binarysearch(s1,i,s);
			break;}

	     case 4:     
			{bubble_sort(s,i);
			break;}
	     case 5:     
               {insertion_sort(s,i);
			break;}
 	     case 6:
 	     		{
 	     			qsort(s,0,i-1);
 	     			display(s,min(10,i));
 	     			break;
 	     		}


	 }
	 cout<<"DO YOU WISH TO CONTINUE"<<endl;
         cin>>p;
}while(p==1);
 

 
}
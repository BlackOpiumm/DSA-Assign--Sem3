#include<bits/stdc++.h>
using namespace std;

struct node{
	char data;
	node *left;
	node *right;
};




node *create_et2(string s){
	stack<node*> st;
	stack<char> st1;
	int n=s.length();
	for(int i=n-1;i>=0;i--){
		node *temp=new node();
		if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z')){
			temp->data=s[i];
			temp->left=NULL;
			temp->right=NULL;
			st.push(temp);
		}else{
			node *r=st.top();st.pop();
			node *l=st.top();st.pop();
			temp->data=s[i];
			temp->left=r;
			temp->right=l;
			st.push(temp);
		}
	}
	return st.top();
}
node* create_et1(string s){
	stack<node*> st;
	stack<char> st1;
	int n=s.length();
	for(int i=0;i<n;i++){
		node *temp=new node();
		if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z')){
			temp->data=s[i];
			temp->left=NULL;
			temp->right=NULL;
			st.push(temp);
		}else{
			node *l=st.top();st.pop();
			node *r=st.top();st.pop();
			temp->data=s[i];
			temp->left=r;
			temp->right=l;
			st.push(temp);
		}
	}
	return st.top();
}

void post_order(node* root){
	if(root==NULL){
		return ;
	}
	post_order(root->left);
	post_order(root->right);
	cout<<root->data<<"";
}

void in_order(node* root){
	if(root==NULL){
		return ;
	}
	in_order(root->left);
	cout<<root->data<<"";
	in_order(root->right);
	
}

void pre_order(node* root){
	if(root==NULL){
		return ;
	}
	cout<<root->data<<"";
	pre_order(root->left);
	pre_order(root->right);
	
}
void inordern(node *root) //non-Recursive inorder 
{ 
   stack <node *> s; 
   while(!s.empty() || root!=NULL) 
   { 
       while(root!=NULL) 
       { 
           s.push(root); 
           root=root->left; 
       } 
       root=s.top(); 
       s.pop(); 
       cout<<root->data<<""; 
       root=root->right; 
   } 
} 

void preordern(node *root) //non-Recursive preorder 
{ 
   stack <node *> s; 
   while(!s.empty() || root!=NULL) 
   { 
       while(root!=NULL) 
       { 
           cout<<root->data<<""; 
           s.push(root); 
           root=root->left; 
       } 
       root=s.top(); 
       s.pop(); 
       root=root->right; 

   } 
} 

void postordern(node *root) //non-Recursive postorder 
{ 
   stack <node*> s1; 
   stack <int> s2; 
   while(root!=NULL) 
   { 
       s1.push(root); 
       s2.push(0); 
       root=root->left; 
   } 
   while(!s1.empty()) 
   { 
       root=s1.top(); 
       if(s2.top()==1) 
       { 
           s1.pop(); 
           s2.pop(); 
           cout<<root->data<<""; 
       } 
       else 
       { 
           s2.top()=1; 
           root=root->right; 
           while(root!=NULL) 
           { 
               s1.push(root); 
               s2.push(0); 
               root=root->left; 
           } 
       } 
   } 
}


void traversel(node *root) //tree traversal 
{ 
   int ch; 
   cout<<"\n[1] RECURSIVE PREORDER\n"; 
   cout<<"[2] NON RECURSIVE PREORDER\n"; 
   cout<<"[3] RECURSIVE INORDER\n"; 
   cout<<"[4] NON RECURSIVE INORDER\n"; 
   cout<<"[5] RECURSIVE POSTORDER\n"; 
   cout<<"[6] NON RECURSIVE POSTORDER\n"; 
   do 
   { 
       cout<<"\nEnter your choice: (enter -1 to exit)"; 
       cin>>ch; 
       switch(ch) 
       { 
           case 1: pre_order(root); 
           break; 
           case 2: preordern(root); 
           break; 
           case 3: in_order(root); 
           break; 
           case 4: inordern(root); 
           break; 
           case 5: post_order(root); 
           break; 
           case 6: postordern(root); 
           break; 
       } 
   } 
   while(ch!=-1); 
}
int main(){

	string s;
	char n;
	do 
   { 
       cout<<"Construct a EXPRESSION TREE from?\n"; 
       cout<<"[1] POSTFIX EXPRESSION\n"; 
       cout<<"[2] PREFIX EXPRESSION\n"; 
       cout<<"\nEnter your choice: (enter 0 to exit)"; 
       cin>>n; 
       if(n=='1') 
       { 
           cout<<"Enter postfix expression: \n"; 
           cin>>s; 
           node* root=create_et1(s);
           traversel(root);
            
       } 
       else if(n=='2') 
       { 
           cout<<"Enter prefix expression: \n"; 
           cin>>s; 
           node* root=create_et2(s);
           traversel(root);
       } 
   } 
   while(n!='0');



	return 0;
}
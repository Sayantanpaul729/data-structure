#include <iostream.h>
#include <bits/stdc++.h>
#include <queue> 

class bst
{   
    struct node
{
  public: int data;
          node* right;
          node* left;
};
    public: node* root;
    
    bst()
    {
        root=NULL;
    }
    void insert(int a)
    {   node* ptr=new node;
        node* p=new node;
        node* p1=new node;
        ptr->data=a;
        ptr->right=NULL;
        ptr->left=NULL;
        if(root==NULL)
        {
            root=ptr;
        }
        else
        {
            p=root;
            while(p!=NULL)
            {
                if(a<p->data)
                {
                    p1=p;
                    p=p->left;
                }
                else
                {
                    p1=p;
                    p=p->right;
                }
            }
            if(a<p1->data)
            {
               p1->left=ptr;
            }
            else
            {
               p1->right=ptr;
            }
        }
    }
    void rec_inorder(node* ptr)
    {     if(ptr!=NULL)
        {
            rec_inorder(ptr->left);
            cout<<ptr->data<<" ";
            rec_inorder(ptr->right);
        }
    }
    void rec_preorder(node* ptr)
    {
        if(ptr!=NULL)
        {
            cout<<ptr->data<<" ";
            rec_preorder(ptr->left);
            rec_preorder(ptr->right);
        }
    }
    void rec_postorder(node* ptr)
    {   if(ptr!=NULL)
      {
        rec_postorder(ptr->left);
        rec_postorder(ptr->right);
        cout<<ptr->data<<" ";
      }
    }
    void it_preorder(node* ptr)
    {
      stack <node*> s;   
      if(ptr!=NULL)
      {
          s.push(ptr);
          while(!s.empty())
          {
              ptr=s.top();
              s.pop();
              cout<<ptr->data<<" ";
              if(ptr->right!=NULL)
              {
                 s.push(ptr->right);
              }
              if(ptr->left!=NULL)
              {
                 s.push(ptr->left);
              }
          }
      }
    }
    void it_Inorder(node* ptr)
    {
        stack <node*> s;
     while(ptr!=NULL||!s.empty())
     {
        while(ptr!=NULL)
        {
           s.push(ptr);
           ptr=ptr->left;
        }
            ptr=s.top();
            s.pop();
            cout<<ptr->data<<" ";
            ptr=ptr->right;
     }
    }
    void it_postorder(node* ptr)
    {
        stack <node*> s1;
        stack <node*> s2;
        s1.push(ptr);
        while(!s1.empty())
        {
            ptr=s1.top();
            s1.pop();
            s2.push(ptr);
            if(ptr->left!=NULL)
            {
            s1.push(ptr->left);
            }
            if(ptr->right!=NULL)
            {
            s1.push(ptr->right);
            }
        }
        while(!s2.empty())
        {
            cout<<s2.top()->data<<" ";
            s2.pop();
        }
    }
    void search(int n)
    {   int flag=0,i=0;
        node* ptr=new node;
        node* ptr1=new node;
        ptr=root;
        if(root==NULL)
        {
            cout<<"Binary search tree is empty "<<endl;
        }
        else
        {
            while(ptr!=NULL)
            {
                if(n<ptr->data)
                {
                    ptr1=ptr;
                    ptr=ptr->left;
                    i++;
                }
                else
                if(n==ptr->data)
                {
                    cout<<"Your entered data "<<n<<" is present in Binary Search Tree at "<<i<< " th level"<<endl;
                    flag=1;
                    break;
                }
                else
                {
                    ptr1=ptr;
                    ptr=ptr->right;
                    i++;
                }
            }
            if(flag==0)
            {
            cout<<"Your entered data "<<n<<" is not present in the Binary Search Tree "<<endl;
            }
        }
    }
    void bfs(node* ptr)
    {
        queue <node*> q;
        q.push(ptr);
        node* n=new node;
        while(!q.empty())
        {   
            n=q.front();
            cout<<n->data<<" ";
            q.pop();
            if(n->left!=NULL)
            {
                q.push(n->left);
            }
            if(n->right!=NULL)
            {
                q.push(n->right);
            }
        }
    }
    void mirror(node* ptr)
    {   node* temp=new node;
        if(ptr==NULL)
        {
            return;
        }
        else
        {
            mirror(ptr->left);
            mirror(ptr->right);
            temp=ptr->left;
            ptr->left=ptr->right;
            ptr->right=temp;
        }
    }
    void number(node* ptr)
    {   int i=0;
        int j=1;
       queue <node*> q;
        q.push(ptr);
        node* n=new node;
        while(!q.empty())
        {   
            n=q.front();
            q.pop();
            if(n->left!=NULL)
            {
                q.push(n->left);
                j++;
            }
            if(n->right!=NULL)
            {
                q.push(n->right);
                j++;
            }
            if(n->right==NULL&&n->left==NULL)
            {
                i++;
            }
        }
        cout<<"Total no. of nodes are: "<<j<<endl;
        cout<<"Total no. of leaves are: "<<i<<endl;
        cout<<"Total no. of non leaves are: "<<j-i<<endl;
    }
    void rep(int n1,int n2)
    {
      int flag=0;
        node* ptr=new node;
        node* ptr1=new node;
        ptr=root;
        if(root==NULL)
        {
            cout<<"Binary search tree is empty "<<endl;
        }
        else
        {
            while(ptr!=NULL)
            {
                if(n1<ptr->data)
                {
                    ptr1=ptr;
                    ptr=ptr->left;
                }
                else
                if(n1==ptr->data)
                {
                    //delete_merge(root,n1);
                    insert(n2);
                    flag=1;
                    break;
                }
                else
                {
                    ptr1=ptr;
                    ptr=ptr->right;
                }
            }
            if(flag==0)
            {
            cout<<"Your entered data "<<n1<<" is not present in the Binary Search Tree "<<endl;
            }
        }  
    }
    int height(node* ptr)
    {    int l,r;
        if(ptr == NULL)
             return 0;
        l=height(ptr->left);
        r=height(ptr->right);
        if(l>=r)
        {
            return l+1;
        }
        else
        {
            return r+1;
        }
    }
    void delete_merge(node* temp,int n)
    {
        node* prev=NULL;
        while(temp!=NULL)
        {
            if(temp->data==n)
            {
                break;
            }
            prev=temp;
            if(temp->data<n)
            {
                temp=temp->right;
            }
            else
            {
                temp=temp->left;
            }
        }
        if(temp!=NULL&&temp->data==n)
        {
            if(temp==root)
            {
                delm(root);
            }
            else
            if(prev->left==temp)
            {
                delm(prev->left);
            }
            else
            if(prev->right==temp)
            {
                delm(prev->right);
            }
        }
        else
        if(root!=NULL)
        {
            cout<<temp->data<<" is not present in tree"<<endl;
        }
        else
        {
            cout<<"Tree is empty"<<endl;
        }
    }
    void delm(node*& temp1)
    {
        node* tmp=temp1;
        if(temp1!=NULL)
        {
            if(temp1->right==NULL)
            {
                temp1=temp1->left;
            }
            else
            if(temp1->left==NULL)
            {
                temp1=temp1->right;
            }
            else
	       {
		      tmp=temp1->left;
	          while(tmp->right!=NULL)
		      {
		        tmp=tmp->right;
		      }
		   tmp->right=temp1->right;
		   tmp=temp1;
		   temp1=temp1->left;
	       }
	       cout<<"Node deleted"<<endl;
	      delete tmp;
        }
    }
    void delete_copy(node* temp,int n)
    {
        node* prev=NULL;
        while(temp!=NULL)
        {
            if(n==temp->data)
            {
                break;
            }
            prev=temp;
            if(n>temp->data)
            {
                temp=temp->right;
            }
            else
            if(n<temp->data)
            {
                temp=temp->left;
            }
        }
        if(temp!=NULL&&temp->data==n)
        {
            if(temp==root)
            {
                delc(root);
            }
            else
            if(prev->left==temp)
            {
                delc(prev->left);
            }
            else
            if(prev->right==temp)
            {
                delc(prev->right);
            }
        }
        else
        if(root!=NULL)
        {
            cout<<temp->data<<" is not present in tree"<<endl;
        }
        else
        {
            cout<<"Tree is empty"<<endl;
        }
    }
    void delc(node*& temp1)
    {
        
	node* prev,*tmp=temp1;
	if(temp1->right==NULL)
		 temp1=temp1->left;
	else if(temp1->left==NULL)
		  temp1=temp1->right;
	else
	 {
		tmp=temp1->left;
		prev=temp1;
		while(tmp->right!=NULL)
		 {
			prev=tmp;
			tmp=tmp->right;
		 }
		temp1->data=tmp->data;
		if(prev==temp1)
			  prev->left=tmp->left;
		else
			  prev->right=tmp->left;
	 }
	 cout<<"Node deleted"<<endl;
	delete tmp;
 
    }
};


void main()
{   int a,n,n1,n2,n3,n4;
    char ch='y';
    bst obj;
    do{
    cout<<"Insert data in BST"<<endl;
    cin>>a;
    obj.insert(a);
    cout<<"Do you want to continue? "<<endl;
    cin>>ch;
    }while(ch=='y'||ch=='Y');
    int choice,flag=1;
 while(flag==1)
 {  cout<<"0 : Exit"<<endl;
    cout<<"1 : Recursive Inorder traversal"<<endl;
    cout<<"2 : Recursive preorder traversal"<<endl;
    cout<<"3 : Recursive postorder traversal"<<endl;
    cout<<"4 : Searching an element"<<endl;
    cout<<"5 : Iterative preorder traversal"<<endl;
    cout<<"6 : Iterative Inorder traversal"<<endl;
    cout<<"7 : Iterative postorder traversal"<<endl;
    cout<<"8 : Level by level traversal (BFS)"<<endl;
    cout<<"9 : Mirror image of tree"<<endl;
    cout<<"10: Count the non-leaf, leaf and total number of nodes"<<endl;
    cout<<"11: Search and replace"<<endl;
    cout<<"12: Height of tree"<<endl;
    cout<<"13: Deletion by merging"<<endl;
    cout<<"14: Deletion by copying"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 0: 
                flag=0;
                break;
        case 1: 
                 cout<<"Inorder traversal is: "<<endl;
                 obj.rec_inorder(obj.root);
                 cout<<endl;
                 break;
        case 2:
                cout<<"Preorder traversal is: "<<endl;
                obj.rec_preorder(obj.root);
                cout<<endl;
                break;
        case 3:
                cout<<"postorder traversal is: "<<endl;
                obj.rec_postorder(obj.root);
                cout<<endl;
                break;
        case 4:
                cout<<"Enter data you want to search "<<endl;
                cin>>n;
                obj.search(n);
                break;
        case 5:
                cout<<"Iterative preorder traversal is: "<<endl;
                obj.it_preorder(obj.root);
                cout<<endl;
                break;
         case 6:
                cout<<"Iterative Inorder traversal is: "<<endl;
                obj.it_Inorder(obj.root);
                cout<<endl;
                break;
        case 7:
                cout<<"Iterative postorder traversal is: "<<endl;
                obj.it_postorder(obj.root);
                cout<<endl;
                break;
        case 8:
                cout<<"level by level traversal (BFS) is: "<<endl;
                obj.bfs(obj.root);
                cout<<endl;
                break;
        case 9:
                cout<<"Mirror image of tree is created "<<endl;
                obj.mirror(obj.root);
                cout<<"BFS traversal of mirror image of tree is: ";
                obj.bfs(obj.root);
                cout<<endl;
                break;
        case 10:
                obj.number(obj.root);
                cout<<endl;
                break;
        case 11:
                cout<<"Enter data you want to search"<<endl;
                cin>>n1;
                cout<<"Enter data you want to replace"<<endl;
                cin>>n2;
                obj.rep(n1,n2);
                break;
        case 12:
               cout<<"Height of tree is: "<<obj.height(obj.root)<<endl;
               break;
        case 13:
               cout<<"Enter the node you want to delete"<<endl;
               cin>>n3;
               obj.delete_merge(obj.root,n3);
               cout<<endl;
               break;
        case 14:
               cout<<"Enter the node you want to delete"<<endl;
               cin>>n4;
               obj.delete_copy(obj.root,n4);
               cout<<endl;
               break;
        default: cout<<"invalid input"<<endl;
    }
 }
    
}

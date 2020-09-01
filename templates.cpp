#include <iostream.h>
#include <stdio.h>
#include<process.h>
#include<conio.h>


#define M 10

template <class T>

class Stack
{
	T arr[M];

 public:

     T item,r;
     int top;

     Stack()
     {
     	top=-1;
     } 	

     void push(T a)
     {
     	if(top==M)
     		cout<<"\nStack is full";
     	else
     	    arr[++top] = a;
     }

     T pop()
     {
     	if(top==-1)
     	{
     		cout<<"\nStack is empty";
     	
     	}
     	else
     		return arr[top--];
     }

     void clear()
     {
         while(top!=-1)
         {
         	cout<<arr[top--]<<"->";
         }
         cout<<"NULL\n";

         
     }
};


void main()
{
    clrscr();

    Stack <int>s;
    int ch;
    while(1)
    {
    	cout<<"\n1.PUSH\n2.POP\n3.CLEAR\n4.exit\n";
    	cin>>ch;
    	switch(ch)
    	{
          case 1:
                  cout<<"\nEnter the value to be pushed : ";
                  cin>>s.item;
                  s.push(s.item);
                  break;
          case 2:
                  s.r = s.pop();
                  cout<<"\nValue popped out is : "<<s.r;
                  break;
          case 3:
                  s.clear();
                  break;
	  case 4:
		  exit(0);
          default:
                  cout<<"\nEnter a valid choice";              
    	}
    }

getch();
}

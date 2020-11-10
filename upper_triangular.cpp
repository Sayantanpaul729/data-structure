#include<iostream.h>

class diagonal
{
	int *d;
	int n;
public:
	 diagonal(int size=10)
	 {
	 	 n=size;
	 	 if(size!=0)
	 	 {
	 	 	d=new int[n*(n+1)/2];
	 	 }
	 	 else
	 	 	d=0;
	 }
	 ~diagonal()
	 {
	 	delete []d;
	 }
	 void store(int x,int i,int j);
	 int retrieve(int i,int j);
	 void show();
	
	 
   };

void diagonal::store(int x,int i,int j)
{
	int k=0;
	if(i<1||i>n||j<1||j>n)
	{
		std::cout<<"\nOut of bound";
		exit(0);
	}
	else if(i>j&&x!=0)
		std::cout<<"\nMust be zero";
	else if(j>=i)
	{
        k= (j*(j-1)/2+i-1);
		d[k]=x;
	}
}


int diagonal::retrieve(int i,int j)
{
	int k=0;
	 if(i<1||i>n||j<1||j>n)
	 {
	 	std::cout<<"\nOut of bound";
	 }
	 else if (j>=i)
	 {
	 	k= (j*(j-1)/2+i-1);
	 	return d[k];
	 }	
	 else 
	 	return 0;
}	 


void diagonal::show()
{
	std::cout<<"\nSparse matrix : ";
	for (int i = 0; i < n*(n+1)/2; ++i)
	{
		cout<<d[i]<<" ";
	}
    
    std::cout<<"\nComplete matrix :\n"; 
    int z=1;
	for(int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
		{
			if(i>j)
				std::cout<<"0"<<" ";
			else
				std::cout<<d[j*(j-1)/2+i-1]<<" ";
		}
		std::cout<<"\n";
	}

}



void main()
{

	int m1=0,m2=0,y=0,i=0,j=0;
	std::cout<<"\nEnter the size of diagonal matrix : \n";
	std::cin>>m1>>m2;
	if(m1!=m2)
	{
		std::cout<<"\nInvalid size";
		exit(0);
	}  
	diagonal ob(m1);
	

	std::cout<<"\nEnter the elements of array : \n";
	for (i = 1; i <= m1; ++i)
	{
		for (j = 1; j <= m2; ++j)
		{
			if(j>=i)
			{
				
				cin>>y;
	            ob.store(y,i,j);
			}
		}
	}
	std::cout<<"\nMatrix is : \n";
    ob.show(); 
    std::cout<<"\nEnter the location of retrieval : \n";
    std::cin>>i>>j;
    cout<<"Retrieved value is : "<<ob.retrieve(i,j)<<"\n";
	
}
#include <iostream.h>
#include <math.h>

int arr[30],size;
int l,r,min1;

void heap_dec_key(int arr[],int i,int n)
{   int p=floor(i/2);
    arr[i]=n;
    while(i>1&&arr[p]>arr[i])
    {
        swap(arr[i],arr[p]);
        i=floor(i/2);
        p=floor(i/2);
    }
}

void insert(int arr[],int val,int size)
{
    
    arr[size]=-100;
    heap_dec_key(arr,size,val);
}

void min_heapify(int arr[],int ele,int size)
{   
    l=2*ele;
    r=2*ele+1;
    min1=ele;
    if(l<=size&&arr[ele]>arr[l])
    {
        min1=l;
    }
    if(r<=size&&arr[min1]>arr[r])
    {
        min1=r;
    }
    if(min1!=ele)
    {
        swap(arr[min1],arr[ele]);
        min_heapify(arr,min1,size);
    }
}

int min_heap(int arr[])
{
    return arr[1];
}


void ex_min_heap(int arr[],int size)
{
    if(size==0)
    {
        cout<<"There is no element in the tree"<<endl;
    }
    else
    {
        arr[1]=arr[size];
        size--;
        min_heapify(arr,1,size);
    }
}


void build_min_heap(int arr[],int size)
{
       int index=floor(size/2);
       for(int i=index;i>=1;i--)
       {
        min_heapify(arr,i,size);
       }
}


void main()
{   int size,ele;
    cout<<"Enter size of priority queue"<<endl;
    cin>>size;
    arr[size];
    for(int i=1;i<=size;i++)
    {
        cout<<"Enter element "<<i<<": "<<endl;
        cin>>arr[i];
    }
    cout<<"priority queue you entered"<<endl;
    for(int i=1;i<=size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
    cout<<"Applying min heapify on element "<<arr[1]<<endl;
    build_min_heap(arr,size);
    cout<<"Priority queue after apply min heapify: "<<endl;
    for(int i=1;i<=size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
    cout<<"0: Exit"<<endl;
    cout<<"1: Heap decrease key"<<endl;
    cout<<"2: Insert"<<endl;
    cout<<"3: Heap minimum"<<endl;
    cout<<"4: Heap extract minimum"<<endl;
    int n,in,val,val1;
    char ch;
    do
    {   cout<<"\nEnter your choice: "<<endl;
        cin>>n;
     switch(n)
     {
        case 0: exit(0);
                break;
        case 1: cout<<"Enter index: "<<endl;
                cin>>in;
                cout<<"Enter value: "<<endl;
                cin>>val;
                heap_dec_key(arr,in,val);
                cout<<"Priority queue after implementing heap decrease key"<<endl;
                for(int i=1;i<=size;i++)
                {
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
                break;
        case 2: cout<<"Enter value to be inserted: "<<endl;
                cin>>val1;
                size++;
                insert(arr,val1,size);
                cout<<"Priority queue after inserting "<<val1<<": "<<endl;
                for(int i=1;i<=size;i++)
                {
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
                break;
        case 3: cout<<"Minimum element in the heap is: ";
                cout<<min_heap(arr)<<endl;
                break;
        case 4: cout<<"Extracting minimum element from the heap"<<endl;
                ex_min_heap(arr,size);
                cout<<"After extracting Priority queue is: "<<endl;
                size--;
                for(int i=1;i<=size;i++)
                {
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
                break;
        default: cout<<"Invalid input"<<endl;
     }
    cout<<"Do you want to continue?"<<endl;
    cin>>ch;
    }while(ch=='y'||ch=='Y');
    
}
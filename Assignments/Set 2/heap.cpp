#include<iostream>
using namespace std;
void insHeap(int *heap,int e,int &heap_size,int n);
void delHeap(int *heap,int &heap_size,int n);
void heapify(int *heap,int i,int heap_size);
int* alloc1DArray(int n);
void display1DArray(int *heap,int heap_size);
void swap(int &a,int &b);
void dealloc1DArray(int *heap);
int main()
{
    int *heap=NULL;
    int i, heap_size=0, n, e, choice;
    cout<<"Input maximum size of heap: ";
    cin>>n;
    heap=alloc1DArray(n);
    do
    {
        cout<<"Enter choice:\n1. Insert element\n2. Delete element\n3. Display heap\n4. Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"Enter element to be inserted: ";
                    cin>>e;
                    insHeap(heap,e,heap_size,n);
                    break;
            case 2: delHeap(heap,heap_size,n);
                    break;
            case 3: display1DArray(heap,heap_size);
                    break;
            case 4: cout<<"Exiting...";
                    break;
        }
    }while(choice!=4);
    dealloc1DArray(heap);
    return 0;
}
void insHeap(int *heap,int e,int &heap_size,int n)
{
    if(heap_size==n)
    {
        cout<<"Heap overflow.\n";
        return;
    }
    int i, parent;
    heap[heap_size]=e;
    i=heap_size;
    parent=(i-1)/2;
    heap_size++;
    while(parent>=0 && heap[i]>heap[parent])
    {
        swap(heap[i],heap[parent]);
        i=parent;
        parent=(i-1)/2;
    }
}
void delHeap(int *heap,int &heap_size,int n)
{
    if(heap_size==0)
    {
        cout<<"Heap underflow.\n";
        return;
    }
    heap[0]=heap[heap_size-1];
    heap_size--;
    heapify(heap,0,heap_size);
}
void heapify(int *heap,int i,int heap_size)
{
    int lchild=2*i+1, rchild=2*i+2, largest=i;
    if(lchild<heap_size && heap[lchild]>heap[largest])
        largest=lchild;
    if(rchild<heap_size && heap[rchild]>heap[largest])
        largest=rchild;
    if(largest!=i)
    {
        swap(heap[i],heap[largest]);
        heapify(heap,largest,heap_size);
    }
}
int* alloc1DArray(int n)
{
    int *t=new int[n];
    return t;
}
void display1DArray(int *heap,int heap_size)
{
    int i;
    cout<<"Displaying heap as a 1D array as follows:\n";
    for(i=0;i<heap_size;i++)
        cout<<heap[i]<<' ';
    cout<<endl;
}
void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
void dealloc1DArray(int *heap)
{
    delete[] heap;
}

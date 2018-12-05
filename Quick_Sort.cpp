#include<iostream>
using namespace std;
class Quicksort
{
      public:
        void quicksort(int* ,int ,int);
       int partition(int* ,int,int);
};

int Quicksort::partition(int *a,int s,int e)
{
       int pivot=a[e];
       int part=s;
       int i,t;
for(i=s;i<e;i++)
    {
	if(a[i]<=pivot)
              {
               	t=a[i];
                            a[i]=a[part];
                            a[part]=t;
                            part++;
               }
     }
    t=a[e];
    a[e]=a[part];
    a[part]=t;
    return part;
}

void Quicksort::quicksort(int *a,int s,int e)
{
	if(s<e)
	{
		int part=partition(a,s,e);
                             quicksort(a,s,part-1);
                             quicksort(a,part+1,e);
	}
}
int main()
{
	Quicksort q1;
	int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
    {
	cin>>a[i];
	}
	q1.quicksort(a,0,n-1);
for(int i=0;i<n;i++)
    {
	cout<<a[i]<<" ";
	}
	return 0;
}


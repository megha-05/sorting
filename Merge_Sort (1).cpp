#include<iostream>

using namespace std;

void Merge(int A[],int p, int q,int r)     /*It merges two arrays */
{

	int n1=q-p+1,i,j,k;       /*n1 is the size of left[]*/

	int n2=r-q;               /*n2 is the size of right[]*/

	int left[n1],right[n2];

	for(i=0;i<n1;i++)

	{
		left[i]=A[p+i];
	}

	for(j=0;j<n2;j++)
	{
		right[j]=A[q+j+1];
	}

	i=0,j=0;

	for(k=p;i<n1&&j<n2;k++)
	{
		if(left[i]<right[j])
		{
			A[k]=left[i++];
		}
		else
		{
			A[k]=right[j++];
		}
	}

	while(i<n1)             /*If left[] has more elements than right[] then it will put all the remaining elements of left[] into A[]*/
	{
		A[k++]=left[i++];
	}

	while(j<n2)             /*If right[] has more elements than left[] then it will put all the remaining elements of right[] into A[]*/
	{
		A[k++]=right[j++];
	}
}

void MergeSort(int A[],int p,int r)    /*It will will divide the array and sort them while merging them*/
{
	int q;

	if(p<r)
	{
		q=(p+r)/2;                      /*q is the middle element to divide the array*/
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		Merge(A,p,q,r);
	}

}


int main()
{

	int n;                          /*n size of A[]*/

	cout<<"Enter number of elements :";

	cin>>n;

	int A[n];

	cout<<"Enter the array elements :";

	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}

	MergeSort(A,0,n-1);
	cout<<"After Sorting :";

	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}

	cout<<endl;
}

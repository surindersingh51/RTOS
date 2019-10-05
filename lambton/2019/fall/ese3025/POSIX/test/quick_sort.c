#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// This is the thread function that will execute when the thread is created
//  it passes and receives data by void pointers
void	*quicksort(void *arr)
{
	int		*x = (int *) arr;	// cast the passed data to integer type
	int		size = sizeof(x);				// storage for the sum
	//int min = 0;
	int max = size-1;
	int i=0,j=0,pivot=0,temp=0;

	if(i<j)
	{
			while(x[i]<=x[pivot]&& i < max)
				i++;
			while(x[j]>x[pivot])
				j--;
		if(i<j)
		{
			temp=x[i];
			x[i]=x[j];
			x[j]=temp;
		}

		temp=x[pivot];
		x[pivot]=x[j];
		x[j]=temp;
/*pthread_t p1,p2;
pthread_create(&p1,NULL,&quicksort,&x)
pthread_create(&p2,NULL,&quicksort,&x)
*/}
	return (int *)x; // return the set, unchanged
}

int main()
{
  //  int x=0, y=0;
    pthread_t thread;         //this is our handle to the pthread
   int s=0,arr[100];

	printf("Enter the number of elements in array: ");
	scanf("%d",&s);

	printf("Enter the elements of array to be sorted: ");
	for(int i=0;i<s;i++)
	{
		scanf("%d",&arr[i]);
	}


   // create the thread, pass the reference, address of the function and data
    // pthread_create() returns 0 on the successful creation of a thread
    if(pthread_create(&thread, NULL, &quicksort, &arr)!=0)
    {
    	printf("Failed to create the thread\n");
    	return 1;
    }
    // at this point the thread was created successfully
            // OPTIONAL: receive data back from pthread
    void* result;
    pthread_join(thread, &result);   // allow the pthread to complete
    int *z = (int *) result;         // cast from void* to int* to get z

for(int i=0;i<s;i++)
{
	printf("%d ",z[i]);
}
   // printf("Final: x=%d, y=%d and z=%d\n",x,y,*z);
    //return EXIT_SUCCESS;
return 0;
}

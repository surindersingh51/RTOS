
/*half way done for it..soon will be completed*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/*Structure to send multiple arguments in a thread*/
struct array_para
{
	int max;
	int min;
	int arr[];
};

/*
 * thread function sorts data set in its current set
 */
void *quick_sort(int *arr)
{
	int arr_size = sizeof(arr[]);
	int pivot = arr_size-1;
	int max = arr_size-1;
	int min = 0
}

int main()
{
	struct array_para arg;
	pthread_t thread;
	int s=0; //variable for size of array
	int arr[]=0;//array initializing

	printf("Enter the number of elements in array: ");
	scanf("%d",&s);

	printf("Enter the elements of array to be sorted: ");
	for(int i=0;i<s;i++)
	{
		scanf("%d",&arr[i]);
	}

	arg.arr = arr[];
	arg.max = s-1;
	 =

	if(pthread_create(&thread,NULL,*quick_sort,&arg)!=0)
	{
	printf("Thread not created!!");
	return 0;
	}

	int result_arr[s]=quick_sort(arr[]);

	printf("Sorted Array: ");

	for(int i=0;i<s;i++)
			printf(" %d "&result_arr[i]);

	return 0;
}





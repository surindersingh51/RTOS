

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/*Structure to send multiple arguments in a thread*/
struct array_para
{
	int max;
	int min;
	int arr[100];
};

/*
 * thread function sorts data set in its current set
 */
void *quick_sort(int *struct_args)
{
	struct array_para *args = (struct array_para *) struct_args;
	//struct array_para arg1,arg2;
	/*int max = args->max;
	int min = args->min;
	int a[size];
	int a[size]=args->arr;*/
	int size = sizeof(args->arr);
	int min,max,a[size];
	struct array_para *arg = {min,max,a[size]};
	int pivot= min;
	int temp=0;
	pthread_t thread_2;
	pthread_t thread_3;
	int i=min;
	int j=max;

if(i<j)
{
		while(a[i]<=a[pivot]&&a<max)
			i++;
		while(a[j]>a[pivot])
			j--;
	if(i<j)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}

	temp=a[pivot];
	a[pivot]=a[j];
	a[j]=temp;

	struct array_para arg1 = {min,j-1,a[size]};
	struct array_para arg2 = {j+1,max,a[size]};
/*
	arg1.min = min;
	arg1.max = j-1;
	arg1.arr= a[];

	arg2.min = j+1;
	arg2.max = max;
	arg2.arr=a[];
*/
pthread_create(thread_2,NULL,*quick_sort,&arg1);
pthread_create(thread_3,NULL,*quick_sort,&arg2);
pthread_join(thread_2,NULL);
pthread_join(thread_3,NULL);
}
return *a;
}

int main()
{
	//struct array_para arg;
	pthread_t thread;
	int s=0; //variable for size of array
	int arr[10];//array initializing

	printf("Enter the number of elements in array: ");
	scanf("%d",&s);

	printf("Enter the elements of array to be sorted: ");
	for(int i=0;i<s;i++)
	{
		scanf("%d",&arr[i]);
	}

	/*strcpy(arg.arr,arr[s]);
	//arg.arr = arr[s];
	arg.max = s-1;
	arg.min = 0;
*/
	struct array_para arg = {0,s-1,arr[s]};
	if(pthread_create(&thread,NULL,*quick_sort,&arg)!=0)
	{
	printf("Thread 1 not created!!");
	return 0;
	}


	printf("Sorted Array: ");

	for(int i=0;i<s;i++)
			printf(" %d ",&arg.arr[i]);

	return 0;
}


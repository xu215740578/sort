#include <stdio.h>

#define swap(a,b) {a=a^b;b=a^b;a=a^b;}


/**
 *冒泡排序算法
 *1.比较相邻的元素。如果第一个比第二个大，就交换他们两个。
 *2.对每一对相邻元素做同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
 *3.针对所有的元素重复以上的步骤，除了最后一个。
 *4.持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
**/
void bubble_sort(int array[], int n)
{
	int i , j;
	int changed;
	for(i = n-1; i > 0; --i)
	{
		changed = 0;
		for(j = 0; j < i; ++j)
		{
			if(array[j] > array[j+1])
			{
				swap(array[j], array[j+1]);
				changed = 1;
			}
		}
		if(changed == 0)
		{
			break;
		}
	}
}

/**
 *插入排序
 *1.先假设第一个元素有序，则第一轮从第二个元素开始，作为待插入的数，往前依次比较，看往哪里插
 *2.第二轮把下一个元素（第三个）插入到其对应于已排序元素的排序位置
 *3.对于数组中的每个元素重复2步骤。即把第四个元素插入到适当位置，然后是第5个元素，等等。
**/
void insertion_sort(int array[], int n)
{
	int i, j, temp;
	for(i = 1; i < n; ++i)
	{
		temp = array[i];
		for (j = i-1; j >= 0 && temp < array[j]; --j)
		{
			array[j+1] = array[j];
		}
		array[j+1] = temp;
	}
}

/**
**/
void selection_sort(int array[], int n)
{
	int i, j, minPos;
	for(i = 0; i < n; ++i)
	{
		minPos = i;
		for(j = i; j < n; ++j)
		{
			if(array[minPos] > array[j])
			{
				minPos = j;
			}
		}
		if(minPos != i)
		{
			swap(array[minPos], array[i]);
		}
	}
}

void double_selection_sort(int array[], int n)
{
	if(n <= 1)
		return;
	int i, j, minPos, maxPos, temp;
	for (i = 0; i < n/2-1; ++i)
	{
		minPos = i;
		maxPos = n-i-1;
		for (j = i; j < n-i; ++j)
		{
			if (array[j] < array[minPos])
			{
				minPos = j;
			}
			if (array[j] > array[maxPos])
			{
				maxPos = j;
			}
		}

		if(minPos != i)
		{
			swap(array[i], array[minPos]);
		}

		if(maxPos != n-i-1)
		{
			if(maxPos == i)
			{////若当前最大值在循环起始位置，则最大值一定在(1)处被交换到了minPos的位置
				maxPos = minPos;
			}
			swap(array[n-i-1], array[maxPos]);
		}
	}
}

int main()
{
	int i;
	int array[10] = {2,4,7,6,5,8,3,9,1,0};
	//bubble_sort(array, sizeof(array)/sizeof(int));
	//insertion_sort(array, sizeof(array)/sizeof(int));
	selection_sort(array, sizeof(array)/sizeof(int));
	for (i = 0; i < sizeof(array)/sizeof(int); ++i)
	{
		printf(" %d", array[i]);
	}
	printf("\n");
	return 0;
}

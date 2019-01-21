#include <stdio.h>

#define swap(a,b) {int temp=a; a=b; b=temp;}


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

/* 
 *算法分析:    
    time-complexity: 最好情况下时间复杂度为O(nlog2n),待排序列接近无序，算法效率越高。
                     最坏情况下时间复杂度为O(n2),待排序列月接近有序，算法效率越低。
                     平均情况下时间复杂度为O(nlog2n);
    space-complexity O(log2n)

 *原理:
    通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，
    然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列
*/
void quick_sort(int a[], int low, int high)
{
	int pivot;
	int i = low, j = high;
	if (low < high)
	{
		pivot = a[low];    //将第一个元素作为枢轴
		while(i < j)
		{
			while(i < j && a[j] >= pivot) //从右往左找到第一个小于枢轴的数
				j--;
			if(i < j)
			{ //将该数移动到左指针的位置
				a[i] = a[j];
				i++;
			}
			while(i < j && a[i] < pivot) //从左往右找到第一个大于等于枢轴的数
				i++;
			if(i < j)
			{ //将该数移动到右指针的位置
				a[j] = a[i];
				j--;
			}
		}
		a[i] = pivot; //循环退出时i == j即枢轴的位置
		//递归处理当前枢轴的左右两部分
        quick_sort(a, low, i-1);
        quick_sort(a, i+1, high);
	}
}

void qsort(int a[], int left, int right)
{
	int index = left;
	int pivot = a[left];
	int l=left,r=right;

	while(l<r)
	{
		for(; l<r && a[r]>pivot; --r);
		swap(a[r], a[index]);
		index = r;
		for(; l<r && a[l]<=pivot; ++l);
		swap(a[l], a[index]);
		index = l;
	}
	if(left < index-1)
		qsort(a, left, index-1);
	if(right > index+1)
		qsort(a, index+1, right);
}

int main()
{
	int i;
	int array[10] = {2,4,7,6,5,8,3,9,1,0};
	printf("input array:\n");
	for (i = 0; i < sizeof(array)/sizeof(int); ++i)
	{
		printf(" %d", array[i]);
	}
	printf("\n");

	//bubble_sort(array, sizeof(array)/sizeof(int));
	//insertion_sort(array, sizeof(array)/sizeof(int));
	//selection_sort(array, sizeof(array)/sizeof(int));
	//double_selection_sort(array, sizeof(array)/sizeof(int));
	quick_sort(array, 0, 9);
	printf("sorted array:\n");
	for (i = 0; i < sizeof(array)/sizeof(int); ++i)
	{
		printf(" %d", array[i]);
	}
	printf("\n");
	return 0;
}

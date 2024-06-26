#pragma once
#include <iostream>

using namespace std;

template<class elemtype>
struct less2
{
	bool operator()(const elemtype& a, const elemtype& b)
		return a < b;
};

template<class elemtype>
struct less_equal2
{
	bool operator()(const elemtype& a, const elemtype& b)
		return a <= b;
};

template<class elemtype>
struct greater2
{
	bool operator()(const elemtype& a, const elemtype& b)
		return a > b;
};

template<class elemtype>
struct greater_equal2
{
	bool operator()(const elemtype& a, const elemtype& b)
		return a >= b;
};

template <class elemtype>
void swap(elemtype& a, elemtype& b)
{
	elemtype tmp = a;
	a = b;
	b = tmp;
}

//冒泡，最优：已是正序，O(n),最差：原本是逆序，O(n^2)
//是稳定排序
template <class elemtype,class compare=greater2<elemtype>>
void bubbleSort(elemtype a[], int n)
{
	compare cmp;
	bool flag = 1;
	for (int i = n - 1; i > 0; --i)
	{
		if (!flag)return;
		flag = 0;
		for (int j = 0; j < i; ++j)
		{
			if (cmp(a[j], a[j + 1]))
			{
				swap(a[j], a[j + 1]);
				flag = 1;
			}
		}
	}
}

//插入：最优：已是正序，O(n)，最差：逆序，O(n^2)
//是稳定排序
template <class elemtype,class compare=greater_equal2<elemtype>>
void insert(elemtype a[], int n, const elemtype& x)
{
	compare cmp;
	int i;
	for (i = n - 1; i >= 0; --i)
	{
		if (cmp(x, a[i]))break;
		else a[i + 1] = a[i];
	}
	a[i + 1] = x;
}
//其实由于在插入第k个元素的时候，前k-1个已是有序的，可以折半找到要插入的位置，但是由于需要移动的复杂度仍为O(n)，再加上循环n，时间复杂度仍是O(n^2)
template <class elemtype,class compare=greater_equal2<elemtype>>
void insertSort(elemtype a[], int n)
{
	compare cmp;
	for (int i = 1; i < n; ++i)
	{
		elemtype tmp = a[i];
		insert(a, i,tmp, cmp);
	}
}

//假如原始数据不是完全有序，而是比较有序，，在前m个元素的有序序列的插入操作中，有些就不是m次，而是少于m次，总的时间复杂度就往O(n)方向靠近
//基于这样的想法，我们可以对原始数据做一定的预处理，使原始数据变为比较有序，这就是希尔排序的目的
//预处理算法如下：每隔固定step距离，抽出一个元素，对抽出的元素进行排序，使原始数据达到一个比较有序的状态
//一般会先取step=n/2，之后逐次减半，最后当step=1时，共取了log2(n)个step
//希尔排序是不稳定排序

template<class elemtype,class compare =greater_equal2<elemtype>>
void shellSort(elemtype a[], int n)
{
	int step;
	compare cmp;
	elemtype tmp;
	for (step = n / 2; step > 0; step /= 2)
	{
		for (int i = step; i < n; ++i)
		{
			tmp = a[i];//这里的tmp记录了待插入的值，便于直接插入
			int j = i;
			while ((j - step) >= 0 && (cmp(a[j - step], tmp)))//这段可以理解为隔step个元素的插入排序
			{
				a[j] = a[j - step];
				j -= step;
			}
			a[j] = tmp;
		}
	}
}


//选择排序，为每个位置选择合适的元素，注意这里的主变量变为了不同的位置
//值相等的元素，有可能在排到他之前和别的元素交换过位置，因此是不稳定的
template <class elemtype,class compare =greater2<elemtype>>
void selectSort(elemtype a[], int n)
{
	int minindex;
	compare cmp;
	for (int i = 0; i < n; ++i)//遍历位置
	{
		minindex = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (cmp(a[minindex], a[j]))
				minindex = j;
		}
		if (minindex == i)continue;
		swap(a[minindex], a[i]);
	}
}

//堆排序是不稳定的
template<class elemtype,class compare =greater2<elemtype>>
void adjust(elemtype a[], int n, int i)
{
	int child;
	compare cmp;
	while (true)
	{
		child = 2 * i + 1;
		if (child > n - 1)return;
		if (child + 1 < n)
		{
			if (cmp(a[child + 1], a[child])||a[child]==a[child+1])//右孩子优先于左孩子
				child++;
		}
		if (a[i] > a[child])return;
		swap(a[i], a[child]);
		i = child;
	}
}

template <class elemtype,class compare=greater2<elemtype>>
void heapSort(elemtype a[], int n)
{
	compare cmp;
	for (int i = (n - 1) / 2; i >= 0; --i)
	{
		adjust(a, n, i, cmp);
	}//初次建堆的时间复杂度为O(nlog2(n))但是实际可达到O(n)
	for (int j = n - 1; j >= 1; --j)
	{
		swap(a[0], a[j]);
		adjust(a, j, 0, cmp);
	}//遍历调整时间复杂度为O(nlog2(n))
}


//归并排序：稳定排序，O(nlog2(n))
//每次归并需要的时间复杂度等同于 O(m+n)
template <class elemtype,class compare =greater2<elemtype>>
void merge(elemtype a[], int low, int mid, int high)
{
	compare cmp;
	int i=low, j=mid+1, k=0;
	elemtype* c=new elemtype [high-low+1];
	while ((i <= mid) && (j <= high))
	{
		if (cmp(a[j], a[i]) || a[i] = a[j])
		{
			c[k++] = a[i];
			i++;
		}
		else
		{
			c[k++] = a[j];
			j++;
		}
	}
	while (i <= mid)
	{
		c[k++] = a[i++];
	}
	while (j <= high)
	{
		c[k++] = a[j++];
	}
	for (int i = 0; i < high - low + 1; ++i)
	{
		a[i + low] = c[i];
	}
	delete[] c;

}

template <class elemtype, class compare = greater2<elemtype>>
void mergeSort(elemtype a[], int low, int high)
{
	if (low >= high)return;
	int mid = (low + high) / 2;
	mergeSort(a, low, mid);
	mergeSort(a, mid + 1, high);//分治-递归
	merge(a, low,mid,high);
}


template <class elemtype,class compare = greater2<elemtype>>
void mergeSort(elemtype a[], int n)
{
	mergeSort(a, 0, n - 1);
}


//快速排序：
//选取一个合适的元素作为标杆，小于他的元素都在他的前面，大于的都在后面
//分别对于每个元素，若前后的序列均排好序，那整体也就排好了,以此递归下去,这也是一种分治-递归的思想
//优化：O(nlog2(n)) 最差：O(n^2)
//优化：取low，high，mid三个元素中处于中间的元素作为，和low swap一下
//不稳定：存在等值非相邻元素之间的交换


template <class elemtype,class compare =greater2<elemtype>>
void quickSort(elemtype a[], int n)
{
	quickSort(a, 0, n - 1);
}

template <class elemtype, class compare = greater2<elemtype>>
void quickSort(elemtype a[], int start, int end)
{
	compare cmp;
	int hole;
	elemtype tmp;
	if (end <= start)return;
	if (start = end - 1)
	{
		if (cmp(a[end], a[start]) || a[end] == a[start])return;
		else swap(a[end], a[start]);
	}
	int mid = (start + end) / 2;//预处理优化
	if (a[start] < a[mid] && a[mid] < a[end])swap(a[mid], a[start]);
	else if (a[end] < a[mid] && a[mid] < a[start])swap(a[mid], a[start]);
	else if (a[start] < a[end] && a[end] < a[mid])swap(a[start], a[end]);
	else if (a[mid] < a[end] && a[end] < a[start])swap(a[end], a[start]);
	tmp = a[start];//标杆
	hole = start;
	int i = start, j = end;
	while (i < j)
	{
		//从后往前找第一个小于标杆的值
		while ((j > i) && (cmp(a[j],tmp)||a[j]==tmp))j--;
		if (i == j)break;
		a[hole] = a[j];
		hole = j;
		//从前往后找第一个大于等于标杆的值
		while ((i < j) && (cmp(tmp, a[i])))i++;
		if (i == j)break;
		a[hole] = a[i];
		hole = i;
	}
	a[hole] = tmp;
	quickSort(a, start, hole - 1);
	quickSrot(a, hole + 1, end);
}


//基数排序（口袋排序）：
// 先看十位，再看个位...即MSD，反之，LSD
//时间复杂度：O(mn)这里的m表示最大数据的位数
//稳定排序

template <class elemtype>
struct node
{
	elemtype data;
	node <elemtype>* next;
};

template <class elemtype>
struct pocketlist
{
	node <elemtype>* front;
	node <elemtype>* tail;
};

template <class elemtype>
void pocketSort(elemtype a[], int n)
{
	node<elemtype>* collectHead=nullptr, * collectTail=nullptr, * tmp;
	pocketlist<elemtype>list[10];
	elemtype max;
	int count = 0;
	int base = 1;
	int k;
	max = a[0];
	for (int i = 0; i < n; ++i)
		max = a[i] > max ? a[i] : max;
	while (max)
	{
		count++;
		max /= 10;
	}
	for (int i = 0; i < n; ++i)//初始化
	{
		tmp = new node<elemtype>;
		tmp->data = a[i];
		tmp->next = nullptr;
		if (!collectHead)
		{
			collectHead = tmp;
			collectTail = tmp;
		}
		else
		{
			collectTail->next = tmp;
			collectTail = tmp;
		}
	}
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < 10; ++j)//清空
		{
			list[j].front = list[j].tail = nullptr;
		}
		while (collectHead)//分配
		{
			k = collectHead->data;
			k = (k / base) % 10;
			if (!list[k].front)
			{
				list[k].front = list[k].tail = collectHead;
			}
			else
			{
				list[k].tail->next = collectHead;
				list[k].tail = list[k].tail->next;
			}
			collectHead = collectHead->next;
		}
		collectHead = collectTail = nullptr;
		k = 0;
		while (k < 10)//收集
		{
			if (!list[k].front)continue;
			if (!collectHead)
			{
				collectHead = list[k].front;
				collectTail = list[k].tail;
			}
			else
			{
				collectTail->next = list[k].front;
				collectTail = list[k].tail;
			}
			k++;
		}
		collectTail->next = nullptr;
		base *= 10;
	}
	
	for (int i = 0; i < n; ++i)//还原
	{
		a[i] = collectHead->data;
		tmp = collectHead;
		collectHead = collectHead->next;
		delete tmp;
	}

}


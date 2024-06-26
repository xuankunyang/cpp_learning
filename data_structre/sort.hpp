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

//ð�ݣ����ţ���������O(n),��ԭ��������O(n^2)
//���ȶ�����
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

//���룺���ţ���������O(n)��������O(n^2)
//���ȶ�����
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
//��ʵ�����ڲ����k��Ԫ�ص�ʱ��ǰk-1����������ģ������۰��ҵ�Ҫ�����λ�ã�����������Ҫ�ƶ��ĸ��Ӷ���ΪO(n)���ټ���ѭ��n��ʱ�临�Ӷ�����O(n^2)
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

//����ԭʼ���ݲ�����ȫ���򣬶��ǱȽ����򣬣���ǰm��Ԫ�ص��������еĲ�������У���Щ�Ͳ���m�Σ���������m�Σ��ܵ�ʱ�临�ӶȾ���O(n)���򿿽�
//�����������뷨�����ǿ��Զ�ԭʼ������һ����Ԥ����ʹԭʼ���ݱ�Ϊ�Ƚ����������ϣ�������Ŀ��
//Ԥ�����㷨���£�ÿ���̶�step���룬���һ��Ԫ�أ��Գ����Ԫ�ؽ�������ʹԭʼ���ݴﵽһ���Ƚ������״̬
//һ�����ȡstep=n/2��֮����μ��룬���step=1ʱ����ȡ��log2(n)��step
//ϣ�������ǲ��ȶ�����

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
			tmp = a[i];//�����tmp��¼�˴������ֵ������ֱ�Ӳ���
			int j = i;
			while ((j - step) >= 0 && (cmp(a[j - step], tmp)))//��ο������Ϊ��step��Ԫ�صĲ�������
			{
				a[j] = a[j - step];
				j -= step;
			}
			a[j] = tmp;
		}
	}
}


//ѡ������Ϊÿ��λ��ѡ����ʵ�Ԫ�أ�ע���������������Ϊ�˲�ͬ��λ��
//ֵ��ȵ�Ԫ�أ��п������ŵ���֮ǰ�ͱ��Ԫ�ؽ�����λ�ã�����ǲ��ȶ���
template <class elemtype,class compare =greater2<elemtype>>
void selectSort(elemtype a[], int n)
{
	int minindex;
	compare cmp;
	for (int i = 0; i < n; ++i)//����λ��
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

//�������ǲ��ȶ���
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
			if (cmp(a[child + 1], a[child])||a[child]==a[child+1])//�Һ�������������
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
	}//���ν��ѵ�ʱ�临�Ӷ�ΪO(nlog2(n))����ʵ�ʿɴﵽO(n)
	for (int j = n - 1; j >= 1; --j)
	{
		swap(a[0], a[j]);
		adjust(a, j, 0, cmp);
	}//��������ʱ�临�Ӷ�ΪO(nlog2(n))
}


//�鲢�����ȶ�����O(nlog2(n))
//ÿ�ι鲢��Ҫ��ʱ�临�Ӷȵ�ͬ�� O(m+n)
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
	mergeSort(a, mid + 1, high);//����-�ݹ�
	merge(a, low,mid,high);
}


template <class elemtype,class compare = greater2<elemtype>>
void mergeSort(elemtype a[], int n)
{
	mergeSort(a, 0, n - 1);
}


//��������
//ѡȡһ�����ʵ�Ԫ����Ϊ��ˣ�С������Ԫ�ض�������ǰ�棬���ڵĶ��ں���
//�ֱ����ÿ��Ԫ�أ���ǰ������о��ź���������Ҳ���ź���,�Դ˵ݹ���ȥ,��Ҳ��һ�ַ���-�ݹ��˼��
//�Ż���O(nlog2(n)) ��O(n^2)
//�Ż���ȡlow��high��mid����Ԫ���д����м��Ԫ����Ϊ����low swapһ��
//���ȶ������ڵ�ֵ������Ԫ��֮��Ľ���


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
	int mid = (start + end) / 2;//Ԥ�����Ż�
	if (a[start] < a[mid] && a[mid] < a[end])swap(a[mid], a[start]);
	else if (a[end] < a[mid] && a[mid] < a[start])swap(a[mid], a[start]);
	else if (a[start] < a[end] && a[end] < a[mid])swap(a[start], a[end]);
	else if (a[mid] < a[end] && a[end] < a[start])swap(a[end], a[start]);
	tmp = a[start];//���
	hole = start;
	int i = start, j = end;
	while (i < j)
	{
		//�Ӻ���ǰ�ҵ�һ��С�ڱ�˵�ֵ
		while ((j > i) && (cmp(a[j],tmp)||a[j]==tmp))j--;
		if (i == j)break;
		a[hole] = a[j];
		hole = j;
		//��ǰ�����ҵ�һ�����ڵ��ڱ�˵�ֵ
		while ((i < j) && (cmp(tmp, a[i])))i++;
		if (i == j)break;
		a[hole] = a[i];
		hole = i;
	}
	a[hole] = tmp;
	quickSort(a, start, hole - 1);
	quickSrot(a, hole + 1, end);
}


//�������򣨿ڴ����򣩣�
// �ȿ�ʮλ���ٿ���λ...��MSD����֮��LSD
//ʱ�临�Ӷȣ�O(mn)�����m��ʾ������ݵ�λ��
//�ȶ�����

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
	for (int i = 0; i < n; ++i)//��ʼ��
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
		for (int j = 0; j < 10; ++j)//���
		{
			list[j].front = list[j].tail = nullptr;
		}
		while (collectHead)//����
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
		while (k < 10)//�ռ�
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
	
	for (int i = 0; i < n; ++i)//��ԭ
	{
		a[i] = collectHead->data;
		tmp = collectHead;
		collectHead = collectHead->next;
		delete tmp;
	}

}


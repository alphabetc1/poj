#include <iostream>
#include <string.h>
using namespace std;
const int NMAX = 20010;
int a[NMAX], b[NMAX];
long long sum;

void merge(int start, int mid, int end)
{
	int i = start, j = mid, k = start, t = 0;
	memcpy(b + start, a + start, (end - start) * sizeof(int));
	while (i < mid && j < end)	//这里可以把检测放到下面那次扫描
	{							//如果逆序对的条件为a[i]>2*a[j]则必须要两次扫描
		if (b[i] > b[j])
		{
			sum += j - i - t;
			t++;
			j++;
		}
		else i++;
	}
	i = start, j = mid;
	while (i < mid && j < end)
	{
		if (b[i] < b[j])
		{
			a[k++] = b[i];
			i++;
		}
		else
		{
			a[k++] = b[j];
			j++;
		}
	}
	while (i < mid)
	{
		a[k++] = b[i];
		i++;
	}
	while (j < end)
	{
		a[k++] = b[j];
		j++;
	}
}

void mergeSort(int start, int end)
{
	if (end - start == 1)	return;
	int k = (start + end) / 2;
	mergeSort(start, k);
	mergeSort(k, end);
	merge(start, k, end);
}

int main()
{
	int i, j, n;
	while (cin >> n && n)
	{
		sum = 0;
		for (i = 0; i < n; i++)
			cin >> a[i];
		mergeSort(0, n);
		cout << sum << endl;
	}
	return 0;
}
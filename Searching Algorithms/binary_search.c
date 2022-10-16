#include<stdio.h>
#include<conio.h>

int main()
{
	int a[30], n, low, high, mid, key, flag = 0;
	printf("Enter no of terms: ");
	scanf("%d", &n);
	printf("Enter sorted array elements: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("Enter key to search: ");
	scanf("%d", &key);
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] == key) {
			printf("%d found at position: %d", key, mid + 1);
			flag = 1;
		}
		if (key < a[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (flag == 0)
		printf("%d not found in array\n", key);
	return 0;
}

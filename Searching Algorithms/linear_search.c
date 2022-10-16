#include<stdio.h>
#include<conio.h>

int main()
{
	int a[30], n, key, flag = 0;
	printf("Enter no of terms: ");
	scanf("%d", &n);
	printf("Enter array elements: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("Enter key to search: ");
	scanf("%d", &key);
	for (int i = 0; i < n; i++) {
		if (a[i] == key) {
			printf("%d found at position: %d", key, i + 1);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("%d not found in array\n", key);
	return 0;
}

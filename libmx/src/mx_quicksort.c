#include "libmx.h"

static void swap(char **arr, int i, int j, int *swaps) {
	char *tmp = NULL;
	tmp = arr[j];
	arr[j] = arr[i];
	arr[i] = tmp;
	(*swaps)++;
}

int mx_quicksort(char **arr, int left, int right) {
	int l = left;
	int r = right;
	int swaps = 0;

	if(!arr)
		return -1;
	if (l < r) {
		for ( ; mx_strlen(arr[l]) < mx_strlen(arr[(left + right) / 2]); l++);
		for ( ; mx_strlen(arr[r]) > mx_strlen(arr[(left + right) / 2]); r--);
		if (mx_strlen(arr[l]) != mx_strlen(arr[r]))
			swap(arr, l, r, &swaps);
		if (++l < right)
			swaps += mx_quicksort(arr, l, right);
		if (--r > left)
			swaps += mx_quicksort(arr, left, r);
	}
	return swaps;
}

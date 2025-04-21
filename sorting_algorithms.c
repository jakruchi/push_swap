/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:14:08 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/12 14:25:00 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// malloc, free
#include <stdio.h>	// printf
#include <unistd.h>	// sleep
#include <time.h>	// clock

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}

void	fill_array(int *numbers, char **input, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		numbers[i] = ft_atoi(input[i]);
		i++;
	}
}

void	print_array(int *numbers, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", numbers[i]);
		i++;
	}
	printf("\n");
}

void	stupid_bubble_sort(int *numbers, int size)
{
	// int	comparisons;
	int	i;
	int	temp;
	int	j;

	temp = 0;
	// comparisons = 0;
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size - 1)
		{
			if (numbers[i] > numbers[i + 1])
			{
				temp = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = temp;
			}
			// comparisons++;
			i++;
		}
		j++;
		// print_array(numbers, size);
	}
	// printf("comparisons made: %d in ", comparisons);
}

void	less_stupid_bubble_sort(int *numbers, int size)
{
	// int	comparisons;
	int	not_sorted;
	int	i;
	int	temp;

	temp = 0;
	// comparisons = 0;
	not_sorted = 1;
	while (not_sorted)
	{
		not_sorted = 0;
		i = 0;
		while (i < size - 1)
		{
			if (numbers[i] > numbers[i + 1])
			{
				temp = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = temp;
				not_sorted = 1;
			}
			// comparisons++;
			i++;
		}
		// print_array(numbers, size);
	}
	// printf("comparisons made: %d in ", comparisons);
}

void	bubble_sort(int *numbers, int size)
{
	// int	comparisons;
	int	not_sorted;
	int	i;
	int	j;
	int	temp;

	temp = 0;
	// comparisons = 0;
	j = 0;
	not_sorted = 1;
	while (not_sorted)
	{
		not_sorted = 0;
		i = 0;
		while (i < size - 1 - j)
		{
			if (numbers[i] > numbers[i + 1])
			{
				temp = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = temp;
				not_sorted = 1;
			}
			// comparisons++;
			i++;
		}
		j++;
		// print_array(numbers, size);
	}
	// printf("comparisons made: %d in ", comparisons);
}

void bubbleSort_from_INTERNET(int array[], int size)
{
	// int	comparisons = 0;

	// loop to access each array element
	for (int step = 0; step < size - 1; ++step) {
	  // loop to compare array elements
	  for (int i = 0; i < size - step - 1; ++i) {
		// compare two adjacent elements
		// change > to < to sort in descending order
		if (array[i] > array[i + 1]) {
		  // swapping occurs if elements
		  // are not in the intended order
		  int temp = array[i];
		  array[i] = array[i + 1];
		  array[i + 1] = temp;
		}
		// comparisons++;
	  }
	//   print_array(array, size);
	}
	// printf("comparisons made: %d in ", comparisons);
}

// Optimized Bubble sort in C
// perform the bubble sort
void optimized_bubbleSort_from_INTERNET(int array[], int size)
{
	// int	comparisons = 0;
  // loop to access each array element
  for (int step = 0; step < size - 1; ++step) {
    // check if swapping occurs
    int swapped = 0;
    // loop to compare array elements
    for (int i = 0; i < size - step - 1; ++i) {
      // compare two array elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {
        // swapping occurs if elements
        // are not in the intended order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swapped = 1;
      }
	//   comparisons++;
    }
    // no swapping means the array is already sorted
    // so no need for further comparison
    if (swapped == 0) {
      break;
    }
	// print_array(array, size);
  }
//   printf("comparisons made: %d in ", comparisons);
}

void	selection_sort(int *numbers, int size)
{
	// int	comparisons;
	int	i;
	int	j;
	int temp;
	int	min_index;

	if (numbers == NULL)
		return;
	// comparisons = 0;
	j = 0;
	while (j < size - 1)
	{
		min_index = j;
		i = 0 + j;
		while (i < size - 1)
		{
			if (numbers[min_index] > numbers[i + 1])
				min_index = (i + 1);
			// comparisons++;
			i++;
		}
		temp = numbers[min_index];
		numbers[min_index] = numbers[j];
		numbers[j] = temp;
		// print_array(numbers, size);
		j++;
	}
	// printf("comparisons made: %d in ", comparisons);
}

// function to swap the the position of two elements
void swap_from_INTERNET(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort_from_INTERNET(int array[], int size)
{
	// int	comparisons;

	// comparisons = 0;
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
		// comparisons++;
    }

    // put min at the correct position
    swap_from_INTERNET(&array[min_idx], &array[step]);
	// print_array(array, size);
  }
//   printf("comparisons made: %d in ", comparisons);
}

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	insertion_sort(int *numbers, int size)
{
	// int	comparisons;
	int	key_value;
	int	key_index;
	int	i;

	if (numbers == NULL)
		return;
	if (size < 2)
		return;
	// comparisons = 0;
	key_index = 1;
	while (key_index < size)
	{
		key_value = numbers[key_index];
		i = key_index - 1;
		while (i >= 0 && numbers[i] > key_value)
		{
			numbers[i + 1] = numbers[i];
			// comparisons++;
			i--;
		}
		numbers[i + 1] = key_value;
		key_index++;
		// print_array(numbers, size);
	}
	// printf("\ncomparisons made: %d in ", comparisons);
}

void insertionSort_from_INTERNET(int array[], int size)
{
	int	comparisons;

	comparisons = 0;
	for (int step = 1; step < size; step++) {
	  int key = array[step];
	  int j = step - 1;

	  // Compare key with each element on the left of it until an element smaller than
	  // it is found.
	  // For descending order, change key<array[j] to key>array[j].
	  while (j >=0 && key < array[j]) {
		array[j + 1] = array[j];
		--j;
		comparisons++;
	  }
	  array[j + 1] = key;
	}
	printf("\ncomparisons made: %d in ", comparisons);
  }

void	merge(int *numbers, int start, int mid_point, int end)
{
	int	size_a = mid_point - start + 1;
	int	size_b = end - mid_point;
	int	a[size_a]; // norminette wants malloced array
	int	b[size_b]; // norminette wants malloced array

	int	i = 0;
	while (i <= mid_point - start)
	{
		a[i] = numbers[start + i];
		i++;
	}
	i = 0;
	while (i < end - mid_point)
	{
		b[i] = numbers[mid_point + 1 + i];
		i++;
	}
	i = 0;
	int	j, k;
	j = 0;
	k = 0;
	while (i < size_a + size_b && (k < size_b && j < size_a))
	{
		if (a[j] > b[k])
			numbers[start + i] = b[k++];
		else
			numbers[start + i] = a[j++];
		i++;
	}
	while (j < size_a)
		numbers[start + i++] = a[j++];
	while (k < size_b)
		numbers[start + i++] = b[k++];
}

void	merge_sort(int *numbers, int start, int end)
{
	int	mid_point;

	if (start >= end)
		return;
	mid_point = (start + end) / 2;
	merge_sort(numbers, start, mid_point);
	merge_sort(numbers, mid_point + 1, end);
	merge(numbers, start, mid_point, end);
}

// Merge sort in C

#include <stdio.h>

// Merge two subarrays L and M into arr
void merge_from_INTERNET(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort_from_INTERNET(int arr[], int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort_from_INTERNET(arr, l, m);
    mergeSort_from_INTERNET(arr, m + 1, r);

    // Merge the sorted subarrays
    merge_from_INTERNET(arr, l, m, r);
  }
}

void	quick_sort(int *numbers, int size)
{
	if (size < 2)
		return;
	int	*pivot = &numbers[size - 1];
	int	i = 0;
	int	j = 0;
	while (i < size - 1)
	{
		if (numbers[i] < *pivot)
		{
			swap(&numbers[j], &numbers[i]);
			j++;
		}
		i++;
	}
	swap(&numbers[j], pivot);
	quick_sort(numbers, size - (size - j));
	quick_sort(&numbers[j], size - j);
}

int	main(int argc, char **argv)
{
	struct timespec start, end;
	int		array[argc - 1];

	if (argc < 3)
	{
		printf("There is no numbers to sort.\n"); // check if any number is twice
		return (1);
	}
	printf("argc: %d\n", argc);
	printf("-----------------------init-----------------------\n");
	fill_array(array, argv + 1, argc - 1);
	print_array(array, argc - 1);
	// printf("-----------------------stats-----------------------\n");
	// printf("-----------------------prep-----------------------\n");
	printf("-----------------------start-----------------------\n");
    clock_gettime(CLOCK_MONOTONIC, &start);
	// bubbleSort_from_INTERNET(array, argc - 1);
	// optimized_bubbleSort_from_INTERNET(array, argc - 1);
	// selectionSort_from_INTERNET(array, argc - 1);
	// insertionSort_from_INTERNET(array, argc - 1);
	// mergeSort_from_INTERNET(array, 0, argc - 2);

	// stupid_bubble_sort(array, argc - 1);
	// less_stupid_bubble_sort(array, argc - 1);
	// bubble_sort(array, argc - 1);
	// selection_sort(array, argc - 1);
	// insertion_sort(array, argc - 1);
	// merge_sort(array, 0, argc - 2);
	quick_sort(array, argc - 1);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
	printf("-----------------------done-----------------------\n");
	print_array(array, argc - 1);
	printf("\n\n%.9f seconds\n\n", elapsed);
	printf("bubble sort (NET):		1225 comparisons in 0.0073, 0.0082, 0.0063 seconds\n");
	printf("optimized bubble sort (NET):	1204 comparisons in 0.0079, 0.0060, 0.0061 seconds\n");
	printf("selection sort (NET):		1225 comparisons in 0.0046, 0.0043, 0.0043 seconds\n");
	printf("insertion sort (NET):		 554 comparisons in 0.0027, 0.0029, 0.0025 seconds\n");
	printf("merge sort (NET):		 xxx comparisons in 0.0003, 0.0002, 0.0002 seconds\n");
	printf("stupid bubble sort:		2450 comparisons in 0.0095, 0.0120, 0.0103 seconds\n");
	printf("less stupid bubble sort:	2107 comparisons in 0.0113, 0.0113, 0.0111 seconds\n");
	printf("bubble sort:			1204 comparisons in 0.0059, 0.0069, 0.0070 seconds\n");
	printf("selection sort:			1225 comparisons in 0.0045, 0.0042, 0.0036 seconds\n");
	printf("insertion sort:			 554 comparisons in 0.0025, 0.0024, 0.0024 seconds\n");
	printf("merge sort:			 xxx comparisons in 0.0002, 0.0002, 0.0003 seconds\n");
	printf("quick sort:			 xxx comparisons in 0.0002, 0.0002, 0.0002 seconds\n");
	printf("jeste vyzkouset v linuxu s valgrindem kvuli space komplexity\n");
	printf("jeste vyzkouset quick sort from the internet\n");
	// printf("i run.\n");
	return (0);
}

// test array[20] for comparisons
// 31 13 19 43 10 22 14 8 3 6 28 12 7 34 21 26 2 33 37 20 44 46 30 49 42 47 35 48 4 11 27 41 1 50 32 23 29 16 38 39 25 45 36 18 15 9 5 40 17 24

// test array[2000] for time
// 8313 8220 9532 -7152 -1774 -8201 8131 7500 -5624 8709 2028 7613 6241 -8517 -3043 5223 -9950 -3826 8697 -6909 -9185 9626 629 3735 8059 7553 4558 6468 -7122 728 2019 2659 3286 -7662 9397 -7905 9799 3771 9967 2520 -1005 -3393 -569 8788 -2094 296 -5526 -4753 -5684 6755 -8004 7899 -4514 6441 -9292 9632 7702 2773 9373 -9457 -6882 9394 -4382 1365 -7029 -9882 -6303 7877 -5855 -8309 -3065 6129 7845 -5399 -5510 -167 7175 -5581 5456 -9688 1468 -7304 9718 220 2104 -441 6015 5482 -680 -1239 8378 -4613 -1453 2700 5458 4110 7914 9924 4958 -3974 -5089 3945 -5846 4220 -3160 -4045 -4508 -863 -7688 8070 6845 9963 -894 -6274 7297 8304 7225 5058 -6122 -6355 8272 8742 8290 8403 -9121 -148 -7866 -46 929 -7261 5812 7602 8940 -353 2990 -7898 -5310 8754 -5887 -6047 4230 -548 -3567 1700 3772 7241 -954 206 7673 -7183 3911 9301 -3870 -4757 6252 -3354 6207 221 5402 7426 -9474 -7982 5617 -9203 3972 6545 7538 2959 4552 -6889 892 9104 9477 4271 -5208 2032 7058 5823 -4703 -8784 1821 5373 3023 3076 -2992 -2945 2041 -6330 9780 -3272 -1960 1500 -8625 4355 4358 6045 3581 9575 -9911 -5148 -8699 6265 -1515 1143 3779 3733 5676 9227 8971 -9760 -6327 9340 -5928 -9368 -4161 9466 -1265 -7134 7181 7048 2795 8772 -6115 4147 -9887 -4583 767 -5694 -1406 9499 -6746 -8215 3550 3725 5104 7887 -5150 -6980 -1376 -1374 7608 -4933 -6597 142 2729 -7104 3773 -3476 -9270 8038 9998 8855 9124 8913 1141 957 -9212 -7385 -7309 -8551 -3945 9418 -1431 -8415 -6808 4450 9270 7074 -5744 5369 -3749 6998 -7496 9043 5248 -2806 -4056 4341 -2279 4606 -7566 3332 2315 -597 3819 -1572 -6061 -7462 2762 8924 -6203 -6423 3707 -8168 -7590 2240 1667 -2358 4471 5997 -5262 8380 3544 -9804 -1158 -6733 -4769 -5717 7852 4601 -7129 1157 -6932 -1717 -6014 3988 7111 -2831 -1027 6011 3909 -6510 -5770 -3728 1950 -9342 -8817 9398 -4509 8497 -2298 -8217 -1611 -5471 -8078 2622 -4446 -5607 1492 1149 4568 -573 8804 -5911 3760 7975 5912 -1988 4646 -1946 2972 5614 1000 -8519 -2112 4223 5010 2099 -16 351 -9454 -181 -9125 8726 -7035 9970 3533 8956 7410 -2979 -2853 -3243 -424 -6726 4988 2576 2405 7427 6716 3299 -8079 -5475 -359 6078 6251 3121 2403 1483 654 -1980 -9591 2995 -2964 8859 -7535 -6066 -3750 -9456 -5503 2284 5953 -7890 7697 3164 -2289 8889 3115 7891 -5497 3964 7134 -4998 6421 -358 4475 8681 9674 -3748 -7322 -4334 -1011 585 4082 3568 -8272 1740 -4202 2273 -8724 -8885 -6968 -6373 3702 4697 2228 9154 -6308 -6243 4816 5177 2167 7117 4442 5543 -7066 -2968 -1732 -9129 4821 8540 6945 9497 6807 7929 -2588 7974 -2795 -9139 -2346 6278 1442 -290 4929 7158 169 4890 -5544 -6220 453 -8667 549 -2016 -3873 541 -3313 -2677 -7779 1032 -6560 2102 1264 8581 -3078 6099 -4970 -8041 -717 8961 802 9109 5867 456 8091 -9300 -6121 -817 8834 3579 6820 -4669 -9066 -6550 5457 5583 -1578 -8014 -8801 8014 6245 6893 5278 4833 7214 9866 3459 5366 1058 3167 3866 3671 -5760 -6788 -7045 -8631 9662 -5302 -8455 3277 9160 -4712 3720 8886 3240 9574 -402 -7794 6501 -5700 -9640 -555 4309 -2376 9889 -9686 3954 -2722 7689 -3769 6386 -2323 -80 -4536 -3850 1410 7926 4928 5101 -3564 -1489 3736 -8932 6109 202 4276 3274 -6884 8347 -196 4214 -7239 3412 1338 1307 -1689 -7137 -601 1207 5494 9892 1525 3632 3091 5865 -7363 -1665 5917 -1949 -8765 -3633 2360 2892 -8797 1697 -39 -3556 -2696 2155 -4655 -9321 3611 -6126 -8350 1596 -151 7574 7357 -699 5246 9407 8600 4124 -778 467 5546 -4053 -975 -4042 2444 -1319 -4226 -5246 6865 -7720 8311 3667 7895 -3397 8401 -2630 8694 -160 1536 -5154 4649 5582 -9771 -8900 2649 7413 -7397 -7065 2770 -9314 4852 -8722 3365 -3585 6761 -5536 -7043 6518 3430 -9219 -888 -8783 6068 4875 9220 -9373 1284 3829 -9421 2322 5972 3266 -7700 -4585 -5688 -4864 8857 -7895 -8167 5153 7599 -6212 8722 3847 422 -7396 -4497 -6113 947 -623 4547 -8238 3910 4616 1026 343 -9566 -6216 5958 6883 300 5160 -8656 -3869 -3452 -1450 -2136 7519 5854 9176 -4221 5886 1691 2233 -7284 1661 3361 4942 4305 -9330 -9698 8666 9845 -9075 -3295 258 -9433 8283 3914 7183 -2217 187 6274 -8339 9228 -1731 5293 4779 -6946 5500 1844 -2079 2060 5721 -4996 -1904 -7039 1321 -8449 6605 -729 -9948 -8977 -1224 3933 -4393 9428 -9848 8171 -328 9743 8207 7015 -9503 7526 6538 -2207 8615 -5628 3353 3315 8100 -9972 -6896 4061 -155 -3893 -3901 -2407 2356 1379 1638 -6148 -540 -5377 3189 2217 5714 -5946 1340 -2983 -8082 -2738 -8830 9194 -6664 -721 -9505 8931 730 -9430 5503 8850 9772 -8115 -279 -7064 -3934 -9874 -9082 -834 1005 5564 6831 -2460 -1632 2615 -1598 -914 5986 3950 3670 9336 -2145 6098 4235 2985 -2402 2059 -9319 -387 3699 978 4657 3357 -2858 6905 8031 -205 -1096 -771 -9148 8233 -7345 -3740 8084 4018 6183 4834 2819 5056 -6583 -7595 4086 9723 1548 8054 -106 -6895 4041 -7001 -5358 6434 6510 4520 4414 -268 2215 7947 -5883 3564 4434 -1421 -9533 5088 -3464 3047 9914 -6781 643 -8710 9062 -9469 -6923 3044 8719 6176 6548 -4176 -6142 -116 -773 -8145 144 -9710 4109 4954 8530 -860 9376 -3389 4551 -1953 595 8107 495 4472 8426 -6996 -7907 6531 4581 -2651 -4713 4 8737 8429 4891 251 1755 3697 -1866 -5767 -7887 -2134 -1963 703 -1958 -1561 4486 9621 770 4868 -7457 -7383 4306 7494 8300 -7659 -7830 191 -1872 6775 -3361 -3812 7172 -4443 -813 -1817 -286 1499 -9906 5453 4771 -8897 -4650 49 -5357 -4251 4172 6259 -7745 9847 -9723 -748 -7053 -6169 -7765 -9391 6903 -9094 -9436 -5747 -6735 -3723 -70 6381 -6248 -427 -284 8775 -9294 7710 -9835 -457 3548 -8574 -7582 6271 -9269 -9749 4823 -9778 -7460 -5626 241 6211 4282 -3682 -7543 9618 -8549 4019 -88 5591 5272 2068 -517 -3562 3275 -7752 -2430 5429 4493 1645 -4320 -1412 1003 -7849 -694 8242 6636 -2229 -9316 -3453 -720 -7106 5608 -9847 -1375 6217 -3475 -6699 3528 9918 4023 7961 -192 -6769 -9445 8941 5161 -859 6562 -6818 7779 7313 -2984 -3346 -4609 -7621 -6328 4379 9979 -1221 6093 -3921 2571 5636 -2455 -7664 3148 -6231 -9553 -5349 -3735 6650 6612 3395 4377 -785 3577 -7624 9920 -2969 7707 39 -6951 -5670 -3186 7670 -6084 8556 -8632 8247 -8723 2221 -8759 -3443 -9261 -676 -5160 -5066 3295 345 -2078 3523 1450 -4631 -6745 -3154 9997 5111 7692 8764 -4156 -4556 570 3674 3351 6351 1362 5733 -1830 9404 -3571 5575 9695 9742 -4802 7765 -3077 -4579 -2664 6061 9305 4521 1514 9666 -5268 -2049 -6620 4953 -9878 -1162 2681 -9708 -1668 2468 4154 7840 9202 8330 3193 -7368 -3990 -7253 1353 8691 4652 5463 6821 7395 2609 1243 -1451 -4379 4576 9821 -9547 2137 3641 -4930 -1690 1354 -9338 4498 -1022 2511 6277 8331 -2324 -2989 7557 -1934 6132 4142 -7787 -2225 7097 487 6148 -2511 -227 -9665 -8499 -2097 -8249 -3534 -5671 7512 -2550 -5665 7170 8619 9612 2777 -4598 6919 -6645 8050 2361 -788 9546 -203 -8175 -6944 8460 3433 6196 8991 -1733 -2888 4257 6793 8873 9896 7376 524 9078 6001 4451 6745 1407 1028 -5387 -6669 1034 2022 5882 8701 3188 2440 -544 1337 2678 4684 -3304 7067 6165 7072 -5672 7387 -820 8370 269 7985 5940 7963 7126 6306 -8075 2037 328 4817 -5202 2704 1361 2766 -1950 784 2279 8871 4800 -6476 -5014 5423 -1061 -1289 1760 3951 -3170 -3449 7312 -850 -5853 596 -7633 7255 6378 1232 -7661 3401 9414 -6970 3201 4164 -2933 4760 -7702 -8034 -53 -2300 7542 4128 96 -7799 7223 5851 2071 -1799 7271 -9926 8135 -2085 9139 8451 -5285 -3223 2139 -2084 -2781 1247 7797 -7990 -5364 -9146 3186 -2309 8866 -4798 4248 -8443 2150 1054 9457 -6002 7848 17 -976 6423 -2443 1917 3104 -3833 -2147 -3889 3098 -7824 -4029 9668 9755 -8644 786 5863 -420 64 59 9779 -4332 -787 -8205 -4237 -8569 166 -8643 -2952 -7557 -9278 313 139 -4544 -1779 1376 -2802 2386 -8600 2005 -9038 2065 6668 2130 -7980 -4487 -1840 -937 -8654 -3779 5491 4367 -5644 4603 -8312 6948 -662 2788 -2197 -2872 -3217 -7048 -2525 2638 8504 -6687 -5041 -5890 -1889 -9001 -8751 7676 -911 -1038 7703 6020 -9090 -3619 9018 3682 1021 -7487 -7852 7981 -3104 -1995 1467 8467 5889 6984 -9417 893 8476 9384 1104 5464 -3691 5979 5397 -9014 -8453 -1974 6990 -2350 -5791 1572 -6798 -9628 -1134 -9477 3063 -6906 2340 6213 2862 8405 -6346 9853 5919 -4845 -4994 -8444 1874 -6999 -1091 9464 337 -1771 -2418 -9551 5638 -4131 7907 7492 5228 6390 -5176 -681 -5149 -2120 9738 -910 -8666 -8367 6864 1210 2581 -9684 1686 -9123 -553 -4892 -9187 4973 -6680 -4709 2792 357 -1687 7803 5660 -7861 -2042 8001 -236 -6048 -9083 340 -5514 -5546 -3091 -5715 -3863 719 3215 -8239 -4139 -1805 -4977 3220 -5015 -1142 -4532 990 -9227 -2998 1924 4180 3801 -9934 -9297 4725 -6853 8336 995 66 3569 130 750 933 2620 4734 7345 -9191 7529 -5541 3791 1531 -9137 -5508 2677 2066 -5138 3984 4714 2258 5436 7836 1115 -3124 5981 -9910 -9767 -4687 3095 5932 -5549 -6306 1333 4548 -7244 -5813 -2339 2917 -4841 -6189 9916 -3751 3367 -6756 -7359 5002 -2726 -3498 7591 -7656 7909 9826 8858 -8624 6619 1975 -4035 -9998 -2002 4840 4134 9790 4168 -9259 536 4480 -8214 -3276 -3287 -1466 -14 8685 -2919 -9031 -4232 -185 -7389 4296 6272 8942 4854 620 -2282 5378 8052 6817 7705 -4241 -2604 -8584 2161 -741 9757 -7554 -9742 -2493 9367 -459 -9124 -176 1213 -3491 8407 7061 -6465 -2317 3153 9947 -8300 9031 -3350 2392 7548 7208 3155 5888 -9577 4039 1718 4827 537 -4444 -3509 -6675 4587 2449 -9713 -9412 -3898 5930 -4371 8379 7363 8010 -8450 8398 1778 8440 -3324 -5934 -8088 -3434 -8599 -9217 -6553 3045 -4525 7101 7109 -1372 -3315 5243 1991 -8918 2574 3826 3675 -33 7447 -8851 -8978 2607 8921 -2037 2367 5295 2123 -7023 -134 -6605 -8081 9267 774 -7984 -3775 9017 9956 -3663 2502 -7266 7636 4621 5141 -6342 7790 2984 -4795 -6972 9513 5928 -8655 -8142 625 -3455 -2143 2768 3941 -6724 7783 9255 -3321 -8737 -9467 0 -3461 -6608 -3234 7231 -1217 4005 -6897 -3661 -225 -8254 4236 -5443 -1279 2702 7696 -6989 2895 7652 -200 7354 4406 -1714 -4797 -8000 -5588 -4706 263 4272 5198 977 9981 -2778 8246 3058 -3322 -1713 3178 -399 1315 -222 -1423 -5632 -869 -3192 8520 8310 -5693 415 5255 -4546 -7747 5605 7327 -7724 7090 9894 -58 4350 5379 6126 -7331 -5649 2001 -3604 8923 9747 816 -7676 -5691 -3188 -5970 5234 5168 7811 1388 -231 8492 8537 1890 3182 7699 2719 2568 5527 29 -7874 -541 1830 6152 5206 4491 7334 315 -8466 -1542 1793 -5723 -1625 539 -3948 -182 4673 -1520 -9659 -5556 9715 1235 -1031 3778 -4720 4645 -3790 -1673 -6086 9225 7551 55 6235 5136 22 -3529 7575 -800 7962 -5851 -2387 6145 -8566 -9722 948 -7567 9006 -4754 -5133 705 1521 7728 -262 -444 -3267 1715 -9504 -3235 -7738 -3242 9190 63 -9144 7884 7295 -9670 -9100 8624 6829 -3185 9968 -1035 -1191 5788 -6638 3619 6279 -803 8043 5957 6313 -6451 9316 4776 5449 5913 -6347 -2776 -497 6806 -6861 -1415 -9651 -8387 1270 -7495 -3096 5493 -8671 -7707 6314 701 6765 1374 -6819 -31 -4319 -7418 460 4527 8733 2744 6275 -946 -3697 -5426 -9132 9827 -963 -704 -60 -4729 -8440 4216 2958 -6197 -3583 -5905 -7674 2714 -2065 -6642 4062 -892 6399 3918 1677 8021 8588 6907 -1618 2688 -5492 -8368 -9960 7948 -4488 6070 2152 -2250 -4799 -7929 -5852 3345 -278 -5130 9980 3706 -2316 6336 -1597 4908 406 -3407 6094 -7339 3618 -6578 -2159 3481 -4791 1308 7759 6355 8557 5645 6543 -1457 859 -3649 5550 -2258 3659 6705 -226 3416 -1080 4049 2701 5993 -9536 -2794 -9040 9044

#include<bits/stdc++.h>
using namespace std;
// --------------------------------------------------------- ARRAY REVISION -------------------------------------------------------------

// 1. Finding the largest element in an array.

int maxArr(int arr[], int n)
{
	int maxx = INT_MIN;
	for (int i = 0; i < n; i++)
		maxx = max(arr[i], maxx);
	return maxx;
}

// 2. Finding the position of the max element.

int maxPos(int arr[], int n)
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > arr[res])
			res = i;
	}
	return res;
}

// 3. Second Largest element in an array.

int secLargest(int arr[], int n)
{
	int res = -1, largest = 0;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[largest])
		{
			res = largest;
			largest = i;
		}
		else if (arr[i] != arr[largest])
		{
			if (res == -1 || arr[i] > arr[res])
				res = i;
		}
	}
	return res;
}

// 4. Check if array is sorted.

bool issorted(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

// 5. Reverse an Array.

void reverseArr(int arr[], int n)
{
	int low = 0, high = n - 1;
	while (low <= high)
	{
		int temp = arr[low];
		arr[low] = arr[high];
		arr[high] = temp;
		low++;
		high--;
	}
}

// 6. Remove duplicates from a sorted array.

int remDupls(int arr[], int n)
{
	int res = 1;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] != arr[res - 1])
		{
			arr[res] = arr[i];
			res++;
		}
	}
	return res;
}

// 7. Move zeroes to end

int moveZeros(int arr[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			swap(arr[i], arr[count]);
			count++;
		}
	}
}

// 8. Left roate an array by one

void leftRot(int arr[], int n)
{
	int temp = arr[0];
	for (int i = 0; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[n - 1] = temp;
}

// 9. Left rotate an array by d -- REVERSAL ALGORITHM --

void leftRotByd(int arr[], int n, int d)
{
	reverse(arr, arr + d); // Reverse 1st d elements.
	reverse(arr + d, arr + n); //Reverse remaining elements.
	reverse(arr, arr + n); // Reverse whole array.


	// REVERSE THE WHOLE PROCESS FOR CLOCKWISE ROTATION THAT IS GO FROM BOTTOM TO TOP.
}

// 10. Leaders in an array.(An element is called leader if there is nothing greater than this element on right of this element.)

void leader(int arr[], int n)
{
	int curr_ldr = arr[n - 1];
	cout << curr_ldr << " ";

	// prints in reverse order.

	for (int i = n - 2; i >= 0; i--)
	{
		if (curr_ldr < arr[i])
		{
			curr_ldr = arr[i];
			cout << curr_ldr << " ";
		}
	}
}

// 11. Maximum difference problem with order
//     we have to find minimum value of a[j]- a[i]  s.t j > i.
// soln 1. the naive solution is we traverse through each and every pair and get the maximum.
// soln 2. we can sort the array and return a[n-1 - a[0].
// soln 3. efficient soln

int maxDiff(int arr[], int n)
{
	int res = arr[1] - arr[0], minval = arr[0];
	for (int i = 1; i < n; i++)
	{
		res = max(arr[i] - minval, res);
		minval = min(minval, arr[i]);

	}
	return res;
}
// 12. freqencies in a sorted Array.

void printFrq(int arr[], int n)
{
	int i = 1, freq = 1;
	while (i < n)
	{
		while (i < n && arr[i] == arr[i - 1])
		{
			freq++;
			i++;
		}
		cout << arr[i - 1] << " " << freq << "\n";
		i++;
		freq = 1;
	}
	if (n == 1 || arr[n - 1] != arr[n - 2])
	{
		cout << arr[n - 1] << " 1" << endl;
	}
}

// 13. stock buy and sell problem.
// we know the prices of the stock we can buy the stock and sell the stock on any day we have
// to maximize the profit.
// 1. Recursive solution

int maxProfit(int arr[], int start, int end)
{
	if (end <= start)
		return 0;

	int profit = 0;
	for (int i = 0; i < end; i++)
	{
		for (int j = i + 1; j <= end; j++)
		{
			if (arr[j] > arr[i])
			{
				int curr_profit = arr[j] - arr[i] + maxProfit(arr, start, i - 1) + maxProfit(arr, j + 1, end);
				profit = max(curr_profit, profit);
			}
		}
	}
	return profit;
}

// 2. Efficient solution

int stockBuy(int arr[], int n)
{
	int profit = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[i - 1])
		{
			profit += arr[i] - arr[i - 1];
		}
	}
	return profit;
}

// 14. Trapping rain water problem

int getWater(int arr[], int n)
{
	int res = 0;

	int Lmax[n], Rmax[n];
	Lmax[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		Lmax[i] = max(Lmax[i - 1], arr[i]);
	}
	Rmax[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		Rmax[i] = max(arr[i], Rmax[i + 1]);
	}

	for (int i = 1; i < n - 1; i++)
	{
		res +=  min(Lmax[i], Rmax[i]) - arr[i];
	}
	return res;

}


// 15. Maximum consecutve ones in a binary array.

int maxConsOnes(int arr[], int n)
{
	int res = 0, curr = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 1)
		{
			curr++;
			res = max(curr, res);
		}
		else
			curr = 0;
	}
	return res;
}



// 16. Maximum Subaray sum -----KADANE'S ALGORITHM--------
// O(n^2)
int maxSum(int arr[], int n)
{
	int res = arr[0];

	int curr;
	for (int i = 0; i < n; i++)
	{
		curr = 0;

		for (int j = i; j < n; j++)
		{
			curr += arr[j];
			res = max(res, curr);
		}
	}

	return res;
}


// Efficient O(n)
// In kadane's Algorithm we begin traversing the array from the second element.
// for every element there are two cases. either you begin a new subaaray or extend the previos subarray


int maxSum(int arr[], int n)
{
	int res = arr[0];
	int maxEnd = arr[0];

	for (int i = 1; i < n; i++)
	{
		maxEnd = max(maxEnd + arr[i], arr[i]);
		res = max(maxEnd, res);
	}

	return res;
}


// 17. Maximum Even odd subarray, count max no of even odd alternating elemenst

int maxEvenOdd(int arr[], int n)
{
	int res = 1;
	int curr = 1;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] % 2 == 0 and arr[i - 1] % 2 == 1 || arr[i] % 2 == 1 and arr[i - 1] % 2 == 0 )
		{
			curr++;
			res = max(curr, res);

		}
		else
			curr = 1;
	}

	return res;
}
// 18. Maximum Circular Subarray sum

// Naive O(n^2)
int maxCircularSum(int arr[], int n)
{
	int res = arr[0];
	for (int i = 0; i < n; i++)
	{
		int curr_sum = arr[0];
		int curr_max = arr[0];
		for (int j = 1; j < n; j++)
		{
			int index = (i + j) % n;
			curr_sum += arr[index];
			curr_max = max(curr_max, curr_sum);
		}
		res = max(res, curr_max);
	}
}

// optimised using kadane's algo , basically what we do is we calculate minimum subarray sum
// then subtract it from the whole array

int maxCirSum(int arr[], int n)
{
	int max_normal = maxSum(arr, n);
	if (max_normal < 0)
		return max_normal;

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		arr[i] = (-1) * arr[i];
	}

	int res = sum + maxSum(arr, n);

	return res;

}

// 19. Finding majority element ---MOORAY'S VOTING ALGO---
// efficient O(n)

// i. Finding the candidate element.

int findMajority(int arr[], int n)
{
	int res = 0, curr = 1;

	for (int i = 1; i < n; i++)
	{
		if (arr[res] == arr[i])
			curr++;
		else
			curr--;

		if (curr == 0)
		{
			curr = 1;
			res = i;
		}
	}
// ii. find if the candidate is actual a majority or not. majority means occurence is greater than n/2
	curr = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == arr[res])
			curr++;
	}
	if (curr <= n / 2)
		res = -1;


	return res;
}

// 20. Minimum group flips to make array same.
//   Ex.  1 1 0 0 0 1 1 1 0 0 1 1
//        0 0 1 1 0 0 0 0 1 1 0 0
// we note that if we flip only the second group elements we get the minimum no of flips
// 2nd group are either less or eual to the count of first group.

void minimumFlips(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (arr[i] != arr[i - 1])
		{
			if (arr[i] != arr[0])
				cout << "From " << i << " to ";
			else
				cout << i << "\n";
		}

	}
	if (arr[n - 1] != arr[0])
		cout << n - 1 << "\n"; // 0 0 1 1 0 1
}

//  21. Sliding Window Technique

// i. Given an array of integers and a number k, find the maximum sum of k consecutive elements.
//  Naive O((n-k)k)
// int max_sum = INT_MIN;
// for(int i = 0; i+k-1 < n; i++)
// {
// 	int sum = 0;
// 	for(int j = 0; j < k; j++)
// 		sum += arr[j+i];
// 	max_sum = max(sum,max_sum);
// }
// return max_sum;

// Efficient O(n)
// we compute the sum of first window now, we can get the sum of the next window in O(1) time.
// we add the next element and subtract the first element of the last window.

int maxSumk(int arr[], int n, int k)
{
	int curr_sum = 0;
	for (int i = 0; i < k; i++)
		curr_sum += arr[i];

	int max_sum = curr_sum;

	for (int i = k; i < n; i++)
	{
		curr_sum  += arr[i] - arr[i - k];
		max_sum = max(curr_sum, max_sum);
	}
	return max_sum;

}

// ii. Given an array of unsorted integers find if there is an array with given sum.
//  We keep adding elements to the current window until the sum is smaller than the given sum.
//  whenever the sum becomes greater we remove elements from the beginning.

bool isSubSum(int arr[], int n, int sum)
{
	int curr_sum = arr[0], start = 0;
	for (int i = 1; i <= n; i++)
	{
		while (curr_sum > sum and start < i - 1)
		{
			curr_sum -= arr[start];
			start++;
		}

		if (curr_sum == sum)
			return true;

		if (i < n)
			curr_sum += arr[i];
	}
	return (curr_sum == sum);
}
// iii. n bonacci series

void nBonacci(int n, int m)
{
	int arr[m] = {0};
	arr[n] = 1;
	arr[n - 1] = 1;

	for (int i = n + 1; i < m; i++)
	{
		arr[i] = 2 * arr[i - 1] - arr[i - n - 1];
	}

	for (auto &i : arr)
		cout << i << " ";
}

// 22. Sliding window technique

// i. Given a a fixed array and multiple queries, how to efficiently perform these queries

// arr[] = {2, 8, 3, 9, 6 , 5, 4}
//  q1 -> getsum(2,4)
//  q2 -> getsum(4,5)
// ...thousanads of queries
// We can answer all the queries in O(1) time by doing preprocessing or precomputation.
// PREFIX SUM ARRAY
// an array which has sum from 0 to i at index i.
// arrPreSum[] = {2,10,13,22,28,33,37}

void calPreSum( int arr[], int n)
{
	int prefix_sum[n];
	prefix_sum[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		prefix_sum[i] = prefix_sum[i - 1] + arr[i];
	}

	for (int x : prefix_sum)
	{
		cout << x << " ";
	}
}
// cout << "\n" << prefix_sum[r] - prefix_sum[l-1]; for answering queries.
//  if l == 0 print prefix_sum[r];

// ii. Given an array of integers, find if it has an equilibrium point.

// Equilibrium point - Sum of elements before it is equal to sum of elements after it.

bool isEqui(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	int l_sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (l_sum == sum - arr[i])
			return true;

		l_sum += arr[i];

		sum -= arr[i];
	}

	return false;
}

// iii. Given n ranges find the amximum appearing elements in these ranges.
//  L[] = {1, 2, 5, 15};
//  R[] = {5, 8, 7, 18};
//  5 is the max appearing element in these ranges.
int maxOcc (int L[], int R[], int n)
{
	// Create a vector of size greater max range.
	vector<int> arr(1000);

	for (int i = 0; i < n; i++)
	{
		arr[L[i]]++; // starting point of the range
		arr[R[i + 1]]--; // one next to ending point of range.
	}

	int maxm = arr[0], res = 0;

	for (int i = 0; i < 1000; i++)
	{
		arr[i] += arr[i - 1];
		if (maxm < arr[i])
		{
			maxm = arr[i];
			res = i;
		}
	}
	return res;
}

int main()
{
	int n = 4;

	int L[] = {1, 2, 5, 15};
	int R[] = {5, 8, 7, 18};

	cout << maxOcc(L, R, n);



	return 0;
}




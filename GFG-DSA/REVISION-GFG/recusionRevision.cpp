// --------------------------RECURSION-REVISION------------------------------//
#include<bits/stdc++.h>
using namespace std;

/*

1. Recursively calculating binary expresson of a number

void fun(int n)
{
	if (n == 0)
		return;
	fun(n / 2);
	cout << n % 2 << " ";
}

2. Printing n to 1 using recursion

void fun(int n)
{
	if (n == 0)
		return;
	cout << n << " ";
	fun(n - 1);
}

3.Print 1 to n using recursion
	not tail recursive.

void fun(int n)
{
	if (n == 0)
		return;
	fun(n - 1);
	cout << n << " ";
}

4. print 1 to n using tail recursion

void fun(int n, int k)//initially pass k=1;
{
	if (n == 0)
		return;
	cout << k << " ";
	fun(n - 1, k + 1);
}

*/
// 5.tail recursiove equivalent of factorial

int fact(int n, int k)
{
	if (n == 0 || n == 1)
		return k;
	return fact(n - 1, k * n);
}

// 6. nth fibonnaci number

int fibon(int n) {
	if (n == 0 || n == 1)
		return n;
	return fibon(n - 1) + fibon(n - 2);
}

// 7. palindrome check using recursion

bool isPalin(string s, int start, int end)
{
	if (start >= end)
		return true;
	return (s[start] == s[end] && isPalin(s, start + 1, end - 1));
}

// 8. Some of digits until it is  a single digit.

int sumDig( int n)
{
	if (n <= 9)
		return n;
	return sumDig(sumDig(n / 10) + n % 10);
}

// 9. Rope cutting problem using recursion

int ropeCut(int n, int a, int b, int c)
{
	if (n == 0)
		return 0;
	if (n < 0)
		return -1;
	int res = max(max(ropeCut(n - a, a, b, c), ropeCut(n - b, a, b, c)), max(ropeCut(n - c, a, b, c), ropeCut(n - b, a, b, c)));
	if (res == -1)
		return -1;
	return res + 1;

}

// time complexity O(3^n).

// 10. Generating Subsets or subsequences of a string

void genSubsets(string s, string curr, int i)
{
	if (i == s.size())
	{
		cout << curr << endl;
		return;
	}
	genSubsets(s, curr, i + 1);
	genSubsets(s, curr + s[i], i + 1);
}
int main() {
	string s;
	cin >> s;
	string curr = "";
	genSubsets(s, curr, 0);
	return 0;
}


// 11. Tower of Hanoi

void towerOfHanoi(int n, string A, string B, string C)
{
	if (n == 1)
	{
		cout << "Move 1 from " << A << " to " << C << endl;
		return;
	}
	towerOfHanoi(n - 1, A, C, B);
	cout << "Move " << n << " from " << A << " to " << C << endl;
	towerOfHanoi(n - 1, B, A, C);
}

// Time complexity = O(2^n)

// 12.Josephus Problem

int josephus(int n, int k)
{
	if (n == 1)
		return 0;
	// after every rotation or kill every person shifts by k position.
	return (josephus(n - 1, k) + k) % n;
}

// 13. Subset sum problem

i / p = {10, 20, 15}
        check how many subsets of sum 25 are present in this array.


        int subsetSum(int arr[], int n, int sum)
{
	if (n == 0)
	{
		if (sum == 0)
			return 1;
		else
			return 0;
	}
	return subsetSum(arr, n - 1, sum) + subsetSum(arr, n - 1, sum - arr[n - 1]);
}

// 14. pritning all permutations of a string.


void permute(string s, int i)
{
	if (i == s.size() - 1)
	{
		cout << s << "\n";
		return;
	}
	for (int j = i; j < s.size(); j++)
	{
		swap(s[i], s[j]);
		permute(s, i + 1);
		swap(s[i], s[j]);
	}
}


int main() {
	string s = "ABC";
	permute(s, 0);
	return 0;
}
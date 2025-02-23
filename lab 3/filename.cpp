//Example 3.1 
/*#include<iostream>
#include<conio.h>
using namespace std;
int facto(int n)
{
	if (n == 0)
		return 1;
	else
		return n * facto(n - 1);
}
int main()
{
	cout << facto(5) << endl;
	getch();
	return 0;
}*/

//example 3.2
/*#include<iostream>
#include<conio.h>
using namespace std;
void rev() {
	char ch;
	cin.get(ch);
	if (ch != '\n') {
		rev();
		cout.put(ch);
	}
}
int main() {
	rev();
	getch();
	return 0;
}*/



// example 3.3
/*int Power(int X, int N)
{
	if (N == 0)
		return 1;
	else
		return Power(X, N - 1) * X;
}*/

// EXERCISE 3.1
/*#include<iostream>
#include<cmath>
using namespace std;
int main() {
	cout << "N\t2^N" << endl;
	for (int N = 1; N <= 20; ++N) {
		long result = pow(2, N);

		cout << N << " \t " << result  << endl;
	}
}*/


//Example 3.4
/*#include<iostream>
#include<conio.h>
using namespace std;
int Ackermann(int m, int n)
{
	if (m == 0)
		return n + 1;
	else if (m > 0 && n == 0)
		return Ackermann(m - 1, 1);
	else if (m > 0 && n > 0)
		return Ackermann(m - 2, Ackermann(m, n - 1));
}*/
//EXERCISE 3.2
/*int main()
{
	cout << "ackermann of 3,4 is: " << Ackermann(3, 4);
}*/

//EXERCISE 3.3 pt a 
/*#include<iostream>
#include<conio.h>
using namespace std;
void printnum(int n)
{
	if (n < 0)
		return;

	cout << n << " ";
	printnum(n - 1);
}

int main()
{
	int n;
	cout << "enter a number: ";
	cin >> n;
	cout << "numbers from " << n << " to 0: ";
	printnum(n);
	cout << endl;
}*/

//EXERCISE 3.3 pt b
/*#include <iostream>
using namespace std;

int binomialCoefficient(int n, int k) {
	if (k == 0 || k == n) {
		return 1;
	}
	return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

int main() {
	int n, k;
	cout << "Enter n and k for C(n, k): ";
	cin >> n >> k;

	cout << "C(" << n << ", " << k << ") = " << binomialCoefficient(n, k) << endl;
	return 0;
}*/

//EXERCISE 3.3 pt c
/*#include <iostream>
using namespace std;

bool isPrimeHelper(int n, int divisor) {
	if (divisor == 1) {
		return true;
	}
	if (n % divisor == 0) {
		return false;
	}
	return isPrimeHelper(n, divisor - 1);
}

bool isPrime(int n) {
	if (n <= 1) {
		return false;
	}
	return isPrimeHelper(n, n - 1);
}

int main() {
	int n;
	cout << "Enter a number to check if it's prime: ";
	cin >> n;

	if (isPrime(n)) {
		cout << n << " is a prime number." << endl;
	}
	else {
		cout << n << " is not a prime number." << endl;
	}

	return 0;
}*/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define BASE 10
#define N 10000
void shift_left (int A[], int n) {
	int	i;

	/* going from left to right, move everything over to the
	 * left n spaces
	 */
	for (i=N-1; i>=n; i--) A[i] = A[i-n];

	/* fill the last n digits with zeros */

	while (i >= 0) A[i--] = 0;
}
void make_int (int A[], int n) {
	int	i;

	/* start indexing at the 0's place */

	i = 0;

	/* while there is still something left to the number
	 * we're encoding... */

	while (n) {

		/* put the least significant digit of n into A[i] */

		A[i++] = n % BASE;

		/* get rid of the least significant digit,
		 * i.e., shift right once
		 */

		n /= BASE;
	}

	/* fill the rest of the array up with zeros */

	while (i < N) A[i++] = 0;
}
void multiply_one_digit (int A[], int B[], int n) {
	int	i, carry;

	/* no extra overflow to add yet */

	carry = 0;

	/* for each digit, starting with least significant... */

	for (i=0; i<N; i++) {

		/* multiply the digit by n, putting the result in B */

		B[i] = n * A[i];

		/* add in any overflow from the last digit */

		B[i] += carry;

		/* if this product is too big to fit in a digit... */

		if (B[i] >= BASE) {

			/* handle the overflow */

			carry = B[i] / BASE;
			B[i] %= BASE;
		} else

			/* no overflow */

			carry = 0;
	}
	if (carry) printf ("overflow in multiplication!\n");
}
void add (int A[], int B[], int C[]) {
	int	i, carry, sum;

	/* no carry yet */

	carry = 0;

	/* go from least to most significant digit */

	for (i=0; i<N; i++) {

		/* the i'th digit of C is the sum of the
		 * i'th digits of A and B, plus any carry
		 */
		sum = A[i] + B[i] + carry;

		/* if the sum exceeds the base, then we have a carry. */

		if (sum >= BASE) {

			carry = 1;

			/* make sum fit in a digit (same as sum %= BASE) */

			sum -= BASE;
		} else
			/* otherwise no carry */

			carry = 0;

		/* put the result in the sum */

		C[i] = sum;
	}

	/* if we get to the end and still have a carry, we don't have
	 * anywhere to put it, so panic! 
	 */
	
}
void subtraction(int A[], int B[], int C[]) {
	int	i, carry, sum;

	/* no carry yet */

	carry = 0;

	/* go from least to most significant digit */

	for (i=0; i<N; i++) {

		/* the i'th digit of C is the sum of the
		 * i'th digits of A and B, plus any carry
		 */
		 if(A[i]<B[i]+carry)
		{
		sum =10+ A[i] - B[i] - carry;
		carry=1;

		
		} else
		{
			/* otherwise no carry */
			sum =A[i] - B[i] - carry;
			carry = 0;

		}/* put the result in the sum */

		C[i] = sum;
	}

	/* if we get to the end and still have a carry, we don't have
	 * anywhere to put it, so panic! 
	 */

}

void multiply (int A[], int B[], int C[]) {
	int	i, j, P[N];

	/* C will accumulate the sum of partial products.  It's initially 0. */

	make_int (C, 0);

	/* for each digit in A... */

	for (i=0; i<N; i++) {
		/* multiply B by digit A[i] */

		multiply_one_digit (B, P, A[i]);

		/* shift the partial product left i bytes */

		shift_left (P, i);

		/* add result to the running sum */

		add (C, P, C);
	}
}

void Pow(int a[], int b,int c[])
	{
	int x[N];
	make_int(x,1);

	while(b > 0)
	{
		multiply(a,x,c);
		int i;
		for(i=0;i<N;i++) x[i]=c[i];
	}
	b--;
	
}


int main(void) 
{
	int a[N];
	make_int(a,100);
	int b[N];
	make_int(b,10);
	int c[N];
	int k=2;
	subtraction(a,b,c);
	int i=0;
	for(i=0;i<5;i++)
	printf("%d",c[i]);
	return 0;
}


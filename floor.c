#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define BASE 10
#define N 100
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
	int	i, P[N];

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
			b--;
	}

	
}

long long division(int dend[],long long divisor,int quotient[])
{
   
    
    long long temp=0;
    int i=0,j=0,o;
	//for(o=0;o<=N;o++) printf("%d ",dividend[o]);
	
		
    while(i<N)
    {
       //printf("%d ",dend[N-1]);
         temp = temp*10+(long long)dend[i];
         if(temp<divisor){
            
             quotient[j++] = 0;
            
         }
         else
         {
         		
             quotient[j++] = (temp / divisor);;
             temp = temp % divisor;
			
         }
         i++;
    }

   //printf("%lld\n",temp);
    long long remainder = temp;
    return remainder;
    
}
int main(void) 
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
			
			long long n,m;
	
			scanf("%lld%lld",&n,&m);
			if(n<=1000000)
			{
				long long result=0,o=1,i=n,l=0,p;
				for(;i>=1;)
				{
					long long int number=i;
					number*=(i+1);
					number/=2;
					number*=(2*i+1);
					number/=3;
						
					long long int k=3*i*i;
					k+=(3*i);
					k-=1;
					if(number%5 == 0)
						number/=5;
					else 
						k/=5;
					number=number*k;
					result+=o*number;
					printf("%lld ",i);
					l=n/i;
					p=n/i;
					while(p==l)
					{
						i--;
						if(i==0)break;
						p=n/i;
					}
			
					if(i<1) break;
						o=p-l;
				}
				
			
			}
			else
			{
					int an[N];
					int sum[N],sum1[N];
					int i=n;
					make_int(sum,0);
					long long result=0,k=1,l=0,p;
					for(;i>=1;)
					{
						int b[N],c[N],res[N],res1[N];
						make_int(an,i);
						int o;
					
						make_int(res,0);
						make_int(res1,0);
						Pow(an,5,b);
						multiply_one_digit(b,c,6);
				
						add(res,c,res1);
				
						Pow(an,4,b);
						multiply_one_digit(b,c,15);
						add(res1,c,res);
				
						Pow(an,3,b);
						multiply_one_digit(b,c,10);
						add(res,c,res1);
				
						//int o;
				
						subtraction(res1,an,res);
						 
						multiply_one_digit(res,res1,k);
			
						add(sum,res1,sum1);
			
						int w=0;
						for(w=0;w<N;w++)
						sum[w]=sum1[w];
						
						l=n/i;
						p=n/i;
						while(p==l)
						{
							i--;
							if(i==0)break;
							p=n/i;
						}
		 //for(o=0;o<N;o++) printf("%d ",sum1[o]);	
						if(i<1) break;
						k=p-l;
					}
					for(i=0;i<N;i++)
					sum1[i]=sum[N-i-1];
					long long kl=division(sum1,30,sum);
					long long number=0;
					number=division(sum,m,sum1);
					printf("%lld\n",number);
				}
	
}	// your code goes here
return 0;
}



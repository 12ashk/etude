#include<stdio.h>
#include<math.h>

float mycbrt(float n, float eps, float x);

int main(void)
{
	double n, eps, x;

	printf("Please input A, epsilon, and initial value:\n");
	scanf("%lf", &n);
	scanf("%lf", &eps);
	scanf("%lf", &x);
	x = mycbrt(n, eps, x);
	printf("%lf\n", x);

	return 0;
}

float mycbrt(float n, float eps, float x)
{
	if(fabs((x*x*x-n)/(3*x*x)) <= eps){
		x = x - (x*x*x-n)/(3*x*x);
		return x;
	}
	else{
		x = x - (x*x*x-n)/(3*x*x);
		mycbrt(n, eps, x);
	}
}

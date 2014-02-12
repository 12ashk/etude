#include<stdio.h>
#include<math.h>

float mysqrt(float n, float eps, float x);

int main(void)
{
	double n, eps, x;

	printf("Please input A, epsilon, and initial value:\n");
	scanf("%lf", &n);
	scanf("%lf", &eps);
	scanf("%lf", &x);
	x = mysqrt(n, eps, x);
	printf("%lf\n", x);

	return 0;
}

float mysqrt(float n, float eps, float x)
{
	if(fabs(x/2 + n/(2*x) - x) <= eps){
		x = x/2 + n/(2*x);
		return x;
	}
	else{
		x = x/2 + n/(2*x);
		mysqrt(n, eps, x);
	}
}

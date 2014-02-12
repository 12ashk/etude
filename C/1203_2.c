#include<stdio.h>
#include<math.h>

float solution(float a, float b, float c, float d, float x, float eps);

int MAX, i;

int main(void)
{
	float a, b, c, d, x, eps;

	printf("Please input coefficients a, b, c, d for\n");
	printf("a x^3 + b x^2 + c x + d = 0: \n");
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);
	scanf("%f", &d);
	printf("epsilon, initial value, and maximum of iteration: \n");
	scanf("%f", &eps);
	scanf("%f", &x);
	scanf("%d", &MAX);
	i = 0;
	x = solution(a, b, c, d, x, eps);

	if(i < MAX){
		printf("x = %f\n", x);
	}
	else{
		printf("ERORR\n");
	}

	return 0;
}

float solution(float a, float b, float c, float d, float x, float eps)
{
	if(i >= MAX){
		return x;
	}
	else if(fabs((a*x*x*x + b*x*x + c*x + d)/(3.0*a*x*x + 2.0*b*x + c))
			<= eps){
		x = x - (a*x*x*x + b*x*x + c*x + d)/(3.0*a*x*x + 2.0*b*x + c);
		return x;
	}
	else{
		x = x - (a*x*x*x + b*x*x + c*x + d)/(3.0*a*x*x + 2.0*b*x + c);
		i++;
		solution(a, b, c, d, x, eps);
	}
}

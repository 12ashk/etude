#include<stdio.h>
#include<math.h>

int Fermat(int n);
int twocheck(int n);

int num;

int main(void)
{
	scanf("%d", &num);
	printf("%d = ", num);
	Fermat(num);
	printf("\n");
	return 0;
}

int Fermat(int n)
{
	int s, t, temp;
	n = twocheck(n);
	if(n != 1){
		for(t = (int)sqrt(n); t < (n+1)/2; t++){
			if(t*t == n){
				Fermat(t);
				Fermat(t);
				return 1;
			}
			else{
				for(s = 1; s < t; s++){
					if(t*t - s*s == n){
						temp = t+s;
						temp = twocheck(temp);
						if(temp != 1){
							Fermat(t+s);
						}
						temp = twocheck(t-s);
						if(temp != 1){
							Fermat(temp);
							return 0;
						}
					}
				}
			}
		}
		if(n != num){
			printf(" * %d", n);
			return 0;
		}
	}
}

int twocheck(int n)
{
	while(1){
		if(n % 2 == 0){
			printf(" * 2");
			n /= 2;
		}
		else{
			break;
		}
	}
	return n;
}

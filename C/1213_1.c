#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int tikeiseisei(void) 
{ 
	float k;
	k=(float)rand()/RAND_MAX;
	if(k<=0.6){
		return 0; 
	}
	else{
		return 1; 
	}
}

int main(void) 
{ 
	srand(time(NULL));
	int x,y,n,i; 
	printf("n×nの地形を生成します。nの値を入力してください n="); 
	scanf("%d", &n);
	int a[n][n]; 
	for(x=0; x<n; ++x){
		for(y=0; y<n; ++y){
			a[x][y] = tikeiseisei();
			if(a[x][y]==1){
				printf("+ ");
			}
			else{
				printf("# "); 
			}
		} 
		printf("\n"); 
	} 
	printf("地形を生成しました。海から水が侵入してきます！\n"); 
	for(y=0; y<n; ++y){ 
		for(x=0; x<n; ++x){
			if(y==0 || x == 0){
				if(a[x][y]==1){
					a[x][y]=2;
				}
			} 
			else if(y==n-1 || x == n-1){
				if(a[x][y]==1){
					a[x][y]=2;
				}
			} 	    
		}
	}
	for(i = 0; i < n; ++i){
		for(y = 1; y < n-1; ++y){
			for(x = 1; x < n-1; ++x){
				if(a[x][y]==1&&(a[x-1][y]==2||a[x+1][y]==2||a[x][y-1]==2||a[x][y+1]==2)){
					a[x][y]=2; 
				}
			} 
		}
	}
	for(x=0; x<n; ++x){
		for(y=0; y<n; ++y){
			if(a[x][y]==0){
				printf("# ");
			}
			else if(a[x][y]==1){
				printf("+ ");
			}
			else{
				printf("- ");
			}
		} 
		printf("\n"); 
	}
	return 0;
} 

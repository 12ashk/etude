#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 3 //number of cluster
#define M 200 //number of data

struct point
{
	double x, y;
	int clust;
}member[M], centerp[N], temp;

float dist(struct point p, struct point q);
struct point center(int i);
void allot(void);
void printall(void);

int main(int argc, char *argv[])
{
	int i, f, t, count;
	srand(time(NULL));

	FILE *file;
	file = fopen(argv[1], "r");
	for(i = 0; i < M; i++){
		fscanf(file, "%lf", &member[i].x);
		fscanf(file, "%lf", &member[i].y);
	}
	fclose(file);

	for(i = 0; i < N; i++){
		centerp[i].clust = i;
		t = rand() % M;
		centerp[i].x = member[t].x;
		centerp[i].y = member[t].y;
	}
	
	count = 1;
	while(1){
		f = 0;
		allot();
		count++;
		printall();
		for(i = 0; i < N; i++){
			temp = center(i);
			if(temp.x == centerp[i].x && temp.y == centerp[i].y){
				f++;
			}
			centerp[i] = temp;
		}
		if(f == N){
			break;
		}
	}
	printall();
	printf("%d\n", count);

	return 0;
}

float dist(struct point p, struct point q)
{
	return sqrt((p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y));
}

struct point center(int i)
{
	struct point p;
	int j, num = 0;
	p.x = 0;
	p.y = 0;
	for(j = 0; j < M; j++){
		if(member[j].clust == i){
			num++;
			p.x += member[j].x;
			p.y += member[j].y;
		}
	}
	p.x /= num;
	p.y /= num;
	return p;
}

void allot(void)
{
	int j, k, num;
	float t;
	for(j = 0, k = 0; j < M; j++){
		t = dist(member[j], centerp[k]);
		for(k = 1, num = 0; k < N; k++){
			if(t > dist(member[j], centerp[k])){
				t = dist(member[j], centerp[k]);
				num = k;
			}
		}
		member[j].clust = num;
	}
}

void printall(void)
{
	int i;
	for(i = 0; i < M; i++){
		printf("%d %lf %lf\n", member[i].clust, member[i].x, member[i].y);
	}
	printf("\n");
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double *insertion(double *array, int n);
double *bubble(double *array, int n);
double *quick(double *array, int n);
double *heap(double *array, int n);

double *insertion(double *array, int n){
    double t;
    int i, j;
    for(i = 1; i < n; i++){
        if(array[i-1] > array[i]){
            t = array[i];
            for(j = i; j > 0; j--){
                if(array[j-1] < t) break;
                array[j] = array[j-1];
            }
            array[j] = t;
        }
    }
    return array;
}

double *bubble(double *array, int n){
    double t;
    for(int i = 0; i < n; i++){
        for(int j = n-1; j > i; j--){
            if(array[j-1] > array[j]){
                t = array[j];
                array[j] = array[j-1];
                array[j-1] = t;
            }
        }
    }
    return array;
}

double *_heap(double *array, int k, int n){
    int j;
    double t = array[k];
    while(1){
        j = 2*k+1;
        if(j > n) break;
        if(j != n && array[j+1] > array[j]) j++;
        if(t >= array[j]) break;
        array[k] = array[j];
        k = j;
    }
    array[k] = t;
    return array;
}

double *heap(double *array, int n){
    double t;
    for(int i = (n-2)/2; i > -1; i--){
        _heap(array, i, n);
    }
    for(int i = n-1; i > 0; i--){
        t = array[0];
        array[0] = array[i];
        array[i] = t;
        _heap(array, 0, i-1);
    }
    return array;
}

double *_quick(double* array, int l, int r){
    if(l < r){
        int i = l, j = r;
        double t, p;
        if(array[l] > array[l+1]) p = array[l];
        else p = array[l+1];
        while(1){
            while(array[i] < p) i++;
            while(p < array[j]) j--;
            if(i >= j) break;
            t = array[i];
            array[i] = array[j];
            array[j] = t;
            i++, j--;
        }
        _quick(array, l, i-1);
        _quick(array, j+1, r);
    }
    return array;
}  

double *quick(double* array, int n){
    return _quick(array, 0, n-1);
}

int main(void){
    int n = 20;
    double *array = (double *)calloc(n, sizeof(double));
    srand((unsigned)time(NULL));
    for(int i = 0; i < n; i++){
        array[i] = (double)(int)(rand()%100);
        printf("%.0f ", array[i]);
    }
    printf("\n");
//    array = insertion(array, n);
//    array = bubble(array, n);
//    array = heap(array, n);
    array = quick(array, n);
    for(int i = 0; i < n; i++){
        printf("%.0f ", array[i]);
    }
    printf("\n");
    return 0;
}

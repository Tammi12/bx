#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

const int N = 20000;
const int A = 20000;//行列向量的元素数相同
int a[N][N];
double col_sum[A], p_row[A];

// n*n矩阵、列向量、给定行向量，赋初值
void init(int n)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = i + j;
    for (int i = 0; i < A; i++)
        col_sum[i] = 0;
    for (int i = 0; i < A; i++)
        p_row[i] = i;
}
int main()
{
    long long head, tail, freq; // timers
    init(N);
    int num = 20000;
    QueryPerformanceFrequency((LARGE_INTEGER *) & freq);
    QueryPerformanceCounter((LARGE_INTEGER *) & head);

//矩阵向量乘法平凡算法
    /*for (int i = 0; i < num; i++) {
        col_sum[i] = 0.0;
        for (int j = 0; j < num; j++)
            col_sum[i] += a[j][i] * p_row[j];
    }*/
//矩阵向量乘法优化算法
//    for (int i = 0; i < num; i++)
//        col_sum[i] = 0.0;
//    for (int j = 0; j < num; j++)
//        for (int i = 0; i < num; i++)
//            col_sum[i] += a[j][i] * p_row[j];
    

//逐个累加的平凡算法
    /*for (int i = 0; i < num; i++)
        col_sum[0] += p_row[i];*/

//超标量优化算法（两路链式累加）
        /*for (int i = 0; i < num; i += 2) {
            col_sum[1] += p_row[i];
            col_sum[2] += p_row[i + 1];
    
        }
        col_sum[0]=0.0;
        col_sum[0] =col_sum[1] + col_sum[2];*/

    QueryPerformanceCounter((LARGE_INTEGER *) & tail);
    cout <<  "col:" << (tail - head) * 1000.0 / freq<< "ms" << endl;
    return 0;
}

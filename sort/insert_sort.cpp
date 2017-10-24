/*
 * File Name: insert_sort.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Mon Oct 23 09:01:31 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 直接插入排序 
*/ 

/*
 * 直接插入排序思想（已优化）
 * 1、数组被分为 R[1...i-1](已排好序的有序区) 和 R[i...n](未排好序的有序区) 
 * 2、将待插入记录R[i]的关键字从右向左一次与有序区中记录R[j](j=i-1, i-2, ..., 1)的关键字进行比较
 *    1) 如果R[j]的关键字大于R[i]的关键字，则将R[j]后移一个位置
 *    2) 如果R[j]的关键字小于或者等于R[i]的关键字，则查找过程结束，j+1即为R[i]的插入位置
 *
 * 优化分析：
 *    关键字比R[j]的关键字大的记录均已后移，所以j+1的位置已经腾空，只要将R[i]直接插入此位置即可完成一趟直接插入排序
 */

#include <iostream>
using namespace std;

void insert_sort(int a[], int n){
    int temp;
    for(int i = 1; i < n; i++){
        temp = a[i];
        int j;
        for(j = i-1; j >= 0 && temp < a[j]; j--){
            a[j+1] = a[j]; //向后移动
        } 
    
        a[j+1] = temp;
    } 
} 


void print(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    } 

    cout << endl;
} 
int main(){
    int a[] = {3, 5, 1, 7, 6, 2, 8, 9, 4};
    cout << "before sort : ";
    print(a, 9);

    insert_sort(a, 9);
    cout << "after  sort : ";
    print(a, 9);

    return 0;
} 


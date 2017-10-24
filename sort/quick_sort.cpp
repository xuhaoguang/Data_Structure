/*
 * File Name: quick_sort.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Mon Oct 23 13:57:55 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 快速排序
*/ 

/*
 * 快速排序思想：
 * 1、在A[low, high]中悬着一个记录作为基准pivot
 * 2、j从右边往前边扫，i从左边往右边扫，保证A[low, pivot-1] <= A[pivot] << A[pivot+1, high] 
 * 3、依次递归进行快速排序
 */

#include <iostream>
using namespace std;

void quick_sort(int a[], int low, int high){
    int i, j, pivot;

    if(low < high){
        pivot = a[low];
        i = low;
        j = high;

        while(i < j){
            while(i < j && a[j] >= pivot){
                j--;
            } 
            if(i < j){
                a[i++] = a[j];
            } 

            while(i < j && a[i] <= pivot){
                i++;
            } 
            if(i < j){
                a[j--] = a[i]; 
            } 
        } 

        a[i] = pivot;
        quick_sort(a, low, i-1);
        quick_sort(a, i+1, high);
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

    quick_sort(a, 0, 8);
    cout << "after  sort : ";
    print(a, 9);

    return 0;
}

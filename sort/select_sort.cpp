/*
 * File Name: select_sort.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Mon Oct 23 14:58:26 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 选择排序 
*/ 


/*
 * 选择排序思想
 * 1、初始状态：无序区为A[1...n]，有序区为空
 * 2、第1趟排序：在无序区中选择最小的记录A[k]，将它与无序区的第1个记录A[1]交换
 * 3、第i趟排序：当前有序区为A[1...i-1]，无序区为A[i...n]，从无序区中选出关键字最小的记录A[k]，将它与A[i]交换，依次类推 
 */

#include <iostream>
using namespace std;

void print(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    } 

    cout << endl;
}

void select_sort(int a[], int n){
    for(int i = 0; i < n; i++){ //进行n-1次遍历
        int x = a[i];
        int l = i;

        print(a, 9);
        for(int j = i; j < n; j++){ //从i位置向数组尾部遍历
            if(a[j] < x){
                x = a[j]; //x保存每次遍历搜索到的最小数
                l = j;    //l记录最小数的位置
            } 
        }   

        a[l] = a[i]; //把最小元素与a[i]进行交换
        a[i] = x;
    } 
}  

int main(){
    int a[] = {3, 5, 1, 7, 6, 2, 8, 9, 4};
    cout << "before sort : ";
    print(a, 9);

    select_sort(a, 9);
    cout << "after  sort : ";
    print(a, 9);

    return 0;
}

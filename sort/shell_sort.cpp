/*
 * File Name: shell_sort.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Mon Oct 23 09:01:31 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 希尔排序 
*/ 

/*
 * 希尔排序思想（直接插入排序是增量为1的希尔排序
 * 1、设置增量区间，[初始值...1]
 * 2、对每个增量区间进行直接插入排序
 */

#include <iostream>
using namespace std;

void shell_sort(int a[], int n){
    int temp;
    for(int h = n/2; h > 0; h=h/2){ //增量控制，初始值为数组长度的一半，以后依次减半，直到增量变为1
        //下面就是直接插入排序
        for(int i = h; i < n; i++){
            temp = a[i];
            int j;
            for(j = i-h; j >= 0 && temp < a[j]; j=j-h){
                a[j+h] = a[j]; //向后移动
            } 
        
            a[j+h] = temp;
        }
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

    shell_sort(a, 9);
    cout << "after  sort : ";
    print(a, 9);

    return 0;
} 

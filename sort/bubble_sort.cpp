/*
 * File Name: bubble_sort.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Mon Oct 23 10:23:31 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 冒泡排序 
*/ 

/*
 * 冒泡排序思想
 * 1、将被排序的记录数组A[1...n]垂直排列，每个记录A[i]看作重量为A[i]气泡
 * 2、从下往上扫描数组，轻气泡不断往上浮动
 *
 * 步骤：
 * 1、初始状态下，A[1...n]为无序区
 * 2、第一趟扫描：从无序区底部向上依次比较相邻的两个气泡重量，若发现轻者在下，重者在上，则交换二者的位置，即依次比较(A[n], A[n-1])，(A[n-1], A[n-2])，...，(A[2, A[1])，对于每对气泡(A[j+1], A[j])，如果A[j+1] < A[j]，则交换A[j+1]和A[j]的内容。
 * 3、第一趟扫描完毕后，最轻的气泡酒漂浮到该区间的顶部，即关键字最小的记录被放在最高的位置A[1]上。
 * 4、第二塘扫描后，扫描A[2...n]，扫描完毕时，第二重的气泡被放在A[2]的位置上。
 * 5、以此类推
 * 6、经过n-1趟扫描后可得到有序区A[1...n]
 */

#include <iostream>
using namespace std;

void bubble_sort(int a[], int n){
    int exchange = 0; //标记排序过程中是否有元素交换
    for(int i = 0; i < n-1; i++){
        exchange = 0;
        for(int j = n-1; j >= i; j--){
            if(a[j] < a[j-1]){
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;

                exchange = 1; //发生交换
            } 
        }

        if(exchange != 1){ //已经排好序了，不需要继续扫描了
            return;
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

    bubble_sort(a, 9);
    cout << "after  sort : ";
    print(a, 9);

    return 0;
} 

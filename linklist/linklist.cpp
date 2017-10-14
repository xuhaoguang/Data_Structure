/*
 * File Name: linklist.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Sat Oct 14 12:53:05 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 链表的常见用法 
*/ 
#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node *next;
}Node;

//@briefs: 创建单链表
Node* create(){
    int i = 0; //记录链表中节点的个数
    Node *head, *p, *q;
    int x = -1;

    head = (Node*)malloc(sizeof(Node));
    
    while(true){
        cin >> x; //输入链表中节点的值
        if(x == -1){
            break; //当输入-1时表示结束输入
        } 

        p = (Node*)malloc(sizeof(Node));
        p->data = x;

        if(++i == 1){
            head->next = p; //链表只有一个元素时连接到head的后面
        }else{
            q->next = p; //连接到链表末尾
        } 

        q = p;
    } 

    q->next = NULL; //将链表的最后一个节点设置为空
    return head; //返回头结点
} 

//@briefs：返回链表的长度
int getLength(Node *head){
    int len = 0;
    Node *p;
    p = head->next;

    while(p != NULL){
        len++;
        p = p->next;
    } 

    return len;
} 

//@briefs：打印单链表
void print(Node *head){
    Node *p;
    int index = 0;
    if(head->next == NULL || head == NULL){
        cerr << "Linklist is empty" << endl;
        return;
    } 

    p = head->next;
    while(p != NULL){
        cout << ++index << "\t" << p->data << endl;
        p = p->next;
    } 
} 

//@briefs：查找单链表节点的位置
Node* search_Node(Node *head, int pos){
    if(pos < 0){
        cerr << "illegal position" << endl;
        return NULL;
    } 
    
    if(pos == 0){
        return head;
    } 

    Node *p = head->next;
    if(head == NULL || p == NULL){
        cerr << "link is empty" << endl;
        return NULL;
    } 

    while(--pos){
        if((p = p->next) == NULL){
            cerr << "illegal position" << endl;
            break;
        } 
    } 

    return p;
} 

//@briefs：指定位置处链表的插入
Node* insert_Node(Node *head, int pos, int data){
    Node* item = NULL;
    Node* p;

    item = (Node*)malloc(sizeof(Node));
    item->data = data;

    p = search_Node(head, pos); //找到插入位置
    if(p != NULL){
        //插入操作
        item->next = p->next;
        p->next = item;
    }

    return head;
} 

int main(){
    Node *head = create();
    cout << "the length of linklist is " << getLength(head) << endl;
    print(head);

    //cout << search_Node(head, 0)->data << endl;
    //cout << search_Node(head, 1)->data << endl;
    //cout << search_Node(head, 2)->data << endl;
    //cout << search_Node(head, 3)->data << endl;
    //cout << search_Node(head, 4)->data << endl;
    //cout << search_Node(head, 5)->data << endl;
    
    print(insert_Node(head, 0, 100));
    cout << endl;
    print(insert_Node(head, 3, 200));

    return 0;
} 

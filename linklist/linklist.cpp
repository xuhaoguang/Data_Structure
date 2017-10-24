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
        //cout << ++index << "\t" << p->data << endl;
        cout << p->data << " -> ";
        p = p->next;
    } 

    cout << "NULL" << endl;
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
    Node* item = (Node*)malloc(sizeof(Node));
    item->data = data;

    Node* p = search_Node(head, pos); //找到插入位置
    if(p != NULL){
        //插入操作
        item->next = p->next;
        p->next = item;
    }

    return head;
} 

//@briefs：单链表的删除
Node* delete_node(Node* head, int pos){
    Node* item = NULL;
    Node* p = head->next;
    
    if(head == NULL || p == NULL){
        cerr << "linklist is empty";
        return NULL;
    } 

    p = search_Node(head, pos);
    if(p != NULL && p->next != NULL){
        item = p->next;
        p->next = item->next;
        delete item;
    } 

    return head;
} 

//@briefs：链表逆置
Node* reverse(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    } 

    Node *p, *q, *r;
    p = head->next;
    q = p->next;
    p->next = NULL; //将第一个节点作为最后一个节点

    while(q != NULL){
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    } 

    head->next = p; //将头节点指针执行p
    return head;
} 

//@briefs：查找单链表的中间元素
Node* find_mid_node(Node* head){
    if(head == NULL || head->next == NULL){
        cerr << "linklist is empty" << endl;
        return NULL;
    } 

    Node *slow, *fast;
    slow = head;
    fast = head;

    while(fast->next != NULL){
        //cout << slow->data << "\t" << fast->data << endl;
        fast = fast->next;
        slow = slow->next;

        if(fast->next != NULL){ //这一步很重要
            fast = fast->next;
        }
    } 

    return slow;
} 


//@briefs：判断链表是否存在环
bool isLoop(Node* head){
    if(head == NULL || head->next == NULL){
        return false;
    } 
    
    Node *slow, *fast;
    slow = head;
    fast = head;

    while(fast->next != NULL && fast != slow){
        fast = fast->next;
        slow = slow->next;

        if(fast->next != NULL){ //这一步很重要
            fast = fast->next;
        }
    } 

    if(fast == slow){
        return true;
    }else{
        return false;
    } 
} 

//@briefs：判断两个链表是否相交
bool isLoop(Node* head1, Node* head2){
    if(head1 == NULL || head1->next == NULL || head2 == NULL || head2->next == NULL){
        return false;
    } 
    
    Node *p1, *p2;
    p1 = head1;
    p2 = head2;

    while(p1->next != NULL){
        p1 = p1->next;
    } 
    
    while(p2->next != NULL){
        p2 = p2->next;
    } 

    if(p1 == p2){
        return true;
    }else{
        return false;
    } 
}

//@briefs：插入节点
Node* merge_insert(Node* head, Node* item){
    Node *p = head->next;
    Node *q = NULL;

    while(p != NULL && p->data < item->data){
        q = p;
        p = p->next;
    } 
    
    q->next = item;
    item->next = p;
    
    print(head);
    //cout << q->data << "\t" << p->data << 
    return head;
} 

//@briefs：单链表的合并，需保证有序
Node* merge(Node* head1, Node* head2){
    //判断便捷情况
    if(head1 == NULL){
        return head2;
    }else if(head2 == NULL){
        return head1;
    } 

    Node* head;
    Node* p;
    Node* nextP;
    //选取较短的链表，这样可以保证插入的次数少一些
    if(getLength(head1) >= getLength(head2)){
        head = head1;
        p = head2->next;
    }else{
        head = head2;
        p = head1->next;
    } 

    while(p != NULL){
        nextP = p->next;
        head = merge_insert(head, p);
        p = nextP;
    } 
    
    return head;
} 

//@briefs：单链表的合并，需保证有序
Node* merge1(Node* head1, Node* head2){
    //判断便捷情况
    if(head1 == NULL){
        return head2;
    }else if(head2 == NULL){
        return head1;
    } 
    
    Node* head = NULL;

    if(head1->data < head2->data){
        head = head1;
        head->next = merge1(head1->next, head2);
    }else{
        head = head2;
        head->next = merge1(head1, head2->next);
    } 
    
    return head;
}

Node* merge2(Node* head1, Node* head2){
    if(head1 == NULL){
        return head2;
    }

    if(head2 == NULL){
        return head1;
    }

    Node* head = NULL;
    Node* p1 = head1->next;
    Node* p2 = head2->next;

    if(head1->data < head2->data){
        head = head1;
        p1 = head1->next;
    }else{
        head = head2;
        p2 = head2->next;
    }

    Node* p = head; //p always point to merge node
    while(p1 && p2){
        if(p1->data < p2->data){
            p->next = p1;
            p1 = p1->next;
        }else{
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    }

    if(p1){
        p->next = p1;
    }else if(p2){
        p->next = p2;
    }

    return head;
}

int main(){
    //Node *head = create();
    //cout << "the length of linklist is " << getLength(head) << endl;
    //
    //cout << endl;
    //print(head);

    //cout << search_Node(head, 0)->data << endl;
    //cout << search_Node(head, 1)->data << endl;
    //cout << search_Node(head, 2)->data << endl;
    //cout << search_Node(head, 3)->data << endl;
    //cout << search_Node(head, 4)->data << endl;
    //cout << search_Node(head, 5)->data << endl;
    
    //print(insert_Node(head, 0, 100));
    //cout << endl;

    //print(insert_Node(head, 3, 200));
    //cout << endl;
    //
    //print(delete_node(head, 3));
    //cout << endl;

    //print(reverse(head));
    //cout << endl;

    //cout << find_mid_node(head)->data << endl;
    
    Node* head1 = create();
    print(head1);

    Node* head2 = create();
    print(head2);
    
    //Node* merge_head = merge(head1, head2);
    //print(merge_head);
    
    //Node* merge_head = merge1(head1, head2);
    //merge_head = merge_head->next; //因为返回来的链表有两个头结点，所以需要删一个头结点
    //print(merge_head);
    
    Node* merge_head = merge2(head1, head2);
    //merge_head = merge_head->next; //因为返回来的链表有两个头结点，所以需要删一个头结点
    print(merge_head);

    return 0;
} 

/*
删除元素
描述

在学会创建链表、逆序输出链表，我们将练习如何删除链表中的元素（0个、单个、多个）。


输入
输入数据包括两行。

在第一行中，输入一串正整数和-1，两个数之间用空格隔开，以-1作为结束标记；只有正整数和-1，不会出现其他数，且-1一定出现在最后。

在第二行中，输入需要删除的元素值。


输出
按顺序输出链表中剩余的元素。如果链表为空，则直接输出-1。


输入样例 1

8 8 2 3 8 9 -1
8
输出样例 1

2 3 9
输入样例 2

10 -1
10
输出样例 2

-1
提示

本题为程序填空题，代码如下。

#include<iostream>

using namespace std;

struct node

{

int val;

node* next;

};

node* createList()

{ // 请将这函数补充完整

}

node* deleteElements(node* head, int v)

{ // 请将这函数补充完整

}

int main()

{

node* head = NULL;

head = createList();

int v;

cin >> v

head = deleteElements(head, v);

if (head == NULL)

{

cout << "-1 ";

}

else

{

node* p = head;

while (p != NULL)

{

cout << p->val << " ";

p = p->next;

}

}

return 0;

}
*/

#include<iostream>

using namespace std;

struct node

{

    int val;

    node* next;

};

node* createList()

{
    // 请将这函数补充完整
    int val=0;
    struct node *head = NULL,*p=head;
    while((cin>>val)&&(val!=-1))
    {
        struct node *q=new struct node;
        if(!head)
            head=p=q;
        p->next=q,q->val=val,q->next=NULL,p=q;
    }
    return head;
}

node* deleteElements(node* head, int v)

{
    // 请将这函数补充完整
    if(head)
    {
        struct node *p=head,*q=p;
        while(q)
            if(q->val==v)
            {
                if(q!=head)
                    q=q->next,delete p->next,p->next=q;
                else
                    head=head->next,p=head,delete q,q=p;
            }
            else
            {
                if(q!=head)
                    p=p->next;
                q=q->next;
            }
    }
    return head;
}

int main()

{

    node* head = NULL;

    head = createList();

    int v;

    cin >> v;

    head = deleteElements(head, v);

    if (head == NULL)

    {

        cout << "-1 ";

    }

    else

    {

        node* p = head;

        while (p != NULL)

        {

            cout << p->val << " ";

            p = p->next;

        }

    }

    return 0;

}

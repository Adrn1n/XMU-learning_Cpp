/*
逆序链表
描述

在上一道题中，我们学会了如何创建链表，这道题我们将练习如何对链表逆序输出。


输入
输入一串正整数和-1，两个数之间用空格隔开，以-1作为结束标记。

在输入的数中，只有正整数和-1，不会出现其他数，且-1一定出现在最后。


输出
按输入时的相反顺序，输出所有的正整数，且每个正整数后输出一个空格。

如果没有输入任何正整数，则直接输出-1。


输入样例 1

5 3 2 6 -1
输出样例 1

6 2 3 5
输入样例 2

-1
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

{//请你将这个函数补充完整

}

node* reverseList(node* head)

{//请你将这个函数补充完整

}

int main()

{

node* head = NULL;

head = createList();

node* head1 = NULL;

head1 = reverseList(head);

if (head1 == NULL)

{

cout << "-1 ";

}

else

{

node* p = head1;

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
    //请你将这个函数补充完整
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

node* reverseList(node* head)

{
    //请你将这个函数补充完整
    if(head)
    {
        struct node *p=head,*q=p->next;
        while(q)
        {
            struct node *r=q->next;
            if(p==head)
                p->next=NULL;
            q->next=p,p=q,q=r;
            if(r)
                r=r->next;
        }
        return p;
    }
    else
        return head;
}

int main()

{

    node* head = NULL;

    head = createList();

    node* head1 = NULL;

    head1 = reverseList(head);

    if (head1 == NULL)

    {

        cout << "-1 ";

    }

    else

    {

        node* p = head1;

        while (p != NULL)

        {

            cout << p->val << " ";

            p = p->next;

        }

    }

    return 0;

}

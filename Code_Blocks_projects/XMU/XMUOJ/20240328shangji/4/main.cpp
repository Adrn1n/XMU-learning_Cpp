/*
链表合并
描述

两个链表存的数都是升序的，对两个链表做合并，合并后的链表仍然是升序的。

例如：

链表1：1 2 3 5

链表2：2 4 9

合并成链表3：1 2 2 3 4 5 9


输入
输入数据包括两行。

在第一行中，输入一串正整数和-1，两个数之间用空格隔开，以-1作为结束标记；只有正整数和-1，不会出现其他数，且-1一定出现在最后；默认输入的正数都是升序的。

在第二行中，输入一串正整数和-1，格式和要求同上。


输出
依次输出合并后的链表中元素。如果链表为空，则直接输出-1。


输入样例 1

1 2 3 5 -1
2 4 9 -1
输出样例 1

1 2 2 3 4 5 9
输入样例 2

1 2 3 5 -1
-1
输出样例 2

1 2 3 5
输入样例 3

-1
-1
输出样例 3

-1
提示

本题为程序填空题，代码如下。

#include <iostream>

using namespace std;

struct node

{

int val;

node* next;

};

node* createList()

{//将这个函数补充完整

}

node* merge(node* head1, node* head2)

{//将这个函数补充完整

}

int main()

{

node *head1, *head2, *head3;

head1 = createList();

head2 = createList();

head3 = merge(head1, head2);

if (head3 == NULL)

{

cout << "-1 ";

}

else

{

node* p = head3;

while (p != NULL)

{

cout << p->val << " ";

p = p->next;

}

}

return 0;

}
*/

#include <iostream>

using namespace std;

struct node

{

    int val;

    node* next;

};

node* createList()

{
    //将这个函数补充完整
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

node* merge(node* head1, node* head2)

{
    //将这个函数补充完整
    struct node *p1=head1,*p2=head2,*p3=NULL,*head=p3;
    while((p1)&&(p2))
    {
        int val=p1->val;
        if((p1->val)>(p2->val))
            val=p2->val,p2=p2->next;
        else
            p1=p1->next;
        struct node *q=new struct node;
        q->val=val,q->next=NULL;
        if(!head)
            head=q;
        else
            p3->next=q;
        p3=q;
    }
    if(p1)
    {
        if(head)
            p3->next=p1;
        else
            head=p1;
    }
    else
    {
        if(head)
            p3->next=p2;
        else
            head=p2;
    }
    return head;
}

int main()

{

    node *head1, *head2, *head3;

    head1 = createList();

    head2 = createList();

    head3 = merge(head1, head2);

    if (head3 == NULL)

    {

        cout << "-1 ";

    }

    else

    {

        node* p = head3;

        while (p != NULL)

        {

            cout << p->val << " ";

            p = p->next;

        }

    }

    return 0;

}

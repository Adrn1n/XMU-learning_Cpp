/*
创建链表
描述

当要输入数的个数不确定时，可以用链表来存储这些数。我们首先要做的是创建一个链表。


输入
输入一串正整数和-1，两个数之间用空格隔开，以-1作为结束标记。

在输入的数中，只有正整数和-1，不会出现其他数，且-1一定出现在最后。


输出
按输入时的顺序，输出所有的正整数，且每个正整数后输出一个空格。

如果没有输入任何正整数，则直接输出-1。


输入样例 1

5 3 2 6 100 9 12 30232 -1
输出样例 1

5 3 2 6 100 9 12 30232
输入样例 2

-1
输出样例 2

-1
提示

单测试用例，不用处理多组数据输入。

本题为程序填空题，代码如下。

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

}

int main()

{

node* head = NULL;

head = createList();

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

int main()

{

    node* head = NULL;

    head = createList();

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

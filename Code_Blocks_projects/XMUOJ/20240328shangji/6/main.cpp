/*
后半个链表
描述

输入一个链表，输出该链表的后半部分。


输入
输入一串正整数和-1，两个数之间用空格隔开，以-1作为结束标记；只有正整数和-1，不会出现其他数，且-1一定出现在最后。


输出
输出链表的后半部分，每个正整数后面有一个空格。

如果输入的链表为空，则输出-1。


输入样例 1

1 2 3 4 5 -1
输出样例 1

3 4 5
输入样例 2

2 3 -1
输出样例 2

3
输入样例 3

2 -1
输出样例 3

2
输入样例 4

-1
输出样例 4

-1
提示

本题为程序填空题，代码如下。

#include <iostream>

using namespace std;

struct ListNode

{

int val;

ListNode* next;

};

ListNode* createList()

{

ListNode* head = NULL;

ListNode* p1, * p2;

p1 = new ListNode;

p2 = p1;

cin >> p1->val;

while (p1->val != -1)

{

if (head == NULL)

head = p1;

else p2->next = p1;

p2 = p1;

p1 = new struct ListNode;

cin >> p1->val;

}

p2->next = NULL;

delete p1;

return head;

}

ListNode* middleNode(ListNode* head) {

// 这个函数需要你补充完整

}

int main()

{

ListNode* head;

head = createList();

ListNode* ans = middleNode(head);

if (ans == NULL)

{

cout << "-1";

}

else

{

while (ans != NULL)

{

cout << ans->val << " ";

ans = ans->next;

}

}

return 0;

}
*/

#include <iostream>

using namespace std;

struct ListNode

{

    int val;

    ListNode* next;

};

ListNode* createList()

{

    ListNode* head = NULL;

    ListNode* p1, * p2;

    p1 = new ListNode;

    p2 = p1;

    cin >> p1->val;

    while (p1->val != -1)

    {

        if (head == NULL)

            head = p1;

        else p2->next = p1;

        p2 = p1;

        p1 = new struct ListNode;

        cin >> p1->val;

    }

    p2->next = NULL;

    delete p1;

    return head;

}

ListNode* middleNode(ListNode* head)
{

// 这个函数需要你补充完整
//    struct ListNode *p=head;
//    int n=0;
//    while(p)
//        n++,p=p->next;
//    n/=2;
//    p=head;
//    while(n--)
//        p=p->next;
//    return p;
    struct ListNode *p=head;
    if(p)
    {
        struct ListNode *q=p->next;
        while(q)
        {
            p=p->next,q=q->next;
            if(q)
                q=q->next;
        }
    }
    return p;
}

int main()

{

    ListNode* head;

    head = createList();

    ListNode* ans = middleNode(head);

    if (ans == NULL)

    {

        cout << "-1";

    }

    else

    {

        while (ans != NULL)

        {

            cout << ans->val << " ";

            ans = ans->next;

        }

    }

    return 0;

}

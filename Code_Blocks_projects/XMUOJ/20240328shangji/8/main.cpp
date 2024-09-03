/*
链表重排
描述

输入一个链表，请你对这个链表进行重新分组排列：所有索引为奇数的节点为第一组，所有索引为偶数的节点为第二组。

第一个节点被看作奇数节点，重新排列后的两组内部的相对顺序应该与输入时保持一致。


输入
输入一串正整数和-1，两个数之间用空格隔开，以-1作为结束标记；只有正整数和-1，不会出现其他数，且-1一定出现在最后。


输出
输出重新排列后的链表，每个正整数后面有一个空格。

如果输入链表为空，则输出-1。


输入样例 1

2 1 3 5 6 4 7 -1
输出样例 1

2 3 6 7 1 5 4
输入样例 2

3 -1
输出样例 2

3
输入样例 3

-1
输出样例 3

-1
提示

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

ListNode* oddEvenList(ListNode* head) {

//这个函数需要你补充完整

}

int main()

{

ListNode* head;

head = createList();

ListNode* ans = oddEvenList(head);

if (ans == NULL)

cout << "-1";

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

ListNode* oddEvenList(ListNode* head)
{

//这个函数需要你补充完整
    if(head)
    {
        struct ListNode *p=head,*q=p->next,*Back=q,*END=q;
        if((q)&&(q->next))
        {
            while(Back->next)
                Back=Back->next;
            while(((p!=END)&&(q!=END))||(p==head))
            {
                p->next=q->next,Back->next=q,q->next=NULL;
                p=p->next,q=p->next,Back=Back->next;
            }
        }
    }
    return head;
}

int main()

{

    ListNode* head;

    head = createList();

    ListNode* ans = oddEvenList(head);

    if (ans == NULL)

        cout << "-1";

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

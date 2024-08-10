/*
倒数第n个节点
描述

输入一个链表，输出该链表中倒数第n个节点。


输入
输入数据包含两行：

第一行输入一串正整数和-1，两个数之间用空格隔开，以-1作为结束标记；只有正整数和-1，不会出现其他数，且-1一定出现在最后；

第二行输入一个非负整数n。


输出
输出链表中倒数第n个节点中的正整数。

如果不存在倒数第n个节点，则输出-1。


输入样例 1

1 2 3 4 5 6 -1
2
输出样例 1

4
输入样例 2

10 -1
1
输出样例 2

-1
输入样例 3

-1
10
输出样例 3

-1
提示

本题为程序填空题，代码如下。

#include <iostream>

using namespace std;

struct ListNode{

int val;

ListNode* next;

};

ListNode* createList(){

ListNode* head = NULL;

ListNode* p1, * p2;

p1 = new ListNode;

p2 = p1;

cin >> p1->val;

while (p1->val != -1){

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

ListNode* getKthFromEnd(ListNode* head, int k) {

// 本函数需要你补充完整

}

int main()

{

ListNode* head;

int k;

head = createList();

cin >> k;

ListNode* ans = getKthFromEnd(head, k);

if (ans == NULL)

cout << "-1";

else cout << ans->val;

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

ListNode* getKthFromEnd(ListNode* head, int k)
{

// 本函数需要你补充完整
//    struct ListNode *p=head;
//    int n=0;
//    while(p)
//        n++,p=p->next;
//    if((k>=0)&&(k<=n-1))
//        n=n-k;
//    else
//        return NULL;
//    p=head;
//    while(--n)
//        p=p->next;
//    return p;
    struct ListNode *p=head,*q=p;
    k++;
    while(q)
    {
        q=q->next;
        if(k)
            k--;
        else
            p=p->next;
    }
    if(k)
        return NULL;
    else
        return p;
}

int main()

{

    ListNode* head;

    int k;

    head = createList();

    cin >> k;

    ListNode* ans = getKthFromEnd(head, k);

    if (ans == NULL)

        cout << "-1";

    else cout << ans->val;

    return 0;

}

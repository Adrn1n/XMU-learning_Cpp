/*
合并子链表
描述

一个链表由非负整数构成，链表开端和末尾是0，中间也可能有0，这些0值将链表分隔成一系列“子链表”。

现在，请你将每条“子链表”合并成一个节点，该节点的值为其对应的子链表的所有节点的值之和，同时去掉分隔标志0。


输入
输入一串非负整数（0、正整数）和-1，两个数之间用空格隔开，以-1作为结束标记；只有非负整数和-1，不会出现其他数，且-1一定出现在最后。

不存在连续0值，且第一个和倒数第二个数均为0值。


输出
输出合并后的链表，每个正整数后面有一个空格。


输入样例 1

0 3 1 0 4 5 2 0 -1
输出样例 1

4 11
输入样例 2

0 6 0 -1
输出样例 2

6
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

ListNode* mergeNodes(ListNode* head)

{ //这个函数需要你补充完成

}

int main()

{

ListNode* head;

head = createList();

ListNode* ans = mergeNodes(head);

while (ans != NULL)

{

cout << ans->val << " ";

ans = ans->next;

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

ListNode* mergeNodes(ListNode* head)

{
    //这个函数需要你补充完成
    struct ListNode *p=head,*ans=NULL,*q=ans;
    if(head)
        do
        {
            int val=0;
            while((p)&&(p->val))
                val+=p->val,p=p->next;
            if(val)
            {
                struct ListNode *tmp=new struct ListNode;
                tmp->val=val,tmp->next=NULL;
                if(!ans)
                    ans=tmp;
                else
                    q->next=tmp;
                q=tmp;
            }
        }
        while((p)&&(p=p->next));
    return ans;
}

int main()

{

    ListNode* head;

    head = createList();

    ListNode* ans = mergeNodes(head);

    while (ans != NULL)

    {

        cout << ans->val << " ";

        ans = ans->next;

    }

    return 0;

}

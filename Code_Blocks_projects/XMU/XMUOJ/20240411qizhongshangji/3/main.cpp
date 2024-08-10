/*
是否回文
描述

判断输入的链表是否是回文的。本题中回文定义：这个链表从头看与从后看是一样的。例如：19 23 19, 就是回文的，但是23 9 32不是回文的。


输入
输入一串正整数和-1，两个数之间用空格隔开，以-1作为结束标记；只有正整数和-1，不会出现其他数，且-1一定出现在最后。题目保证正整数的个数不超过100。


输出
输出一行，首先如果链表为空，那么输出-1。链表不为空时，如果是回文的，那么输出1，否则输出0。


输入样例 1

2 1 2 -1
输出样例 1

1
输入样例 2

2 1 2 4 -1
输出样例 2

0
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

 int isPalindrome(ListNode* head) {
     //这个函数需要你补充完整

 }

 int main() {
     ListNode* head;
     head = createList();
     int ans = isPalindrome(head);
     cout<<ans<<'\n';
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

int isPalindrome(ListNode* head)
{
    //这个函数需要你补充完整
    if(head)
    {
//        const short N=100;
//        ListNode *p_LN=head;
//        int A[N]= {0},*p_A=A,*q_A=A;
//        while(p_LN)
//        {
//            *q_A++=(p_LN->val);
//            p_LN=p_LN->next;
//        }
//        q_A--;
//        while(p_A<q_A)
//        {
//            if(*p_A!=*q_A)
//                return 0;
//            p_A++,q_A--;
//        }
//        return 1;
        ListNode *p_0=head,*p_1=NULL,*q_1=p_1,*tmp=NULL;
        while(p_0)
        {
            q_1=new struct ListNode,q_1->val=p_0->val;
            if(p_1)
                q_1->next=p_1;
            else
                q_1->next=NULL;
            p_1=q_1;
            p_0=p_0->next;
        }
        p_0=head;
        while((p_0)&&(p_1))
        {
            if((p_0->val)!=(p_1->val))
            {
                while(q_1)
                {
                    tmp=q_1->next;
                    delete q_1;
                    q_1=tmp;
                }
                return 0;
            }
            p_0=p_0->next,p_1=p_1->next;
        }
        while(q_1)
        {
            tmp=q_1->next;
            delete q_1;
            q_1=tmp;
        }
        return 1;
    }
    else
        return -1;
}

int main()
{
    ListNode* head;
    head = createList();
    int ans = isPalindrome(head);
    cout<<ans<<'\n';
    return 0;
}

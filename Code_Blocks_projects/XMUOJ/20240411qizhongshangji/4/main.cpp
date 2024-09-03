/*
链表加法
描述

使用链表模拟加法。给定两个链表代表正整数，数字最高位位于链表的开始位置，每个节点只存储一位数字。将这两个数字相加后返回一个新的链表。


输入
输入为两行，每行一串整数和-1。代表将要进行相加的两个数。对于每一行，两个数之间用空格隔开，以-1作为结束标记。每一个整数的范围在0到9之间，代表那一位的数字。输入的两个正整数没有前导0。


输出
输出一行，表示相加后的新链表，以-1作为结束标志。


输入样例 1

7 2 4 3 -1
5 6 4 -1
输出样例 1

7 8 0 7 -1
输入样例 2

1 -1
2 -1
输出样例 2

3 -1
输入样例 3

9 -1
1 0 -1
输出样例 3

1 9 -1
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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //这个函数需要你补充完整

}

int main() {
    ListNode* head1,*head2;
    head1 = createList();
    head2 = createList();
    ListNode* ans = addTwoNumbers(head1, head2);
    if (ans == NULL)
        cout << "-1";
    else {
        while (ans != NULL) {
            cout << ans->val << " ";
            ans = ans->next;
        }
        cout<<-1;
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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    //这个函数需要你补充完整
    if(l1)
//    {
        if(l2)
        {
//            ListNode *head_l1=l1,*head_l2=l2,*p_l1=l1,*q_l1=p_l1->next,*p_l2=l2,*q_l2=p_l2->next;
            ListNode *head_l1=l1,*head_l2=l2,*p_l1=l1,*q_l1=p_l1->next,*p_l2=l2,*q_l2=p_l2->next,*tmp=NULL;
            while(q_l1)
            {
//                ListNode *tmp=q_l1->next;
                tmp=q_l1->next;
                if(p_l1==l1)
                    p_l1->next=NULL;
                q_l1->next=p_l1,p_l1=q_l1,q_l1=tmp;
            }
            head_l1=p_l1,q_l1=p_l1;
            while(q_l2)
            {
//                ListNode *tmp=q_l2->next;
                tmp=q_l2->next;
                if(p_l2==l2)
                    p_l2->next=NULL;
                q_l2->next=p_l2,p_l2=q_l2,q_l2=tmp;
            }
            head_l2=p_l2,q_l2=p_l2;
            ListNode *head_res=NULL,*p_res=head_res,*q_res=NULL;
//            int a=0;
            short carrying=0;
//            while((p_l1->val!=-1)&&(p_l2->val!=-1))
            while(p_l1&&p_l2)
            {
//                q_res=new ListNode;
//                q_res->val=((a+(p_l1->val)+(p_l2->val))%10),q_res->next=NULL;
                q_res=new ListNode,q_res->val=((carrying+(p_l1->val)+(p_l2->val))%10),q_res->next=NULL;
//                a=((a+(p_l1->val)+(p_l2->val))/10);
                carrying=(short)((carrying+(p_l1->val)+(p_l2->val))/10);
                if(head_res)
                    p_res->next=q_res,p_res=q_res;
                else
                    head_res=p_res=q_res;
                p_l1=p_l1->next,p_l2=p_l2->next;
            }
//            while(p_l1->val!=-1)
            while(p_l1)
            {
//                q_res=new ListNode;
//                q_res->val=((a+p_l1->val)%10),q_res->next=NULL;
                q_res=new ListNode,q_res->val=((carrying+p_l1->val)%10),q_res->next=NULL;
//                a=((a+(p_l1->val))/10);
                carrying=(short)((carrying+(p_l1->val))/10);
//                if(head_res)
                p_res->next=q_res,p_res=q_res;
//                else
//                    head_res=p_res=q_res;
                p_l1=p_l1->next;
            }
//            while(p_l2->val!=-1)
            while(p_l2)
            {
//                q_res=new ListNode;
//                q_res->val=((a+p_l2->val)%10),q_res->next=NULL;
                q_res=new ListNode,q_res->val=((carrying+p_l2->val)%10),q_res->next=NULL;
//                a=((a+(p_l2->val))/10);
                carrying=(short)((carrying+(p_l2->val))/10);
//                if(head_res)
                p_res->next=q_res,p_res=q_res;
                //                else
//                    head_res=p_res=q_res;
                p_l2=p_l2->next;
            }
            if(carrying)
            {
//                q_res=new ListNode;
//                q_res->val=a,q_res->next=NULL;
                q_res=new ListNode,q_res->val=carrying,q_res->next=NULL;
//                if(head_res)
                p_res->next=q_res,p_res=q_res;
//                else
//                    head_res=p_res=q_res;
            }
//            p_res=q_res=head_res;
            p_res=head_res,q_res=p_res->next;
            p_l1=head_l1,p_l2=head_l2;
            while(q_l1)
            {
                tmp=q_l1->next;
                if(p_l1==head_l1)
                    p_l1->next=NULL;
                q_l1->next=p_l1,p_l1=q_l1,q_l1=tmp;
            }
            while(q_l2)
            {
                tmp=q_l2->next;
                if(p_l2==head_l2)
                    p_l2->next=NULL;
                q_l2->next=p_l2,p_l2=q_l2,q_l2=tmp;
            }
            while(q_res)
            {
//                ListNode *tmp=q_res->next;
                tmp=q_res->next;
                if(p_res==head_res)
                    p_res->next=NULL;
                q_res->next=p_res,p_res=q_res,q_res=tmp;
            }
            return p_res;
        }
        else
            return l1;
//    }
    else
        return l2;
}

int main()
{
    ListNode* head1,*head2;
    head1 = createList();
    head2 = createList();
    ListNode* ans = addTwoNumbers(head1, head2);
    if (ans == NULL)
        cout << "-1";
    else
    {
        while (ans != NULL)
        {
            cout << ans->val << " ";
            ans = ans->next;
        }
        cout<<-1;
    }
    return 0;
}

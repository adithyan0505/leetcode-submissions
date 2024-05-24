/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* createNode(void)
{
    struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
    new->val = 0;
    new->next = NULL;
    return new;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int sum;
    if(l2!=NULL)
    {
        sum = l1->val + l2->val;
        l1->val = sum%10;
    }
    else
    {
        sum = l1->val;
        l1->val = sum%10;
    }

    if((l1->next != NULL)&&(l2 != NULL)&&(l2->next != NULL))
    {
        (l1->next)->val += sum/10;
        addTwoNumbers(l1->next,l2->next);
    }
    else if(l1->next != NULL)
    {
        (l1->next)->val += sum/10;
        addTwoNumbers(l1->next,NULL);
    }
    else if((l2 != NULL)&&(l2->next != NULL))
    {
        l1->next = createNode();
        (l1->next)->val += sum/10;
        addTwoNumbers(l1->next,l2->next);
    }
    else
    {
        if(sum/10 != 0)
        {
            l1->next = createNode();
            (l1->next)->val += sum/10;
        }
    }
    return l1;
}
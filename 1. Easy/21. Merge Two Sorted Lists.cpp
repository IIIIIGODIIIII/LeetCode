class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp=list2,*head=list2;
        if(list1 == NULL && list2 == NULL)
            return NULL;
        
        if(list1 == NULL && list2 != NULL)
            return list2;
        if(list2 == NULL && list1 != NULL)
            return list1;
      
        while(temp->next!=NULL)
        {
            if(list1->next == NULL)
            {
                temp = temp->next;
                temp->next = list1;
                temp = temp->next; 
                temp->next = list2;
                temp = temp->next;
                break;
            } 
           
            if((list2->val) <= (list1->val))
            {
                temp = list2;
                list2 = list2->next; 
                temp->next = list1; 
                list1 = list1->next;
            } 
            
            else 
            {
                temp = list1; 
                list1 = list1->next; 
                temp->next = list2; 
                list2 = list2->next;
            }
        }
        
        return head;
    }
};
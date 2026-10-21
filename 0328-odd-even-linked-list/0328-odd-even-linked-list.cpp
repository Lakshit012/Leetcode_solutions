class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        vector<int > arr;
        ListNode *temp=head;
        if (head==NULL || head->next==NULL) return head;
        while (temp!=NULL && temp ->next !=NULL){
            arr.push_back(temp->val);
            temp=temp->next->next;
        }
        if (temp){
            arr.push_back(temp->val);
        }
        temp=head->next;
        while (temp!=NULL &&temp->next !=NULL){
            arr.push_back(temp->val);
            temp=temp->next->next;
        }
        if (temp){
            arr.push_back(temp->val);
        }
        int i=0;
        temp=head;
        while (temp!=NULL){
            temp->val=arr[i];
            i++;
            temp=temp->next;
        }
            return head;
    }
};
 


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* d= new ListNode(0);
        ListNode* tmp=d;
        
        while(left && right){
            if(left->val < right->val){
                tmp->next=left;
                left=left->next;
            }
            else{
                tmp->next=right;
                right=right->next;
            }
            tmp=tmp->next;
        }
        tmp->next=left? left: right;
        return d->next;
    }
    ListNode* divide(vector<ListNode *> & lists, int l, int r){
        if(l==r)    return lists[l];
        if(l+1==r)  return merge(lists[l],lists[r]);
        int mid=l+(r-l)/2;
        ListNode * left=divide(lists,l,mid);
        ListNode * right=divide(lists,mid+1,r);
        return merge(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return divide(lists,0,lists.size()-1);
    }
};
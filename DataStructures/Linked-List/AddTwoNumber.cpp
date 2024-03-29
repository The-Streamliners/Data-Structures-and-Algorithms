#include<bit/stdcpp.h>

using namespace std;

class Solution {
public:
    void insert_node(ListNode *&root,int n){
        if(root==NULL){
            root=new ListNode(n);
            return;
        }
        ListNode *temp=root;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new ListNode(n);
        return;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res=NULL;
        int carry=0;
        while(l1!=NULL and l2!=NULL){
            int temp=l1->val+l2->val+carry;
            insert_node(res,temp%10);
            carry=temp/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            int temp=l1->val+carry;
            insert_node(res,temp%10);
            carry=temp/10;
            l1=l1->next;
        }
        while(l2!=NULL){
            int temp=l2->val+carry;
            insert_node(res,temp%10);
            carry=temp/10;
            l2=l2->next;
        }
        if(carry!=0){
            insert_node(res,carry);
        }
        return res;
    }
}; 

int main(){

    ListNode* l1 , *l2 ;
    int n;
    cout<<"Enter value of n"<<endl;
    cin>>n;
    cout<<"Enter root elements"<<endl;
    cin>>l1>>l2;
    Solution ss = new Solution();
    ss.addTwoNumbers(l1,l2);
    return 0;
}
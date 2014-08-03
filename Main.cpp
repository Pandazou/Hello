#include <iostream>
#include <vector>

using namespace std;

 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
ListNode *removeNthFromEnd(ListNode *head, int n) {
	ListNode *pre = head;
	if(pre == NULL)
		return pre;
	ListNode *p = pre->next;
	n--;
	while(n > 0){
		p = p ->next;
		--n;
	}
	if(p == NULL){
		p = head;
		head = head->next;
		delete p;
		return head;
	}
	else{
		while(p->next){
			p = p->next;
			pre = pre->next;
		}
		p = pre->next;
		pre->next = p->next;
		delete p;
		return head;
	}
	
}

void display(ListNode *p){
	while(p){
		cout<<p->val<<" ";
		p = p->next;
	}
	cout<<endl;
}

int main(){
	ListNode *head = new ListNode(0);
	ListNode *tail = head;
	for(int i =1; i < 10; i++){
		ListNode *p = new ListNode(i);
		tail->next = p;
		tail = tail->next;
	}
	display(head);
	head = removeNthFromEnd(head,10);
	display(head);
}
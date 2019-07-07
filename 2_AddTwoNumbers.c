// Author: cdsss
// This is the code for LeetCode <2. AddTwoNumbers https://leetcode.com/problems/add-two-numbers/>
//
// Description
// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order and each of their nodes contain a single digit. 
// Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Example: 
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
//
// Explanation: 342 + 465 = 807.

#include<iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* h1 = l1;
	ListNode* h2 = l2;
	ListNode* l3 = new ListNode(0);
	ListNode* h3 = l3;
	int c = 0;
	while (h1 != NULL && h2 != NULL) {
		int v1 = h1->val;
		int v2 = h2->val;
		h3->next = new ListNode((v1 + v2 + c) % 10);
		c = (v1 + v2 + c) / 10;
		h1 = h1->next;
		h2 = h2->next;
		h3 = h3->next;
	}
	if (h1 != NULL) {
		while (h1 != NULL) {
			int v1 = h1->val;
			h3->next = new ListNode((v1 + c) % 10);
			c = (v1 + c) / 10;
			h1 = h1->next;
			h3 = h3->next;
		}
	}
	if (h2 != NULL) {
		while (h2 != NULL) {
			int v2 = h2->val;
			h3->next = new ListNode((v2 + c) % 10);
			c = (v2 + c) / 10;
			h2 = h2->next;
			h3 = h3->next;
		}
	}
	if (c == 1) {
		h3->next = new ListNode(1);
		h3 = h3->next;
	}
	return l3->next;
}

ListNode* Init_ListNode(int a[], int n) {
	ListNode* l = new ListNode(0);
	ListNode* h = l;
	for (int i = 0; i < 3; ++i) {
		h->next = new ListNode(a[i]);
		h = h->next;
	}
	return l->next;
}

bool equal(ListNode* l1, ListNode* l2) {
	ListNode* h1 = l1;
	ListNode* h2 = l2;
	while (h1 != NULL && h2 != NULL) {
		if (h1->val != h2->val)
			return false;
		h1 = h1->next;
		h2 = h2->next;
	}
	if (h1 != NULL || h2 != NULL) {
		return false;
	}
	return true;
}

int main() {
	int a1[] = {2, 4, 3};
	int a2[] = { 5, 6, 4 };
	int res[] = { 7, 0, 8 };
	ListNode* l1 = Init_ListNode(a1, 3);
	ListNode* l2 = Init_ListNode(a2, 3);
	ListNode* l3 = addTwoNumbers(l1, l2);
	if (equal(Init_ListNode(res, 3), l3)) {
		cout<< "TRUE" <<endl;
	}
	else {
		cout << "FALSE" << endl;
	}
	return 0;
}

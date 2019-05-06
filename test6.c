//删除一个排序的链表中重复的节点，返回链表头指针
ListNode* deleteDuplication(ListNode* pHead)
{
	ListNode* fake = (ListNode*)malloc(sizeof(ListNode));
	fake->next = pHead;
	ListNode* p1 = pHead;
	ListNode* p2 = NULL;
	ListNode* pPre = fake;
	if (pHead == NULL)
		return NULL;
	p2 = pHead->next;
	while (p2 != NULL) {
		if (p1->val != p2->val) {
			pPre = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else {
			while (p2 != NULL&&p2->val == p1->val) {
				p2 = p2->next;
			}
			ListNode* cur = p1;
			while (cur != p2) {
				ListNode* next = cur->next;
				free(cur);
				cur = next;
			}
			pPre->next = p2;
			p1 = p2;
			if (p2 != NULL)
				p2 = p2->next;
		}
	}
	pHead = fake->next;
	free(fake);
	return pHead;
}
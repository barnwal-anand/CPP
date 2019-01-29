Node* FlattenLinkedList(Node *head)
{
	Node dummy;
Node *pCrawler = &dummy;

dummy.next = head;

Node *pNext = head->next;
Node *pDown = head->down;

pCrawler = pCrawler->next;
while(pNext && pDown)
{
	if (pNext->data <= pDown->data)
	{
		pCrawler->next = pNext;
		pNext = pNext->next;
	}
	else
	{
		pCrawler->next = pDown;
		pDown = pDown->next;
	}

	pCrawler = pCrawler->next;
}

if (pNext)
{
	pCrawler->next = pNext;
}

if (pDown)
{
	pCrawler->next = pDown;
}

return dummy.next;
}

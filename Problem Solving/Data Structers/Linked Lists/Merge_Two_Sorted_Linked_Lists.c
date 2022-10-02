SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
    SinglyLinkedListNode* tmp;
    SinglyLinkedListNode* lst;
    if (head1->data <= head2->data)
    {
        tmp = head1;
        head1 = head1->next;
    }
    else
    {
        tmp = head2;
        head2 = head2->next;
    }
    lst = tmp;
    printf("%d, \n",lst->data);
    while(head1 || head2)
    {
        if (head1 && head2 && head1->data <= head2->data)
        {
            tmp ->next = head1;
            head1 = head1->next;
            tmp = tmp ->next;
        }
        else if (head1 && head2 && head1->data > head2->data)
        {
            tmp ->next = head2;
            head2 = head2->next;
            tmp = tmp ->next;
        }
        else if (head1)
        {
            tmp ->next = head1;
            break;
        }
        else
        {
            tmp ->next = head2;
            break;
        }
    }
    return lst;
}

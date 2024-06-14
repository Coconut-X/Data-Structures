node* mergeList(node* list1, node* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    // Find the last node of the first list
    node* tail1 = list1;
    while (tail1->next != list1) {
        tail1 = tail1->next;
    }

    // Find the last node of the second list
    node* tail2 = list2;
    while (tail2->next != list2) {
        tail2 = tail2->next;
    }

    // Connect the last node of the first list to the head of the second list
    tail1->next = list2;

    // Connect the last node of the second list to the head of the first list
    tail2->next = list1;

    return list1;
}

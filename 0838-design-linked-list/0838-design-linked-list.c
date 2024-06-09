

typedef struct LL {
    int val;
    struct LL* next;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    node->next = NULL; // creates a dummy head node before actual head
    node->val = -1;
    return node;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    obj = obj->next; // skipping dummy node before head
    while (obj) {
        if (index-- == 0)
            return obj->val;
        obj = obj->next;
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* temp = myLinkedListCreate();
    temp->val = val;
    temp->next = obj->next;
    obj->next = temp;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* temp = myLinkedListCreate();
    while (obj->next)
        obj = obj->next;
    obj->next = temp;
    temp->val = val;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    while ((index-- > 0) && obj)
        obj = obj->next;
    if (obj) {
        MyLinkedList* temp = myLinkedListCreate();
        temp->val = val;
        temp->next = obj->next;
        obj->next = temp;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    while ((index-- > 0) && obj)
        obj = obj->next;
    if (obj && obj->next) {
        MyLinkedList* temp = obj->next;
        obj->next = temp->next;
        free(temp);
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    while (obj) {
        MyLinkedList* temp = obj;
        obj = obj->next;
        free(temp);
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/
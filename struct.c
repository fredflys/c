#include "utils.h"
#include <stdlib.h>

/**
 * struct exmaple: single linked list
 */
typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

ListNode* CreateNode(int val) {
    ListNode* node = malloc(sizeof(ListNode));
    if (!node) exit(1);

    node->value = val;
    node->next = NULL;
    return node;
}

/**
 * @param nodeptr: pointer that points to the pointer of the node to be destroyed
 * @note: not only do we have to destroy the node itself, but also the pointer that points to the node. that's why we need the pointer to the pointer
 */
void DestroyNode(ListNode** nodeptr) {
    // isiolate
    (*nodeptr)->next = NULL;
    // destroy: passing in the value of nodeptr, which is the address of the node
    free(*nodeptr);
    // avoid dangling pointer
    *nodeptr = NULL;
}

ListNode* CreateList(int array[], int size) {
    if (size <= 0) return;

    ListNode* head = CreateNode(array[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = CreateNode(array[i]);
        current = current->next;
    }

    return head;
}

void DestroyList(ListNode** head) {
    // head itself and the node pointer it points to should not be NULL
    if (!head || !(*head)) return;

    ListNode* current = *head;
    while (current) {
        // current is still needed for the next run
        ListNode* alias = current;
        current = current->next;
        DestroyNode(&alias);
    }
    // avoid dangling pointer since we have a copy of head
    *head = NULL;
}

void PrintList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        PRINTINT(current->value);
        current = current->next;
    }
}

void InsertNode(ListNode** head, int insertion_index, int val) {
    // stop if there is an empty pointer to a pointer or there is a invalid index given
    if (!head || insertion_index < 0) return;
    ListNode* new_node = CreateNode(val);

    // insert at the start
    if (insertion_index == 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    
    // insert not at the start
    // create one if even the head does not exist
    if (!(*head)) {
        *head = CreateNode(val);
    }
    // now move to the insertion point 
    ListNode* current = *head;
    while (insertion_index > 1) {
        if (!current->next) {
            current->next = CreateNode(0);
        }
        current = current->next;
        insertion_index--;    
    }
    // insert at current position, link from behind
    // current --> new_node --> next 
   new_node->next = current->next;
   current->next = new_node; 
}


int main() {
    /**
     * struct
     */
    struct {char* name; int age;} anonymous_struct;

    struct Employee {char* id; char* name; int age;};

    // designated initializer: . is member access operator
    struct Employee empl = {.id = "123", .name = "Fred"};
    PRINTINT(empl.age);

    // pointer to struct
    struct Employee *empl_ptr = &empl;
    // access struct member through pointer
    PRINTINT(empl_ptr->age);

    // typedef to alias struct
    PRINTINT(sizeof(struct Employee));
    typedef struct Employee Employee;
    PRINTINT(sizeof(Employee));

    // nested struct
    typedef struct Manager {
        char* position;
        Employee worker;
        struct {
            char* name;
            int age;
        } info;
    } Manager;

    // structure padding and memory alignment
    // purpose: no overlapping means that member can be accessed in a single memory fetch
    typedef struct {
        char a;
        short b;
        int c;
        double d;
    } optimized_aligned_struct;

    // customized alignment
    typedef struct {
        char a;
        short b;
        // gcc feature
        __attribute((aligned(2))) int c;
        // C11
        _Alignas(8) double d;
    } customized_aligned_struct;

    Manager manager = {.position = "Team Leader", .worker = {.name = "Bob"}};


    /**
     * struct example: single linked list
     */
    int arr[] = {1, 2, 3, 4, 5};
    ListNode* head = CreateList(arr, 5);
    PrintList(head);
    PRINTLN("Before Insertion");
    InsertNode(&head, 3, 100);
    InsertNode(&head, 0, -100);
    InsertNode(&head, 7, 700);
    PrintList(head);
    PRINTLN("After Deletion");
    DestroyList(&head);
    PRINTHEX(head);

}


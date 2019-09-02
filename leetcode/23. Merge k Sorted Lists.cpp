/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */




struct ListNode* create(){
    struct ListNode * T = (struct ListNode *)malloc(sizeof(struct ListNode));
    T->next = NULL;
    return T;
}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * root = NULL, *p = NULL;
    while(l1 && l2) {
        if (root == NULL) {
            root = create();
            p = root;
            if (l1->val < l2->val) {
                root->val = l1->val;
                l1 = l1->next;
            } else {
                root->val = l2->val;
                l2 = l2->next;
            }
        } else {
            struct ListNode * node = create();
            if (l1->val < l2->val) {
                node->val = l1->val;
                l1 = l1->next;
            } else {
                node->val = l2->val;
                l2 = l2->next;
            }
            p->next = node;
            p = p->next;
        }
    }
    while(l1) {
        if (root == NULL) {
            root = create();
            p = root;
            root->val = l1->val;
        } else {
            struct ListNode * node = create();
            node->val = l1->val;
            p->next = node;
            p = p->next;
        }
        l1 = l1->next;
    }
    while(l2) {
        if (root == NULL) {
            root = create();
            p = root;
            root->val = l2->val;
        } else {
            struct ListNode * node = create();
            node->val = l2->val;
            p->next = node;
            p = p->next;
        }
        l2 = l2->next;
    }
    return root;
}


/**
   两两合并，测试用例130超时
 */


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (listsSize == 1) return lists[0];
    struct ListNode * head = NULL; 
    for(int i = 0; i < listsSize - 1; i++) {
        if (head == NULL) head = mergeTwoLists(lists[i], lists[i+1]);
        else head = mergeTwoLists(lists[i+1], head);
    }
    return head;
}

/**
   归并优化
 */

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (listsSize == 1) return lists[0];
    if (listsSize == 0) return NULL;
    int interval = 1;
    while(interval < listsSize) {
        for (int i = 0 ; i < listsSize - interval; i = i + interval * 2) {
            lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
        }    
        interval *= 2;
    }
    
    return lists[0];
}

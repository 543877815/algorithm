#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode, *TreeNodePtr;

typedef struct ListNode {
    struct TreeNode *node; // 值的类型是树
    struct ListNode *next;
} ListNode, *ListNodePtr;

typedef struct Queue {
    ListNodePtr dummyHead;
    ListNodePtr tail;
    int size;
} Queue, *QueuePtr;

// 创建链表的节点
ListNodePtr createListNode(TreeNodePtr node, ListNodePtr next) {
    ListNodePtr curr = (ListNodePtr) (malloc(sizeof(ListNode)));
    curr->node = node;
    curr->next = next;
    return curr;
}

// 创建树的节点
TreeNodePtr createTreeNode(int val, TreeNodePtr left, TreeNodePtr right) {
    TreeNodePtr curr = (TreeNodePtr) (malloc(sizeof(TreeNode)));
    curr->val = val;
    curr->left = left;
    curr->right = right;
    return curr;
}

// 单链表队列初始化
void init(QueuePtr queue) {
    TreeNodePtr dummyTreeNode = createTreeNode(-1, NULL, NULL);
    queue->size = 0;
    queue->dummyHead = createListNode(dummyTreeNode, NULL);
    queue->tail = queue->dummyHead;
}

// 在 queue 的尾部添加一个元素的副本
void push(QueuePtr queue, TreeNodePtr node) {
    ListNodePtr curr = createListNode(node, NULL);
    queue->tail->next = curr;
    queue->tail = queue->tail->next;
    queue->size++;
}

// 删除 queue 中的第一个元素
void pop(QueuePtr queue) {
    if (queue->size == 0) return;
    ListNodePtr head = queue->dummyHead->next;
    queue->dummyHead->next = head->next;
    queue->size--;
    if (queue->size == 0) queue->tail = queue->dummyHead;
    free(head);
}

// 如果 queue 中没有元素, 返回 true
bool empty(QueuePtr queue) {
    return queue->size == 0;
}

// 返回 queue 中第一个元素的引用
TreeNodePtr front(QueuePtr queue) {
    if (empty(queue)) {
        perror("error! the size of queue is zero.");
        return NULL;
    } else {
        return queue->dummyHead->next->node;
    }
}

// 返回 queue 中最后一个元素的引用
TreeNodePtr back(QueuePtr queue) {
    if (empty(queue)) {
        perror("error! the size of queue is zero.");
        return NULL;
    } else {
        return queue->tail->node;
    }
}

// 将输入转换为数组
void getDigits(char *buff, int *data) {
    int len = strlen(buff);
    int index = 0;
    for (int i = 0; i < len; i++) {
        int num = 0;
        while(buff[i]!=' ' && buff[i] != '\0') {
            num = num * 10 + (buff[i++] - '0');
        }
        data[index++] = num;
    }
}

/** TODO:  任务一：请你通过队列来实现层次遍历构建二叉树，并返回二叉树的头结点 */
TreeNodePtr createBiTree(int *data) {
    return NULL;
}

/** TODO: 任务二：请你通过深度优先遍历和回溯来求取该二叉树的最大路径和 */
int maxPathSum(TreeNodePtr root) {
    return 0;
}

/** ToDO: 任务三：请你通过递归求取该二叉树的所有左子叶权重之和 */
int sumOfLeftLeaves(TreeNodePtr root) {
    return 0;
}

/** TODO: 任务四：请你通过递归求取该树的镜像，即翻转该二叉树 */
TreeNodePtr invertTree(TreeNodePtr root) {
    return NULL;
}


int main() {
    // ===============================================================
    // ||                      test for Queue                       ||
    // ===============================================================
    QueuePtr queue = (QueuePtr) malloc(sizeof(Queue));
    TreeNodePtr node3 = createTreeNode(3, NULL, NULL);
    TreeNodePtr node2 = createTreeNode(2, NULL, NULL);
    TreeNodePtr node1 = createTreeNode(1, node2, node3);

    node1->left = node2;
    node1->right = node3;
    init(queue);
    push(queue, node1);
    push(queue, node2);
    push(queue, node3);

    pop(queue);

    printf("%d back: %d front: %d\n", empty(queue), back(queue)->val, front(queue)->val);
    pop(queue);
    pop(queue);
    pop(queue);

    // ===============================================================
    // ||                      end test                             ||
    // ===============================================================

    int SIZE = 128;
    int MAX_NUM = 10;
    char buff[SIZE];
    char num[MAX_NUM];
    FILE *fp = fopen("../test.txt", "r");
    if (!fp) {
        perror("打开文件时发生错误");
        return -1;
    } else {
        int i = 0;
        while (fgets(num, MAX_NUM, fp) && fgets(buff, SIZE, fp)) {
            printf("data %d: %s, nodes number: %s", i, buff, num);
            int data[atoi(num)];
            getDigits(buff, data);
            int a = 1;
            /** 任务一 */

            /** 任务二 */

            /** 任务三 */

            /** 任务四 */


            i++;
        }
    }

    fclose(fp);

}
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
    struct TreeNode *node; // 链表（栈）值的类型是树
    struct ListNode *next;
} ListNode, *ListNodePtr;

typedef struct Queue {
    ListNodePtr dummyHead;
    ListNodePtr tail;
    int size;
} *QueuePtr;

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
QueuePtr Queue() {
    QueuePtr queue = (QueuePtr) malloc(sizeof(struct Queue));
    TreeNodePtr dummyTreeNode = createTreeNode(-1, NULL, NULL);
    queue->size = 0;
    queue->dummyHead = createListNode(dummyTreeNode, NULL);
    queue->tail = queue->dummyHead;
    return queue;
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
    if (queue->size == 0) {
        perror("error! the size of queue is zero when call pop().");
        return;
    }
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
        perror("error! the size of queue is zero when call front().");
        return NULL;
    } else {
        return queue->dummyHead->next->node;
    }
}

// 返回 queue 中最后一个元素的引用
TreeNodePtr back(QueuePtr queue) {
    if (empty(queue)) {
        perror("error! the size of queue is zero when call back().");
        return NULL;
    } else {
        return queue->tail->node;
    }
}

int max(int a, int b) {
    return (a >= b) ? a : b;
}

// 将输入转换为数组
void getDigits(char *buff, int *data) {
    int len = strlen(buff);
    int index = 0;
    for (int i = 0; i < len; i++) {
        int num = 0;
        while (buff[i] != ' ' && buff[i] != '\0') {
            num = num * 10 + (buff[i++] - '0');
        }
        data[index++] = num;
    }
}

/**
 * 函数说明：
 *
 *
 *
 *
 */


/** TODO:  任务一：请你通过队列来实现层次遍历构建二叉树，并返回二叉树的头结点 */
/**
 * ================================================
 * ||            Solution 1, 使用栈               ||
 * ================================================
 */
//TreeNodePtr createTreeWithLevelOrder(int *data, int size) {
//    TreeNodePtr root = createTreeNode(data[0], NULL, NULL);
//    int index = 1;
//    QueuePtr queue = Queue();
//    push(queue, root);
//    while (!empty(queue)) {
//        TreeNodePtr curr = front(queue);
//        pop(queue);
//        if (index < size) {
//            while (data[index] == -1) index++;
//            curr->left = createTreeNode(data[index++], NULL, NULL);
//            push(queue, curr->left);
//        } else break;
//        if (index < size) {
//            while (data[index] == -1) index++;
//            curr->right = createTreeNode(data[index++], NULL, NULL);
//            push(queue, curr->right);
//        } else break;
//    }
//    return root;
//}

/**
 * ================================================
 * ||            Solution 2, 使用索引             ||
 * ================================================
 */
TreeNodePtr createTreeWithLevelOrder(int *data, int size) {
    TreeNodePtr nodes[size];
    for (int i = 0; i < size; i++) {
        while (data[i] == -1) i++;
        nodes[i] = createTreeNode(data[i], NULL, NULL);
        if (i != 0) {
            if ((i - 1) % 2 == 0) nodes[(i - 1) / 2]->left = nodes[i];
            else nodes[(i - 1) / 2]->right = nodes[i];
        }
    }
    return nodes[0];
}

/** TODO: 任务二：请你通过深度优先遍历来求取该二叉树的最大路径和 */
/**
 * ================================================
 * ||                 Solution 1                 ||
 * ================================================
 */
int maxPathSum(TreeNodePtr root, int sum) {
    if (!root) return sum;
    return max(maxPathSum(root->left, sum + root->val), maxPathSum(root->right, sum + root->val));
}

/** ToDO: 任务三：请你通过递归求取该二叉树的所有左子叶权重之和 */
/**
 * ================================================
 * ||        Solution 1,  深度优先搜索             ||
 * ================================================
 */
//int dfs(TreeNode *root, bool isLeft) {
//    if (!root) return 0;
//    if (!root->left && !root->right && isLeft) return root->val;
//    return dfs(root->left, true) + dfs(root->right, false);
//}
//
//int sumOfLeftLeaves(TreeNodePtr root) {
//    if (!root) return 0;
//    return dfs(root->left, true) + dfs(root->right, false);
//}

/**
 * ================================================
 * ||          Solution 2,  深度优先搜索           ||
 * ================================================
 */

//bool isLeafNode(struct TreeNode *node) {
//    return !node->left && !node->right;
//}
//
//int dfs(struct TreeNode *node) {
//    int ans = 0;
//    if (node->left) {
//        ans += isLeafNode(node->left) ? node->left->val : dfs(node->left);
//    }
//    if (node->right && !isLeafNode(node->right)) {
//        ans += dfs(node->right);
//    }
//    return ans;
//}
//
//int sumOfLeftLeaves(struct TreeNode *root) {
//    return root ? dfs(root) : 0;
//}

/**
 * ================================================
 * ||          Solution 3,  广度优先搜索           ||
 * ================================================
 */
bool isLeafNode(struct TreeNode *node) {
    return !node->left && !node->right;
}

int sumOfLeftLeaves(TreeNodePtr root) {
    if (!root) return 0;
    QueuePtr queue = Queue();
    push(queue, root);
    int ret = 0;
    while (!empty(queue)) {
        TreeNodePtr curr = front(queue);
        pop(queue);
        if (curr->left) {
            if (isLeafNode(curr->left)) ret += curr->left->val;
            else push(queue, curr->left);
        }
        if (curr->right) {
            if (!isLeafNode(curr->right)) push(queue, curr->right);
        }
    }
    return ret;
}


/**
 * ================================================
 * ||          Solution 4,  广度优先搜索           ||
 * ================================================
 */
//bool isLeafNode(struct TreeNode *node) {
//    return !node->left && !node->right;
//}
//
//int sumOfLeftLeaves(struct TreeNode *root) {
//    if (!root) return 0;
//
//    struct TreeNode **q = malloc(sizeof(struct TreeNode *) * 2001);
//    int left = 0, right = 0;
//    q[right++] = root;
//    int ans = 0;
//    while (left < right) {
//        struct TreeNode *node = q[left++];
//        if (node->left) {
//            if (isLeafNode(node->left)) {
//                ans += node->left->val;
//            } else {
//                q[right++] = node->left;
//            }
//        }
//        if (node->right) {
//            if (!isLeafNode(node->right)) {
//                q[right++] = node->right;
//            }
//        }
//    }
//    return ans;
//}


/** TODO: 任务四：请你通过递归求取该树的镜像，即翻转该二叉树 */
TreeNodePtr invertTree(TreeNodePtr root) {
    /**
     * ================================================
     * ||               Solution 1, 递归              ||
     * ================================================
     */
    if (!root) return NULL;
    if (!root->left && !root->right) return root;
    TreeNodePtr tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    if (root->left) invertTree(root->left);
    if (root->right) invertTree(root->right);

    return root;
}


int main() {
    /**
     * ===============================================================
     * ||                      Test for Queue                       ||
     * ===============================================================
     */
    QueuePtr queue = Queue();
    TreeNodePtr node3 = createTreeNode(3, NULL, NULL);
    TreeNodePtr node2 = createTreeNode(2, NULL, NULL);
    TreeNodePtr node1 = createTreeNode(1, node2, node3);

    node1->left = node2;
    node1->right = node3;

    push(queue, node1);
    push(queue, node2);
    push(queue, node3);

    pop(queue);

    printf("%d back: %d front: %d\n", empty(queue), back(queue)->val, front(queue)->val);
    pop(queue);
    pop(queue);
    pop(queue);
    /**
     * ===============================================================
     * ||                      End test                             ||
     * ===============================================================
     */

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
        /**
         * ===============================================================
         * ||                   Read data here                          ||
         * ===============================================================
         */
        while (fgets(num, MAX_NUM, fp) && fgets(buff, SIZE, fp)) {
            printf("Case %d, data: %s, nodes number: %s", i, buff, num);

            int size = atoi(num);
            int data[size];
            getDigits(buff, data);

            /** 任务一 */
            TreeNodePtr root = createTreeWithLevelOrder(data, size);

            /** 任务二 */
            int max_path_sum = maxPathSum(root, 0);
            printf("Answer for task 2 is : %d \n", max_path_sum);

            /** 任务三 */
            int weight_sum = sumOfLeftLeaves(root);
            printf("Answer for task 3 is : %d \n", weight_sum);

            /** 任务四 */
            TreeNodePtr invert_tree = invertTree(root);

            i++;
        }

        /**
         * ===============================================================
         * ||                       End read                            ||
         * ===============================================================
         */
    }

    fclose(fp);

}
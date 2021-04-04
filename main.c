#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct TreeNode {
    int id;
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
int TreeId = 0;

TreeNodePtr createTreeNode(int val, TreeNodePtr left, TreeNodePtr right) {
    TreeNodePtr curr = (TreeNodePtr) (malloc(sizeof(TreeNode)));
    curr->id = TreeId++;
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
        if (buff[i] == '#') {
            num = -1;
            i++;
        } else {
            while (buff[i] != ' ' && buff[i] != '\0') {
                num = num * 10 + (buff[i++] - '0');
            }
        }
        data[index++] = num;
    }
}

// 创建 dot 可视化文件
void createDotFile(const char *filename, TreeNodePtr root, int MaxSize) {
    FILE *fp = fopen(filename, "w");    // 文件指针
    if (fp == NULL) {   // 为NULL则返回
        printf("File cannot open!");
        exit(0);
    }
    fprintf(fp, "digraph G {\n");   // 开头
    // 利用层次遍历构造
    QueuePtr queue = Queue();
    push(queue, root);
    int id = 1;
    TreeNodePtr record[MaxSize];
    while (!empty(queue)) { // 若队列不空，继续遍历。否则，遍历结束
        TreeNodePtr curr = front(queue);
        pop(queue);
        fprintf(fp, "%d [shape=circle, label=\"%d\"];\n", curr->id, curr->val);
        record[id] = curr;
        if (curr->left != NULL) { // 如果有左孩子，左孩子入队
            push(queue, curr->left);
            fprintf(fp, "%d->%d;\n", curr->id, curr->left->id);
        } else if (id < MaxSize) { // 否则，创建虚拟节点
            fprintf(fp, "_%d [shape=circle, label=\"#\", style=invis];\n", id);
            fprintf(fp, "%d->_%d [style=invis];\n", curr->id, id);
        }
        id++;

        if (curr->right != NULL) { // 如果有右孩子，右孩子入队
            push(queue, curr->right);
            fprintf(fp, "%d->%d;\n", curr->id, curr->right->id);
        } else if (id < MaxSize) { // 否则，创建虚拟节点
            fprintf(fp, "_%d [shape=circle, label=\"#\", style=invis];\n", id);
            fprintf(fp, "%d->_%d [style=invis];\n", curr->id, id);
        }
        id++;
    }
    fprintf(fp, "}\n"); // 结尾
    fclose(fp); // 关闭IO
}

// 绘制二叉树图片
void plot(TreeNodePtr tree_root, int i, int size, char *name) {
    char tree_filename[50], paint_tree[100];
    sprintf(tree_filename, "./%s_%d.dot", name, i);
    createDotFile(tree_filename, tree_root, size);
    sprintf(paint_tree, "dot -Tpng %s -o ./%s_%d.png", tree_filename, name, i);
    // puts(paint_tree);
    system(paint_tree);
}

/** TODO:  任务一：请你通过队列来实现层次遍历构建二叉树，并返回二叉树的头结点 */
/**
 * ================================================
 * ||            Solution 1, 使用栈               ||
 * ================================================
 */
TreeNodePtr createTreeWithLevelOrder(int *data, int size) {
    TreeNodePtr root = createTreeNode(data[0], NULL, NULL);
    int index = 1;
    QueuePtr queue = Queue();
    push(queue, root);
    while (!empty(queue) && index < size) {
        TreeNodePtr curr = front(queue);
        pop(queue);
        TreeNodePtr new = createTreeNode(data[index], NULL, NULL);
        if (index < size && curr->val != -1) {
            if (data[index] != -1)
                curr->left = new;
        }
        push(queue, new);
        index++;
        new = createTreeNode(data[index], NULL, NULL);
        if (index < size && curr->val != -1) {
            if (data[index] != -1)
                curr->right = new;
        }
        push(queue, new);
        index++;
    }
    return root;
}

/**
 * ================================================
 * ||            Solution 2, 使用索引             ||
 * ================================================
 */
//TreeNodePtr createTreeWithLevelOrder(int *data, int size) {
//    TreeNodePtr nodes[size];
//    for (int i = 0; i < size; i++) {
//        while (data[i] == -1) i++;
//        nodes[i] = createTreeNode(data[i], NULL, NULL);
//        if (i != 0) {
//            if ((i - 1) % 2 == 0) nodes[(i - 1) / 2]->left = nodes[i];
//            else nodes[(i - 1) / 2]->right = nodes[i];
//        }
//    }
//    return nodes[0];
//}

/** TODO: 任务一：请你输出该二叉树的前序遍历、中序遍历、后序遍历的序列 */
/**
 * ================================================
 * ||                  前序遍历                   ||
 * ================================================
 */
void preOrderTraverse(TreeNodePtr root) {
    if (!root) return;
    printf("%d ", root->val);
    if (root->left) preOrderTraverse(root->left);
    if (root->right) preOrderTraverse(root->right);
}

/**
 * ================================================
 * ||                  中序遍历                   ||
 * ================================================
 */
void inOrderTraverse(TreeNodePtr root) {
    if (!root) return;
    if (root->left) inOrderTraverse(root->left);
    printf("%d ", root->val);
    if (root->right) inOrderTraverse(root->right);
}

/**
 * ================================================
 * ||                  后序遍历                   ||
 * ================================================
 */
void postOrderTraverse(TreeNodePtr root) {
    if (!root) return;
    if (root->left) postOrderTraverse(root->left);
    if (root->right) postOrderTraverse(root->right);
    printf("%d ", root->val);
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
int dfs(TreeNode *root, bool isLeft) {
    if (!root) return 0;
    if (!root->left && !root->right && isLeft) return root->val;
    return dfs(root->left, true) + dfs(root->right, false);
}

int sumOfLeftLeaves(TreeNodePtr root) {
    if (!root) return 0;
    return dfs(root->left, true) + dfs(root->right, false);
}

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

//int sumOfLeftLeaves(TreeNodePtr root) {
//    if (!root) return 0;
//    QueuePtr queue = Queue();
//    push(queue, root);
//    int ret = 0;
//    while (!empty(queue)) {
//        TreeNodePtr curr = front(queue);
//        pop(queue);
//        if (curr->left) {
//            if (isLeafNode(curr->left)) ret += curr->left->val;
//            else push(queue, curr->left);
//        }
//        if (curr->right) {
//            if (!isLeafNode(curr->right)) push(queue, curr->right);
//        }
//    }
//    return ret;
//}


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
/**
 * ================================================
 * ||               Solution 1, 递归              ||
 * ================================================
 */
TreeNodePtr invertTree(TreeNodePtr root) {
    if (!root) return NULL;
    if (!root->left && !root->right) return root;
    TreeNodePtr tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    if (root->left) invertTree(root->left);
    if (root->right) invertTree(root->right);
    // invertTree(root->left);
    // invertTree(root->right);
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

    push(queue, node1);
    // printf("%d back: %d front: %d\n", empty(queue), back(queue)->val, front(queue)->val);
    push(queue, node2);
    // printf("%d back: %d front: %d\n", empty(queue), back(queue)->val, front(queue)->val);
    push(queue, node3);
    // printf("%d back: %d front: %d\n", empty(queue), back(queue)->val, front(queue)->val);
    pop(queue);
    // printf("%d back: %d front: %d\n", empty(queue), back(queue)->val, front(queue)->val);
    pop(queue);
    // printf("%d back: %d front: %d\n", empty(queue), back(queue)->val, front(queue)->val);
    pop(queue);
    /**
     * ===============================================================
     * ||                      End test                             ||
     * ===============================================================
     */


    /**
     * ===============================================================
     * ||                       Configuration                        ||
     * ===============================================================
     */
    int SIZE = 128;
    int MAX_NUM = 10;
    char buff[SIZE];
    char num[MAX_NUM];
    bool use_graphviz = true;
    /**
     * ===============================================================
     * ||                   End Configuration                       ||
     * ===============================================================
     */

    // printf("Read data...\n");
    FILE *fp = fopen("../test.txt", "r");
    if (!fp) {
        perror("打开文件时发生错误");
        return -1;
    } else {
        int i = 0;
        // printf("success!\n");
        /**
         * ===============================================================
         * ||                   Read data here                          ||
         * ===============================================================
         */
        while (fgets(num, MAX_NUM, fp) && fgets(buff, SIZE, fp)) {
            char *nextline = strchr(buff, '\n');          //查找换行符
            if (nextline)                            //如果find不为空指针
                *nextline = '\0';
            printf("Case %d, data: %s, nodes number: %s", i, buff, num);
            int size = atoi(num);
            int data[size];
            getDigits(buff, data);
            /**
             * ===============================================================
             * ||       你的任务在这里，当然你也可以以任意方式修改函数的原型          ||
             * ===============================================================
             */

            /** 任务一 */
            TreeNodePtr tree_root = createTreeWithLevelOrder(data, size);
            printf("Answer for task 1 is: \n");
            printf("preOrderTraverse is:");
            preOrderTraverse(tree_root);
            printf("\n");
            printf("inOrderTraverse is:");
            inOrderTraverse(tree_root);
            printf("\n");
            printf("postOrderTraverse is:");
            postOrderTraverse(tree_root);
            printf("\n");
            /** 通过 graphviz 可视化 */
            if (use_graphviz) {
                plot(tree_root, i, size, "tree");
            }

            /** 任务二 */
            int max_path_sum = maxPathSum(tree_root, 0);
            printf("Answer for task 2 is : %d \n", max_path_sum);

            /** 任务三 */
            int weight_sum = sumOfLeftLeaves(tree_root);
            printf("Answer for task 3 is : %d \n", weight_sum);

            /** 任务四 */
            TreeNodePtr invert_tree_root = invertTree(tree_root);
            printf("inOrderTraverse for task 4 is:");
            inOrderTraverse(invert_tree_root);
            printf("\n\n");
            /** 通过 graphviz 可视化 */
            if (use_graphviz) {
                plot(invert_tree_root, i, size, "invert_tree");
            }

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

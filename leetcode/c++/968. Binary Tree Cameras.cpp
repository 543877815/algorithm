/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//状态 a：root 必须放置摄像头的情况下，覆盖整棵树需要的摄像头数目。
//状态 b：覆盖整棵树需要的摄像头数目，无论 root 是否放置摄像头。
//状态 c：覆盖两棵子树需要的摄像头数目，无论节点 root 本身是否被监控到。

// 时间复杂度：O(n)
// 空间复杂度：O(n)

struct States {
    int a, b, c;
};

class Solution {
public:
    States DFS(TreeNode *root) {
        if (!root) return {INT_MAX / 2, 0, 0};

        auto[la, lb, lc] = DFS(root->left);
        auto[ra, rb, rc] = DFS(root->right);

        int a = lc + rc + 1;
        int b = min(a, min(la + rb, ra + lb));
        int c = min(a, lb + rb);
        return {a, b, c};
    }

    int minCameraCover(TreeNode *root) {
        auto[a, b, c] = DFS(root);
        return b;
    }
};


// 方法2
class Solution {
public:
    // 0: 待覆盖
    // 1: 已覆盖
    // 2: 已安装相机
    int res = 0;
    int minCameraCover(TreeNode* root) {
        // 如果root仍为未覆盖，则给root加相机
        if (DFS(root) == 0) res++;
        return res;
    }

    int DFS(TreeNode *root) {
        if (!root) return 1;
        int left = DFS(root->left);
        int right = DFS(root->right);

        // 下面的节点没有把left或者right覆盖，只能靠root
        if (left == 0 || right == 0) {
            res ++;
            return 2;
        }

            // left和right都已经被覆盖了，但是没有安装相机，所以root是待覆盖的
        else if(left == 1 && right == 1) {
            return 0;
        }

            // left和right至少有一个安装相机
        else if(left + right >= 3) {
            return 1;
        }

        return -1;
    }
};
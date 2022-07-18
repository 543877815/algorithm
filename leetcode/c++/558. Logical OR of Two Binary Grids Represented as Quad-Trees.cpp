/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

// 递归合并
// 时间复杂度：O(n^2)
// 空间复杂度：O(nlogn)
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (!quadTree1 || !quadTree2) return NULL;
        Node* quadTree = new Node(false, false, NULL, NULL, NULL, NULL);

        quadTree->val = quadTree1->val || quadTree2->val;
        quadTree->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        quadTree->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        quadTree->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        quadTree->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        if (quadTree->topLeft && quadTree->topRight && quadTree->bottomLeft && quadTree->bottomRight) {
            quadTree->isLeaf = false;
        } else {
            quadTree->isLeaf = true;
        }
        return quadTree;
    }
};
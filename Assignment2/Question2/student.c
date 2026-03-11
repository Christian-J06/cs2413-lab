/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int checkAVL(struct TreeNode *node, long min, long max) {
    if (node == NULL) return 0;
    // enforce strict BST property
    if (node->val <= min || node->val >= max) {
        return -1;
    }
    int lh = checkAVL(node->left, min, node->val);
    if (lh == -1) return -1;
    int rh = checkAVL(node->right, node->val, max);
    if (rh == -1) return -1;
    if (lh - rh > 1 || rh - lh > 1) {
        return -1;
    }
    return 1 + (lh > rh ? lh : rh);
}

bool isAVL(struct TreeNode* root) {
    return checkAVL(root, LONG_MIN, LONG_MAX) != -1;
}

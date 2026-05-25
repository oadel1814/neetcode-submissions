/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
    /*
        first I have root and subroot pointing to the two roots and present a state so 
        when root.Val == subRoot.Val ---> move the two pointers simultanuosely 
        else move try moving the root to left and right and so on
    */

    if subRoot == nil {
        return true
    }

    if root == nil {
        return false
    }

    if sameTree(root, subRoot) {
        return true
    }

    return isSubtree(root.Left, subRoot) || isSubtree(root.Right, subRoot)
}



func sameTree(root *TreeNode, subRoot *TreeNode) bool {
    if root == nil && subRoot == nil {
        return true
    }

    if root != nil && subRoot != nil && root.Val == subRoot.Val {
        return sameTree(root.Left, subRoot.Left) && sameTree(root.Right, subRoot.Right)
    }

    return false
}

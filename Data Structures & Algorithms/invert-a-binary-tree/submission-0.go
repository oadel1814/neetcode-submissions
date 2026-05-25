/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func invertTree(root *TreeNode) *TreeNode {
    if root == nil {
        return nil
    }

    var newRoot TreeNode
    newRoot.Val = root.Val

    if root.Left != nil {
        newRoot.Right = invertTree(root.Left)
    }


    if root.Right != nil {
        newRoot.Left = invertTree(root.Right)
    }


    return &newRoot
}

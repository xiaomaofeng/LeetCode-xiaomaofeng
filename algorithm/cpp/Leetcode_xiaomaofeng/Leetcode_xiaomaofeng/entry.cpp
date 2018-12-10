// Leetcode_xiaomaofeng.cpp: 定义控制台应用程序的入口点。
//
//108  Convert Sorted Array to Binary Search Tree
#include "stdafx.h"
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x)
		:val(x), left(NULL), right(NULL)
	{

	}
};


TreeNode* sortedArrayToBST(vector<int>&nums)
{
	/*for (int i = 0; i < nums.size(); i++)
	{
		TreeNode
	}*/
	if (nums.size() == 0)
		return NULL;
	if (nums.size() == 1)
		return new TreeNode(nums[0]);
	int mid = nums.size() / 2;
	TreeNode* node = new TreeNode(nums[mid]);
	vector<int>::iterator first;
	vector<int>::iterator last;
	first = nums.begin();
	last = nums.begin() + mid;
	vector<int>v(first, last);
	node->left = sortedArrayToBST(v);
	if (mid == nums.size() - 1) {
		node->right = NULL;
	}
	else
	{
		first = nums.begin() + mid + 1;
		last = nums.end();
		vector<int>v(first, last);
		node->right = sortedArrayToBST(v);
	}
	return node;

	//root->val= nums[0];

}

bool isSameTree(TreeNode* p, TreeNode* q)
{
	if (!p && !q)
		return true;
	if (p == nullptr || q == nullptr)
		return false;
	queue<TreeNode*>q1,q2;
	q1.push(p);
	q2.push(q);
	while (q1.size() > 0 && q2.size() > 0)
	{
		TreeNode* p1 = q1.front();
		q1.pop();
		TreeNode* p2 = q2.front();
		q2.pop();
		if (!p1 && !p2)
			continue;
		if (!p1 || !p2)
			return false;
		if (p1->val != p2->val)
			return false;
		q1.push(p1->left);
		q2.push(p2->left);
		q1.push(p1->right);
		q2.push(p2->right);
	}

	return true;
}


int main()
{
	
    return 0;
}


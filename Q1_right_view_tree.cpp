#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void printRight(TreeNode *curr, int level, int &maxLevel)
{
    if (!curr)
        return;

    if (level > maxLevel)
    {
        maxLevel = level;
        cout << curr->val << " ";
    }

    printRight(curr->right, level + 1, maxLevel);
    printRight(curr->left, level + 1, maxLevel);
}

void preOrder(TreeNode *curr)
{
    if (!curr)
        return;

    cout << curr->val << " ";
    preOrder(curr->left);
    preOrder(curr->right);
}

TreeNode *makeTree()
{
    queue<TreeNode *> q;
    int x;
    cin >> x;
    TreeNode *root = new TreeNode(x);

    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        int left;
        cin >> left;
        int right;
        cin >> right;

        if (left != -1)
        {
            TreeNode *lf = new TreeNode(left);
            curr->left = lf;
            q.push(lf);
        }

        if (right != -1)
        {
            TreeNode *rg = new TreeNode(right);
            curr->right = rg;
            q.push(rg);
        }
    }
    return root;
}

void solve()
{
    TreeNode *root = makeTree();

    // preOrder(root);
    // cout << endl;

    int maxLevel = -1;
    printRight(root, 0, maxLevel);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

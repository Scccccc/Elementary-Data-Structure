#define _CRT_SECURE_NO_WARNINGS 1


//二叉树的前序遍历OJ
int TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

void preorder(struct TreeNode* root, int* a, int* pi)
{
    if (root == NULL)
        return;

    a[(*pi)++] = root->val;
    preorder(root->left, a, pi);
    preorder(root->right, a, pi);


}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = TreeSize(root);
    int* a = (int*)malloc(*returnSize * sizeof(int));
    if (a == NULL)
    {
        perror("malloc fail");
        return NULL;
    }
    int i = 0;
    preorder(root, a, &i);
    return a;
}

//另一棵树的子树
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
        return true;

    if (p == NULL || q == NULL)
        return false;

    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (root == NULL)
        return false;

    if (isSameTree(root, subRoot))
        return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

//二叉树的构建以及遍历
struct TreeNode
{
    struct TreeNode* left;
    struct TreeNode* right;
    int val;
};

struct TreeNode* CreateTree(char* a, int* pi)
{
    if (a[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = a[(*pi)++];
    root->left = CreateTree(a, pi);
    root->right = CreateTree(a, pi);

    return root;
}

void Inorder(struct TreeNode* root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    printf("%c ", root->val);
    Inorder(root->right);

}

int main()
{
    char a[100];
    scanf("%s", a);
    int i = 0;
    struct TreeNode* root = CreateTree(a, &i);
    Inorder(root);

    return 0;
}


//翻转二叉树

struct TreeNode* invertTree(struct TreeNode* root)
{
    if (root == NULL)
        return NULL;

    struct TreeNode* lret = invertTree(root->left);
    struct TreeNode* rret = invertTree(root->right);

    root->left = rret;
    root->right = lret;

    return root;

}

//对称二叉树
bool cheakNode(struct TreeNode* left, struct TreeNode* right)
{
    if (left == NULL && right == NULL)
        return true;
    if (left == NULL || right == NULL)
        return false;
    if (left->val != right->val)
        return false;

    return cheakNode(left->left, right->right) && cheakNode(left->right, right->left);
}
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;
    return cheakNode(root->left, root->right);
}
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
void insert(int x)
{
    struct node *p, *temp = createNode(x);
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        p = root;
        while (p != NULL)
        {
            if (x < p->data && p->left == NULL)
            {
                p->left = temp;
                return;
            }
            else if (x >= p->data && p->right == NULL)
            {
                p->right = temp;
                return;
            }
            if (x < p->data)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
    }
}
struct node inOrderSuccessor(struct node root)
{
    root = root->right;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
struct node *deleteNode(struct node *root, int value)
{
    struct node *iSuc;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL && root->data == value)
    {
        free(root);
        return NULL;
    }
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    // deletion
    else
    {
        iSuc = inOrderSuccessor(root);
        root->data = iSuc->data;
        root->right = deleteNode(root->right, iSuc->data);
    }
    return root;
}
int main()
{
    int op, el;
    do
    {
        printf("1.Insert\n2.Delete\n3.Postorder\n4.Preorder\n5.Inorder\n6.Exit\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter the element to insert : ");
            scanf("%d", &el);
            insert(el);
            break;
        case 2:
            printf("Enter the element to delete : ");
            scanf("%d", &el);
            deleteNode(root, el);
            break;
        case 3:
            postOrder(root);
            printf("\n");
            break;
        case 4:
            preOrder(root);
            printf("\n");
            break;
        case 5:
            inOrder(root);
            printf("\n");
            break;
        case 6:
            break;
        default:
            printf("Invalid option\n");
        }
    } while (op != 6);
    return 0;
}
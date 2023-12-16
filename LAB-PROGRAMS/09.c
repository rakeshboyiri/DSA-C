//9.write a program to implement the binary search tree with operations

#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *left, *right;
};

void Inorder(struct node *);
void Preorder(struct node *);
void Postorder(struct node *);

//create a new BST node
struct node* newNode(int item)
{
	struct node* new= (struct node*)malloc(sizeof(struct node));
	new->data = item;
	new->left = new->right = NULL;
	return new;
}

// insert

struct node* insert(struct node* node, int data)
{
	// If the tree is empty, return a new node
	if (node == NULL)
		return newNode(data);

	if (data < node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);

	return node;
}
//Delete

int getRightMin(struct node *root)
{
    struct node *temp = root;

    //min value should be present in the left most node.
    while(temp->left != NULL){ temp = temp->left;}

    return temp->data;
}

struct node *removeNode(struct node *root, int val)
{
    /*
     * If the node becomes NULL, it will return NULL
     * Two possible ways which can trigger this case
     * 1. If we send the empty tree. i.e root == NULL
     * 2. If the given node is not present in the tree.
     */
    if(root == NULL)
        return NULL;
    /*
     * If root->data < val. val must be present in the right subtree
     * So, call the above remove function with root->right
     */
    if(root->data < val)
        root->right = removeNode(root->right,val);
    /*
     * if root->data > val. val must be present in the left subtree
     * So, call the above function with root->left
     */
    else if(root->data > val)
        root->left = removeNode(root->left,val);
    /*
     * This part will be executed only if the root->data == val
     * The actual removal starts from here
     */
    else
    {
        /*
         * Case 1: Leaf node. Both left and right reference is NULL
         * replace the node with NULL by returning NULL to the calling pointer.
         * free the node
         */
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        /*
         * Case 2: Node has right child.
         * replace the root node with root->right and free the right node
         */
        else if(root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        /*
         * Case 3: Node has left child.
         * replace the node with root->left and free the left node
         */
        else if(root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        /*
         * Case 4: Node has both left and right children.
         * Find the min value in the right subtree
         * replace node value with min.
         * And again call the remove function to delete the node which has the min value.
         * Since we find the min value from the right subtree call the remove function with root->right.
         */
        else
        {
            int rightMin = getRightMin(root->right);
            root->data = rightMin;
            root->right = removeNode(root->right,rightMin);
        }

    }

    //return the actual root's address
    return root;
}


//search
struct node* search(struct node* root, int data)
{
	// Base Cases: root is null or data is present at root
	if (root == NULL || root->data == data)
		return root;

	// data is greater than root's data
	if (root->data < data)
		return search(root->right, data);

	// data is smaller than root's data
	return search(root->left, data);
}

void Inorder(struct node *root)
{
    if( root != NULL)
    {
        Inorder(root->left);
        printf(" %d ",root->data);
        Inorder(root->right);
    }
}

void Preorder(struct node *root)
{
    if( root != NULL)
    {
        printf(" %d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct node *root)
{
    if( root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf(" %d ",root->data);
    }
}

int main()
{
    printf("\nImplementation of Binary Search Tree\n");
	struct node* root = NULL;
	root = insert(root, 50);
	root=insert(root, 30);
	root=insert(root, 20);
	root=insert(root, 40);
	root=insert(root, 70);
	root=insert(root, 60);
	root=insert(root, 80);

    printf("Binary Search tree is Created Successfully\n");
    Inorder(root);

    int ch,data;
	// data to be found
    while(1)
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Search\n");
        printf("4.Inorder\n");
        printf("5.Postoreder\n");
        printf("6.Preorder\n");
        printf("Enter the choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter the data : ");
                    scanf("%d",&data);
                    root=insert(root,data);
                    break;
            case 2:printf("Enter Element to Delete : ");
                    scanf("%d",&data);
                    root=removeNode(root,data);
                    break;
            case 3:printf("Enter Element to Search : ");
                    scanf("%d",&data);
                    if(search(root,data)==NULL)
                    {
                        printf("%d is found \n",data);
                    }
                    else
                    {
                        printf("%d is not found\n",data);
                    }
                    break;
            case 4:Inorder(root); break;
            case 5:Postorder(root); break;
            case 6: Preorder(root); break;
            default:printf("\nInvalid\n");
        }
        printf("\n");
    }
	printf("\nProgram Successfully Completed\n\n");

	
	return 0;
}

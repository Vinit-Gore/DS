#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define max(a,b) (a> b? a: b)
struct node
{
int data;
int height;
int level;
struct node * left;
struct node * right;
};
struct node * makenode(int data)
{
struct node * head = malloc(sizeof(struct node));
head -> left = NULL;
head -> right = NULL;
head -> data = data;
head -> height = 0;
head -> level = 0;
return head;
}
void inorder(struct node * tree)
{
}
void inorderwithheight(struct node * tree)
{
if(!tree) return;
inorderwithheight(tree -> left);
printf("%d:%d ", tree -> data, tree -> height);
inorderwithheight(tree -> right);
}
void inorderwithlevel(struct node * tree)
{
if(!tree) return;
inorderwithlevel(tree -> left);
printf("%d:%d ", tree -> data, tree -> level);
inorderwithlevel(tree -> right);
}
void preorder(struct node * tree)
{
}
void postorder(struct node * tree)
{
}
int height(struct node * tree)//fills the height attribute of each node in tree
{
}
void level(struct node * tree, int lev)//fills the level attribute of each node in tree
{
}
void insert(struct node * tree, int elem)
{
struct node * parent;
char left = 0;
while(tree)
{
if(elem < tree -> data)
{
parent = tree;
tree = tree -> left;
left = 1;

}
else if(elem > tree -> data)
{
parent = tree;
tree = tree -> right;
left = 0;
}
else
{
printf("Duplicates not allowed!"); return;
}

}
if(left == 1) parent -> left = makenode(elem);
else
parent -> right = makenode(elem);

}
void printdot(struct node* node, FILE * f)
{
if(node == NULL)
return;
if(node-> left != NULL)
{
fprintf(f, "%d -- %d;\n", node->data, node->left->data);
}
if(node-> right != NULL)
{
fprintf(f, "%d -- %d;\n", node->data, node->right->data);
}
printdot(node->left, f);
printdot(node->right, f);
}

int main()
{
struct node * tree = NULL;
int n, val;
printf("Enter the  no. of numbers: ");
scanf("%d", &n);
for(int i = 0; i < n; i++)
{
scanf("%d", &val);
if(tree == NULL)
{
tree = makenode(val);
}
else
insert(tree, val);
}
inorder(tree);
printf("\n");
height(tree);
level(tree, 0);
inorderwithheight(tree);
printf("\n");
inorderwithlevel(tree);
printf("\n");
preorder(tree);
printf("\n");
postorder(tree);

FILE * f = fopen("tree.dot", "w");
fprintf(f, "graph tree { \n");
printdot(tree, f);
fprintf(f, "}\n");
fclose(f);

#if defined(__linux__) || (defined(__APPLE__) && defined(__MACH__) || (defined (__gnu_linux__)) )
system("dot -Tpng tree.dot -o output.png; eog output.png");
#endif
}
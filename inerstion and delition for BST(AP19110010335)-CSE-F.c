#include <stdio.h>
#include <stdlib.h>
struct tNode {
        int a;
        struct tNode *l,*r;
  };
struct tNode *root = NULL;
struct tNode* createNode(int a) 
{
        struct tNode *newNode;
        newNode = (struct tNode *) malloc(sizeof (struct tNode));
        newNode->a= a;
        newNode->l= NULL;
        newNode->r= NULL;
        return(newNode);
}
void insertion(struct tNode **node, int a) {
        if (*node==NULL) 
        {
           *node = createNode(a);
        } else if (a<(*node)->a) 
        {
                insertion(&(*node)->l,a);
        } else if (a>(*node)->a) 
        {
                insertion(&(*node)->r,a);
        }
  }
void deletion(struct tNode **node, struct tNode **parent, int data) 
{
       struct tNode *tmpNode, *tmpParent;
        if (*node == NULL)
                return;
        if ((*node)->a==a) 
        {
            if (!(*node)->l && !(*node)->r) 
            {
                        if (parent) 
                        {
                                
                                if ((*parent)->l == *node)
                                        (*parent)->l = NULL;
                                else
                                        (*parent)->r = NULL;
                                free(*node);
                        } else 
                        {
                               
                            free(*node);
                        }
                
            } else if (!(*node)->r && (*node)->l) {
                        tmpNode = *node;
                        (*parent)->r = (*node)->l;
                        free(tmpNode);
                        *node = (*parent)->r;
                } else if ((*node)->r && !(*node)->l) {
                        tmpNode = *node;
                        (*parent)->l = (*node)->r;
                        free(tmpNode);
                        (*node) = (*parent)->l;
                } else if (!(*node)->r->l) {
                        tmpNode = *node;
                        (*node)->r->l = (*node)->l;
                        (*parent)->l = (*node)->r;
                        free(tmpNode);
                        *node = (*parent)->l;
                } else {
                        tmpNode = (*node)->r;
                        while (tmpNode->l) {
                                tmpParent = tmpNode;
                                tmpNode = tmpNode->l;
                        }
                        tmpParent->l = tmpNode->r;
                        tmpNode->l = (*node)->l;
                        tmpNode->r =(*node)->r;
                        free(*node);
                        *node = tmpNode;
                }
        } else if (a<(*node)->a) {
                deletion(&(*node)->l, node,a);
        } else if (a>(*node)->a) {
               deletion(&(*node)->r,node,a);
        }
}
void traverse(struct tNode *node) {
        if (node != NULL) {
                traverse(node->l);
                printf("%3d", node->a);
                traverse(node->r);
        }
        return;
  }

  int main() {
        int data, ch;
        while (1) {
                printf("Insertion in Binary Search Tree");
                printf("Deletion in Binary Search Tree");
                printf("3. Inorder traversal\n4. Exit\n");
                printf("Enter your choice");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                while (1) {
                                printf("Enter your data:");
                                scanf("%d", &a);
                                insertion(&root, a);
                                printf("Continue Insertion");
                                scanf("%d", &ch);
                                if (!ch)
                                        break;
                                }
                                break;
                        case 2:
                                printf("Enter your data:");
                                scanf("%d", &a);
                                deletion(&root, NULL, a);
                                break;
                        case 3:
                                printf("Inorder Traversal");
                                traverse(root);
                                printf("\n");
                                break;
                        case 4:
                                exit(0);
                        default:
                                printf("  you enter wrong one");
                                break;
                }
        }
        return 0;

  }

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

struct node* insert( struct node* root, int data ) {
		
	if(root == NULL) {
	
        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
	  
	} else {
      
		struct node* cur;
		
		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}
	
		return root;
	}
}

/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/
typedef struct s_node{
    struct node *add;
    struct s_node *next;
} t_node;

t_node *addback(t_node *node, struct node * address)
{
    if (!address)
        return node;
    t_node * l_new;
    l_new = malloc(sizeof(t_node));
    l_new->next = NULL;
    l_new->add = address;
    if (!node)
        return (l_new);
    t_node *tmp = node;
    while (tmp -> next)
        tmp = tmp -> next;
    tmp -> next = l_new;
    return (node);
}

void levelOrder( struct node *root)
{
    t_node *que;
    que = addback(que, root);
    while (que)
    {
        printf("%d ",(que->add)->data);
        que = addback(que, (que->add)->left);
        que = addback(que, (que->add)->right);
        que = que ->next;
    }
}


int main() {
  
    struct node* root = NULL;
    
    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
  
	levelOrder(root);
    return 0;
}

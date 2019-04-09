#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This is a collection of binary tree helper functions
 * to :
 *      traverse the tree
 *      delete the tree nodes
 */

struct _b_tree {
    struct _b_tree *left;
    struct _b_tree *right;
    struct _b_tree *parent;
    int value;
    int x;
    int y;
};
typedef struct _b_tree BTree;

BTree* new_b_tree ( )
{
    return calloc(1, sizeof(BTree));
}

BTree* search_b_tree_xy( BTree *node , int x, int y)
{
    if (node == NULL) { return NULL; }
    /* value found */
    if ( (node-> x == x) && (node->y == y) )
    {
        return node;
    }
    /* a leaf node */
    if ( (node->right == NULL) && (node->left == NULL))
    {
        return NULL;
    }
    /* a branch node */
    else
    {
        BTree* right = NULL;
        BTree* left = NULL;
        if ( node->y < y) right = search_b_tree_xy( node->right , x, y);
        if ( node->x < x) left = search_b_tree_xy( node->left  , x, y);
        if (right) { return right; }
        else if (left) { return left; }
        else return NULL;
    }
}

void create_b_tree ( BTree *node, int row_max, int** intMatrix)
{
    node->value = intMatrix[node->x][node->y];
    /* if we're still within bounds we'll expand the tree */
    if ( ( node->x < row_max ) &&
         ( node->y < row_max ) &&
         ( node != NULL ) ) // aka the max column
    {
        /* we'll build the left nodes first... but only if we're on
         * the left edge as we'll connect the neighboring nodes in
         * another round once we've built the tree
         */
        if ( node->y == 0 )
        {
            node->left = calloc(1, sizeof(BTree));
            node->left->parent = node;
            node->left->x = node->x+1;
            node->left->y = node->y;
            create_b_tree( node->left, row_max, intMatrix);
        }
        /* then the right */
        node->right = calloc(1, sizeof(BTree));
        node->right->parent = node;
        node->right->x = node->x+1;
        node->right->y = node->y+1;
        create_b_tree( node->right , row_max, intMatrix);
    }
    else return;
}

void connect_right_hand_nodes( BTree* node, BTree* root)
{
    /* a leaf node */
    if ( (node->right == NULL) && (node->left == NULL) )
    { }
    /* both have children -> continue in both directions */
    else if ( node->left && node->right )
    {
        connect_right_hand_nodes( node->left , root);
        connect_right_hand_nodes( node->right , root);
    }
    /* only right has child ( add left and cont. right ) */
    else if ( (node->left == NULL) && node->right )
    {
        // we'll try to connect the left node
        node->left = node->parent->left->right;
        connect_right_hand_nodes( node->right , root);
    }
    return;
}

void find_max_path(BTree* node, int acc, int* max)
{
    /* add the node's value to the accumulator */
    acc += node->value;
    /* stop at leaf nodes */
    if ( (node->right == NULL) && (node->left == NULL) )
    {
        if (acc > *max) { *max = acc; }
    }
    else
    {
        find_max_path(node->right, acc, max);
        find_max_path(node->left, acc, max);
    }
    return;
}

/*
 * prints the nodes of the tree...
 */
void print_tree( BTree* node )
{
    if ( node)
    {
        printf("node <%d, %d> : %d @ %p\n", node->x, node->y,
                node->value, node);
        //printf("    parent: %p\n", node->parent);
        if (node->left)
        {
            printf("    left : <%d, %d> @ %p\n", node->left->x,
                    node->left->y, node->left);
        }// else { printf("    is leaf\n"); }
        if (node->right)
        {
        printf("    right: <%d, %d> @ %p\n", node->right->x,
                node->right->y, node->right);
        }// else { printf("    is leaf\n"); }
        if ( node->left ) { print_tree(node->left ); }
        if ( node->right) { print_tree(node->right); }
    }
}

int main(int argc, const char * argv[]) {

    FILE* file = fopen(argv[1], "r");
    char line[1024];
    // NOTE: this would definitely have to change if I didn't know my
    //       set size already...
    int row_max = 100;
    int** intMatrix = calloc(row_max, sizeof(int*));

    /* parsing */
    int line_no = 0;
    while (fgets(line, 1024, file)) {
        /* NOTE: *MAJOR* assumption that each line has the same
         *       number of elements as the line number...
         */
        line_no++;
        /* create an array[int] which holds the int(s) on that line */
        char* token = strdup(line);
        int* intRow = calloc(line_no, sizeof(int));
        int idx = 0;
        while ( ((token = strtok(token, " ")) != NULL) &&
                (idx < line_no) )
        {
            sscanf(token, "%d", (intRow + idx) );
            token = NULL;
            idx++;
        }
        /* add the read in row to the rows array */
        intMatrix[line_no - 1] = intRow;
    }
    row_max = line_no - 1; // get the true number of lines

    /* tree building */
    BTree* root = new_b_tree();
    root->value = intMatrix[0][0];
    create_b_tree(root,row_max,intMatrix);
    connect_right_hand_nodes(root, root);

    /* search for largest path */
    int max = 0;
    find_max_path(root, 0, &max);
    printf("%d\n", max);

    return 0;
}

/*
 * This is a collection of binary tree helper functions
 * to :
 *      traverse the tree
 *      delete the tree nodes
 */

struct _b_tree {
    size_t *left;
    size_t *right;
    size_t *object;
}
typedef struct _b_tree BTree;

// TODO: This might leave the *object allocated
//       if it was allocated on the heap;
void delete_b_tree ( _b_tree* node )
{
    if ( node )
    {
        delete_b_tree ( node->left );
        delete_b_tree ( node->right );
        free( node );
    }
}

_b_tree* new_b_tree_with_obj ( size_t *object )
{
    _b_tree* tmp = calloc(1, sizeof(_b_tree));
    tmp->object = object;
    return tmp;
}

_b_tree* new_b_tree ( )
{
    return calloc(1, sizeof(_b_tree));
}

/* a traverse stub */
void traverse_b_tree ( _b_tree *node , size_t *invariant )
{
    /* a leaf node */
    if ( (node->right == NULL) && (node->left == NULL))
    {
        // do what ever we need to do
    }
    /* a branch node */
    else
    {
        traverse_b_tree ( node->right , size_t *invariant);
        traverse_b_tree ( node->left  , size_t *invariant);
    }
}

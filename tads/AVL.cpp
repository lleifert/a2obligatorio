#ifndef AVL_TREE
#define AVL_TREE

// based on: https://www.geeksforgeeks.org/avl-tree-set-1-insertion/

template <class T>
class AVL
{
private:
    class AVLNode
    {
    public:
        T element;
        AVLNode *left;
        AVLNode *right;
        int height;
        AVLNode(T element) : element(element), left(NULL), right(NULL), height(1) {}
    };

    AVLNode *root; // root of the tree
    
    // forma de comparar para ordenar el arbol
    int (*comparacion)(T, T);

    // A utility function to get the height of the tree.
    // In case of an empty tree, it returns 0.
    int height(AVLNode *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return node->height;
    }

    // A utility function to right
    // rotate subtree rooted with y
    AVLNode *rightRotate(AVLNode *y)
    {
        AVLNode *x = y->left;
        AVLNode *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = std::max(height(y->left),
                             height(y->right)) +
                    1;
        x->height = std::max(height(x->left),
                             height(x->right)) +
                    1;

        // Return new root
        return x;
    }

    // A utility function to left
    // rotate subtree rooted with x
    AVLNode *leftRotate(AVLNode *x)
    {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = std::max(height(x->left),
                             height(x->right)) +
                    1;
        y->height = std::max(height(y->left),
                             height(y->right)) +
                    1;

        // Return new root
        return y;
    }

    // Get Balance factor of node N
    int getBalance(AVLNode *node)
    {
        if (node == NULL)
            return 0;
        return height(node->right) - height(node->left);
    }

    // Recursive function to insert a element
    // in the subtree rooted with node and
    // returns the new root of the subtree.
    AVLNode *insert(AVLNode *node, T element)
    {
        /* 1. Perform the normal BST insertion */
        if (node == NULL)
            return new AVLNode(element);
        //if (element < node->element)
        if ( comparacion(element, node->element) < 0 )
            node->left = insert(node->left, element);
        //else if (element > node->element)
        else if ( comparacion(element, node->element) > 0 )
            node->right = insert(node->right, element);
        else // Equal elements are not allowed in BST
            return node;

        /* 2. Update height of this ancestor AVLnode */
        node->height = 1 + std::max(height(node->left),
                                    height(node->right));

        /* 3. Get the balance factor of this ancestor
            node to check whether this node became
            unbalanced */
        int balance = getBalance(node);

        // If this node becomes unbalanced, then
        // there are 4 cases

        // Left Left Case
        //if (balance < -1 && element < node->left->element)
        if (balance < -1 && comparacion(element, node->left->element) < 0)
            return rightRotate(node);

        // Right Right Case
        //if (balance > 1 && element > node->right->element)
        if (balance > 1 && comparacion(element, node->right->element) > 0)
            return leftRotate(node);

        // Left Right Case
        //if (balance < -1 && element > node->left->element)
        if (balance < -1 && comparacion(element, node->left->element) > 0)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        //if (balance > 1 && element < node->right->element)
        if (balance > 1 && comparacion(element, node->right->element) < 0)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        /* return the (unchanged) node pointer */
        return node;
    }
    void inOrder(AVLNode *node, void (*each)(T))
    {
        if (node == NULL)
        {
            return;
        }
        inOrder(node->left, each);
        each(node->element);
        inOrder(node->right, each);
    }

    void imprimirInOrder(AVLNode *root)
    {
        if (root == NULL) return;
        imprimirInOrder(root->left);
        cout << root->element;
        imprimirInOrder(root->right);
    }

    bool contains(AVLNode *node, T element)
    {
        if(node == NULL) {
            return false;
        }
        //if(node->element == element) {
        if(comparacion(node->element, element) == 0) {  // si el id del libro A menos el id del libro B me dan cero entonces el libro existe
            return true;
        }
        //else if(node->element > element) {
        else if(comparacion(node->element, element) > 0) {
            return contains(node->left, element);
        }
        else {
            return contains(node->right, element);
        }
    }

    T get(AVLNode *node, T element)
    {
        if(comparacion(node->element, element) == 0 ) {
            return node->element;
        }
        else if(comparacion(node->element, element) > 0) {
            return get(node->left, element);
        }
        else {
            return get(node->right, element);
        }
    }

public:
    //AVL() : root(NULL) {}

    AVL( int (*_comparacion)(T, T) ) : root(NULL) {
        comparacion = _comparacion;
    }

    void insert(T element)
    {
        root = insert(root, element);
    }

    // TODO: implement this
    // void remove(T element)
    // {
    //     root = remove(root, element);
    // }

    bool contains(T element)
    {
        return this->contains(root, element);
    }

    void inOrder(void (*each)(T))
    {
        inOrder(root, each);
    }

    void imprimir()
    {
        this->imprimirInOrder(root);
    }

    T get(T* element)
    {
        return this->get(root, element);
    }
};

#endif
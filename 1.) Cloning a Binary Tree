//inserts dummy nodes in between original node and left child of original node
Node* insert(Node* root)
{
    if(!root)
        return NULL;
    Node* temp = root->left;
    root->left = new Node(root->data);
    root->left->left = temp;

    if(temp)
        temp->left = insert(temp);
    root->left->right = insert(root->right);
    //root->right is also change as insert() function affects structur
    //and root->left->right is also updates.
    return root->left;
}

/*
        1
      /  \
    2     3


    would become

        1
      /  \
     1'   3
    / \  /
   2   3'
  /
 2'

    after insert() function

*/
//to ensure that clone->random points towards corresponding node in its own tree
void addRandom(Node* root , Node* clone)
{
    if(!root)
        return;
    if(!root->random)
        clone->random = NULL;
    else
        clone->random = root->random->left;

    //its possibe that root->left is NOT NULL and clone->left is.
    //so check both
    if(root->left and clone->left)
        addRandom(root->left->left , clone->left->left);

    addRandom(root->right , clone->right);
    return;
}


//to restore the structure of both original tree and clone tree
void recover(Node* root , Node* clone)
{
    if(!root)
        return;

    if(clone->left)
    {
        Node* leftOfClone = clone->left->left;
        root->left = root->left->left;
        clone->left = leftOfClone;
    }
    else
        root->left = NULL;

    recover(root->left , clone->left);
    recover(root->right , clone->right);
    return;
}



Node* cloneTree(Node* root)
{
    if(!root)
        return NULL;
    Node* clone = insert(root);
    addRandom(root , clone);
    recover(root , clone);
    return clone;
}

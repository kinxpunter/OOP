#ifndef TREE_H
#define TREE_H

#include "tree_item.h"

struct node
{
  int key_value;     
  TreeItem* value;
  node *left;
  node *right;
};

class btree
{
    public:
        btree();
        ~btree();
Square front() const;
        void insert(const Square& square,int key);
        void destroy_tree();
        node *search(int key);
friend std::ostream& operator << (std::ostream& os, const btree& btree);
    private:
        void destroy_tree(node *leaf);
        void insert(const Square& square,int key, node *leaf);
        node *search(int key, node *leaf);
        int node_count;
        node *root;
};
#endif

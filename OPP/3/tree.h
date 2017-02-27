#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "tree_item.h"

struct node
{
  int key_value;     
  std::shared_ptr<TreeItem> value;
  node *left;
  node *right;
};

class btree
{
    public:
        btree();
        ~btree();
std::shared_ptr<Figure> front() const;
        void insert(const  std::shared_ptr<Figure>& figure,int key);
        void destroy_tree();
        node *search(int key);
friend std::ostream& operator << (std::ostream& os, const btree& btree);
    private:
        void destroy_tree(node *leaf);
        void insert(const std::shared_ptr<Figure>& figure,int key, node *leaf);
        node *search(int key, node *leaf);
        int node_count;
        node *root;
};
#endif

#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "tree_item.h"

struct node
{
  int key_value;     
  std::shared_ptr<TreeItem<T>> value;
  node *left;
  node *right;
};
template <class T>
class btree
{
    public:
        btree();
        ~btree();
        std::shared_ptr<T> front() const;
        void insert(const  std::shared_ptr<T>& item,int key);
        void destroy_tree();
        node *search(int key);
        template <class K>
friend std::ostream& operator << (std::ostream& os, const btree<K>& btree);
    private:
        void destroy_tree(node *leaf);
        void insert(const std::shared_ptr<T>& item,int key, node *leaf);
        node *search(int key, node *leaf);
        int node_count;
        node *root;
};
#include "tree_impl.cpp"
#endif

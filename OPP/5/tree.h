


#include <iostream>
#include "tree_item.h"
#include "iterator.h"
#include <memory>

template <class T>
struct node
{
  int key_value;     
  std::shared_ptr<TreeItem<T>> value;
  node<T> *left;
  node<T> *right;
};


template <class T>
class btree
{
    public:
        btree();
        ~btree();
        std::shared_ptr<T> front() const;
        void insert(const std::shared_ptr<T>& item,int key);
        void destroy_tree();
        node<T> *search(int key);
        void delete_t(int key);
        Iterator<TreeItem<T>, T> begin() const;
	Iterator<TreeItem<T>, T> end() const;
        template <class K>
friend std::ostream& operator << (std::ostream& os, const btree<K>& btree);
    private:
        void destroy_tree(node<T> *leaf);
        void insert(const std::shared_ptr<T>& item,int key, node<T> *leaf);
        node<T> *search(int key, node<T> *leaf);
        int node_count;
        node<T> *root;
};

#include "tree.cpp"


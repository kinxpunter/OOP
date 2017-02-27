#include "tree.h"

template <class T>
btree::btree()
{
  root=NULL;
}
template <class T>
btree::~btree()
{
  root=NULL;
}
template <class T>
void btree::destroy_tree(node *leaf)
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

template <class T>
void btree::insert(const std::shared_ptr<T>& item,int key, node *leaf)
{
     std::shared_ptr<TreeItem<T>> item = std::make_shared<TreeItem<T>>(item);
  if(key<leaf->key_value )
  {
    if(leaf->left!=NULL)
     insert(square,key, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->value=item;
      leaf->left->key_value=key;
      leaf->value->setNext(item);
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }  
  }
  else if(key>=leaf->key_value)
  {
    if(leaf->right!=NULL)
      insert(square,key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->value=item;
      leaf->right->key_value=key;
      leaf->value->setNext(item);
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
  node_count++;
}
template <class T>
void btree::insert(const std::shared_ptr<T>& item,int key)
{
     std::shared_ptr<TreeItem<T>> item = std::make_shared<TreeItem<T>>(item);
  if(root!=NULL)
    insert(square,key, root);
  else
  {
    root=new node;
    root->key_value=key;
    root->value=item;
    root->left=NULL;
    root->right=NULL;
  }
  node_count++;
}

template <class T>
void btree::destroy_tree()
{
  destroy_tree(root);
}
template <class K>
std::ostream& operator << (std::ostream& os, const btree& btree)
{
	if (btree.node_count == 0)
	{
		os << "================" << std::endl;
		os << "Tree is empty" << std::endl;
	}
	else
	{
		std::shared_ptr<TreeItem<K>> item = btree.root->value;

		while (item != NULL)
		{
			os << item->getItem();
			item = item->getNext();
		}
	}

	return os;
}
node *btree::search(int key, node *leaf)
{
  if(leaf!=NULL)
  {
    if(key==leaf->key_value)
      return leaf;
    if(key<leaf->key_value)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return NULL;
}
node *btree::search(int key)
{
  return search(key, root);
}

Square btree::front() const
{
	return root->value->getItem();
}

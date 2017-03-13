

template <class T>
btree<T>::btree()
{
  root=NULL;
}
template <class T>
btree<T>::~btree()
{
  root=NULL;
}
template <class T>
void btree<T>::destroy_tree(node<T> *leaf)
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}
template <class T>
Iterator<TreeItem<T>, T> btree<T>::begin() const
{
	return Iterator<TreeItem<T>,T>(root->value);
}

template <class T>
Iterator<TreeItem<T>, T> btree<T>::end() const
{
	return Iterator<TreeItem<T>, T>(nullptr);
}
template <class T>
void btree<T>::insert(const std::shared_ptr<T>& item,int key, node<T> *leaf)
{
     std::shared_ptr<TreeItem<T>> itemptr = std::make_shared<TreeItem<T>>(item);
  if(key<leaf->key_value )
  {
    if(leaf->left!=NULL)
     insert(item,key, leaf->left);
    else
    {
      leaf->left=new node<T>;
      leaf->left->value=itemptr;
      leaf->left->key_value=key;
      leaf->value->setNext(itemptr);
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }  
  }
  else if(key>=leaf->key_value)
  {
    if(leaf->right!=NULL)
      insert(item,key, leaf->right);
    else
    {
      leaf->right=new node<T>;
      leaf->right->value=itemptr;
      leaf->right->key_value=key;
      leaf->value->setNext(itemptr);
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
  node_count++;
}
template <class T>
void btree<T>::insert(const std::shared_ptr<T>& item,int key)
{
     std::shared_ptr<TreeItem<T>> itemptr = std::make_shared<TreeItem<T>>(item);
  if(root!=NULL)
    insert(item,key, root);
  else
  {
    root=new node<T>;
    root->key_value=key;
    root->value=itemptr;
    root->left=NULL;
    root->right=NULL;
  }
  node_count++;
}

template <class T>
void btree<T>::destroy_tree()
{
  destroy_tree(root);
}
template <class K>
std::ostream& operator << (std::ostream& os, const btree<K>& btree)
{
	if (btree.node_count == 0)
	{
		os << "================" << std::endl;
		os << "Queue is empty" << std::endl;
	}
	else
		for (std::shared_ptr<K> item : btree)
			item->print();

	return os;
}

template <class T>
void btree<T>::delete_t(int key)
{
if( node<T> *leaf= search(key,root)){
 if (leaf->left==NULL && leaf->left==NULL)
 {
  leaf->key_value=0;
  leaf->value=NULL;
 }
 else 
 {
  if( leaf->left!=NULL)
  {
   delete_t(leaf->left->key_value); 
  }
  if( leaf->right!=NULL)
  {
   delete_t(leaf->right->key_value); 
  }
 }
   node_count--;
}
else std::cout<<"no such item in tree\n";
}

template <class T>
node<T> *btree<T>::search(int key, node<T> *leaf)
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

template <class T>
node<T> *btree<T>::search(int key)
{
  return search(key, root);
}
template <class T>
std::shared_ptr<T> btree<T>::front() const
{
	return root->value->getItem();
}


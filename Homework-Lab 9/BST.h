#ifndef BST_H
#define BST_H

/*
   
   Lab 9 (BST)
 */
#include <ostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cmath>

using namespace std;

template <class T>
class Node{
public: Node(Node* left, Node* right, T value)
  :data(value),left(left),right(right){}
  T data;
  Node* left;
  Node* right;
};

template <class T>
class BST {

public:
  BST( int (*f)(const T&, const T&) ){
    cmpfn = f;
		root = NULL;
  }

  ~BST() {
		clear();
  }

  BST(const BST& other){
    cmpfn = other.cmpfn;
    root = NULL;
    root = copyFast(other.root);
  } 	

  BST<T>& operator= (const BST& other){  
		if(&other == this){
			return *this;
		}
		clear();
    cmpfn = other.cmpfn;
    root = NULL;
    root = copyFast(other.root);
				
		return *this;
	}
  
  void insert(T thing){
		if(!root){
			root = new Node<T>(NULL, NULL, thing);
		}
		else{
			insert(
			root, thing);
		}
  }
  
  bool find(const T& thing) const{
		bool doesExist = false;
		if(!root){
			doesExist = false;
			return doesExist;
		}
		getFind(root, thing, doesExist);
    return doesExist;
  }

  unsigned int size() const{
//call the recursive version
    return size(root);
  }
  
  T getSmallest() const{
//call the recursive version
		if(!root){
			throw logic_error("root doesn't exist");
		}
		return getSmallestFn(root);
  }
  
  T getLargest() const{
//call the recursive version
		if(!root){
			throw logic_error("root doesn't exist");
		}
		return getLargestFn(root);
  }
  
	void clear(){
//recursive clear
		clear(root);
		root = NULL;
	}

	string getInOrder() const{
		stringstream s;
		s << "[";
	  getInOrder(root,s);
		string ret(s.str());
		if(ret.length() > 1){
			ret.erase(ret.length()-1);
		}
		ret = ret + "]";
    return ret;
  }
  
  string getPreOrder() const{
//use a stringstream
		stringstream s;
		s << "[";
	  getPreOrder(root,s);
		string ret(s.str());
		if(ret.length() > 1){
			ret.erase(ret.length()-1);
		}
		ret = ret + "]";
    return ret;
  }  
  string getPostOrder() const{
//use a stringstream
		stringstream s;
		s << "[";
	  getPostOrder(root,s);
		string ret(s.str());
		if(ret.length() > 1){
			ret.erase(ret.length()-1);
		}
		ret = ret + "]";
    return ret;
  } 

  bool isFull() const{
		if(!root){
			return true;
		}
    return isFull(root);
  }
  
  bool isBalanced() const{
		if(!root){
			return true;
		}
    return isBalanced(root);
  }

  unsigned int getHeight() const{
		if(!root){
			return 0;
		}
		return getHeight(root)-1;
  }

private:
  Node<T>* root;

  int (*cmpfn)(const T& left, const T& right);
  
	unsigned int size(Node<T>* node) const{
		if(!node){
			return 0;
		}
		return size(node->left) + size(node->right) + 1;
  }

  bool isFull(Node<T>* node) const{
		if(!node){
			return true;
		}
		if( (abs(getHeight(node->left) - getHeight(node->right)) == 0) &&	isFull(node->left) && isFull(node->right)){
			return true;
		}
    return false;
  }

	bool isBalanced(Node<T>* node) const{
		if(!node){
			return true;
		}
		float left = getHeight(node->left);
		float right = getHeight(node->right);
		if( ((abs(left - right)) <= 1) &&	isBalanced(node->left) && isBalanced(node->right)){
			return true;
		}
    return false;
	}

  unsigned int getHeight(Node<T>* node) const{
		if(!node){
			return 0;
		}
	return max(getHeight(node->left), getHeight(node->right)) + 1;
  }

  void insert(Node<T>* node, T thing){
  	if(!node){
  		throw logic_error("Wrong Area!");
  	}
		if( (*cmpfn)(thing, node->data) <= 0)   {  
			if(node->left){ 
				insert(node->left, thing);
			}else{ 
				node->left = new Node<T>(NULL, NULL, thing);
			}
		}else{  
			if(node->right){ 
				insert(node->right, thing);
			}else{ 
				node->right = new Node<T>(NULL, NULL, thing);
			}
		}
  }
  
	void getInOrder(Node<T>* node, stringstream& s) const{
		if(!node){
			return; 
		}else{
			getInOrder(node->left, s);
			s << node->data << ",";
			getInOrder(node->right, s);
		}
	}

	void getPreOrder(Node<T>* node, stringstream& s) const{
		if(!node){
			return; 
		}else{
			s << node->data << ",";
			getPreOrder(node->left, s);
			getPreOrder(node->right, s);
		}
	}
	
	void getPostOrder(Node<T>* node, stringstream& s) const{
		if(!node){
			return; 
		}else{
			getPostOrder(node->left, s);
			getPostOrder(node->right, s);
			s << node->data << ",";
		}
	}

  bool getFind(Node<T>* node, const T& thing, bool& doesExist)const{
		if(!node){
			return false;
		}else{
			getFind(node->left, thing, doesExist);
			if(node->data == thing){
				doesExist = true;
				return doesExist;
			}
			getFind(node->right, thing, doesExist);
		}
    return doesExist;
  }

  T getSmallestFn(Node<T>* node) const{
		if(!node){
			return 0;
		}else{
			if(!node->left){
				return node->data;
			}else{
				return getSmallestFn(node->left);
		  }
		}
	}
  
  T getLargestFn(Node<T>* node) const{
		if(!node){
			return 0;
		}else{
			if(!node->right){
				return node->data;
			}else{
				return getLargestFn(node->right);
		  }
		}
	}

	void clear(Node<T>* node){
		if(node){ 
			clear(node->left);
			clear(node->right);
			delete node;
		}
	}

  Node<T>* copyFast(Node<T>* node){
    if(!node){
      return NULL;
    }else{
      Node<T>* ret =  new Node<T>(copyFast(node->left), copyFast(node->right), node->data);
      return ret;
    }
  }
};
#endif

#ifndef HASHTABLE_H
#define HASHTABLE_H

/*
	String Hash Table class.
	Uses open addressing - linear probing.
	Paul Talaga
	October 2015
*/
#include <ostream>
#include <stdexcept>

using namespace std;

enum status {NOTUSED, USED, DELETE};

template <class T>
struct thing_t{
	T data;
	status the_status;
};

template <class T>
class HashTable{

  public:
  HashTable( unsigned int (*f)(const T&), unsigned int capacity){
    hashfn = f;
    // Keep filling me in!
    the_cap = capacity;
    the_size = 0;
    table = new thing_t<T>[the_cap];
    for(unsigned int i = 0; i < the_cap; i++){
      table[i].the_status = NOTUSED;
    }
  }

  ~HashTable() {
    // TODO
    delete[] table;
		table = NULL;
		the_size = 0;

  }

  HashTable(const HashTable& other){
    // TODO
		the_cap = other.the_cap;
    hashfn = other.hashfn;
    table = new thing_t<T>[the_cap];
    for(unsigned int i = 0; i < the_cap; i++){
      table[i].the_status = NOTUSED;
    }
    the_size = 0;
    if(other.size() == 0){
      return;
    }
    
    for(unsigned int i = 0; i < other.the_cap; i++){
      if(other.table[i].the_status == USED){
        insert(other.table[i].data);
      }
    }
  }
	
  HashTable<T>& operator= (const HashTable& other){  
		// TODO
		if(this == &other){
		  return *this;
		}
		delete[] table;
		table = NULL;
		the_size = 0;
		hashfn = other.hashfn;
		the_cap = other.the_cap;
		table = new thing_t<T>[the_cap];
		for(unsigned int i = 0; i < the_cap; i++){
		  table[i].the_status = NOTUSED;
		}
		the_size = 0;
		if(other.size() == 0){
		  return *this;
		}
		for(unsigned int i = 0; i < other.the_cap; i++){
		  if(other.table[i].the_status == USED){
		    insert(other.table[i].data);
		  }
		}
		return *this;
	}
     
  bool find(T thing) const{
		// TODO
		unsigned int index = (*hashfn)(thing);
		index = index % the_cap;
		unsigned int index0 = index;
		while(table[index].the_status != NOTUSED){
		  if(table[index].the_status == USED && table[index].data == thing){
		    return true;
		  }
		  index = index + 1;
		  index = index % the_cap;
		  if(index0 == index){
		    return false;
		  }
		}
    return false;
  }

  unsigned int size() const{
    // TODO
//    return 0;
		return the_size;
  }
  
  unsigned int capacity() const{
    // TODO
//    return 0;
		return the_cap;
  }
  
  bool isFull() const{
    // TODO
//    return false;
		return the_size == the_cap;
  }
 
  void insert(T thing){
    // TODO
    // Demo of hash function
//    cout << "hash of " << thing << " is " << (*hashfn)(thing) << endl;
    if(find(thing)){
      return;
    }
    if(isFull()){
      throw logic_error("FULL");
    }
    unsigned int index = (*hashfn)(thing);
    index = index % the_cap;
    int move = 0;
    while(table[index].the_status == USED){
      index = index + 1;
      index = index % the_cap;
      move++;
    }
    table[index].data = thing;
    table[index].the_status = USED;
    the_size++;
  }
  
  void remove(T thing){
    // TODO
    if(!find(thing)){
      return;
    }
    unsigned int index = (*hashfn)(thing);
    index = index % the_cap;
    while(table[index].the_status != NOTUSED){
      if(table[index].the_status == USED && table[index].data == thing){
        table[index].the_status = DELETE;
       	the_size--;
        return;
      }
      index = index + 1;
      index = index % the_cap;
    }
  }
	
	void clear(){
		// TODO
		for(unsigned int i = 0; i < the_cap; i++){
      table[i].the_status = NOTUSED;
    }
    the_size = 0;
	}
	
 
  
  private:
  // TODO
  // This will store the hash function that was passed in.
  unsigned int (*hashfn)(const T& thing);
  unsigned int the_cap;
  unsigned int the_size;
  thing_t<T>* table;

};

#endif

#ifndef DLIST_H
#define DLIST_H

/*
	Templated Doubly Linked List class.
	Paul Talaga
	October 2015
*/
#include <ostream>
#include <stdexcept>

using namespace std;

template <class T>
struct node_t {
  T data;
  node_t<T>* prev;
  node_t<T>* next;
};

// This implementation will use a head and tail pointers,
// allowing O(1) insertion on the front and end.
template <class T>
class DList{

  public:
  DList(){
		head = NULL;
		tail = NULL;
		the_size = 0;
   // Fill me in
  }
  
  ~DList(){
		// Fill me in
		clear();
	}
	
  DList(const DList& other){
    // Fill me in
  	head = NULL;
		tail = NULL;
		the_size = 0;
		// Check if the other DList is empty
		if(other.head == NULL || other.tail == NULL){
			return;
		}
		// Not empty?  Iterate through the other list
		// and push_back on myself.
		node_t<T>* temp = other.head;
		while(temp){
			push_back(temp->data);
			temp = temp->next;
		}
  }
	
	// Similar to copy constructor, but check for self
	// assignment, if not, clear and copy all data.
  DList<T>& operator= (const DList& other){  
		if(this == &other){
			return *this;
		}
  	clear();
		if(other.head == NULL || other.tail == NULL){
			return *this;
		}
		node_t<T>* temp = other.head;
		while(temp){
			push_back(temp->data);
			temp = temp->next;
		}
		return *this;
	}
/*     
  T getAt(int pos) const{
		// Fill me in
		// Handle negatives
		if(pos < 0){
			pos = pos + the_size;	
		}
		if(pos < 0){
			throw logic_error("Index too negative");
		}
		// Walk down the list and decrement pos.
    node_t<T>* temp = head;
    while(temp != NULL && pos > 0){
      temp = temp->next;
      pos--;
    }
    // As long as we don't have a NULL temp, return
    // what was desired.
    if(pos == 0 && temp !=NULL){
      return temp->data;
    }
    throw logic_error("Index invalid");
  } */


  T getAt(int pos) const{
		if (pos < 0 ){
			pos = the_size + pos;
		}
		if(pos > the_size-1 || pos < 0 || head == NULL ){
			//throw error
			throw logic_error("value of Index invalid");
		}

		if( pos < ( ( the_size ) / 2 ) )
		{
			node_t<T>* temp = head;
			int i = 0;
			while(i<pos){
				temp = temp->next;
				i++;
			}
			return temp->data;
		}
		else
		{
			node_t<T>* temp = tail;
			int i = the_size-1;
			while(i>pos){
				temp = temp->prev;
				i--;
			}
			return temp->data;
			
		}
	}


	void setAt(T value, int pos){
		// Fill me in
		// Handle negatives
		if(pos < 0){
			pos = the_size + pos;	
		}
		if(pos > the_size-1 || pos < 0 || head == NULL ){
			//throw error
			throw logic_error("value of Index invalid");
		}
		if( pos < ( ( the_size ) / 2 ) )
		{
			node_t<T>* temp = head;
			int i = 0;
			while(i<pos){
				temp = temp->next;
				i++;
			}
			temp->data = value;
		}
		else
		{
			node_t<T>* temp = tail;
			int i = the_size-1;
			while(i>pos){
				temp = temp->prev;
				i--;
			}
			temp->data = value;
			
		}
	}

/*	    while(temp != NULL && pos > 0){
	      temp = temp->next;
	      pos--;
	    }
    	if(pos == 0 && temp !=NULL){
    		temp->data = value;
				return;
    	}
		}
    // As long as I don't have a null pointer, assign.
		else
		{
			node_t<T>* temp = tail;
	    while(temp != NULL && pos < the_size){
	      temp = temp->prev;
	      pos++;
	    }
//		}

    	if(pos == the_size && temp !=NULL){
    		temp->data = value;
				return;
    	}
		}
    throw logic_error("Index invalid");
  }
*/

/*
	void setAt(T value, int pos){
		// Fill me in
		// Handle negatives
		if(pos < 0){
			pos = pos + the_size;	
		}
		if(pos < 0){
			throw logic_error("Index too negative");
		}

		node_t<T>* temp = head;
    while(temp != NULL && pos > 0){
      temp = temp->next;
      pos--;
    }
    // As long as I don't have a null pointer, assign.
    if(pos == 0 && temp !=NULL){
    	temp->data = value;
			return;
    }
    throw logic_error("Index invalid");
  }
*/
/*
		if( pos < ( ( this->size() ) / 2 ) )
		{
			node_t<T>* temp = head;
			int i = 0;
			while(i<pos){
				temp = temp->next;
				i++;
			}
			temp->data = value;

    // As long as I don't have a null pointer, assign.
    if(pos == 0 && temp !=NULL){
    	temp->data = value;
			return;
    }
    throw logic_error("Index invalid");

		}
		else
		{
			node_t<T>* temp = tail;
			int i = this->size()-1;
			while(i>pos){
				temp = temp->prev;
				i--;
			}
			temp->data = value;
		}

*/



/*
//returns an element at a given location
  T getAt(int pos) const{
		if (pos < 0 ){
//			pos = this.size() + pos;
//			pos = *this.size() + pos;
			pos = this->size() + pos;
		}
		if(pos > this->size()-1 || pos < 0 || head == NULL ){
			//throw error
			throw logic_error("value of Index invalid");
		}
		if( pos < ( ( this->size() ) / 2 ) )
		{
			node_t<T>* temp = head;
			int i = 0;
			while(i<pos){
				temp = temp->next;
				i++;
			}
			return temp->data;
		}
		else
		{
			node_t<T>* temp = tail;
			int i = this->size()-1;
			while(i>pos){
				temp = temp->prev;
				i--;
			}
			return temp->data;
			
		}
	}

//Puts value at location position (0 based). Negative?
	void setAt(T value, int pos){
		if (pos < 0){
			pos = this->size() + pos;
		}
		if(pos > this->size()-1 || pos < 0 || head == NULL ){
			//throw error
			throw logic_error("value of Index invalid");
		}
		if( pos < ( ( this->size() ) / 2 ) )
		{
			node_t<T>* temp = head;
			int i = 0;
			while(i<pos){
				temp = temp->next;
				i++;
			}
			temp->data = value;
		}
		else
		{
			node_t<T>* temp = tail;
			int i = this->size()-1;
			while(i>pos){
				temp = temp->prev;
				i--;
			}
			temp->data = value;
		}
	}
*/

/*
  T getAt(int pos) const{
    //gets value at position pos in linked list
    node_t<T>* item = this->first;
    if(pos<0) {
      //backtrack
      pos = this->size() + pos;
    }
    //check range
    if(pos<0 || pos >=this->size()) {
      throw logic_error("Index out of Range");
    }
    if(pos==size()-1) { //edge case: last
      return this->last->data;
    }
    if(pos <= size()/2) {
      for(int i=0; i<pos && item; i++) {
        item = item->next;
      }
    }
    else {
      pos=size()-pos;
      item = this->last;
      pos--; //first 1
      while(pos && item->prev) {
        pos--;
        item = item->prev;
      }
    }
    if(!item) {
      throw logic_error("Index out of Range");
    }
    return item->data;
  }
*/


  unsigned int size() const{
    // Fill me in
    return the_size;
  }

// /* \/\/\/\/\/\/\/\/\/\/\/\/\/ */
/* 
//Puts value at location position (0 based). Negative?
	void setAt(T value, int pos){
		if (pos < 0){
			pos = this->size() + pos;
		}
		if(pos > this->size()-1 || pos < 0 || head == NULL ){
			//throw error
			throw logic_error("value of Index invalid");
		}
		node_t<T>* temp = head;
		int i = 0;
		while(i<pos){
			temp = temp->next;
			i++;
		}
		temp->data = value;
	}

  unsigned int size() const{
		node_t<T>* temp = head;
		int ii = 0; //set to ii to help debug
//		while(temp != NULL){ //keeps running while temp doesn't = null, i think
		while(temp){ //keeps running while temp doesn't = null, i think
//			cout << i << ":" << temp->value << " " << endl;
			temp = temp->next;
			ii++;
		}
		return ii;	
	}


//Remove the element at location, making the list smaller

 void remove(int pos){
    if(pos < 0){
      pos = this->size() + pos;
    }
    if(this->size() == 0 || abs(pos) > this->size()-1 || head == NULL){
			//throw error
			throw logic_error("value of Index invalid");
		}

    if(pos == 0){
      node_t<T>* to_delete = head;
      head = head->next;
      delete to_delete;
    }
		else{
	  	node_t<T>* temp = head;
	    int i=0;

	  	while((temp) && i!=pos-1){
	  	  temp=temp->next;
	      i++;
	    }
	    node_t<T>* to_delete = temp->next;
	    if(temp->next->next){
	    	temp->next=temp->next->next;
      }
			else {
	    	temp->next=NULL;
      }
      delete to_delete;
		}
	}


*/
// /* /\/\/\/\/\/\/\/\/\/\/\/\/\/\ */

  void push_back(T value){
    // Fill me in
    // Empty list?
    if(head == NULL || tail == NULL){
      push_front(value);
    }else{
      // Not empty.  Use my tail pointer to tack
      // on a last element.
      node_t<T>* temp = new node_t<T>;
      node_t<T>* oldTail = tail;
      temp->data = value;
      temp->next = NULL;
      tail->next = temp;
      tail = temp;
			tail->prev = oldTail;
      the_size++;
    }
  }
  
  void push_front(T value){
    // Fill me in
    // Empty list?
    if(head == NULL || tail == NULL){
      head = new node_t<T>;
      head->data = value;
      head->next = NULL;
			head->prev = NULL;
      tail = head;
      the_size = 1;
    }else{// Not empty
      node_t<T>* temp = new node_t<T>;
      temp->data = value;
      temp->next = head;
      head = temp;
			temp->prev = NULL;
			temp->next->prev = temp;
      the_size++;
    }
  }
/*  void push_front(T value) {
    //adds a new node to the beginning of the list
    the_size++;
    node_t<T>* temp = new node_t<T>();
    temp->data = value;
    temp->next = this->head;
    temp->prev = NULL;
    this->head = temp;
    if(temp->next) { //nonempty
      temp->next->prev = temp;
    }
    if(!this->tail) { //if empty
      this->tail = this->head;
    }
  }*/

		
	void remove(int pos){
		// Fill me in
		// Handle negatives
		if(pos < 0){
			pos = the_size + pos;	
		}
		if(pos < 0){
			throw logic_error("Index too negative");
		}
		if(pos >= the_size){
			throw logic_error("Index invalid");
		}
		// Removing the first and only element?
		if(pos == 0 && the_size == 1){
			delete head;
			head = NULL;
			tail = NULL;
			the_size = 0;
		}else if(pos == 0){ // First element when more than one?
			node_t<T>* temp = head;
			head = head->next;
			head->prev = NULL; //added
			delete temp;
			the_size--;
			return;
		}else if(pos == the_size-1){ // Last element?
//			node_t<T>* temp = head;
//			cout << "testing delete of last element\n";//testing
			node_t<T>* temp = tail;
//	    while(temp->next != tail ){
//	      temp = temp->next;
//	    }
//			node_t<T>* to_delete = temp->next;
//			tail = temp;
//			temp->next = NULL;
			tail = tail->prev;
			tail->next = NULL;
//			delete to_delete;
			delete temp;
			the_size--;
//		}else{ // In the middle, get the node before.
			// Need to get one before
		}else if( pos < ( ( the_size ) / 2 ) )
		{
			node_t<T>* temp = head;
			int i = 0;
			while(i<pos){
				temp = temp->next;
				i++;
			}
//				node_t<T>* to_delete = temp->next;
				node_t<T>* to_delete = temp;
				temp->prev->next = to_delete->next;
				temp->next->prev = to_delete->prev;
				delete to_delete;
				the_size--;
				return;
		}
		else
		{
			node_t<T>* temp = tail;
			int i = the_size-1;
			while(i>pos){
				temp = temp->prev;
				i--;
			}
				node_t<T>* to_delete = temp;
				temp->prev->next = to_delete->next;
				temp->next->prev = to_delete->prev;
				delete to_delete;
				the_size--;
				return;
			
//			}
//		}

/*
			pos = pos - 1;
			node_t<T>* temp = head;
	    while(temp != NULL && pos > 0){
	      temp = temp->next;
	      pos--;
	    }
	    // Verify temp is valid before dereferencing.
	    if(pos == 0 && temp !=NULL){
	    	// Now delete the next element!
				node_t<T>* to_delete = temp->next;
				temp->next = to_delete->next;
				delete to_delete;
				the_size--;
				return;
	    }*/
			cout << "throw logic error line 545\n"; //testing when does this get thrown?
	    throw logic_error("Index invalid"); //<- is this needed? does it ever run?
		}
	}
// end remove

	
	DList<T> reverse() const{
		// Fill me in
		// Step through this list and add to the front of ret.
		DList<T> ret;
		node_t<T>* temp = head;
		while(temp){
			ret.push_front(temp->data);
			temp = temp->next;
		}
		return ret;
	}
	
	DList<T> operator+(const DList<T>& other) const{
		// Step through this list and add to the end of ret.
		DList<T> ret;
		node_t<T>* temp = head;
		while(temp){
			ret.push_back(temp->data);
			temp = temp->next;
		}
		// Do the same for other
		temp = other.head;
		while(temp){
			ret.push_back(temp->data);
			temp = temp->next;
		}
		return ret;
	}
	
	bool operator==(const DList<T>& other) const{
	  // Fill me in
	  // Sizes differ?
		if(the_size != other.the_size){
			return false;
		}
		// Now step through both lists and verify data
		node_t<T>* temp1 = head;
		node_t<T>* temp2 = other.head;
		while(temp1 && temp2){
			if(temp1->data != temp2->data){
				return false; // Why keep looking if we found an error?
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		// Did we pop out early because one is NULL?
		if(temp1 != temp2){ // Both should be null!
			return false;
		}
		return true;
	}
	
	bool operator!=(const DList<T>& other) const{
		// Fill me in
		return ! operator==(other);
	}
	
	void clear(){
		// Fill me in
		node_t<T>* last = head;
		while(head){
			head = head->next;
			delete last;
			last = head;
		}
		// Normaly you never want to change head or you'll orphan part
		// of the list, but in this case we are wiping the list,
		// so it is ok to so and saves us a variable.
		head = NULL;
		tail = NULL;
		the_size = 0;
		delete last;
	}
 


 
//think everything above is done, finish below for HW
// \/\/\/\/\/\/\/\/\/\/

	
	// HW additions.
	//count(T thing) - Returns an unsigned int number of times thing was in the DList.O(n)
	unsigned int count(T thing){
	  // Fill me in
		unsigned int tally = 0;
		node_t<T>* temp = head;
		while (temp != NULL) 
		{
			if (temp->data == thing)
			{
				tally++;
			}
			temp = temp->next;
		}
		return tally;
	}
	
	//Split the current DList in half and set left and right to be the left and right half respectively.This
	//will erase all existing elements in left and right, and the current DList will
	//be empty after this operation.If the current DList is not evenly divisible,
	//the right should be one larger than the left.O(n)
	void splitHalf(DList<T>& a, DList<T>& b){
	  // Fill me in
		
		int counter = 0;
		int halfway = (the_size / 2);
		node_t<T>* temp = head;
		
		while (temp != NULL && counter < halfway)
		{
			a.push_back(temp->data);
			temp = temp->next;
			remove(0);
			counter++;
		}
		while (temp != NULL)
		{
			b.push_back(temp->data);
			temp = temp->next;
			remove(0);
		}
	}

	/*splitEveryOther(DList& evens, DList& odds) - Splits the
	current DList into two smaller DLists, with evens containing all the even
	indexed elements, and odds, the odd indexed elements. (0 based)  This
	will erase all existing elements in evens and odds, and the current DList
	will be empty after this operation.O(n)*/
	void splitEveryOther(DList<T>& evens, DList<T>& odds){
	  // Fill me in
		int counter = 0;
		node_t<T>* temp = head;
		while (temp != NULL)
		{
			if (counter%2 == 0)
			{
				evens.push_back(temp->data);
				
			}
			else
			{
				odds.push_back(temp->data);
			}
			
			temp = temp->next;
			remove(0);
			counter++;
		}
	}
	
	//Reverses the current DList.  O(n)
	void reverseThis(){
	  // Fill me in
		int counter = 0;
		node_t<T>* T1 = head;
		node_t<T>* T2 = tail;
		T temp;

		while (counter < (the_size / 2))
		{
			temp = T2->data;
			T2->data = T1->data;
			T1->data = temp;
			T1 = T1->next;
			T2 = T2->prev;
			counter++;
		}
	}
	
	//Changes the current DList where every element exists twice in the resulting DList, thus having twice the length.[1, 2, 3] .double()
	//->[1, 1, 2, 2, 3, 3]  O(n)
	void doubleThis(){
	  // Fill me in
		int counter = 0;
		int originalSize = the_size;
		node_t<T>* T1 = head;
		
		while (counter < originalSize)
		{
			node_t<T>* newby = new node_t<T>;
			newby->data = T1->data;
			newby->next = T1->next;
			newby->prev = T1;
			if (T1->next != NULL)
			{
				T1->next->prev = newby;
			}
			else
			{
				tail = newby;
			}
			
			T1->next = newby;
			if (T1->next->next != NULL)
			{
				T1 = T1->next->next;
			}
			counter++;
		}
		the_size = the_size * 2;
	}
	
	//setEq(const DList& other) - Return true if all the elements exist
	//somewhere in other, and all elements in other exist somewhere in the
	//current DList.The sizes must match, and duplicate values may occur.
	//Order does not matter.Be as efficient as possible : O(m x n) in general,
	//and O(n) for the case listed in the unit tests.You may only use linked lists and pointers.

//*************

///*
	bool setEq(const DList<T>& other){
	  DList otherCopy(other);
	  if(size() != other.size()){
	    return false;
	  }
	  node_t<T>* temp = head;
	  while(temp){
	    bool found = false;
	    node_t<T>* otherTemp = otherCopy.head;
	    while(otherTemp){
	      if(otherTemp->data == temp->data){
	        found = true;
	        otherCopy.deleteNode(otherTemp);
	        break;
	      }
	      otherTemp = otherTemp->next;
	    }
	    if(!found){
	      return false;
	    }
	    temp = temp->next;
	  }
	  return true;
	}

  void deleteNode(node_t<T>* to_delete){
    if(to_delete->prev){
      to_delete->prev->next = to_delete->next;
    }
    else{
      head = to_delete->next;
    }
    
    if(to_delete->next){
      to_delete->next->prev = to_delete->prev;
    }
    else{
      tail = to_delete->prev;
    }
    
    delete to_delete;
    the_size--;
  }
// */
//*************
/*
	bool setEq(DList<T>& other){
//	bool setEq(const DList<T>& other){
	  // Fill me in
//		DList<T> o = other;
		
		node_t<T>* T1 = head;
//		int a = 0;
//		int b = 0;
		
//		if(	the_size != other.size()){
//			return false;
//		}

		while (T1 != NULL){
//			a = o.count2(T1->data); //b
			if(other.count2(T1->data)){ //b
//			other.count2(T1->data);
//			b = count2(T1->data); //a
			
//			if (a != b){
//				return false;
//			}

//cout<<"a "<<T1->data<<endl;
//cout<<"next\n";
			T1 = T1->next;
//cout<<T1->data<<endl;
			}else{
			return false;
			}
		}
		while (T1 != NULL){
//			a = o.count2(T1->data); //b
			if(count2(T1->data)){ //b
//			other.count2(T1->data);
//			b = count2(T1->data); //a
			
//			if (a != b){
//				return false;
//			}

//cout<<"b "<<T1->data<<endl;
//cout<<"next\n";
			T1 = T1->next;
//cout<<T1->data<<endl;
			}else{
			return false;
			}
		}
		
	  return true;
	}
*/
///*
	bool count2(T& thing){
//		unsigned int tally = 0;
		node_t<T>* temp = head;
		while (temp != NULL){
			if (temp->data == thing){
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
//*/

/* /\/\/\/\/\/\/\/\/\/\/\ */
//think everything below is done, finish above
  
  private:
  // Fill me in
		node_t<T>* head;
		node_t<T>* tail;

	  unsigned int the_size;

};

// Note this function is O(n^2) because getAt is O(n) and we are
// doing it n times.
template <class T>
ostream& operator<<(ostream& out, const DList<T> other){
	out << "[";
	// Fill me in
	for(unsigned int i = 1; i < other.size(); i++){
		out << other.getAt(i-1) << ", ";
	}
	if(other.size() > 0){
		out << other.getAt(-1);
	}
	out << "]";
	return out;
}


#endif

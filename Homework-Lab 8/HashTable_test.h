#ifndef HASHTABLE_TEST_H
#define HASHTABLE_TEST_H

#include "HashTable.h"
#include <stdexcept>
#include <string>
// Needed for space removal.
#include <sstream>
#include <algorithm>
#include <cxxtest/TestSuite.h>
#include <ctime>

using namespace std;

// This requires CxxTest to be installed!
// For this CPPVideos example, navigate your terminal to CPPVideos and type:
// git submodule add https://github.com/CxxTest/cxxtest.git
// This will add the public CxxTest repository INSIDE the current repo.
// The current Makefile in this directory assumes cxxtest is a folder one
// level down.

const int SIZE = 2000;  // Size of Linked List to test speed.

// Some useful hash functions
unsigned int hash(const int& number){
  return abs(number);
}

unsigned int hash(const string& word){
  unsigned int ret = 0;
  for(unsigned int i = 0; i < word.length(); i++){
    ret += word[i] * i + i * 47;
  }
  return ret;
}

class HashTableInsertSizeCap : public CxxTest::TestSuite {
public:

  void testEmpty() {
    HashTable<int> a(hash, 5);
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_EQUALS(a.capacity(), 5);
  }
  
  void testInsert1() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(a.capacity(), 5);
  }

   void testInsert2() {
    HashTable<int> a(hash, 3);
    a.insert(5);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(a.capacity(), 3);
  }

   void testInsert3() {
    HashTable<int> a(hash, 2);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(a.capacity(), 2);
  }

   void testInsert4() {
    HashTable<int> a(hash, 7);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    TS_ASSERT_EQUALS(a.size(), 3);
    TS_ASSERT_EQUALS(a.capacity(), 7);
  }

   void testInsert5() {
    HashTable<int> a(hash, 7);
    a.insert(5);
    a.insert(5);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(a.capacity(), 7);
  }

   void testInsert6() {
    HashTable<int> a(hash, 4);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    TS_ASSERT_EQUALS(a.size(), 3);
    TS_ASSERT_EQUALS(a.capacity(), 4);
  }

   void testInsert7() {
    HashTable<int> a(hash, 4);
    a.insert(5);
    a.insert(5);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(a.capacity(), 4);
  }

   void testInsert8() {
    HashTable<int> a(hash, 4);
    a.insert(5);
    a.insert(5);
    a.insert(5);
    a.insert(6);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(a.capacity(), 4);
  }

   void testInsert9() {
    HashTable<int> a(hash, 4);
    a.insert(5);
    a.insert(5);
    a.insert(5);
    a.insert(6);
    a.insert(6);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(a.capacity(), 4);
  }

   void testInsert10() {
    HashTable<int> a(hash, 4);
    a.insert(5);
    a.insert(5);
    a.insert(5);
    a.insert(6);
    a.insert(6);
    a.insert(7);
    TS_ASSERT_EQUALS(a.size(), 3);
    TS_ASSERT_EQUALS(a.capacity(), 4);
  }

  void testFull1() {
    HashTable<int> a(hash, 1);
    a.insert(7);
    TS_ASSERT(a.isFull());
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(a.capacity(), 1);
  }
  
  void testFull2() {
    HashTable<int> a(hash, 2);
    a.insert(7);
    a.insert(8);
    TS_ASSERT(a.isFull());
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(a.capacity(), 2);
  }
  
  void testFull3() {
    HashTable<int> a(hash, 3);
    a.insert(7);
    a.insert(8);
    a.insert(9);
    TS_ASSERT(a.isFull());
    TS_ASSERT_EQUALS(a.size(), 3);
    TS_ASSERT_EQUALS(a.capacity(), 3);
  }
  
  void testFull4() {
    HashTable<int> a(hash, 3);
    a.insert(7);
    a.insert(7);
    a.insert(8);
    TS_ASSERT(!a.isFull());
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(a.capacity(), 3);
  }
  
  void testFull5() {
    HashTable<int> a(hash, 3);
    a.insert(7);
    a.insert(7);
    a.insert(8);
    a.insert(8);
    TS_ASSERT(!a.isFull());
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(a.capacity(), 3);
  }
  
  void testFull6() {
    HashTable<int> a(hash, 3);
    a.insert(7);
    a.insert(7);
    a.insert(8);
    a.insert(8);
    a.insert(9);
    TS_ASSERT(a.isFull());
    TS_ASSERT_EQUALS(a.size(), 3);
    TS_ASSERT_EQUALS(a.capacity(), 3);
  }
  


  // TODO
};

class HashTableClear : public CxxTest::TestSuite {
public:

  void testClear1(){
    HashTable<int> a(hash, 1);
    a.insert(7);
    a.clear();
    TS_ASSERT_EQUALS(a.size(),0);
  }
  
  void testClear2(){
    HashTable<int> a(hash, 4);
    a.insert(7);
    a.insert(7);
    a.clear();
    TS_ASSERT_EQUALS(a.size(),0);
  }
  
  void testClear3(){
    HashTable<int> a(hash, 55);
    a.insert(7);
    a.insert(8);
    a.insert(9);
    a.clear();
    TS_ASSERT_EQUALS(a.size(),0);
  }
  
  void testClear4(){
    HashTable<int> a(hash, 55);
    a.insert(7);
    a.insert(8);
    a.insert(9);
    a.clear();
    a.insert(7);
    a.insert(8);
    a.insert(9);
    a.clear();
    TS_ASSERT_EQUALS(a.size(),0);
  }
  
  void testClear5(){
    HashTable<int> a(hash, 55);
    a.insert(7);
    a.insert(8);
    a.insert(9);
    a.clear();
    a.insert(9);
    a.clear();
    a.insert(9);
    a.clear();
    TS_ASSERT_EQUALS(a.size(),0);
  }
  


  // TODO
  
};

class HashTableConCopyAssign : public CxxTest::TestSuite {
   
public:
  // Copy Constructor
	void testCopy1() {
    HashTable<int> a(hash,55);
    a.insert(9);
    HashTable<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
  }
	void testCopy2() {
    HashTable<int> a(hash,55);
    a.insert(9);
    a.insert(8);
    HashTable<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(b.size(), 2);
  }
	void testCopy3() {
    HashTable<int> a(hash,55);
    a.insert(9);
    a.insert(8);
    a.insert(7);
    HashTable<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 3);
    TS_ASSERT_EQUALS(b.size(), 3);
  }

	void testCopy4() {
    HashTable<int> a(hash,55);
    a.insert(9);
    a.insert(8);
    a.insert(7);
    HashTable<int> b(a);
    a.clear();
    TS_ASSERT_EQUALS(a.size(),0);
    TS_ASSERT_EQUALS(b.size(), 3);
  }

	void testCopy5() {
    HashTable<int> a(hash,55);
    a.insert(9);
    a.insert(8);
    a.insert(7);
    HashTable<int> b(a);
    a.clear();
    b.clear();
    TS_ASSERT_EQUALS(a.size(),0);
    TS_ASSERT_EQUALS(b.size(),0);
  }



// TODO
  
};

class HashTableInsertFind : public CxxTest::TestSuite {
public:
  void testInsertFind1(){
    HashTable<int> a(hash, 5);
    a.insert(5);
    TS_ASSERT(a.find(5));
  }

  void testInsertFind2(){
    HashTable<int> a(hash, 5);
    a.insert(5);
    TS_ASSERT(!a.find(9));
  }

  void testInsertFind3(){
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.insert(9);
    TS_ASSERT(a.find(9));
  }


  // TODO
  
};

class HashTableRemove : public CxxTest::TestSuite {
public:

  void testRm1() {
    HashTable<int> a(hash, 5);
    a.remove(5);
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testRm2() {
    HashTable<int> a(hash, 55);
		a.insert(9);
    a.remove(9);
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testRm3() {
    HashTable<int> a(hash, 5);
		a.insert(5);
		a.insert(9);
    a.remove(5);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
  void testRm4() {
    HashTable<int> a(hash, 5);
		a.insert(5);
		a.insert(9);
    a.remove(5);
    a.remove(9);
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  // TODO
};


#endif

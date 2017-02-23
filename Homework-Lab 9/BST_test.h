#ifndef BST_TEST_H
#define BST_TEST_H// - Unit Tests
#include "BST.h"
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

int compare(const int& left, const int& right){
  return left - right;
}

int compare(const string& left, const string& right){
  // The string class has a built-in compare function!
  return left.compare(right);
}

class BSTInsertSize : public CxxTest::TestSuite {
public:

  void testEmpty() {
    BST<int> a(compare);
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testInsert1() {
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  void ttestInsert2() {
    BST<int> a(compare);
    a.insert(6);
    a.insert(7);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 3);
  }
  // TODO starting with 26 tests given, need 40 for lab, 5 more for hm wk, total 45 + 26 = 71
  void testInsert3() {
    BST<int> a(compare);
    a.insert(6);
    a.insert(7);
    a.insert(5);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 4);
  }
  void testInsert4() {
    BST<int> a(compare);
    a.insert(6);
    a.insert(6);
    a.insert(7);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 4);
  }
  void testInsert5() {
    BST<int> a(compare);
    a.insert(6);
    a.insert(7);
    a.insert(7);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 4);
  }
  void testInsert6() {
    BST<int> a(compare);
    a.insert(6);
    a.insert(7);
    a.insert(7);
    a.insert(5);
    a.insert(50);
    TS_ASSERT_EQUALS(a.size(), 5);
  }
  
  void testInsert7() {
    BST<string> a(compare);
    a.insert("a");
    a.insert("b");
    a.insert("c");
    a.insert("d");
    a.insert("a");
    TS_ASSERT_EQUALS(a.size(), 5);
  }
  
};

class BSTClear : public CxxTest::TestSuite {
public: 
  void testClear2() {
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }

  // TODO
  void testClear3() {
    BST<int> a(compare);
    a.insert(5);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 2);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }

  void testClear4(){  // balanced
    BST<string> a(compare);
    a.insert("bob");
    a.insert("a");
    a.insert("car");
		a.insert("cars");
    TS_ASSERT_EQUALS(a.size(), 4);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }

  void testClear5(){  // balanced
    BST<string> a(compare);
    a.insert("bob");
    a.insert("a");
    a.insert("car");
		a.insert("cars");
    TS_ASSERT_EQUALS(a.size(), 4);
    a.clear();
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }

  void testClear6(){  // balanced
    BST<string> a(compare);
    a.insert("bob");
    a.insert("a");
    a.insert("car");
		a.insert("cars");
    TS_ASSERT_EQUALS(a.size(), 4);
    a.clear();
    a.insert("car");
    TS_ASSERT_EQUALS(a.size(), 1);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }

  void testClear7() {
    BST<int> a(compare);
    a.insert(5);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 2);
    a.clear();
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }

  void testClear8() {
    BST<int> a(compare);
    a.insert(5);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 2);
    a.clear();
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
//    a.insert("a");
//    TS_ASSERT_EQUALS(a.size(), 1);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }


};

class BSTSmallestLargest : public CxxTest::TestSuite {
public:
  void testSmallest0(){
    BST<int> a(compare);
    TS_ASSERT_THROWS_ANYTHING(a.getSmallest());
  }
  
  void testSmallest1(){
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT_EQUALS(a.getSmallest(), 5);
  }
  // TODO
  void testSmallest2(){
    BST<int> a(compare);
    a.insert(-1);
    a.insert(5);
    a.insert(55);
    a.insert(5);
    TS_ASSERT_EQUALS(a.getSmallest(), -1);
  }
   void testSmallest3(){
    BST<int> a(compare);
    a.insert(-5);
    a.insert(-5);
    a.insert(55);
    TS_ASSERT_EQUALS(a.getSmallest(), -5);
  }
   void testSmallest4(){
    BST<int> a(compare);
    a.insert(5);
		a.clear();
		a.insert(56);
		a.insert(565);
    TS_ASSERT_EQUALS(a.getSmallest(), 56);
  }

   void testSmallest5(){
    BST<string> a(compare);
    a.insert("apples");
		a.insert("a");
    TS_ASSERT_EQUALS(a.getSmallest(), "a");
  }

   void testSmallest6(){
    BST<string> a(compare);
    a.insert("apples");
		a.insert("oranges");
		a.insert("pears");
    TS_ASSERT_EQUALS(a.getSmallest(), "apples");
  }

   void testSmallest7(){
    BST<string> a(compare);
    a.insert("apples");
		a.insert("oranges");
		a.insert("pears");
		a.insert("ape");
    TS_ASSERT_EQUALS(a.getSmallest(), "ape");
  }

  void testLargest8(){
    BST<int> a(compare);
    a.insert(-1);
    a.insert(5);
    a.insert(55);
    a.insert(5);
    TS_ASSERT_EQUALS(a.getLargest(), 55);
  }
   void testLargest9(){
    BST<int> a(compare);
    a.insert(-5);
    a.insert(-5);
    a.insert(55);
    TS_ASSERT_EQUALS(a.getLargest(), 55);
  }
   void testLargest10(){
    BST<int> a(compare);
    a.insert(5);
		a.clear();
		a.insert(56);
		a.insert(565);
    TS_ASSERT_EQUALS(a.getLargest(), 565);
  }

   void testLargest11(){
    BST<string> a(compare);
    a.insert("apples");
		a.insert("a");
    TS_ASSERT_EQUALS(a.getLargest(), "apples");
  }

   void testLargest12(){
    BST<string> a(compare);
    a.insert("apples");
		a.insert("oranges");
		a.insert("pearsZZ");
    TS_ASSERT_EQUALS(a.getLargest(), "pearsZZ");
  }

   void testLargest13(){
    BST<string> a(compare);
    a.insert("apples");
		a.insert("oranges");
		a.insert("pearsZZ");
		a.insert("ape");
    TS_ASSERT_EQUALS(a.getLargest(), "pearsZZ");
  }

 };

class BSTConCopyAssign : public CxxTest::TestSuite {
public:
  // Copy Constructor
	void testCopy() {
    BST<int> a(compare);
    a.insert(5);
    BST<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
  }

  void testCopy1() {
    BST<int> a(compare);
    a.insert(5);
    BST<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    a.insert(6);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(b.size(), 1);
  }
// TODO
  void testCopy2() {
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
		a.clear();
    BST<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_EQUALS(b.size(), 0);
  }


};

class BSTFind : public CxxTest::TestSuite {
public:
  void testInsertFind0(){
    BST<int> a(compare);
    TS_ASSERT(!a.find(5));
  }

  void testInsertFind1(){
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT(a.find(5));
  }
 
  void testInsertFind7(){  // balanced
    BST<string> a(compare);
    a.insert("bob");
    a.insert("apple");
    a.insert("binge");
    TS_ASSERT(a.find("bob"));
    TS_ASSERT(a.find("apple"));
    TS_ASSERT(a.find("binge"));
    TS_ASSERT(!a.find("broad"));
  }
  // TODO

  void testInsertFind8(){  // balanced
    BST<string> a(compare);
    a.insert("bob");
    a.insert("a");
    a.insert("wigwam");
    TS_ASSERT(a.find("bob"));
    TS_ASSERT(a.find("a"));
    TS_ASSERT(a.find("wigwam"));
    TS_ASSERT(!a.find("bigbob"));
    TS_ASSERT_EQUALS(a.size(), 3);
    TS_ASSERT_EQUALS(a.isBalanced(), 1);
  }

  void testInsertFind9(){  // balanced
    BST<string> a(compare);
    a.insert("bob");
    a.insert("a");
    a.insert("car");
    TS_ASSERT(a.find("bob"));
    TS_ASSERT(a.find("a"));
    TS_ASSERT(a.find("car"));
    TS_ASSERT(!a.find("bigbob"));
    TS_ASSERT_EQUALS(a.size(), 3);
    TS_ASSERT_EQUALS(a.isFull(), 1);
  }

  void testInsertFind10(){  // balanced
    BST<string> a(compare);
    a.insert("bob");
    a.insert("apple");
    a.insert("binge");
    a.insert("big");
    a.insert("bird");
    a.insert("birdy");
    a.insert("birdys");
    TS_ASSERT(a.find("bob"));
    TS_ASSERT(a.find("apple"));
    TS_ASSERT(a.find("binge"));
    TS_ASSERT(!a.find("bigbobbobs"));
    TS_ASSERT_EQUALS(a.size(), 7);
    TS_ASSERT_EQUALS(a.isBalanced(), 0);
  }

  void testInsertFind11(){  // balanced
    BST<string> a(compare);
    a.insert("bob");
    a.insert("apple");
    a.insert("binge");
    a.insert("binge");
    a.insert("binge");
    TS_ASSERT(a.find("bob"));
    TS_ASSERT(a.find("apple"));
    TS_ASSERT(a.find("binge"));
    TS_ASSERT(!a.find("bingebinge"));
    TS_ASSERT_EQUALS(a.size(), 5);
    TS_ASSERT_EQUALS(a.isFull(), 0);
  }

  void testInsertFind12(){  // balanced
    BST<string> a(compare);
    a.insert("bob");
    a.insert("a");
    a.insert("car");
		a.insert("cars");
    TS_ASSERT(a.find("bob"));
    TS_ASSERT(a.find("a"));
    TS_ASSERT(a.find("car"));
    TS_ASSERT(a.find("cars"));
    TS_ASSERT(!a.find("bigbob"));
    TS_ASSERT_EQUALS(a.size(), 4);
    TS_ASSERT_EQUALS(a.isFull(), 0);
  }


};

class BSTGetOrders : public CxxTest::TestSuite {
public:
  
  void testInorder1(){
    BST<int> a(compare);
    a.insert(5);
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5]");
  }
  
  void testInorder2(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6,7,8]");
  }
 
   void testPostorder2(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    string out = a.getPostOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[8,7,6,5]");
  }
  // TODO
  void testInorder3(){
    BST<string> a(compare);
    a.insert("a");
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[a]");
  }
  
  void testInorder4(){
    BST<string> a(compare);
    a.insert("b");
    a.insert("c");
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[b,c]");
  }
  
  void testInorder5(){
    BST<string> a(compare);
    a.insert("b");
    a.insert("c");
    a.insert("a");
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[a,b,c]");
  }

   void testPostorder3(){
    BST<string> a(compare);
    a.insert("a");
    a.insert("b");
    a.insert("c");
    a.insert("d");
    string out = a.getPostOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[d,c,b,a]");
  }
  


};

class BSTHeight : public CxxTest::TestSuite {
public:

  void testHeight0() {
    BST<int> a(compare);
    TS_ASSERT_EQUALS(a.getHeight(), 0);
  }
  
  void testHeight1() {
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT_EQUALS(a.getHeight(), 0);
  }
  
  void testHeight2() {
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    TS_ASSERT_EQUALS(a.getHeight(), 1);
  }
  // TODO
  
  void testHeight3() {
    BST<string> a(compare);
    a.insert("b");
    a.insert("a");
    TS_ASSERT_EQUALS(a.getHeight(), 1);
  }

  void testHeight4() {
    BST<string> a(compare);
    a.insert("b");
    a.insert("a");
    a.insert("c");
    TS_ASSERT_EQUALS(a.getHeight(), 1);
  }

  void testHeight5() {
    BST<string> a(compare);
    a.insert("b");
    a.insert("a");
    a.insert("c");
    a.insert("z");
    TS_ASSERT_EQUALS(a.getHeight(), 2);
  }

  void testHeight6() {
    BST<string> a(compare);
    a.insert("b");
    a.insert("a");
    a.insert("c");
    a.insert("z");
    a.insert("a");
    TS_ASSERT_EQUALS(a.getHeight(), 2);
  }

  void testHeight7() {
    BST<string> a(compare);
    a.insert("b");
    a.insert("a");
    a.insert("c");
    a.insert("z");
    a.insert("a");
		a.clear();
    TS_ASSERT_EQUALS(a.getHeight(), 0);
  }

  void testHeight8() {
    BST<string> a(compare);
    a.insert("b");
    a.insert("a");
    a.insert("c");
    a.insert("z");
    a.insert("a");
		a.clear();
    a.insert("b");
    a.insert("a");
    a.insert("c");
    a.insert("z");
    a.insert("a");
    TS_ASSERT_EQUALS(a.getHeight(), 2);
  }

  void testHeight9() {
    BST<string> a(compare);
    a.insert("b");
    a.insert("a");
    a.insert("c");
    a.insert("z");
    a.insert("a");
		a.clear();
    a.insert("b");
    a.insert("a");
    a.insert("c");
    a.insert("z");
    a.insert("a");
    a.insert("g");
    TS_ASSERT_EQUALS(a.getHeight(), 3);
  }
  

};

class BSTFull : public CxxTest::TestSuite {
public:
  void testFull0() {
    BST<int> a(compare);
    TS_ASSERT(a.isFull());
  }
  
  void testFull1() {
    BST<int> a(compare);
    a.insert(10);
    TS_ASSERT(a.isFull());
  }
  
  void testFull2() {
    BST<int> a(compare);
    a.insert(10);
    a.insert(12);
    TS_ASSERT(!a.isFull());
  }
  
  void testFull3() {
    BST<int> a(compare);
    a.insert(10);
    a.insert(12);
    a.insert(8);
    TS_ASSERT(a.isFull());
  }
  // TODO
};

class BSTBalanced : public CxxTest::TestSuite {
public:
  void testBalanced0(){
    BST<int> a(compare);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced1(){
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced2(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(3);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced3(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(3);
    a.insert(8);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced4(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(3);
    a.insert(8);
    a.insert(4);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced5(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    TS_ASSERT(!a.isBalanced());
  }
  // TODO

  void testBalanced6(){
    BST<string> a(compare);
    a.insert("a");
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced7(){
    BST<string> a(compare);
    a.insert("b");
    a.insert("a");
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced8(){
    BST<string> a(compare);
    a.insert("b");
    a.insert("a");
    a.insert("c");
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced9(){
    BST<string> a(compare);
    a.insert("b");
    a.insert("a");
    a.insert("c");
    a.insert("d");
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced10(){
    BST<string> a(compare);
    a.insert("c");
    a.insert("d");
    a.insert("e");
    TS_ASSERT(!a.isBalanced());
  }


};

#endif

/*
	Dictionary lookup program.
	Paul Talaga
	October 2015
*/

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "HashTable.h"

using namespace std;

// Good hash function for strings
unsigned int hash(const string& thing){
  unsigned int ret = 7;
  for(unsigned int i = 0; i < thing.length(); i++){
    ret = ret * 31 * thing[i];
    // 31 is the next prime above 26
  }
  return ret;
}

HashTable<string> inputFile(char* filename){
  HashTable<string> array(hash, 200000);
  fstream file;
  file.open(filename, ios::in);
  while(file){
    string word;
    file >> word;
    array.insert(word);
  }
  file.close();
  return array;
}

void dothing(const HashTable<string>& dic, const string& word){
  for(unsigned int i = 0; i < word.length(); i++){
    for(int j = 'a'; j <= 'z'; j++){
      string newWord = word;
      newWord[i] = j;
      if(newWord != word && dic.find(newWord)){
        cout << " " << newWord;
      }
    }
  }
  for(unsigned int i = 0; i < word.length(); i++){
    string newWord = word.substr(0,i) + word.substr(i+1, word.length() - i);
    if(dic.find(newWord)){
      cout << " " << newWord;
    }
  }
  for(unsigned int i = 0; i <= word.length(); i++){
    for(int j = 'a'; j <= 'z'; j++){
      string newWord = word.substr(0,i) + " " + word.substr(i, word.length() - i + 1);
      newWord[i] = j;
      if(dic.find(newWord)){
        cout << " " << newWord;
      }
    }
  }
}


int main(int argc, char* argv[]){
  // Change me!
  // Example of how to pass a function to a function.
  // This will pass the above hash function to the class.

  if(argc != 2){
    cout << "Enter filename to find words: \n";
    return 1;
  }
  HashTable<string> dic = inputFile(argv[1]);
//  cout << "Number of words in file: " << dic.size() << endl;
  cout << "Number Loaded: " << dic.size() << endl;
  
  string word;
  while(1){
//    cout << "Enter a word to search: (or q to quit)";
    cout << "Enter word: (or q to quit)";
    cin >>word;
    if(word == "q"){
      return 0;
    }
    if(dic.find(word)){
//      cout << "The search word was found.\n";
      cout << "FOUND!\n";
    }
    else{
//      cout << "The search word was not found.\n";
      cout << "Not FOUND.\n";
    }
    cout << "Similar words: ";
    dothing(dic, word);
    cout << endl;
  }
}

/*
  HashTable<string> test(hash, 10);
  test.insert("bob");
  cout << "bob? " << test.find("bob") << endl;
  
  return 0;
}*/

/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree newTree;
  ariel::Tree rightTree; 
  ariel::Tree mixTree;
  ariel::Tree emptyTree;

  rightTree.insert(5);
  rightTree.insert(10);
  rightTree.insert(15);
  rightTree.insert(20);

  newTree.insert(10);
  newTree.insert(15);
  newTree.insert(5);
  newTree.insert(7);
  newTree.insert(12);

  mixTree.insert(100);
  mixTree.insert(200);
  mixTree.insert(150);
  mixTree.insert(60);
  mixTree.insert(40);
  mixTree.insert(30);

 


  badkan::TestCase tc("Binary tree");
  tc



  .CHECK_EQUAL (rightTree.size(), 4)
  .CHECK_OK    (rightTree.insert(25))
  .CHECK_EQUAL (rightTree.size(), 5)
  .CHECK_EQUAL (rightTree.contains(5), true)
  .CHECK_OK    (rightTree.remove(10))
  .CHECK_EQUAL (rightTree.parent(20), 15)
  .CHECK_EQUAL (rightTree.contains(10), false)
  .CHECK_OK(rightTree.remove(5))
  .CHECK_EQUAL (rightTree.size() ,3)
  
  .CHECK_THROWS (newTree.insert(10))
  .CHECK_EQUAL (newTree.right(5),7)
  .CHECK_EQUAL (newTree.left(15),12)
  .CHECK_THROWS(newTree.right(15))
  .CHECK_EQUAL (newTree.parent(15), 10)
  .CHECK_EQUAL (newTree.parent(5), 10)
  .CHECK_THROWS(newTree.insert(7))
  .CHECK_THROWS(newTree.left(5))
  

  .CHECK_THROWS (mixTree.parent(100))
  .CHECK_EQUAL (mixTree.right(100),200)
  .CHECK_THROWS (mixTree.right(200))
  .CHECK_EQUAL (mixTree.left(40),30)
  .CHECK_OK    (mixTree.remove(150))
  .CHECK_EQUAL    (mixTree.size(),5)
  .CHECK_OK    (mixTree.insert(400))
  .CHECK_EQUAL (mixTree.right(200),400)


  
  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
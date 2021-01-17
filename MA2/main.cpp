/*
Name: Gabriel Byram
Assigment: MA2
Date: October 2, 2020

Move Constructor: A move constructor is a constructor that creates an object by moving the contents
of a different object of the same class into the object being created

Move Assignment Operator: A move assignment operator allows an object's contents to be transfered
to a different of the same class by using the assignment operator (=)

Time Complexities:

What is the time complexity (Big-O) in the worst-case for the BST::empty () algorithm? 
    O(1) because it only needs to check whether the root is equal to nullptr
    This is a constant number of checks. Therefore this is O(1)

What is the time complexity (Big-O) in the worst-case for the BST::add () algorithm?
    O(n) because in the worst-case scenario, all of the BST nodes would need to be
    traversed through in order to add the new node to the BST at the end of the BST.
    This would only occur if the BST was a skew BST.

What is the time complexity (Big-O) in the worst-case for the BST::makeEmpty () algorithm?
    O(n) because makeEmpty() must traverse the BST to each node and delete each node. This
    means that the number of traversals and deletions will be equal to n,
    meaning the time complexity is O(n).

What is the time complexity (Big-O) in the worst-case for the BST::printLevelOrder () algorithm? 
    O(n) because printLevelOrder() must traverse through each node in the
    BST to print each value in each node out. This means the time complexity
    is O(n).

What is the time complexity (Big-O) in the worst-case for the BST::cloneTree () algorithm?
    O(n^2) because it must not only read in n nodes from the orignal BST
    (which has a time complexity of O(n)), but it must also traverse the
    newly cloned BST a worst-case scenario number of n times in order to
    insert each node into the correct location. This means that the time
    complexity is O(n^2).
*/

#include "BST.h"

int main(void) {
    // test destructor
    // create BST and delete it, then check to see if it is actually deleted
    BST<int>* destBST = new BST<int>;
    destBST->add(1);
    destBST->~BST();

    if (!destBST->contains(1))
        cout << "Destructor test: Passed!\n";
    else
        cout << "Destructor test: Failed!\n";
    
    // test copy constructor
    BST<int>* copyConBST1 = new BST<int>;
    copyConBST1->add(1);
    copyConBST1->add(2);
    copyConBST1->add(3);
    
    BST<int>* copyConBST2(copyConBST1);

    // see that both are the same from printing in order
    cout << "If output is the same, copy constructor test passes:\n";
    cout << "Original BST: ";
    copyConBST1->printInOrder();
    cout << endl;
    cout << "Copied BST: ";
    copyConBST2->printInOrder();
    cout << endl;

    if(copyConBST2->contains(1) && copyConBST2->contains(2) && copyConBST2->contains(3)) {
        cout << "Copy Constructor test: Passed!\n";
    }
    else
        cout << "Copy Constructor test: Failed!\n";

    // test move constructor
    BST<int>* moveConBST1 = new BST<int>;
    moveConBST1->add(1);
    moveConBST1->add(2);
    moveConBST1->add(3);
    
    BST<int>* moveConBST2 = new BST<int>;
    moveConBST2 = move(moveConBST1);

    // see that both are the same from printing in order
    cout << "Original BST: ";
    moveConBST1->printInOrder();
    cout << endl;
    cout << "Moved BST: ";
    moveConBST2->printInOrder();
    cout << endl;

    if(moveConBST2->contains(1) && moveConBST2->contains(2) && moveConBST2->contains(3))
        cout << "Move Constructor test: Passed\n!";
    else
        cout << "Move Constructor test: Failed!\n";

    // test copy assignment operator

    BST<int>* copyAssBST1 = new BST<int>;
    copyAssBST1->add(1);
    copyAssBST1->add(2);
    copyAssBST1->add(3);
    
    BST<int>* copyAssBST2 = copyAssBST1; // copy assign
    BST<int>* cum = copyAssBST1;

    cout << "Original BST: ";
    copyAssBST1->printInOrder();
    cout << endl;
    cout << "Copy Assigned BST: ";
    copyAssBST2->printInOrder();
    cout << endl;

    if(copyAssBST2->contains(1) && copyAssBST2->contains(2) && copyAssBST2->contains(3))
        cout << "Copy Assignment test: Passed!\n";
    else
        cout << "Copy Assignment test: Failed!\n";

    // move assignment operator

    BST<int>* moveAssBST1 = new BST<int>;
    moveAssBST1->add(1);
    moveAssBST1->add(2);
    moveAssBST1->add(3);
    
    BST<int>* moveAssBST2 = move(moveAssBST1); // move assign

    cout << "Original BST: ";
    moveAssBST1->printInOrder();
    cout << endl;
    cout << "Move Assigned BST: ";
    moveAssBST2->printInOrder();
    cout << endl;

    if(moveAssBST2->contains(1) && moveAssBST2->contains(2) && moveAssBST2->contains(3))
        cout << "Move Assignment test: Passed!\n";
    else
        cout << "Move Assignment test: Failed!\n";

    // test printLevelOrderHelper()
    BST<int>* printLevelBST = new BST<int>;
    printLevelBST->add(3);
    printLevelBST->add(2);
    printLevelBST->add(4);
    printLevelBST->add(1);
    printLevelBST->add(5);

    std::cout << "Print Level Order test: If expected output equals actual output, the test passes\n";
    std::cout << "Expected output: 3 2 4 1 5\n";
    std::cout << "Actual Output: ";
    printLevelBST->printLevelOrder();
}
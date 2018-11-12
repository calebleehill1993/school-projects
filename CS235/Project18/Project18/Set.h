//
//  BSTSet.hpp
//  Pokemon
//
//  Created by Victoria Black on 4/9/18.
//  Copyright © 2018 Victoria Black. All rights reserved.
//

#ifndef BSTSet_H
#define BSTSet_H

#include <stdio.h>


#include "SetInterface.h"
#include <string>
#include <sstream>
#include <ostream>
#include <iostream>
using std::string;

template<typename T>
class Set : public SetInterface<T> {
private:
    //a node that contains data and pointers to the other parts of the set
    struct Node {
        Node(T data_item){
            data = data_item;
            left = NULL;
            right = NULL;
            parent = NULL;
        }
        ~Node( ) {
        }
        T data;
        Node* left;
        Node* right;
        Node* parent;
    };
    Node* root;
    size_t size_of;
    
    // the recursive function to add a Node.
    bool findPlacement(const T value, Node* current) {
        if (current == NULL) {
            Node* myNode = new Node(value);
            root = myNode;
            return true;
        }
        if (value == current->data) {
            return false;
        }
        else if (value < (current->data)) {
            if (current->left == NULL) {
                Node* myNode = new Node(value);
                current->left = myNode;
                return true;
            }
            else {
                return findPlacement(value, current->left);
            }
        }
        else if (value > (current->data)) {
            if (current->right == NULL) {
                Node* myNode = new Node(value);
                current->right = myNode;
                return true;
            }
            else {
                return findPlacement(value, current->right);
            }
        }
        else {
            return false;
        }
    }
    
    // the rescursive function to delete a Node
    bool removeNode(const T& value, Node* checkNode, Node* parent) {
        if (checkNode == NULL) {
            return false;
        }
        else if (value < checkNode->data) {
            return removeNode(value, checkNode->left, checkNode);
        }
        else if (value > checkNode->data) {
            return removeNode(value, checkNode->right, checkNode);
        }
        else if (value == checkNode->data) {
            Node* temp = NULL;
            if ((checkNode->left == NULL) && (checkNode->right == NULL)) {
                if (parent->data > checkNode->data){
                    parent->left = NULL;
                }
                else if (parent->data < checkNode->data){
                    parent->right = NULL;
                }
                else if (parent->right != NULL && parent->right->data == value){
                    parent->right = NULL;
                }
                else if (parent->left != NULL && parent->left->data == value){
                    parent->left = NULL;
                }
                else if (parent->left == NULL && parent->right == NULL && parent == root){
                    root = NULL;
                }
                delete checkNode;
                checkNode = NULL;
                return true;
            }
            else if ((checkNode->left == NULL) && (checkNode->right != NULL)) {
                if(checkNode == root){
                    temp = root;
                    root = root->right;
                    delete temp;
                    temp = NULL;
                }
                else{
                    temp = checkNode;
                    checkNode = checkNode->right;
                    delete temp;
                    temp = NULL;
                    if (parent->data > value){
                        parent->left = checkNode;
                    }
                    else if (parent->data < value){
                        parent->right = checkNode;
                    }
                    else if (parent->right != NULL && parent->right->data == value){
                        parent->right = NULL;
                    }
                    else if (parent->left != NULL && parent->left->data == value){
                        parent->left = NULL;
                    }
                }
                return true;
            }
            else if ((checkNode->left != NULL) && (checkNode->right == NULL)) {
                if(checkNode == root){
                    temp = root;
                    root = root->left;
                    delete temp;
                    temp = NULL;
                }
                else{
                    temp =  checkNode;
                    checkNode = checkNode->left;
                    delete temp;
                    temp = NULL;
                    if (parent->data > checkNode->data){
                        parent->left = checkNode;
                    }
                    if (parent->data < checkNode->data){
                        parent->right = checkNode;
                    }
                }
                return true;
            }
            else {
                Node* temp_;
                if (checkNode->left != NULL) {
                    temp_ = checkNode->left;
                    temp = findReplacement(temp_);
                    checkNode->data = temp->data;
                    return removeNode(temp->data, temp_, checkNode);
                }
                else if (checkNode->right != NULL){
                    return removeNode(checkNode->right->data, checkNode->right, checkNode);
                }
                else {
                    return false;
                }
            }
        }
        else {
            return false;
        }
    }
    
    //recursive function to find the greatest value;
    Node* findReplacement(Node* temp) {
        if (temp->right != NULL) {
            return findReplacement(temp->right);
        }
        else {
            return temp;
        }
    }
    
    //recursive function that clears the set
    bool clearSet(Node* currentNode) {
        while (root != NULL){
            removeNode(root->data, root, root);
        }
        if (root == NULL){
            return true;
        }
        else {
            return false;
        }
    }
    
    /**checks value if not the same as the current node then checks if it is less that or greater than
     and uses that branch and calls the function again*/
    bool searchNode(const T& value, Node* checkNode) const {
        if (checkNode == NULL) {
            return false;
        }
        else if (checkNode->data == value) {
            return true;
        }
        else if (checkNode->data > value) {
            return searchNode(value, checkNode->right);
        }
        else if (checkNode->data < value) {
            return searchNode(value, checkNode->left);
        }
        else {
            return false;
        }
    }
    // calls the recursive search Node function
    T findNode(const T& value) {
        return searchNode(value, root);
    }
    
    
public:
    Set(void) {
        root = NULL;
    }
    ~Set(void) {
        clear();
    }
    
    /** Return true if node added to Set, else false */
    bool insert(const T& value) {
        if (findPlacement(value, root)) {
            size_of++;
            return true;
        }
        return false;
    }
    // takes in value and returns if it is in the set or not
    bool findValue(Node*& top, const T& datum) {
        if (top == NULL)
        {
            return false;
        }
        if (datum == top->data) {
            return true;
        }
        if (datum < top->data)
        {
            return findValue(top->left, datum);
        }
        if (datum > top->data)
        {
            return findValue(top->right, datum);
        }
        //Node* old_root = top;
        if (top->left == NULL)
        {
            top = top->right;
        }
        else if (top->right == NULL)
        {
            top = top->left;
        }
        /*else
        {
            replace_parent(old_root, old_root->left);
        }*/
        return false;
    }
    // the recursive function for the find function
    bool findChild(Node* node, const T& value) const{
        bool status = false;
        if(node->data == value){
            return true;
        }
        if(node->left != NULL){
            status = findChild(node->left, value);
            if (status == true){
                return status;
            }
        }
        if(node->right != NULL){
            status = findChild(node->right, value);
            if (status == true){
                return status;
            }
        }
        return status;
    }
    //the recursive function that is used to find a value
    bool find(const T& value) {
        bool status = false;
        if (root == NULL){
            return false;
        }
        else if (root->data == value)
        {
            return true;
        }
        if(root->left != NULL){
            status = findChild(root->left, value);
            if (status == true){
                return status;
            }
        }
        if(root->right != NULL){
            status = findChild(root->right, value);
            if (status == true){
                return status;
            }
        }
        return status;
    }
    
    /** Return true if node removed from Set, else false */
    size_t erase(const T& value) {
        if (removeNode(value, root, root)){
            size_of--;
        }
        return size_of;
    }
    
    /** clears the Set*/
    void clear() {
        if (clearSet(root)) {
            size_of = 0;
        }
    }
    
    /** @return: the number of elements contained by the Set. */
    size_t size() const {
        return size_of;
    }
    
    /** @return: return 1 if contains element equivalent to item, else 0. */
    size_t count(const T& item) const {
        if (searchNode(item, root)) {
            return 1;
        }
        else return 0;
    }
    /** to string uses this to find a node to print */
    string findLeft(Node* node, string& output) const{
        if(node->left != NULL){
            findLeft(node->left, output);
        }
        output = output + " " + node->data;
        if(node->right != NULL){
            findLeft(node->right, output);
        }
        return output;
    }
    
    /** Return a post order trav bersal of a Set as a string */
    string toString() const {
        string output;
        if (root == NULL){
            return "";
        }
        if(root->left != NULL){
            output = findLeft(root->left, output);
        }
        if (output == "") {
           output = root->data;
        }
        else {
           output = output + " " + root->data;
        }
        if(root->right != NULL){
            output = findLeft(root->right, output);
        }
        return output;
    }
    
    /** friend operator that outputs the tree*/
    friend std::ostream& operator<< (std::ostream& os, const Set<T>& bst) {
        os << bst.toString();
        return os;
    }
    
};
#endif

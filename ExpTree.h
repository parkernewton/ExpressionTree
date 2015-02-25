//
//  ExpTree.h
//  lab8
//
//  Created by parker on Feb 24, 2015.
//  Copyright (c) 2015 parker. All rights reserved.
//
#ifndef EXPTREE_H_
#define EXPTREE_H_


// INTERFACE file for ExpTree class

// The ExpTree (Expression Tree) class stores the terms of an arithmetic expression entered from the stdin,
// 		and includes functions to evaluate and print the expression.

// 		Note: Enter expressions in the following postfix format:

// 			<term 1> <space> <term 2> <space> <operator1> <space> <term 3> <space> <term 4> <space> <operator> ...

// CONSTRUCTOR for ExpTree class
// ExpTree()

// DESTRUCTOR for ExpTree class
// ~ExpTree()

// node class
// stores data of terms of expression, and pointers to left and right children

// MEMBER functions

// void build()
// Post-condition: constructs a binary tree

// void evaluate()
// Post-condition: evaluates and prints to the stdout the result of the expression

// void print_preorder()
// Post-condition: prints to the stdout the terms of the expression in a preorder manner

// void print_inorder()
// Post-condition: prints to the stdout the terms of the expression in a inorder manner

// void print_postorder()
// Post-condition: prints to the stdout the terms of the expression in a postorder manner


#include <cstdio>
#include <cstdlib>
#include <iostream>


class ExpTree{
public:
	class node {
	public:
		int data;
		node *left, *right;
	};

	ExpTree(){ this->root=NULL; };
	~ExpTree();
	void build();
	void evaluate();
	void print_preorder();
	void print_inorder();
	void print_postorder();
private:
	node *root;
};


#endif /* EXPTREE_H_ */

//
//  ExpTree.cpp
//  lab8
//
//  Created by parker on Feb 24, 2015.
//  Copyright (c) 2015 parker. All rights reserved.
//


// IMPLEMENTATION file for ExpTree class


#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include "ExpTree.h"


void post_order_delete(ExpTree::node* p_cur);
// Deletes the tree nodes in postorder
// Pre-condition: p_cur points to root of tree to delete
// Post-condition: all nodes in tree are de-allocated

void read_expression(std::stack<ExpTree::node>& s);
// Reads expression in post-fix notation from stdin into nodes which are inserted into stack ADT s
// Pre-condition: stack ADT s must be instantiated
// Post-condition: each term in the expression is inserted as a tree node into the stack

unsigned int number_of_digits(int d);
// Returns the number of digits in the int d

ExpTree::node* create_tree(ExpTree::node* p_cur, std::stack<ExpTree::node>& s);
// Builds tree with nodes in stack s
// Pre-condition: p_cur points to root of tree; s is instantiated
// Post-condition: nodes are popped from s and inserted in a postorder manner into the binary tree

int postorder_evaluate(ExpTree::node* p_cur);
// Evaluates and returns the expression read from the stdin
// Pre-condition: p_cur points to the root of the tree whose nodes contain the expression to evaluate
// Post-order: returns the value of the expression; note that due to integer division, quotients are evaluated as their floor values

void pre_order_traversal(ExpTree::node* p_cur);
// Prints the terms of the expression in a preorder manner
// Pre-condition: p_cur points to the root of the tree containing the terms of the expression
// Post-condition: the terms of the expression are printed to the stdout

void in_order_traversal(ExpTree::node* p_cur);
// Prints the terms of the expression in an inorder manner
// Pre-condition: p_cur points to the root of the tree containing the terms of the expression
// Post-condition: the terms of the expression are printed to the stdout

void post_order_traversal(ExpTree::node* p_cur);
// Prints the terms of the expression in an postorder manner
// Pre-condition: p_cur points to the root of the tree containing the terms of the expression
// Post-condition: the terms of the expression are printed to the stdout


ExpTree::~ExpTree(){
	post_order_delete(this->root);
}

void ExpTree::build(){
	std::stack<ExpTree::node> s;
	read_expression(s);
	this->root = create_tree(this->root, s);
}

void ExpTree::evaluate(){
	std::cout<<"Answer: "<<(int)postorder_evaluate(this->root)<<std::endl;
}

void ExpTree::print_preorder(){
	pre_order_traversal(this->root);
	std::cout<<std::endl;
}

void ExpTree::print_inorder(){
	in_order_traversal(this->root);
	std::cout<<std::endl;
}

void ExpTree::print_postorder(){
	post_order_traversal(this->root);
	std::cout<<std::endl;
}

void post_order_delete(ExpTree::node* p_cur){
	if(p_cur==NULL)
		return;
	post_order_delete(p_cur->left);
	post_order_delete(p_cur->right);
	delete p_cur;
}

void read_expression(std::stack<ExpTree::node>& s){
	unsigned int i = 0;
	int operand;
	char op;
	ExpTree::node *p_new;
	std::string str;

	std::cout<<"Enter the calculation in post-fix form below: "<<std::endl;
	std::getline(std::cin, str);
	while(i<std::strlen(str.c_str())){
		switch(str.c_str()[i]){
		case '+':
			op = str.c_str()[i];
			i+=sizeof(char)+1; // offset by 1 for the space
			p_new = new ExpTree::node;
			p_new->data = op;
			p_new->left = NULL;
			p_new->right = NULL;
			s.push(*p_new);
			break;
		case '-':
			op = str.c_str()[i];
			i+=sizeof(char)+1; // offset by 1 for the space
			p_new = new ExpTree::node;
			p_new->data = op;
			p_new->left = NULL;
			p_new->right = NULL;
			s.push(*p_new);
			break;
		case '*':
			op = str.c_str()[i];
			i+=sizeof(char)+1; // offset by 1 for the space
			p_new = new ExpTree::node;
			p_new->data = op;
			p_new->left = NULL;
			p_new->right = NULL;
			s.push(*p_new);
			break;
		case '/':
			op = str.c_str()[i];
			i+=sizeof(char)+1; // offset by 1 for the space
			p_new = new ExpTree::node;
			p_new->data = op;
			p_new->left = NULL;
			p_new->right = NULL;
			s.push(*p_new);
			break;
		default:
			if(str.c_str()[i]==' ')
				break;
			operand = std::atoi(&str.c_str()[i]);
			i+=number_of_digits(operand)+1;
			p_new = new ExpTree::node;
			p_new->data = operand;
			p_new->left = NULL;
			p_new->right = NULL;
			s.push(*p_new);
			break;
		}
	}
	return;
}

unsigned int number_of_digits(int d){
	unsigned int counter = 1;
	while((d=std::abs(d/10))>0){
		++counter;
	}
	return counter;
}

ExpTree::node* create_tree(ExpTree::node* p_cur, std::stack<ExpTree::node>& s){
	if(s.empty())
		return NULL;
	p_cur = &(s.top());
	s.pop();
	if((char)p_cur->data!='+' && (char)p_cur->data!='-' && (char)p_cur->data!='*' && (char)p_cur->data!='/'){
		// then our data value is an integer term of the expression, so we want to return this
		 return p_cur;
	}
	p_cur->right = create_tree(p_cur->right, s);
	p_cur->left = create_tree(p_cur->left, s);
	return p_cur;
}

int postorder_evaluate(ExpTree::node* p_cur){
	int first, second, answer;
	if(p_cur==NULL)
		return 0;
	if((char)p_cur->data!='+' && (char)p_cur->data!='-' && (char)p_cur->data!='*' && (char)p_cur->data!='/'){
		return p_cur->data;
	}
	first = postorder_evaluate(p_cur->left);
	second = postorder_evaluate(p_cur->right);

	// Perform the arithmetic operation
	char op = (char)p_cur->data;
	switch(op){
	case '+':
		answer = first + second;
		break;
	case '-':
		answer = first - second;
		break;
	case '*':
		answer = first*second;
		break;
	case '/':
		answer = first / second;
		break;
	default:
		answer = 0;
		break;
	}
	return answer;
}

void pre_order_traversal(ExpTree::node* p_cur){
	if(p_cur==NULL)
		return;
	if((char)p_cur->data=='+' || (char)p_cur->data=='-' || (char)p_cur->data=='*' || (char)p_cur->data=='/'){
		 std::cout<<(char)p_cur->data<<" ";
	}
	else{
		std::cout<<p_cur->data<<" ";
	}
	post_order_traversal(p_cur->left);
	post_order_traversal(p_cur->right);
}

void in_order_traversal(ExpTree::node* p_cur){
	if(p_cur==NULL)
		return;
	post_order_traversal(p_cur->left);
	if((char)p_cur->data=='+' || (char)p_cur->data=='-' || (char)p_cur->data=='*' || (char)p_cur->data=='/'){
		 std::cout<<(char)p_cur->data<<" ";
	}
	else{
		std::cout<<p_cur->data<<" ";
	}
	post_order_traversal(p_cur->right);
}

void post_order_traversal(ExpTree::node* p_cur){
	if(p_cur==NULL)
		return;
	post_order_traversal(p_cur->left);
	post_order_traversal(p_cur->right);
	if((char)p_cur->data=='+' || (char)p_cur->data=='-' || (char)p_cur->data=='*' || (char)p_cur->data=='/'){
		 std::cout<<(char)p_cur->data<<" ";
	}
	else{
		std::cout<<p_cur->data<<" ";
	}
}

// DRIVER function for ExpTree class
int main(){
	ExpTree t;
	t.build();
	t.print_postorder();
	t.print_preorder();
	t.print_inorder();
	t.evaluate();
	return 0;
}

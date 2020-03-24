/*
 * File Name:				decision_tree.cpp
 * Program Description:		Decision trees
 * Course Name:				Data Structures 2
 * Assignment Number:		1
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#include "decision_tree.h"

decision_tree::decision_node::decision_node() {}

decision_tree::decision_node::decision_node(string value)
	: value(value) {}

decision_tree::decision_node::decision_node(const decision_node& n) {
	value = n.value;
	for (list<answer_node*>::const_iterator i = n.answers.begin(); i != n.answers.end(); i++) {
		answers.push_back(new answer_node(**i));
	}
}

string decision_tree::decision_node::get_value() {
	return value;
}

decision_tree::decision_node* decision_tree::decision_node::find(string value) {
	if (this->value == value) {
		return this;
	}
	for (list<answer_node*>::const_iterator i = answers.begin(); i != answers.end(); i++) {
		if ((*i)->get_next()->find(value)) {
			return (*i)->get_next();
		}
	}
	return NULL;
}

void decision_tree::decision_node::add_answer(string answer, string next) {
	answers.push_back(new answer_node(answer, next));
}

void decision_tree::decision_node::print(int level) {
	cout << string(level * 3, ' ') << value << endl;
	for (list<answer_node*>::const_iterator i = answers.begin(); i != answers.end(); i++) {
		(*i)->print(level);
	}
}

bool decision_tree::decision_node::print_path(string value) {
	if (this->value == value) {
		cout << value;
		return true;
	}
	for (list<answer_node*>::const_iterator i = answers.begin(); i != answers.end(); i++) {
		if ((*i)->get_next()->print_path(value)) {
			cout << "=>" << this->value;
			return true;
		}
	}
	return false;
}

void decision_tree::decision_node::run() {
	cout << value << endl;
	if (!answers.empty()) {
		string answer;
		cin >> answer;
		for (list<answer_node*>::const_iterator i = answers.begin(); i != answers.end(); i++) {
			if ((*i)->get_answer() == answer) {
				(*i)->get_next()->run();
				return;
			}
		}
	}
}

bool decision_tree::decision_node::remove_subtree(string value) {
	for (list<answer_node*>::const_iterator i = answers.begin(); i != answers.end(); i++) {
		if ((*i)->get_next()->get_value() == value) {
			delete *i;
			answers.remove(*i);
			return true;
		}
		if ((*i)->get_next()->remove_subtree(value)) {
			return true;
		}
	}
	return false;
}

decision_tree::decision_node::~decision_node() {
	for (list<answer_node*>::const_iterator i = answers.begin(); i != answers.end(); i++) {
		delete *i;
	}
}

decision_tree::answer_node::answer_node() {}

decision_tree::answer_node::answer_node(string answer, string next)
	: answer(answer), next(new decision_node(next)) {}

decision_tree::answer_node::answer_node(const answer_node& n) {
	answer = n.answer;
	next = new decision_node(*n.next);
}

string decision_tree::answer_node::get_answer() {
	return answer;
}

decision_tree::decision_node* decision_tree::answer_node::get_next() {
	return next;
}

void decision_tree::answer_node::print(int level) {
	cout << string(level * 3, ' ') << ": " << answer << endl;
	next->print(level + 1);
}

decision_tree::answer_node::~answer_node() {
	delete next;
}

decision_tree::decision_tree() {
	root = NULL;
}

decision_tree::decision_tree(string init) {
	root = new decision_node(init);
}

decision_tree::decision_tree(const decision_tree& t) {
	root = new decision_node(*t.root);
}

decision_tree::decision_node* decision_tree::find(string question) {
	return root->find(question);
}

decision_tree& decision_tree::operator=(const decision_tree& t) {
	if (this != &t) {
		decision_node* new_root = new decision_node(*t.root);
		delete root;
		root = new_root;
	}
	return *this;
}

bool decision_tree::add_node(string question, string answer, string next) {
	decision_node* question_node = find(question);
	if (question_node == NULL) {
		return false;
	}
	question_node->add_answer(answer, next);
	return true;
}

void decision_tree::remove_subtree(string value) {
	if (root->get_value() == value) {
		delete root;
		root == NULL;
		return;
	}
	root->remove_subtree(value);
}

void decision_tree::print() {
	root->print(0);
}

void decision_tree::print_path(string value) {
	root->print_path(value);
}

void decision_tree::run() {
	root->run();
}

decision_tree::~decision_tree() {
	delete root;
}
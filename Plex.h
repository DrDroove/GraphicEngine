#pragma once
#include"BaseFigure.h"
#include"Dot.h"
#include"Line.h"

#include<stack>
#include<stdexcept>


class Plex
{
public:
	static Plex* instance;
private:
	BaseFigure* root;
	
	Plex() {
		root = nullptr;
	}
public:
	static Plex* getInstance() {
		if (instance == nullptr) {
			instance = new Plex();
		}
		return instance;
	}
	/*BaseFigure* getRoot() {
		return root;
	}*/
	
	Plex(const Plex& source) = delete;
	Plex& operator=(const Plex& source) = delete;

	BaseFigure* findLineByDot(BaseFigure* curr, BaseFigure* ref) { //finds first line that based on referenced dot
		if (curr->getType() == _Line) {
			if (((Line*)curr)->getLeft() == ref || ((Line*)curr)->getRight() == ref) {
				return curr;
			}
			BaseFigure* result = findLineByDot(((Line*)curr)->getLeft(), ref);
			if (result != NULL) { return result; }
			result = findLineByDot(((Line*)curr)->getRight(), ref);
			return result;
		}
		else if (curr->getType() == _Point) {
			return NULL;
		}
	}

	void Add(BaseFigure* what) { //always lower left is the connecting one to the upper
		if (what->getType() != _Line) {
			
			throw std::invalid_argument("Not a line");
		}
		else if (root == nullptr) {
			root = what;
			return;
		}
		BaseFigure* result = findLineByDot(root, ((Line*)what)->getLeft());
		if (result != NULL) {
			if (((Line*)what)->getLeft() == ((Line*)result)->getLeft()) {
				((Line*)result)->setLeft(what);
				return;
			}
			else {
				((Line*)result)->setRight(what);
				return;
			}
		}
		result = findLineByDot(root, ((Line*)what)->getRight());
		if (result != NULL) {
			if (((Line*)what)->getRight() == ((Line*)result)->getLeft()) {
				((Line*)what)->inverse();
				((Line*)result)->setLeft(what);
				return;
			}
			else {
				((Line*)what)->inverse();
				((Line*)result)->setRight(what);
				return;
			}
		}
		throw std::invalid_argument("The line is not connected to the others");
	}
	void traverse(BaseFigure* curr) {
		if (curr->getType() == _Line) {
			Line* smth = ((Line*)curr);
			traverse(((Line*)curr)->getLeft());
			traverse(((Line*)curr)->getRight());
			return;
		}
		else if (curr->getType() == _Point) {
			return;
		}
	}

	void traverseAll() {
		traverse(root);
	}
};

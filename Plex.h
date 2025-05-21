#pragma once
#include"BaseFigure.h"
#include"Dot.h"
#include"Line.h"
#include<stack>
ref class Plex
{
private:
	BaseFigure* root;
public:
	Plex() {
		root = nullptr;
	}
	Plex(const Plex^ source) {
		std::stack<BaseFigure*> Ls;
		std::stack<BaseFigure*> copies;
		Ls.push(nullptr);
		Dot* duplicates[1000];
		BaseFigure* curr = source->root;
		while (curr != nullptr) {
			switch (curr->getType()) {
			case _Point:
				if (curr->getRating() > 1) {
					//searchByName ? p = dupl[l]&push : new p & push & dupl[n] = p
				}
				Dot* p = new Dot(*(Dot*)curr);
				copies.push(p);
				break;
			case _Line:
				switch (curr->getRating()) {
				case 1:
					Ls.push(curr);
					curr->changeRating();
					curr = ((Line*)curr)->getLeft();
					break;
				case 2:
					curr = ((Line*)curr)->getRight();
					curr->changeRating();
					break;
				case 3:
					BaseFigure * right = copies.top(); copies.pop();
					BaseFigure* left = copies.top(); copies.pop();
					Line* p = new Line(*(Line*)curr);
					p->setLeft((Dot*)left);
					p->setRight((Dot*)right);
					copies.push(p);
					curr->changeRating();
					curr = Ls.top();
					Ls.pop();
					break;
				}
				break;
			}
			root = copies.top();
		}

	}
	Plex^ operator=(const Plex^ source) {
		delete root;
		Plex tmp(source);
		root = tmp.root;
		delete tmp.root;
		return this;
	}
	~Plex() {
		std::stack<BaseFigure*> Ls;
		Ls.push(nullptr);
		BaseFigure* curr = root;
		while (curr) {
			switch (curr->getType()) {
			case _Point:
				if (curr->getRating() > 1) {
					curr->changeRating(-1);
					curr = Ls.top(); Ls.pop();
				}
				else {
					BaseFigure* p = curr;
					delete p;
					curr = Ls.top(); Ls.pop();
				}
				break;
			default:
				curr->changeRating();
				switch (curr->getRating()) {
				case 1:
					Ls.push(curr);
					curr = ((Line*)curr)->getLeft();
					break;
				case 2:
					Ls.push(curr);
					curr = ((Line*)curr)->getRight();
					break;
				case 3:
					BaseFigure * p = curr;
					delete p;
					curr = Ls.top(); Ls.pop();
					break;
				}
			}
		}
	}
	Dot* searchByName(std::string name) {
		std::stack<BaseFigure*> Ls;
		Ls.push(nullptr);
		Dot* res = nullptr;
		BaseFigure* curr = root;
		while (curr) {
			switch (curr->getType()){
			case _Point:
				if (curr->getName() == name) {
					return (Dot*)curr;
				}
			}
		}
	}
	//Line* searchByName(std::string name);
	Dot* searchByPlace(int x, int y) {

	}
	//void connect(Dot* whem, Line* what) {

	//}
	////Line* searchByPlace(int x, int y);
	//void add(BaseFigure* source) {
	//	if (!root) {
	//		root = source;
	//		return;
	//	}
	//	Dot* left = searchByName((((Line*)source)->getLeft()->getName()));
	//	Dot* right = searchByName((((Line*)source)->getRight()->getName()));
	//	if (left&&!right) {
	//		connect(left, (Line*)source);
	//	}
	//	else if (left && right) {
	//		((Line*)source)->inverse(); connect(right, (Line*)source);
	//	}
	//	return;
	//}
};

#pragma once
#include"BaseFigure.h"
#include"Dot.h"
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

			}
		}

	}
};


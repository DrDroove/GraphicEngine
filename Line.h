//
//  Line.hpp
//  GraphicEngine
//
//  Created by Dmitriy on 10.04.2025.
//

#ifndef Line_hpp
#define Line_hpp

#include <stdio.h>
#include<string>
#include "BaseFigure.h"
#include "Dot.h"

class Line:protected BaseFigure{
protected:
    BaseFigure* left;
    BaseFigure* right;
public:
    Line(Dot* left, Dot* right){
        name = left->getName() + " " + right->getName();
        color = 0;
        boldness = 5;
        radius = 2*boldness;
        isVisible = true;
        rating = 0;
        this->left = left;
        this->right = right;
    }
    Line(const Line& tmp){
        left = nullptr;
        right = nullptr;//and all other fields copied
    }
    void inverse(){
        name = right->getName() + " " +left->getName();
        std::swap(left, right);
    }
    void changerating(){
        rating = (rating+1)%3;
    }
    int getrating(){
        return ++rating;
    }
    Line& operator=(const Line& source){
        return *this;
    }
    
};

#endif /* Line_hpp */

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
#include<stdio>

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
        rating = (rating + 1) % 3;
    }
    int getrating(){
        return ++rating;
    }
    Line& operator=(const Line& source){
        return *this;
    }
    bool inArea(int x, int y) {
        int ax = ((Dot*)left)->getX();
        int ay = ((Dot*)left)->getY();
        int bx = ((Dot*)right)->getX();
        int by = ((Dot*)right)->getY();
        int a = std::sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
        int lengthA = std::sqrt((ax - x) * (ax - x) + (ay - y) * (ay - y));
        int lengthB = std::sqrt((bx - x) * (bx - x) + (by - y) * (by - y));
        int halfPerimetr = (a + lengthA + lengthB) / 2;
        int h = (2 * std::sqrt(halfPerimetr * (halfPerimetr - a) * (halfPerimetr - lengthA) * (halfPerimetr - lengthB)));
    }
    //преобразование в строку и обратно как в точке
    
    
};

#endif Line_hpp 

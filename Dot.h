//
//  Dot.hpp
//  GraphicEngine
//
//  Created by Dmitriy on 10.04.2025.
//

#ifndef Dot_hpp
#define Dot_hpp
#include "BaseFigure.h"
#include "strToWords.h"

inline std::string boolToString(bool a){
    return a ? "true":"false";
}
inline bool stringToBool(std::string source) {
    return source == "true" ? true : false;
}

#include <stdio.h>
#include <string>
using std::stoi;

class Dot:public BaseFigure{
private:
    int x, y;
public:
    Dot(std::string name, int x, int y, int radius = 12) : BaseFigure(_Point, name, radius) {
        this->x = x;
        this->y = y;
    }
    void Draw(System::Drawing::Graphics^ g) override
    {
        if (isVisible == false) return;
        int tmp = color;
        System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(255,0,255));
        g->FillEllipse(brush, x, y, boldness, boldness);
    }
    bool inArea(int x, int y){
        if((this->x - x)*(this->x - x) + (this->y - y)*(this->y - y) <= std::pow(boldness/2, 2)){
            return true;
        }
        return false;
    }
    void move(int dx, int dy){
        x+=dx;
        y+=dy;
    }
    std::string to_string(){
        std::string res = "d";
        res = res + " "+ std::to_string(x) + " "+ std::to_string(y) + " "+ std::to_string(boldness) + " "+ std::to_string(color) + " "+ std::to_string(rating) + " "+ boolToString(isVisible);
        return res;
    }
    Dot(std::string source){
        std::string words[12];
        int k;

        stringToWords(source, words, k);

        type = _Point;
        name = words[1];
        x = stoi(words[2]);
        y = stoi(words[3]);
        isVisible = stringToBool(words[4]);
        radius = stoi(words[5]);
        boldness = stoi(words[6]);
        color = stoi(words[7]);
        rating = stoi(words[8]);
    }
    void IncRating(int dr) override{
        if(dr==1){
            rating++;
        }else if(dr==-1){
            rating--;
        }else{
            throw std::exception();
        }
    }
    bool IsFigure(int _x, int _y) override
    {
        auto sqr = [](int x) ->long long
            {
                return (long long)x * x;
            };
        if (sqr(_x - x) + sqr(_y - y) <= sqr(radius)) return 1;
        return 0;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    int getWidth() {
        return boldness;
    }
};
#endif /* Dot_hpp */

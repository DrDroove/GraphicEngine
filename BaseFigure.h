#pragma once

#include <iostream>
#include <string>

enum TypeElem { _Point, _Line, _Rectangle, _Curve };

class BaseFigure
{
protected:
    TypeElem type;
    std::string name;
    bool isVisible;
    int color;
    int radius;
    int boldness;
    int rating;
public:
    BaseFigure(TypeElem _type = _Point, std::string _name = "", int _radius = 12, bool _isVisible = true,
        int _color = 0, int _boldness = 6, int _rating = 1)
    {
        type = _type;
        name = _name;
        radius = _radius;
        isVisible = _isVisible;
        color = _color;
        boldness = _boldness;
        rating = _rating;
    }

    virtual ~BaseFigure() {}

    BaseFigure(const BaseFigure& tmp)
    {
        type = tmp.type;
        name = tmp.name;
        radius = tmp.radius;
        isVisible = tmp.isVisible;
        color = tmp.color;
        boldness = tmp.boldness;
        rating = tmp.rating;
    }

    TypeElem getType()
    {
        return type;
    }
    bool getisVisible()
    {
        return isVisible;
    }
    int getboldness()
    {
        return boldness;
    }
    int getRadius()
    {
        return radius;
    }
    int getRating()
    {
        return rating;
    }
    std::string getName() const
    {
        return name;
    }
    int getColor()
    {
        return color;
    }
    /*virtual int getX() = 0;
    virtual int getY() = 0;*/

    void setType(TypeElem _type)
    {
        type = _type;
    }
    void setColor(int _color)
    {
        color = _color;
    }
    void setRating(int _rating)
    {
        rating = _rating;
    }
    void setName(const std::string& _name)
    {
        name = _name;
    }
    void setboldness(int _boldness)
    {
        boldness = _boldness;
    }
    void setisVisible(bool _isVisible)
    {
        isVisible = _isVisible;
    }
    virtual void changeRating(int value = 1)
    {
        if (value > 0)
            rating++;
        else
            rating--;
    }
    virtual void IncRating(int dr) = 0;
    virtual void Draw(System::Drawing::Graphics^ g) = 0;
    virtual bool IsFigure(int _x, int _y) = 0;
    virtual std::string to_string() = 0;
};


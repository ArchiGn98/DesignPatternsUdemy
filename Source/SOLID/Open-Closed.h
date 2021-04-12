//
// Created by artig on 25.01.2019.
//

#ifndef DESIGNPATTERNS_OPEN_CLOSED_H
#define DESIGNPATTERNS_OPEN_CLOSED_H

#include <string>
#include <vector>
#include <initializer_list>
using namespace std;

enum class Color{ red, green, blue };
enum class Size{ small, medium, large };

struct Product
{
    string name;
    Color color;
    Size size;
};

struct ProductFilter
{
    vector<Product*> by_color(vector<Product*> items, Color color)
    {
        vector<Product*> result;
        for(auto &i : items)
        {
            if(i->color == color)
            {
                result.push_back(i);
            }
        }
        return result;
    }

    vector<Product*> by_size(vector<Product*> items, Size size)
    {
        vector<Product*> result;
        for(auto &i : items)
        {
            if(i->size == size)
            {
                result.push_back(i);
            }
        }
        return result;
    }

    vector<Product*> by_size_and_color(vector<Product*> items, Color color, Size size)
    {
        vector<Product*> result;
        for(auto &i : items)
        {
            if(i->color == color && i->size == size)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

template <class T> struct Specification
{
    virtual bool is_satisfied(T* item) = 0;
};

template<class T> struct Filter
{
    virtual vector<T*> filter(vector<T*> items,
                              Specification<T> &spec) = 0;
};

struct BetterFilter : Filter<Product>
{
    vector<Product*> filter(vector<Product*> items, Specification<Product> &spec) override
    {
        vector<Product*> result;

        for(auto &item : items)
            if(spec.is_satisfied(item))
                result.push_back(item);

        return  result;
    }
};

struct ColorSpecification : Specification<Product>
{
    Color color;

    explicit ColorSpecification(Color color) : color{color}
    {
    }

    bool is_satisfied(Product *item) override
    {
        return item->color == this->color;
    }
};

template <class T> struct AndSpecification : Specification<T>
{
    Specification<T> &first;
    Specification<T> &second;

    AndSpecification(Specification<T> &first, Specification<T> &second) : first{first}, second{second}
    {
    }

    bool is_satisfied(T *item) override
    {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};

struct SizeSpecification : Specification<Product>
{
    Size size;
    explicit SizeSpecification(const Size size) : size{size}
    {
    }

    bool is_satisfied(Product* item) override
    {
        return item->size == this->size;
    }
};
#endif //DESIGNPATTERNS_OPEN_CLOSED_H

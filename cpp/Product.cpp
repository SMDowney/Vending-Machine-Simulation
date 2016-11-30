/*
 * Scott Downey
 * scott.m.downey@gmail.com
 * C/C++ Programming III : Intermediate Programming with Objects, 114426, Raymond Mitchell III
 * Product.cpp
 * Windows 10
 * Visual Studio Community 2015
 *
 * This source code defines the class 'Product'
 *
 */

#include <cstring>
using std::strcpy;

#include "Product.h"

//constructor for Product class
Project1::Product::Product(const char *brand, const char *name,
    const char *size)
{
    strcpy_s(this->brand, brand);
    strcpy_s(this->name, name);
    strcpy_s(this->size, size);
}

//accessor for brand member
const char *
Project1::Product::getBrand() const
{
    return (const char *)Project1::Product::brand;
}

//mutator for brand member
void
Project1::Product::setBrand(const char *value)
{
    strcpy_s(brand, value);
}

//accessor for name member
const char *
Project1::Product::getName() const
{
    return (const char *)Project1::Product::name;
}

//accessor for name member
void
Project1::Product::setName(const char *value)
{
    strcpy_s(name, value);
}

//accessor for size member
const char *
Project1::Product::getSize() const
{
    return (const char *)Project1::Product::size;
}

//accessor for size member
void
Project1::Product::setSize(const char *value)
{
    strcpy_s(size, value);
}

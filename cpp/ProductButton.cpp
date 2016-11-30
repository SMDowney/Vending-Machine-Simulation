/*
 * Scott Downey
 * scott.m.downey@gmail.com
 * C/C++ Programming III : Intermediate Programming with Objects, 114426, Raymond Mitchell III
 * ProductButton.cpp
 * Windows 10
 * Visual Studio Community 2015
 *
 * This source code defines the class 'ProductButton'
 *
 */

#include <cstring>
using std::strcpy;

#include "ProductButton.h"

//constructor for ProductButton class
Project1::ProductButton::ProductButton(ProductRack &productRack)
    : productRack(productRack) {}

//function to return the desired product (from product rack)
bool
Project1::ProductButton::press()
{
    if (productRack.deliverProduct())
        return true;
    else
        return false;
}

//function returns price of product (in cents)
unsigned
Project1::ProductButton::getProductPriceCents() const
{
    return productRack.getProductPriceCents();
}

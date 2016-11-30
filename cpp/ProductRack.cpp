/*
 * Scott Downey
 * scott.m.downey@gmail.com
 * C/C++ Programming III : Intermediate Programming with Objects, 114426, Raymond Mitchell III
 * ProductRack.cpp
 * Windows 10
 * Visual Studio Community 2015
 *
 * This source code defines the class 'ProductRack'
 *
 */

#include <cstring>
using std::strcmp;

#include "ProductRack.h"

//constructor for ProductRack class
Project1::ProductRack::ProductRack(
    StatusPanel &statusPanel,
    const char *allowedProductName,
    DeliveryChute &deliveryChute,
    unsigned productPriceCents)
    : statusPanel(statusPanel),
        deliveryChute(deliveryChute),
        productCount(0),
        productPriceCents(productPriceCents)
{
    strcpy_s(this->allowedProductName, allowedProductName);
}

//destructor for ProductRack class
Project1::ProductRack::~ProductRack()
{
    //loop through products array and destroy each product
    for (int product = 0; product < productCount; ++product)
        delete products[product];
}

//function to determine if product name is compatible with instance of rack
bool
Project1::ProductRack::isCompatibleProduct(const char *productName) const
{
    //if strings don't match, return false.  Otherwise, return true
    if (strcmp(productName, allowedProductName))
        return false;
    else
        return true;
}

//function to determine whether product rack is full
bool
Project1::ProductRack::isFull() const
{
    return productCount == MAX_PRODUCTS;
}

//function to determine whether product rack is empty
bool
Project1::ProductRack::isEmpty() const
{
    return !productCount;
}

//function to add product to product rack
bool
Project1::ProductRack::addProduct(Product* pProduct)
{
    //return false if rack is full or name of product doesn't match rack's allowed names, otherwise
    //add the product to the rack
    if (isFull()) {
        statusPanel.displayMessage(Project1::StatusPanel::MESSAGECODE_RACK_IS_FULL);
        return false;
    }
    else if (!isCompatibleProduct((*pProduct).getName())) {
        statusPanel.displayMessage(Project1::StatusPanel::MESSAGECODE_PRODUCT_DOES_NOT_MATCH_PRODUCT_RACK);
        return false;
    }
    else {
        products[productCount++] = pProduct;
        return true;
    }
}

//function to deliver product to the delivery chute
bool
Project1::ProductRack::deliverProduct()
{
    //if there aren't any products in the rack, display 'sold-out' error and return false
    if (!productCount) {
        statusPanel.displayMessage(Project1::StatusPanel::MESSAGECODE_SOLD_OUT);
        return false;
    }

    //if function 'insertProduct' returns true, remove product from rack and add to chute
    if (deliveryChute.insertProduct(products[--productCount]))
        return true;
    else {
        //have to re-increment product count if above statement fails
        ++productCount;
        return false;
    }
}

//function to return the count of products in the rack
unsigned
Project1::ProductRack::getNumProductsInRack() const
{
    return productCount;
}

//function to return the price (in cents) set for the products in the rack
unsigned
Project1::ProductRack::getProductPriceCents() const
{
    return productPriceCents;
}

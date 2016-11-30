/*
 * Scott Downey
 * scott.m.downey@gmail.com
 * C/C++ Programming III : Intermediate Programming with Objects, 114426, Raymond Mitchell III
 * DeliveryChute.cpp
 * Windows 10
 * Visual Studio Community 2015
 *
 * This source code defines the class 'DeliveryChute'
 *
 */

 #include "DeliveryChute.h"

//constructor for DeliveryChute
Project1::DeliveryChute::DeliveryChute(StatusPanel &statusPanel)
    : statusPanel(statusPanel),
      pProduct(0) {}

//destructor for DeliveryChute class
Project1::DeliveryChute::~DeliveryChute()
{
    delete pProduct;
}

//function to insert product into chute
bool
Project1::DeliveryChute::insertProduct(Product *pProduct)
{
    //if chute is currently full, display status message and return false.
    //otherwise, insert product and return true
    if (containsProduct()) {
       statusPanel.displayMessage(Project1::StatusPanel::MESSAGECODE_CHUTE_FULL);
        return false;
    }
    else {
        this->pProduct = pProduct;
        return true;
    }
}

//remove product from chute and return
Project1::Product *
Project1::DeliveryChute::retrieveProduct()
{
    Product *tempProduct = pProduct;
    pProduct = 0;
    return tempProduct;
}

//check if product is in chute
bool
Project1::DeliveryChute::containsProduct() const
{
    return (pProduct != 0);
}

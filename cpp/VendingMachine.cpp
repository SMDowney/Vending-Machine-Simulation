/*
 * Scott Downey
 * scott.m.downey@gmail.com
 * C/C++ Programming III : Intermediate Programming with Objects, 114426, Raymond Mitchell III
 * VendingMachine.cpp
 * Windows 10
 * Visual Studio Community 2015
 *
 * This source code defines the class 'VendingMachine'
 *
 */

#include "VendingMachine.h"

//constructor for VendingMaching class
Project1::VendingMachine::VendingMachine(
    ostream &statusPanelStream,
    const char *productNames[NUM_PRODUCT_RACKS],
    unsigned productPrices[NUM_PRODUCT_RACKS])
    : statusPanel(statusPanelStream),
        deliveryChute(statusPanel),
        numCoins(0),
        unspentMoneyCents(0)
{
    //initialize product racks and product buttons into arrays for vending machine
    for (int currentRack = 0; currentRack < NUM_PRODUCT_RACKS; ++currentRack) {
        productRacks[currentRack] = new ProductRack(statusPanel, productNames[currentRack], deliveryChute, productPrices[currentRack]);
        productButtons[currentRack] = new ProductButton(*productRacks[currentRack]);
    }
}

//destructor for VendingMachine
Project1::VendingMachine::~VendingMachine()
{
    //delete all coins in coinBox
    for (int coin = 0; coin < numCoins; ++coin)
        delete coinBox[coin];

    //delete all racks and buttons in their respective arrays
    for (int rack = 0; rack < NUM_PRODUCT_RACKS; ++rack) {
        delete productRacks[rack];
        delete productButtons[rack];
    }
}

//function to insert a coin into the vending machine
bool
Project1::VendingMachine::insertCoin(Coin *pCoin)
{
    //if the coin is not valid, display error and return false
    if ((*pCoin).getValueCents() == Project1::Coin::COINTYPE_WOODEN_NICKEL) {
        statusPanel.displayMessage(Project1::StatusPanel::MESSAGECODE_BAD_COIN);
        return false;
    }
    //otherwise, add the coin to the coinbox and add value as unspent money
    else {
        unspentMoneyCents += (*pCoin).getValueCents();
        coinBox[numCoins++] = pCoin;
        return true;
    }
}

//function to press the button on the vending machine to get a product
bool
Project1::VendingMachine::pressButton(int button)
{
    //if an invalid button is chosen, display error message and return false
    if (button >= NUM_PRODUCT_RACKS || button < 0) {
        statusPanel.displayMessage(Project1::StatusPanel::MESSAGECODE_WRONG_BUTTON);
        return false;
    }
    //if there isn't enough unspent money currently in machine, display error and return false
    else if (unspentMoneyCents < (*productRacks[button]).getProductPriceCents()) {
        statusPanel.displayMessage(Project1::StatusPanel::MESSAGECODE_INSUFFICIENT_MONEY);
        return false;
    }
    //otherwise, execute button press and remove the price of product from unspent money
    else {
        if ((*productButtons[button]).press()) {
            unspentMoneyCents -= (*productRacks[button]).getProductPriceCents();
            return true;
        }
        else
            return false;
    }
}

//function to retrieve a product from the delivery chute
Project1::Product *
Project1::VendingMachine::retrieveProduct()
{
    return deliveryChute.retrieveProduct();
}

//function to add a product to the vending machine
bool
Project1::VendingMachine::addProduct(Product *pProduct)
{
    //check each product rack to make sure the product name matches
    for (int product = 0; product < NUM_PRODUCT_RACKS; ++product) {

        //if product name matches, add the product to the rack
        if ((*productRacks[product]).isCompatibleProduct((*pProduct).getName()))
            return ((*productRacks[product]).addProduct(pProduct));
    }
    //if the product name doesn't match any rack, display error message and return false
    statusPanel.displayMessage(Project1::StatusPanel::MESSAGECODE_NO_RACK_FOR_PRODUCT);
    return false;
}

//function to return the number of products with given name (passed as argument)
unsigned
Project1::VendingMachine::getProductCount(const char *productName) const
{
    int totalProducts = 0;

    //check eas product rack for the matching name
    for (int rack = 0; rack < NUM_PRODUCT_RACKS; ++rack)

        //if the name matches, return the number of products currently in the rack
        if ((*productRacks[rack]).isCompatibleProduct(productName))
            return (*productRacks[rack]).getNumProductsInRack();

    return 0;
}

//function to get the total value of coins currently in the machine's coin box
unsigned
Project1::VendingMachine::countTill() const
{
    int coinSum = 0;

    //iterate through each coin entered into the coin box and sum of their value
    for (int count = 0; count < numCoins; ++count)
        coinSum += (*coinBox[count]).getValueCents();

    return coinSum;
}

//function to return the number of coins in the coin box
unsigned
Project1::VendingMachine::getNumCoinsInCoinBox() const
{
    return numCoins;
}

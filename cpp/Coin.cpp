/*
 * Scott Downey
 * scott.m.downey@gmail.com
 * C/C++ Programming III : Intermediate Programming with Objects, 114426, Raymond Mitchell III
 * Coin.cpp
 * Windows 10
 * Visual Studio Community 2015
 *
 * This source code defines the class 'Coin'
 *
 */

#include "Coin.h"

//constructor for Coin class
Project1::Coin::Coin(CoinType denomination)
    : denomination(denomination) {}

//returns denomination
Project1::Coin::CoinType
Project1::Coin::getDenomination() const
{
    return denomination;
}

//returns value of denomination
unsigned
Project1::Coin::getValueCents() const
{
    return denomination;
}

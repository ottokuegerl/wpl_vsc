#include "wpl.h"

int WPL::constructorCallCount = 0; // Initialize the static member

WPL::WPL(const std::string &text, int price)
{
    this->Text = text;
    this->price = price;
    ++constructorCallCount;
    std::cout << "constructor called " << constructorCallCount << std::endl;
}

// Getter for text property
std::string WPL::getText() const
{
    return Text;
}

// Setter for Text property
void WPL::setText(const std::string &newText)
{
    Text = newText;
}

// Getter for price property
int WPL::getPrice() const
{
    return price;
}

// Setter for price property
void WPL::setPrice(int newPrice)
{
    price = newPrice;
}


void DEF::Study()
{
    std::cout << " ---> Hello from class DEF <---" << std::endl;
}

void GHI::Study()
{
    std::cout << " ---> Hello from class GHI <---" << std::endl;
}

void JKL::Study()
{
    std::cout << " ---> Hello from class JKL <---" << std::endl;
}
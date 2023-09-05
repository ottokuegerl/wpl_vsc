#pragma once // Include guard to prevent multiple inclusions

#include <iostream>
#include <string>

class WPL
{
private:
    static int constructorCallCount; // Static member to track constructor calls
    std::string Text;
    int price;

public:
    // constructor
    WPL(const std::string &text, int price);

    // Getter for Text property
    std::string getText() const;

    // Setter for Text property
    void setText(const std::string &newText);

    // Getter for price property
    int getPrice() const;

    // Setter for price property
    void setPrice(int newPrice);
};

// abstract class ABC
// it is not able to create an instance from an sabstract class
class ABC
{
public:
    std::string Name;
    int Age;
    char Gender;
    virtual void Study() = 0;
};

class DEF : public ABC
{
    void Study();
};

class GHI : public ABC
{
    void Study();
};

class JKL : public ABC
{
    void Study();
};

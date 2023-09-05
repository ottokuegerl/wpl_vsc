#include <iostream>
#include <string>
// The use of std::vector simplifies memory management.
// There's no need to manually allocate and deallocate memory
// for each object and the array itself
#include <vector>
#include <cstdlib> // Include this for rand() and srand()
#include <ctime>   // Include this for seeding srand()
#include "wpl.h"

int main()
{
    // Seed the random number generator
    // der Zufallszahlengenerator wird mit der aktuellen Zeit initialiiert,
    // dies stellt sicher, dass die in nachfolgenden Aufrufen generierten Zufallszahlen
    // bei jedem Programmstart unterschiedlich sind
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    WPL item("Sample text", 100); // Creating an instance of WPL
    std::cout << "Text: " << item.getText() << std::endl;
    std::cout << "Price: " << item.getPrice() << std::endl;

    const int arraySize = 2000000;
    std::vector<WPL> wplArray;
    wplArray.reserve(arraySize); // allocate memory for the array of WPL objects

    // Dynamically allocate memory for the array of WPL objects
    // WPL **wplArray = new WPL *[arraySize];

    // Initialize each object individually
    for (int i = 0; i < arraySize; ++i)
    {
        // wplArray[i] = new WPL("Item " + std::to_string(i + 1), (i + 1) * 100);
        wplArray.emplace_back("Item " + std::to_string(i + 1), (i + 1) * 100);
        // Die Methode emplace_back von std::vector konstruiert die WPL-Objekte direkt
        // an Ort und Stelle
    }

    // Accessing properties of the first and last objects in the array using pointers
    WPL *wplZeiger = wplArray.data();
    std::cout << "Erstes Objekt - Text: " << wplZeiger->getText() << ", Preis: " << wplZeiger->getPrice() << std::endl;
    std::cout << "Letztes Objekt - Text: " << (wplZeiger + arraySize - 1)->getText() << ", Preis: " << (wplZeiger + arraySize - 1)->getPrice() << std::endl;

    // std::cout << "First object - Text: " << wplArray[0]->getText() << ", Price: " << wplArray[0]->getPrice() << std::endl;
    // std::cout << "First object - Text: " << wplArray.front().getText() << ", Price: " << wplArray.front().getPrice() << std::endl;
    // std::cout << "Last object - Text: " << wplArray[arraySize - 1]->getText() << ", Price: " << wplArray[arraySize - 1]->getPrice() << std::endl;
    // std::cout << "Last object - Text: " << wplArray.back().getText() << ", Price: " << wplArray.back().getPrice() << std::endl;

    // Adding 123 to the price of each item in the array and
    // Adding a random character to the text of each item in the array
    /*
    for (int i = 0; i < arraySize; ++i)
    {
        int currentPrice = wplArray[i]->getPrice();
        wplArray[i]->setPrice(currentPrice + 123);
        char randomChar = static_cast<char>('A' + std::rand() % 26); // Generates a random uppercase letter
        wplArray[i]->setText(wplArray[i]->getText() + randomChar);
    }
    */

    for (auto &wplItem : wplArray)
    {
        int currentPrice = wplItem.getPrice();
        wplItem.setPrice(currentPrice + 123);
        char randomChar = static_cast<char>('A' + std::rand() % 26);
        wplItem.setText(wplItem.getText() + randomChar);
    }

    // Accessing properties of the first and last objects in the array using pointers
    // std::cout << "First object - Text: " << wplArray[0]->getText() << ", Price: " << wplArray[0]->getPrice() << std::endl;
    // std::cout << "Last object - Text: " << wplArray[arraySize - 1]->getText() << ", Price: " << wplArray[arraySize - 1]->getPrice() << std::endl;
    std::cout << "First object - Text: " << wplArray.front().getText() << ", Price: " << wplArray.front().getPrice() << std::endl;
    std::cout << "Last object - Text: " << wplArray.back().getText() << ", Price: " << wplArray.back().getPrice() << std::endl;

    // Cleanup
    //
    // The use of std::vector simplifies memory management.
    // There's no need to manually allocate and deallocate memory
    // for each object and the array itself
    //
    // Loop through the array of pointers and delete each individual WPL object pointed to by the pointers
    /*
    for (int i = 0; i < arraySize; ++i)
    {
        delete wplArray[i];
    }

    // After you've deleted all individual objects, you can delete the array of pointers itself
    delete[] wplArray;
*/

    /*
        ABC *students[3];
        students[0] = new DEF();
        students[1] = new GHI();
        students[2] = new JKL();

        for (int i = 0; i <= 2; i++)
        {
            students[i]->Study();
        }

    for (int i = 0; i <= 2; i++)
        {
            delete students[i];
        }
    */

    std::vector<ABC *> students;
    students.reserve(3 * arraySize); // allocate memory for ABC* pointers
    
      // Initialize each object individually
    for (int i = 0; i < arraySize; ++i)
    {     
        students.push_back(new DEF());
        students.push_back(new GHI());
        students.push_back(new JKL());
    }

    for (ABC *student : students)
    {
        student->Study();
    }

    for (ABC *student : students)
    {
        delete student;
    }

    // Optionally, you can clear the vector after deleting the objects
    students.clear();

    return 0;
}

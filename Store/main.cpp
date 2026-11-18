#include <iostream>
#include <vector>
#include <iomanip>
#include "product.h"
#include <algorithm>

void showProducts(const std::vector<Product>& products) {
    for (size_t i = 0; i < products.size(); i++) {
        std::cout << i + 1 << ". "
            << std::left << std::setw(10) << products[i].name
            << std::fixed << std::setprecision(2) << products[i].price << " EUR"
            << "   quantity: " << products[i].quantity << "\n";
    }
}

int main() {
    std::vector<Product> products = {
        { "Milk", 1.20, 30 },
        { "Bread", 0.95, 15 },
        { "Cheese", 4.50, 8 }
    };

    std::sort(products.begin(), products.end(),
        [](const Product& a, const Product& b) {
            return a.name < b.name;
        });

    int choice = -1;
    while (choice != 0) {
        std::cout << "\n=== Store ===\n";
        std::cout << "1. Show products\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            showProducts(products);
            break;
        case 0:
            std::cout << "Bye!\n";
            break;
        default:
            std::cout << "Unknown option.\n";
        }
    }
    return 0;
}

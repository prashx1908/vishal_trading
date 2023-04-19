#include <iostream>
using namespace std;

class Stock {
  private:
    string name;
    int quantity;
    double price;
  
  public:
    // Constructor
    Stock(string n, int q, double p) {
      name = n;
      quantity = q;
      price = p;
    }
    
    // Getters
    string getName() {
      return name;
    }
    
    int getQuantity() {
      return quantity;
    }
    
    double getPrice() {
      return price;
    }
    
    // Setters
    void setName(string n) {
      name = n;
    }
    
    void setQuantity(int q) {
      quantity = q;
    }
    
    void setPrice(double p) {
      price = p;
    }
    
    // Buy stock
    void buyStock(int q, double p) {
      quantity += q;
      price = (price * quantity + p * q) / (quantity + q);
    }
    
    // Sell stock
    void sellStock(int q, double p) {
      if (quantity >= q) {
        quantity -= q;
        price = (price * quantity - p * q) / (quantity - q);
      } else {
        cout << "Not enough stock to sell." << endl;
      }
    }
};

int main() {
  // Create a stock object
  Stock apple("AAPL", 100, 135.60);
  
  // Buy 50 shares at $140
  apple.buyStock(50, 140);
  
  // Sell 75 shares at $130
  apple.sellStock(75, 130);
  
  // Display stock info
  cout << "Stock Name: " << apple.getName() << endl;
  cout << "Quantity: " << apple.getQuantity() << endl;
  cout << "Price: $" << apple.getPrice() << endl;
  
  return 0;
}

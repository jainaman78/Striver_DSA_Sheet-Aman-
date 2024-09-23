/*
    O stands for open/close Principle that means open for extention but close for modifictation 
    example 
    Imagine you have a class called PaymentProcessor that processes payments for an online store. Initially, 
    the PaymentProcessor class only supports processing payments using credit cards. However, 
    you want to extend its functionality to also support processing payments using PayPal.
    Instead of modifying the existing PaymentProcessor class to add PayPal support, 
    you can create a new class called PayPalPaymentProcessor that extends the PaymentProcessor class. 
    This way, the PaymentProcessor class remains closed for modification but open for extension, adhering to the Open-Closed Principle
*/

class Shape {
public:
  virtual double area() = 0;
};

class Rectangle : public Shape {
private:
  double width;
  double height;
public:
  Rectangle(double width, double height);
  double area() override;
};

class Circle : public Shape {
private:
  double radius;
public:
  Circle(double radius);
  double area() override;
};

class Triangle : public Shape {
private:
  double base;
  double height;
public:
  Triangle(double base, double height);
  double area() override;
};
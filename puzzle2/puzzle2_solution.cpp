#include <iostream>

class Foo;
Foo* foo();
class Bar;
Bar* bar();

class Foo
{
  public:
    Foo()
    {
        text = "Hello from foo!";
        std::cout<<"Foo constructor"<<std::endl;
    }
    void hello()
    {
        std::cout<<text<<std::endl; 
    };
  private:
    std::string text;
};

class Bar
{
  public:
      Bar()
      {
          std::cout<<"Bar constructor"<<std::endl;
          foo()->hello();
      }
      void hello()
      {
          std::cout<<"Hello from bar!"<<std::endl;
      }
};

Foo* foo()
{
    static Foo staticFoo;
    return &staticFoo;
}

Bar* bar()
{
    static Bar staticBar;
    return &staticBar;
}

int main(void)
{
    std::cout<<"Main entry"<<std::endl;
    foo()->hello();
    std::cout<<"Main exit"<<std::endl; 
    return 0;
}

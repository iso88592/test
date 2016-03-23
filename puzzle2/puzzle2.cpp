#include <iostream>

class Foo;
extern Foo* foo;
class Bar;
extern Bar* bar;

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
          foo->hello();
      }
      void hello()
      {
          std::cout<<"Hello from bar!"<<std::endl;
      }
};

Bar* bar = new Bar();
Foo* foo = new Foo();

int main(void)
{
    std::cout<<"Main entry"<<std::endl;
    foo->hello();
    std::cout<<"Main exit"<<std::endl; 
    return 0;
}

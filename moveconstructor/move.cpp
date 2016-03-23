#include <iostream>
#include <string>
#include <cstring>

class Movable
{
  public:
    Movable()
    {
        data = new int[64];
        std::cout << "Default constructor" << std::endl;
    }
    Movable(const Movable& other)
    {
        data = new int[64];
        memcpy(other.data, data, 64* sizeof(int));
        std::cout << "Copy constructor" << std::endl;
    }
    Movable(Movable&& other): data(std::move(other.data))
    {
        other.data = 0;
        std::cout << "Move constructor" << std::endl;
    }
    ~Movable()
    {
        delete[] data;
        std::cout << "Destructor" << std::endl;
    }
    int& operator()(int idx)
    {
        if ((idx < 0) || (idx >= 64)) 
        {
            throw new MovableException("Index out of bounds");
        }
        return data[idx];
    }
    int operator()(int idx) const
    {
        if ((idx < 0) || (idx >= 64)) 
        {
            throw new MovableException("Index out of bounds");
        }
        return data[idx];
    }
    bool hasData() const
    {
        return data != 0;
    }
    class MovableException
    {
      public:
        MovableException(std::string reason):reasonM(reason)
        {
        }
        std::string getReason() const
        {
          return reasonM;
        }
      private:
        std::string reasonM;
    };
  private:
    int* data;
};
#define T std::cout<< " TRACE: " << __FILE__ << ":" << __LINE__ << " -> ";
int main(void)
{
    T Movable a;
    T Movable b = a;
    T Movable c = std::move(b);
    std::cout<< "a has data = "<<a.hasData()<<std::endl;
    std::cout<< "b has data = "<<b.hasData()<<std::endl;
    std::cout<< "c has data = "<<c.hasData()<<std::endl;
    return 0;
}

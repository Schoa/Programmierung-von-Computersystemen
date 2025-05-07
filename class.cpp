#include <iostream>

static int Queue = 0;

class Pet
{
    private:
        std::string address;
        std::string phonenumber;
        float owner;
    public:
        void queuePosition()
        {
            Queue ++;
            std::cout << "Queueing Position: " << Queue << std::endl;
        }

        void dissease(std::string)
        {
            
        }
};
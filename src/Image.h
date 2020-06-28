//Development put on hold

#ifndef IMAGE_H_
#define IMAGE_H_
#include <vector>

class image
{
    public:
    image();
    ~image();
    void initialize();
    //Make parse a separate function to future threadings
    virtual void parse();

    std::vector<uint8_t> red;
    std::vector<uint8_t> green;
    std::vector<uint8_t> blue;

    private:
    virtual void extractHeader();
    virtual void verify();

};

#endif
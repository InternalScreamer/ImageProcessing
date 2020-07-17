//Development put on hold

#ifndef IMAGE_H_
#define IMAGE_H_
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
class image
{
    public:
    image(string file, unsigned int id);
    ~image();
    void initialize();
    //Make parse a separate function to future threadings
    void parse();

    //variables
    vector<uint8_t> red;
    vector<uint8_t> green;
    vector<uint8_t> blue;
    vector<uint8_t> alpha;
    vector<uint8_t> gray;
    string filename;
    
    uint32_t id;
    uint32_t width;
    uint32_t height;
    
    uint8_t mode;
    
    private:
    void extractHeader();
    vector<uint8_t> populateFromFile(int offset, int size);
};

#endif
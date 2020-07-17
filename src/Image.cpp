#include "Image.h"

image::image(string file, unsigned int id):
filename(file),
id(id)
{
    extractHeader();
}

//Need to research destructor best practices
image::~image()
{
}

//create enums or a constants file to eliminate magic numbers
//maybe better to do this in a single file read
void image::parse()
{
    int blockSize = height*width;
    if(mode == 0)
    {
        populateFromFile(17, blockSize, gray);
    }
    if(mode >= 1)
    {
        populateFromFile(17, blockSize, red);
        populateFromFile(17 + blockSize, blockSize, green);
        populateFromFile(17 + 2 * blockSize, blockSize, blue);
    }
    if(mode == 2)
    {
        populateFromFile(17+ 3*height*width, height*width, alpha);
    }
}

//private functions
void image::extractHeader()
{
    vector<uint8_t> memBlock;
    populateFromFile(0, 17, memBlock);
    cout<<memBlock.size()<<endl;
    if(static_cast<int>(memBlock[0]) == 0x12 && static_cast<int>(memBlock[1]) == 0x34)
    {
        mode = static_cast<uint8_t>(memBlock[2]);
        width = byte_convert(memBlock.begin() + 3, memBlock.begin() + 7);
        height = byte_convert(memBlock.begin() + 7, memBlock.begin() + 11);
    }
    else
    {
        cout<<"could not read sync pattern"<<endl;
    }
}

void image::populateFromFile(int offset, int size, vector<uint8_t>& out)
{
    ifstream file (filename, ios::binary);
    char* memBlock;
    if (file.is_open())
    {
        memBlock = new char[size];
        file.seekg(offset, ios::beg);
        file.read(memBlock, size);
        file.close();
        out.assign(memBlock, memBlock + size);
    }
    else 
    {
        cout << "Unable to open file: "<<filename<<endl;
        return;
    }
}

//May possibly move this to a utilities file
uint32_t image::byte_convert(vector<uint8_t>::iterator start, vector<uint8_t>::iterator end)
{
    uint32_t out = *start;
    for(vector<uint8_t>::iterator it = start+1; it != end; ++it)
    {
        out = out << 8;
        out += static_cast<uint32_t>(*it);
    }
    return out;
}
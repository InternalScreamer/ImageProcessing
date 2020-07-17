#include "Image.h"

image::image(string file, unsigned int id):
filename(file),
id(id)
{
    extractHeader();
}
image::~image()
{
}


//private functions
void image::extractHeader()
{
    ifstream file (filename, ios::binary);
    char* memBlock;
    if (file.is_open())
    {
        //Add a constants file to remove magic nums
        static const int HEADER_SIZE = 17;
        memBlock = new char[HEADER_SIZE]; 
        file.seekg(0, ios::beg);
        file.read(memBlock, HEADER_SIZE);
        file.close();
    }
    else 
    {
        cout << "Unable to open file: "<<filename<<endl;
        return;
    }
    if(static_cast<int>(memBlock[0]) == 0x12 && static_cast<int>(memBlock[1]) == 0x34)
    {
        mode = static_cast<uint8_t>(memBlock[2]);
        width = (static_cast<uint32_t>(memBlock[3]) << 24) +
               (static_cast<uint32_t>(memBlock[4])<< 16) + 
               (static_cast<uint32_t>(memBlock[5])<< 8)  + 
               (static_cast<uint32_t>(memBlock[6]));
        height = (static_cast<uint32_t>(memBlock[7]) << 24) +
               (static_cast<uint32_t>(memBlock[8])<< 16) + 
               (static_cast<uint32_t>(memBlock[9])<< 8)  + 
               (static_cast<uint32_t>(memBlock[10]));
    }
    else{
        cout<<"could not read sync pattern"<<endl;
    }
}

void image::parse()
{
    char* memGray;
    char* memRed;
    char* memGreen;
    char* memBlue;
    char* memAlpha;
    ifstream file (filename, ios::binary);
    if (file.is_open())
    {
        if(mode == 0)
        {
            memGray = new char[height*width];
            file.seekg(17 + height*width, ios::beg);
            file.read(memGray, height*width);
            gray.reserve(height*width);
            gray.assign(memGray, memGray+height*width);
        }
        
        if(mode >= 1)
        {
            memRed = new char[height*width];
            memGreen = new char[height*width];
            memBlue = new char[height*width];
            //memAlpha = new char[height*width];
            file.seekg(17 + height*width, ios::beg);
            file.read(memRed, height*width);
            red.assign(memGray, memGray+height*width);
            file.seekg(height*width, ios::cur);
            file.read(memGreen, height*width);
            green.assign(memGreen, memGreen+height*width);
            file.seekg(height*width, ios::cur);
            file.read(memBlue, height*width);
            blue.assign(memBlue, memBlue+height*width);
        }
        if(mode == 2)
        {

        }
        
    }
    else
    {
        return;
    }
    if(mode == 0)
    {
        
    }
    else if(mode == 1)
    {

    }

}

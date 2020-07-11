#include "../src/image.h"

using namespace std;

int main()
{
    string file = "ReformattedImages/testImage5";
    image* test_image = new image(file, 0);
    cout<< test_image->height<<endl;
    cout<< test_image->width<<endl;
    
    return 0;
}
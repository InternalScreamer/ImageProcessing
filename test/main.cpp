#include "../src/Image.h"

using namespace std;

int main()
{
    string file = "test/ReformattedImages/testImage5";
    image* test_image = new image(file, 0);
    cout<< test_image->height<<endl;
    cout<< test_image->width<<endl;
    cout<< static_cast<int>(test_image->mode)<<endl;
    test_image->parse();
    cout<<test_image->red.size()<<endl;
    delete test_image;
    return 0;
}
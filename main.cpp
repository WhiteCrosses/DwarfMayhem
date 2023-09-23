#include <iostream>

using namespace std;




//class of pixel (x,y,ptr to object in this place)
class pixel{
    public:
        int x;
        int y;
        pixel *ptr;
};

int main() {
    pixel pixelarray[100];
    for(int x=0;x<10;x++){
        for(int y=0;y<10;y++){
            pixelarray[x].x=x;
            pixelarray[x].y=y;
        }
    }

    cout<< "Hello World!";
    return 0;
}


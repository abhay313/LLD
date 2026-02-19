#include<bits/stdc++.h> 
using namespace std;

/*
Use case:
    Authenticate
    Login, Premium, Validation etc

*/

class IImage {
    public:
        virtual void display() = 0;
        virtual ~IImage() = default;
};

class RealImage: public IImage {
    private:
        string filename;
    public:
        RealImage(string file){
            filename = file;
            // Heavy ops
            cout << "[Real Image] Loading from disk: " << filename << endl;
        }

        void display(){
            cout << "[Real Image] Displaying: " << filename << endl;
        }
};

class ImageProxy: public IImage {
    private:
        RealImage *realImage;
        string filename;
    public:
        ImageProxy(string file){
            filename = file;
            realImage = nullptr;
        }

        void display() override{
            // lazy initializtion
            if(realImage == nullptr){
                realImage = new RealImage(filename);
            }
            realImage->display();
        }
};

int main(){
    IImage *image = new ImageProxy("sample.jpg");
    image->display();
    return 0;
}
/*
Design Pattern Bridge. 


*/
// implementation hierarchy
class PixelImplementation{
public:
    virtual void Draw() = 0;
};

class ColoredPixelImp : public PixelImplementation{
public:
    virtual void Draw(){};

};

// interface hierarchy
class Pixel{
public:
    virtual void Draw() = 0;
protected:
    PixelImplementation* pPixel;

};

class ColoredPixel: public Pixel{
public:
    ColoredPixel(int x, int y){
        pPixel = new ColoredPixelImp;
    }
    void Draw(){
        pPixel->Draw();
    }
};

int main(){
    ColoredPixel pixel(30, 120);
    pixel.Draw();


}
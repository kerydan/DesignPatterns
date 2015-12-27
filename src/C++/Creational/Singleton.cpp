class Singleton{
private:
    Singleton(){};
    static Singleton* pInst;
public:
    static Singleton* GetInstance();
};

Singleton* Singleton::pInst = nullptr;
Singleton* Singleton::GetInstance(){ 
    if (!pInst) {
        pInst = new Singleton;
    }
    return pInst;

}


int main()
{
   // Singleton Singleton1; // error, constructor is private

    Singleton* pSingleton = Singleton::GetInstance();  // new instance of Singleton created
    Singleton* pSingleton1 = Singleton::GetInstance(); // returns pointer to the same previously created Singleton object

    return 0;
}
// Design Pattern Adapter
class OldClass{
public:
    void OpenInOldStyle(){};
    void CloseInOldStyle(){};

};

class NewClass{
public:
    void Open(){};
    void Close(){};

};

class AdoptedClass : public NewClass, private OldClass{
public:
    void Open(){ OpenInOldStyle(); };
    void Close(){ CloseInOldStyle(); };

};


int main(){

    AdoptedClass adopted;
    adopted.Open(); // now old class works with new class interface Open() and Close()
    adopted.Close();

    // adopted.OpenInOldStyle();  // error, old style functions cannot be called anymore
    // adopted.CloseInOldStyle(); // error
}
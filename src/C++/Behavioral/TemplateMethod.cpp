class BaseFile{
public:
    void Open(){};
    void Close(){};
    // these 2 methods require implementation in inhereted concrete classes
    virtual void ReadHeader() = 0;
    virtual void ReadBody() = 0;

    // Template method describing sceleton of algorithm
    bool Read(){
        Open();
        ReadHeader();
        ReadBody();
        Close();
        return true;
    }

};

class PdfFile :public BaseFile{
    virtual void ReadHeader(){
        // Open Pdf header
    }
    virtual void ReadBody(){
        // Read Pdf file body
    }


};

int main(){
    PdfFile pdfFile;
    pdfFile.Read();
}
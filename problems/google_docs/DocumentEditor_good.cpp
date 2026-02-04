#include<bits/stdc++.h> 
using namespace std;

class DocumentElement {
    public:
        virtual string render() = 0;
};

class TextElement: public DocumentElement {
    private:
        string text; 
    public:
        TextElement(string text){
            this->text = text;
        }
        string render() override{
            return text;
        }
};

class ImageElement: public DocumentElement {
    private:
        string imagePath;
    public:
        ImageElement(string imagePath){
            this->imagePath = imagePath;
        }

        string render() override {
            return "[Image: " + imagePath + " ]";
        }
};

class NewLineElement: public DocumentElement {
    public:
        string render() override {
            return "\n";
        }
};

class TabElement: public DocumentElement {
    public:
        string render() override {
            return "\t";
        }
};

class Document {
    private:
        vector<DocumentElement*> documentElements;
    public:
        void addElement(DocumentElement *element){
            documentElements.push_back(element);
        }

        string render(){
            string result;
            for(auto a: documentElements){
                result += a->render();
            }
            return result;
        }
};

class Persistance {
    public:
        virtual void save(string data) = 0;
};

class FileStorage: public Persistance {
    public:
        void save(string data) override {
            ofstream file("document.txt");
            if(file.is_open()){
                file << data;
                file.close();
                cout << "Document save to document.txt" << endl;
            }else{
                cout << "Error: unable to open file and writing" << endl;
            }
        }
};

class DBStorage: public Persistance {
    public:
        void save(string data){
            cout << "Saving to DB: " + data << endl;
        }
};

class DocumentEditor {
    private:
        Document *document;
        Persistance *storage;
        string renderedDocument;
    
    public:
        DocumentEditor(Document *d, Persistance *p){
            this->document = d;
            this->storage = p;
        }

        void addText(string text){
            document->addElement(new TextElement(text));
        }

        void addImage(string imagePath){
            document->addElement(new ImageElement(imagePath));
        }

        void addNewLine(){
            document->addElement(new NewLineElement());
        }

        void addTabSpace(){
            document->addElement(new TabElement());
        }

        string renderDocument(){
            if(renderedDocument.empty()){
                renderedDocument = document->render();
            }
            return renderedDocument;
        }

        void saveDocument(){
            storage->save(renderDocument());
        }
};

int main(){

    Document *document = new Document();
    Persistance *persistance = new FileStorage();
    
    DocumentEditor *editor = new DocumentEditor(document, persistance);

    editor->addText("Hello");
    editor->addNewLine();
    editor->addImage("abhay.jpg");
    editor->addNewLine();
    editor->addText("This is new");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("john tab");

    cout << editor->renderDocument() << endl;
    
    editor->saveDocument();

    return 0;
}
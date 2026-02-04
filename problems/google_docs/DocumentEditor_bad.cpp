#include<bits/stdc++.h> 
using namespace std;

class DocumentEditor {
    private:
        vector<string> documentElements;
        string renderedDocument;
    public:
        void addText(string text){
            documentElements.push_back(text);
        }

        void addImage(string path){
            documentElements.push_back(path);
        }

        string renderDocument(){
            if(renderedDocument.empty()){
                string result;
                for(auto element: documentElements){
                    int n = element.size();
                    if(n > 4 && (element.substr(n - 4) == ".jpg" || element.substr(n - 4) == ".png")){
                        result += "[Image: " + element + " ] \n";
                    }else{
                        result += element + "\n";
                    }
                }
                renderedDocument = result;
            }
            return renderedDocument;
        }

        void saveToFile(){
            ofstream file("document.txt");
            if(file.is_open()){
                file << renderedDocument;
                file.close();
                cout << "Document save to document.txt" << endl;
            }else{
                cout << "Error: unable to open file and writing" << endl;
            }
        }
};

int main(){
    DocumentEditor editor;
    editor.addText("Hello");
    editor.addImage("photo.jpg");
    editor.addText("Abhay");

    cout << editor.renderDocument() << endl;
     editor.saveToFile();
    return 0;
}
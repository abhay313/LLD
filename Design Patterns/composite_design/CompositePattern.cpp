#include<bits/stdc++.h>
using namespace std;

/*
Use Cases:

Tree like structure

1. File System
2. Frontend Dropdown like file -> save, save as, preferences etc 

*/
class FileSystemItem {
    public:
        virtual ~FileSystemItem(){}
        virtual void ls(int indent = 0) = 0;
        virtual void openAll(int indent = 0) = 0;
        virtual int getSize() = 0;
        virtual FileSystemItem* cd(const string& name) = 0;
        virtual string getName() = 0;
        virtual bool isFolder() = 0;
};

class File: public FileSystemItem {
    private:
        string name;
        int size;
    public:
        File(string n, int s) {
            name = n;
            size = s;
        }

        void ls(int indent = 0) override{
            cout << string(indent, ' ') << name << endl;
        }
       
        void openAll(int indent = 0) override{
            cout << string(indent, ' ') << name << endl;
        }

        int getSize() {
            return size;
        }

        FileSystemItem* cd(const string& name){
            return nullptr;
        }

        string getName(){
            return name;
        }

        bool isFolder() {
            return false;
        }
};

class Folder: public FileSystemItem {
    private:
        string name;
        vector<FileSystemItem*> children;
    public:
        Folder(const string &n){
            name = n;
        }
        ~Folder(){
            for(auto &ch: children){
                delete ch;
            }
        }

        void add(FileSystemItem *it){
            children.push_back(it);
        }

        void ls(int indent = 0) override{
            for(auto &child: children){
                if(child->isFolder()){
                    cout << string(indent, ' ') + "+ " + child->getName() << endl;
                }else{
                    cout << string(indent, ' ') + child->getName() << endl;
                }
            }
        }

        void openAll(int indent = 0)override {
            cout << string(indent, ' ') << "+ " << name << endl;
            for(auto &ch: children){
                ch->openAll(indent + 4);
            }
        }

        int getSize() {
            int total = 0;
            for(auto &child: children){
                total += child->getSize();
            }
            return total;
        }

        FileSystemItem *cd(const string &target) override {
            for(auto &child: children){
                if(child->isFolder() && child->getName() == target){
                    return child;
                }
            }
            return nullptr;
        }

        string getName() override{
            return name;
        }

        bool isFolder() override{
            return true;
        }       
};

int main() {

    Folder *root = new Folder("root");
    root->add(new File("file1.txt", 1));
    root->add(new File("file2.txt", 1));
    
    Folder *docs = new Folder("docs");
    docs->add(new File("resume.txt", 1));
    docs->add(new File("sign.txt", 1));
    root->add(docs);
    
    Folder *images = new Folder("images");
    images->add(new File("photo.jpg", 1));

    root->add(images);

    
    
    //root->openAll();
    //root->ls();

    //docs->ls();

    FileSystemItem *cwd = root->cd("docs");

    if(cwd != nullptr){
        cwd->ls();
    }else{
        cout << "Could not found directory" << endl;
    }

    cout << root->getSize() << endl;

    delete root;
    return 0;
}
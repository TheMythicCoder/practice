#include <iostream>
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

int main() {
    XMLDocument doc;

    if (doc.LoadFile("data.xml") != XML_SUCCESS) {
        cout << "Error loading XML file!" << endl;
        return 1;
    }

    XMLElement* root = doc.RootElement();

    if (root == nullptr) {
        cout << "No root element found!" << endl;
        return 1;
    }

    cout << "Root: " << root->Name() << endl;

    for (XMLElement* elem = root->FirstChildElement();
         elem != nullptr;
         elem = elem->NextSiblingElement()) {

        cout << "Element: " << elem->Name() << endl;

        if (elem->GetText())
            cout << "Value: " << elem->GetText() << endl;
    }

    return 0;
}
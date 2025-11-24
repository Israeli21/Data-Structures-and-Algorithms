// SuperText: September 17, 2024
#include <iostream>
#include <string>
using namespace std;

struct node{
    string data;
    node* next;
};

class Headers{
    private:
        node* head;
    public:
        Headers() { head = nullptr; };
        void insertatEnd(string value){
            node* temp = new node();
            temp -> data = value;
            temp -> next = nullptr;

            if(head == nullptr){
                head = temp;
                return;
            }
            node* cu = head;
            while(cu -> next != nullptr){
                cu = cu -> next;
            }
            cu -> next = temp;
        }
        void supertext(){           
            node* cu = head;
            while(cu != nullptr){
                string dashes = "// -------------------------------------------------------------------------";
                string header = cu -> data;
                int size = header.size();
                for(int i = 0; size != 0; i++){
                    dashes[i + 3] = header[i];
                    size--;
                }
                cout << dashes << endl << endl << endl << endl;
                cu = cu -> next;
            }
        }
};

int main(){
    string input;
    cout << "Enter Header: ";
    getline(cin, input);
    input = input + " ";
    
    Headers headers;
    headers.insertatEnd(input);

    char y;
    cout << "More Headers? (press 'y'): ";
    cin >> y;
    cin.ignore();
    while(y == 'y'){
        cout << "\nEnter Header: ";
        getline(cin, input);
        input = input + " ";
        headers.insertatEnd(input);
        cout << "More Headers? (press 'y'): ";
        cin >> y;
        cin.ignore();
    }
    cout << "\nCopy all Outputs: " << endl;
    headers.supertext();

    return 0;
}
#include <iostream>
#include <string>

int main();

class List{
private:
    struct packet{
        std::string word;
        int position;
        packet* next;
    };

    packet* head;
    packet* temp;
    packet* current;

public:
    List();
    ~List();
    void AddPacket(std::string word, int position);
    void readList();
};

List::List(){
    temp = nullptr;
    current = nullptr;
    packet* lastPacket = new packet;
    lastPacket->word = "/0";
    lastPacket->next = nullptr;
    head = lastPacket;
}

List::~List(){

}

void List::AddPacket(std::string word, int position){
    packet* newp = new packet;
    newp->word = word;
    newp->position = position;
    current = head;
    temp = head;

    if((current-> word =="/0") || (current->position > position) ){
        newp->next = head;
        head = newp;
    }else{
        while((current->position < position) && (current->word !="/0")){
            temp = current;
            current = current-> next;
        }
        temp->next = newp;
        newp->next = current;
    }    
}

void List::readList(){
    current = head;
    while(current->word != "/0"){
        std::cout<< current->word << " " <<current->position <<std::endl;
        current = current->next;
    }
}


int main(){
    std::string sentence;
    List newStream;
    newStream.AddPacket("how", 2);
    newStream.AddPacket("Hello", 1);
    newStream.AddPacket("you", 4);
    newStream.AddPacket("are", 3);
    newStream.readList();
    return 0;
}
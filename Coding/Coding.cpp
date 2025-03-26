#include <iostream>
#include <string>
using namespace std;

struct MusicPlayer
{
    string musicName = "";
    double Duration = 0.0;
    string genre = "";
    string artistName = "";
    int id = 0;
};

struct Node
{
    Node* next = nullptr;

    MusicPlayer musicPlayer;
};

void InputData(string instructions, string&data) {
    cout << instructions;
    getline(cin, data);
}

void InputData(string instructions, double& data) {
    cout << instructions;
    cin >> data;
    data = data / 60;
}

MusicPlayer Directions(int& counter) {
    MusicPlayer musicPlayer;
    cin.ignore();
    InputData("Name of Music: ", musicPlayer.musicName);
    InputData("Duration of the music in Seconds: ", musicPlayer.Duration);
    cin.ignore();
    InputData("Genre of Music: ", musicPlayer.genre);
    InputData("Name of the Artist: ", musicPlayer.artistName);
    musicPlayer.id = counter;
    return musicPlayer;
};


void CreateNode(Node*& head, Node*& tail, int& counter) {
    Node* temp = new Node;
    if (head == nullptr)
    {
        temp->musicPlayer = Directions(counter);

        head = temp;
        tail = temp;

        cout << "Music Added";
    }

    else
    {
        temp->musicPlayer = Directions(counter);

        tail->next = temp;
        tail = temp;
    }
    counter++;
}

void TraverseList(Node*& head, Node*& curr) {
    int counter = 1;
    curr = head;

    if (head)
    {
        while (curr != nullptr) 
        {
            cout << counter << ". " << curr->musicPlayer.musicName << "|| Duration: " << curr->musicPlayer.Duration << " mins" << endl;;
            counter++;
            curr = curr->next;
        }
    }
    else
    {
        cout << "No list has been created yet.";
        return;
    }
}

int MainMenu(int& choice) {
    cout << "What would you like to do?" << endl << "[1] Add Music" << endl << "[2] View music" << endl << "[0] Exit" << endl << ":: ";
    cin >> choice;
    return choice;
}
void SearchNode(Node* head, int& musicDecision) {
    MusicPlayer musicPlayer;
    Node* curr = head;

    cout << "Which music would you like to view?" << endl << "[0]exit" << endl << ":: ";
    cin >> musicDecision;
    musicDecision = musicDecision - 1;
    if (head)
    {
        while (curr)
        {
            if (curr->musicPlayer.id == musicDecision)
            {
                cout << curr->musicPlayer.musicName << "|| Duration: " << curr->musicPlayer.Duration << " Mins || Genre: " << curr->musicPlayer.genre << "|| Artist: " << curr->musicPlayer.artistName << endl;
                break;
            }
            else if (curr)
            {
                curr = curr->next;
            }
            if (curr == nullptr)
            {
                cout << "This music does not exist";
            }
        }
    }
}


int main()
{
    int counter = 0;
    int choice = 0, musicDecision = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* curr = nullptr;


    do
    {
        MainMenu(choice);
        if (1 == choice)
        {
            CreateNode(head, tail, counter);

        }
        else if (2 == choice)
        {
            TraverseList(head, curr);

            if (head != nullptr)
            {
                SearchNode(head, musicDecision);
            }
           
        }
        else if (0 == choice)
        {
            return 0;
        }

        system("pause");
        system("cls");
    } while (true);
}


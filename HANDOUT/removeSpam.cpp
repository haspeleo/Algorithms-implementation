#include <iostream>
#include <vector>

using namespace std;

struct eMailMsg {
    string to;
    string from;
    string message;
    string subject;
    int date;
    int time;
};


void fillEmailStructure(vector<eMailMsg> &emails) {

    int nbMails;
    string to, from, message, subject;
    int date, time;

    cout <<"How many emails ?"<<endl;
    cin >> nbMails;

    for(int i = 0; i < nbMails; i++) {
        cout <<"Enter informations for mail N° "<<i<<endl;
        cout <<"To: "<<endl;

        cin >> to;
        emails[i].to = to;
        cin >> from;
        emails[i].from = from;
        cin >> message;
        emails[i].message = message;
        cin >> subject;
        emails[i].subject = subject;
        cin >> date;
        emails[i].date = date;
        cin >> time;
        emails[i].time = time;
    }
}

void printStructure(vector<eMailMsg> emails) {

    for(int i = 0; i < emails.size(); i++) {

       cout <<emails[i].to<<endl; 
       cout <<emails[i].from<<endl; 
       cout <<emails[i].message<<endl; 
       cout <<emails[i].subject<<endl; 
       cout <<emails[i].date<<endl; 
       cout <<emails[i].time<<endl; 
    }


}

vector<eMailMsg> removeSpam(vector<eMailMsg> emails) {

    vector<eMailMsg> clean_mail;

    for(int i = 0; i < emails.size(); i++) {
        if(emails[i].subject != "SPAM") {
            clean_mail.push_back(emails[i]);
        }
    }

    return clean_mail;
}

int main() {

    vector<eMailMsg> emails;
    vector<eMailMsg> clean_mail;
    
    fillEmailStructure(emails);

    printStructure(emails);
    
    clean_mail = removeSpam(emails);
    
    printStructure(clean_mail);

return 0;
}

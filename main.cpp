#include <iostream>
#include <map>
#include <string>
#include <algorithm>  // For transform function
#include <cctype>     // For tolower function

using namespace std;

class PasswordManager {
private:
    map<string, pair<string, string> >passwords;

public:
    void addPassword(const string& website, const string& username, const string& password) {
        passwords[website] = make_pair(username, password);
    }

  string getPassword(const string& website) {
    map<string, pair<string, string> >::iterator it = passwords.find(website);
    if (it != passwords.end()) {
        string username = it->second.first;
        string password = it->second.second;
        return "Username: " + username + ", Password: " + password;
    } else {
        return "Password not found.";
    }
}




    void listWebsites() {
    cout << "Websites stored in the password manager:" << endl;
    for (map<string, pair<string, string> >::const_iterator it = passwords.begin(); it != passwords.end(); ++it) {
        cout << it->first << endl;
    }
}


    static string toLower(const string& str) {
        string lowerStr = str;
        transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
        return lowerStr;
    }
};

int main() {
    PasswordManager manager;

    manager.addPassword("example.com", "user123", "securepass123");
    manager.addPassword("other-site.com", "user456", "mysecret456");

    manager.listWebsites();

    string website;
    cout << "Enter website to retrieve password: ";
    cin >> website;

    string lowerWebsite = PasswordManager::toLower(website);
    string password = manager.getPassword(lowerWebsite);
    cout << "Password: " << password << endl;

    return 0;
}

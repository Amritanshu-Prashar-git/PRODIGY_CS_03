#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

pair<string, vector<string> > passwordStrength(const string &password) {
    // Define the criteria
    bool length_criteria = password.length() >= 8;
    bool upper_criteria = false;
    bool lower_criteria = false;
    bool digit_criteria = false;
    bool special_criteria = false;

    for (size_t i = 0; i < password.length(); ++i) {
        if (isupper(password[i])) upper_criteria = true;
        else if (islower(password[i])) lower_criteria = true;
        else if (isdigit(password[i])) digit_criteria = true;
        else if (ispunct(password[i])) special_criteria = true;
    }

    // Assess the strength based on criteria
    int criteria_met = length_criteria + upper_criteria + lower_criteria + digit_criteria + special_criteria;

    // Provide feedback
    vector<string> feedback;

    if (!length_criteria) {
        feedback.push_back("Password should be at least 8 characters long.");
    }
    if (!upper_criteria) {
        feedback.push_back("Password should include at least one uppercase letter.");
    }
    if (!lower_criteria) {
        feedback.push_back("Password should include at least one lowercase letter.");
    }
    if (!digit_criteria) {
        feedback.push_back("Password should include at least one number.");
    }
    if (!special_criteria) {
        feedback.push_back("Password should include at least one special character.");
    }

    // Determine strength
    string strength;
    if (criteria_met == 5) {
        strength = "Strong";
    } else if (criteria_met >= 3) {
        strength = "Moderate";
    } else {
        strength = "Weak";
    }

    return make_pair(strength, feedback);
}

int main() {
    string password;
    cout << "Enter a password to test: ";
    getline(cin, password);

    pair<string, vector<string> > result = passwordStrength(password);
    string strength = result.first;
    vector<string> feedback = result.second;

    cout << "Password Strength: " << strength << endl;
    if (!feedback.empty()) {
        cout << "Feedback:" << endl;
        for (size_t i = 0; i < feedback.size(); ++i) {
            cout << "- " << feedback[i] << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

// Function to round a value to a specified number of decimal places
double roundTo(double value, int places) {
    if (places < 0)
        throw invalid_argument("Decimal places must be non-negative.");

    double multiplier = pow(10.0, places);
    return round(value * multiplier) / multiplier;
}

// Function to find the key (person) corresponding to a given value (debt amount)
string getKeyFromValue(const unordered_map<string, double>& details, double value) {
    for (const auto& pair : details) {
        if (pair.second == value) {
            return pair.first;
        }
    }
    return "";
}

// Function to process and settle the debts recursively
void findPath(unordered_map<string, double>& details) {
    // Find the maximum and minimum values in the details map
    auto max_iter = max_element(details.begin(), details.end(),
                                 [](const pair<string, double>& a, const pair<string, double>& b) {
                                     return a.second < b.second;
                                 });
    auto min_iter = min_element(details.begin(), details.end(),
                                 [](const pair<string, double>& a, const pair<string, double>& b) {
                                     return a.second < b.second;
                                 });

    double max_value = max_iter->second;
    double min_value = min_iter->second;

    // If the maximum and minimum values are the same, no debts remain to be settled
    if (max_value != min_value) {
        string max_key = max_iter->first;
        string min_key = min_iter->first;
        double result = max_value + min_value;
        result = roundTo(result, 1);

        // Determine who pays whom and how much
        if (result >= 0.0) {
            cout << min_key << " needs to pay " << max_key << ": " << roundTo(abs(min_value), 2) << endl;
            details.erase(max_key);
            details.erase(min_key);
            details[max_key] = result;
            details[min_key] = 0.0;
        } else {
            cout << min_key << " needs to pay " << max_key << ": " << roundTo(abs(max_value), 2) << endl;
            details.erase(max_key);
            details.erase(min_key);
            details[max_key] = 0.0;
            details[min_key] = result;
        }

        // Recursively call findPath with updated details
        findPath(details);
    }
}

int main() {
    // Initialize the debt details for each person
    unordered_map<string, double> parm = {
        {"A", -5.0},
        {"B", 25.0},
        {"C", -20.0},
        {"D", 25.0},
        {"E", -20.0},
        {"F", -5.0}
    };

    // Call the findPath function to process the debts
    findPath(parm);

    return 0;
}

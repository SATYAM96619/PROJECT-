Here’s the **C++ Readme** in the same format as your original, with the code example for the **Shortest Path or CashFlow-Algorithm-Splitwise**:

---

# Welcome to the Shortest Path or CashFlow-Algorithm-Splitwise Readme!

The idea is to use the Shortest Path algorithm where, at every step, we settle all amounts of one person and recur for the remaining n-1 persons.

# Getting Started

For example, if the following weighted directed graph represents some people and the arrows represent debts between them (Alice owes Bob $20 and Charlie $5, Bob owes Charlie $10, etc.):

How to pick the first person? To pick the first person, calculate the net amount for every person where the net amount is obtained by subtracting all debts (amounts to pay) from all credits (amounts to be paid). Once the net amount for every person is evaluated, find two persons with maximum and minimum net amounts. These two persons are the most creditors and debtors. The person with the minimum of the two is our first person to be settled and removed from the list. Let the minimum of two amounts be x. We pay ‘x’ amount from the maximum debtor to the maximum creditor and settle one person. If x is equal to the maximum debit, then the maximum debtor is settled, else the maximum creditor is settled.

There's no sense in $10 making its way from Alice to Bob and then from Bob to Charlie if Alice could just give it to Charlie directly.

The goal, then, in the general case, is to take a debt graph and simplify it (i.e., produce a new graph with the same nodes but different edges).

# How to Use?

I have created a method that does this.

### Create a Map for the People and Their Debts

In C++, we use a **`std::map`** to store each person's name and the amount they owe or are owed.

```cpp
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip> // for setting decimal precision

using namespace std;

void findPath(map<string, double>& debts);
double round(double value, int places);
string getKeyFromValue(map<string, double>& debts, double value);

int main() {
    // Create a map for debts
    map<string, double> debts;
    debts["A"] = -5.0;
    debts["B"] = 25.0;
    debts["C"] = -20.0;
    debts["D"] = 25.0;
    debts["E"] = -20.0;
    debts["F"] = -5.0;

    // Call findPath to simplify debts
    findPath(debts);

    return 0;
}
```

### Steps to Follow

1. **Add Expenses in the Map**:
   Add the debts or credits for each person in the format of `"Name", Amount`.

   Example:
   ```cpp
   debts["A"] = -5.0;  // A owes 5.0
   debts["B"] = 25.0;  // B is owed 25.0
   debts["C"] = -20.0; // C owes 20.0
   debts["D"] = 25.0;  // D is owed 25.0
   debts["E"] = -20.0; // E owes 20.0
   debts["F"] = -5.0;  // F owes 5.0
   ```

2. **Call the `findPath` Method**:
   The `findPath()` method simplifies the debt graph and outputs the simplified transactions.

   Example usage:
   ```cpp
   findPath(debts);
   ```

3. **Output**:
   After running the program, you will receive an output like:

   ```
   C needs to pay B: 20.0
   E needs to pay D: 20.0
   A needs to pay B: 5.0
   F needs to pay D: 5.0
   ```

This output represents the minimal set of transactions required to settle all the debts.

---

This C++ Readme outlines the algorithm used to simplify a debt graph into a minimal set of transactions. The program recursively finds the most significant creditors and debtors, settles their debts, and repeats until all amounts are settled. Let me know if you need any changes!

// SAP ID :  70145393
// NAME   :  Muhammmad Faizan
//PRJECT  :  Daily Habbit Tracker 

#include<iostream>
#include<string>
//Because we used setw Fuctions
#include<iomanip>
using namespace std;
//Global Variables and Constants
int habitcount = 0;
string habit[10];
const int col = 7;
//Funtion Prototypes
int showMenu(); //1
void addHabit(); //2
void viewHabit(); //3
void markDone(string[][col], int); //4
void viewProgress(string[][col], int); //5
void delHabit(); //6 
void editHabit(); //7
void eraseData(); //8 
void showCount(); //9
double percentCalculator(string[][col], int); //10
void globalScore(double); //11
void checkBalance(string[][col], int); //12
void habitSuggestion();
// The Main Body
int main() {
    cout << "|---------------------------------------------------------------------------------|\n|                   WELCOME TO YOUR DAILY HABBIT TRACKER MR.FAIZAN                |\n|---------------------------------------------------------------------------------|" << endl;
    cout << "|------------------- Complete the daily tasks and earn real money ----------------|" << endl << endl;
    string complete[10][col];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < col; j++) {
            complete[i][j] = "- ";
        }
    }
    int choice;
    //do While From here-----
    do {
        choice = showMenu();
        switch (choice) {
            //CASES----
        case 1:
            addHabit();
            break;
        case 2:
            viewHabit();
            break;
        case 3:
            markDone(complete, 10);
            break;
        case 4:
            viewProgress(complete, 10);
            break;
        case 5:
            delHabit();
            break;
        case 6:
            editHabit();
            break;
        case 7:
            eraseData();
            break;
        case 8:
            showCount();
            break;
        case 9:
            habitSuggestion();
            break;
        case 10:
        {
            double percent = percentCalculator(complete, 10);
            globalScore(percent);
        }
        break;
        case 11:
            checkBalance(complete, 10);
            break;
        case 12:
            cout << "                                -----Closing-----";
            break;
        default:
            cout << "Your Programme has Terminated ! Invalid Response ! ";
        }
        cout << endl;
    } while (choice != 12);
    cout << "|---------------------------------------------------------------------------------|\n";
    cout << "                  Thank You for using my app :) see you again ! " << endl;
    cout << "|---------------------------------------------------------------------------------|\n";
    return 0;
}
//Fuctions From Here : 
//show Menu-------
int showMenu() {
    int choice;
    cout << "|---------------------------------------------------------------------------------|" << endl;;
    cout << "|                                 MAIN MENU                                       |" << endl;
    cout << "|---------------------------------------------------------------------------------|" << endl;
    cout << "|  1. Add Habit                                                                   |" << endl;
    cout << "|  2. View Habit                                                                  |" << endl;
    cout << "|  3. Mark Habit as Done                                                          |" << endl;
    cout << "|  4. View Progress                                                               |" << endl;
    cout << "|  5. Delete Habit                                                                |" << endl;
    cout << "|  6. Edit Habit                                                                  |" << endl;
    cout << "|  7. Reset All Data                                                              |" << endl;
    cout << "|  8. Show Habit Count                                                            |" << endl;
    cout << "|  9. Habit Suggestions                                                           |" << endl;
    cout << "| 10. Check Global Score                                                          |" << endl;
    cout << "| 11. Check Balance                                                               |" << endl;
    cout << "| 12. Exit                                                                        |" << endl;
    cout << "|---------------------------------------------------------------------------------|" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9 && choice != 10 && choice != 11 && choice != 12)//for chrcking between1 to 12 and not alphabet etc this checks both 
    {
        cout << "Invalid Choice !! Please choose a number between 1 to 12: ";
        cin >> choice;
    }

    return choice;
}
//ADD HABBIT----
void addHabit() {
    if (habitcount >= 10) {
        cout << "Sorry you cannot add Further :( ";
        return;
    }
    cout << "Enter Habit : ";
    cin.ignore();
    getline(cin, habit[habitcount]);
    cout << "Habit Successfully added :) ";
    habitcount++;
    return;
}
//VIEW HABBITS----
void viewHabit() {
    if (habitcount == 0) {
        cout << "No Habit has been added ! Please Add :( " << endl;
        return;
    }
    cout << "Here are your Daily Tasks : " << endl;
    for (int i = 0; i < habitcount; i++) {
        cout << i + 1 << ". " << habit[i] << endl;
    }
    return;
}
//MARK AS DONE----
void markDone(string(*complete)[col], int row) {
    if (habitcount == 0) {
        cout << "No Habit has been added ! Please Add :(" << endl;
        return;
    }
    int habitnumber, day;
    for (int i = 0; i < habitcount; i++) {
        cout << i + 1 << ". " << habit[i] << endl;
    }
    cout << "Enter Habit Number : ";
    cin >> habitnumber;
    while (habitnumber < 1 || habitnumber > habitcount) {
        cout << "Invalid !! Please select Correct Number : ";
        cin >> habitnumber;
    }
    cout << "Enter Day you want to mark (0=Mon 1=Tues 2=Wed 3=Thurs 4=Fri 5=Sat 6=Sun ) : ";
    cin >> day;
    while (day > 6 || day < 0) {
        cout << "Invalid !! Select Correct Day : ";
        cin >> day;
    }
    complete[habitnumber - 1][day] = "o ";
    cout << "Task Marked as done [ok]";
    return;
}
//VIEW PROGRESS----
void viewProgress(string(*progress)[col], int row) {
    if (habitcount == 0) {
        cout << "No Habit has been added ! Please Add :(" << endl;
        return;
    }
    cout << "\t\t\tMon  Tue  Wed  Thu  Fri  Sat  Sun " << endl;
    for (int i = 0; i < habitcount; i++) {
        cout << i + 1 << ". " << left << setw(22) << habit[i];
        for (int j = 0; j < 7; j++) {
            cout << progress[i][j] << "   ";
        }
        cout << endl;
    }
    return;
}
//DELETE A HABBIT----
void delHabit() {
    if (habitcount == 0) {
        cout << "No Habit To delete ! Please Add :( " << endl;
        return;
    }
    int del;
    cout << "Choose a Habit to delete :( " << endl;
    for (int i = 0; i < habitcount; i++) {
        cout << i + 1 << ". " << habit[i] << endl;
    }
    cout << "Enter Choice : ";
    cin >> del;
    while (del<1 || del>habitcount) {
        cout << "Invalid number ! Enter Again : ";
        cin >> del;
    }
    del = del - 1;
    for (int i = del + 1; i < habitcount; i++) {
        habit[i - 1] = habit[i];
    }
    habitcount--;
    cout << "Habit is successfully Deleted :)";
    cout << endl;
    if (habitcount == 0) {
        cout << "No Habit is left ! Add more :(" << endl;
        return;
    }
    cout << "Here are your Daily Tasks :) " << endl;
    for (int i = 0; i < habitcount; i++) {
        cout << i + 1 << ". " << habit[i] << endl;
    }
    return;
}
//EDIT A HABBIT----
void editHabit() {
    if (habitcount == 0) {
        cout << "No Data is there to edit ! Please Add :( " << endl;
        return;
    }
    int edit;
    cout << "Here are your Daily Tasks :)" << endl;
    for (int i = 0; i < habitcount; i++) {
        cout << i + 1 << ". " << habit[i] << endl;
    }
    cout << "Enter the Habit you want to edit : ";
    cin >> edit;
    while (edit<1 || edit>habitcount) {
        cout << "Enter a valid number ! ";
        cin >> edit;
    }
    edit = edit - 1;
    cout << endl;
    cout << "Enter Edited Text : ";
    cin.ignore();
    getline(cin, habit[edit]);
    cout << "Habit successfully updated :)" << endl;
    cout << endl;
    cout << "Updated List is :  " << endl;
    for (int i = 0; i < habitcount; i++) {
        cout << i + 1 << ". " << habit[i] << endl;
    }
    return;
}
//ERASE ALL DATA----
void eraseData() {
    if (habitcount == 0) {
        cout << "No Data is there to remove ! Please Add :(" << endl;
        return;
    }
    habitcount = 0;
    cout << "Data has been erased successfully :)";
    cout << endl;
    cout << "Add more Habits." << endl;
    return;
}
//SHOW COUNT OF HABBIT----
void showCount() {
    cout << "Curently you have " << habitcount << " Habits stored in your Tracker :)" << endl;
    return;
}
//PERCENTAGE CALCULATOR-----
double percentCalculator(string(*counting)[col], int row) {
    double marked = 0.00;
    double total = 0.00;
    for (int i = 0; i < habitcount; i++) {
        for (int j = 0; j < col; j++) {
            total++;
            if (counting[i][j] == "o ") {
                marked++;
            }
        }
    }
    double percent = ((marked / total) * 100);
    return percent;
}
//GLOBAL SCORE-----
void globalScore(double score) {
    cout << endl;
    cout << "\t\t\t--------TOP 20 USERS OF WEEK--------" << endl << endl;
    string names[20] = { "Ahmad Zia", "Farhaj Anwar", "Yasir Zahid", "Abdullah Zahid", "Ehtesham", "Moiz", "Fahad Hussain", "Rutab Bukhari", "Fazeela Anwar", "Sumbul Saeed", "Laiba Iqbal", "Iqra Shehzadi", "Laiba", "Faiza Nayyab", "Beenish Gohar", "Hashim Omar", "Saad Asif", "Daniyal", "Abdullah Azmat","Muhammad Faizan" };
    double values[20] = {
    100.0, 95.8, 91.6, 87.4, 83.2,
    79.0, 74.8, 70.6, 66.4, 62.2,
    58.0, 53.8, 49.6, 45.4, 41.2,
    37.0, 32.8, 28.6, 24.4,0.00 };
    int size = 20;
    values[19] = score;
    for (int i = 1; i < size; i++) {
        double current = values[i];
        string currentname = names[i];
        int j = i - 1;
        while (current > values[j] && j >= 0) {
            values[j + 1] = values[j];
            names[j + 1] = names[j];
            j--;
        }
        values[j + 1] = current;
        names[j + 1] = currentname;
    }
    for (int i = 0; i < size; i++) {
        cout << left << setw(3) << i + 1 << ". " << left << setw(20) << names[i] << values[i] << "%";
        if (names[i] == "Muhammad Faizan") { cout << " (You) "; }
        cout << endl;
    }
    return;
}
//Show Balance-------
void checkBalance(string(*progress)[col], int row) {
    int Balance = 0;
    for (int i = 0; i < habitcount; i++) {
        bool iscomplete = true;
        for (int j = 0; j < col; j++) {
            if (progress[i][j] == "- ") {
                iscomplete = false;
            }
        }
        if (iscomplete) {
            Balance = Balance + 100;
        }
    }
    cout << "Your current balance is Rs. " << Balance << " PKR :)" << endl;
}//HABBIT SUGGESTION-----------
void habitSuggestion() {
    string newhabit[10] = {
      "Learn new word",
      "Give Compliment",
      "No sugar",
      "Gratitude note",
      "Streching",
      "No complain",
      "Learn skill",
      "Track expenses",
      "dont lie",
      "Nature break"
    };
    char choice;
    cout << "\t\t\t-------HABBITS TO CONSIDER-------" << endl << endl;
    for (int i = 0; i < 10; i++) {
        cout << left << setw(3) << i + 1 << ". " << left << setw(20) << newhabit[i] << endl;
    }
    cout << endl;
    cout << "Do you want any above Habit in your Tracker : (Y / N) : ";
    cin >> choice;
    while (choice != 'y' && choice != 'Y' && choice != 'N' && choice != 'n') {
        cout << "Invalid Choice Only Enter ( Y or N ) :";
        cin >> choice;
    }
    if (choice == 'y' || choice == 'Y') {
        int option;
        cout << "Enter the Habit number you wnat to Add : ";
        cin >> option;
        while (option < 1 || option>10) {
            cout << "Invalid choice ! Please Enter the number Between 1 to 10 : ";
            cin >> option;
        }
        if (habitcount >= 10) {
            cout << "Your Tracker is Full add the moment Delete any habit to Add new ";
            return;
        }
        option = option - 1;
        habit[habitcount] = newhabit[option]; //habit is +1 then indx,index=4,Con=5
        habitcount++; //becase added a new habit
        cout << "Here are your Updated Daily Tasks :)" << endl;
        for (int i = 0; i < habitcount; i++) {
            cout << i + 1 << ". " << habit[i] << endl;
        }
        return;
    }
    cout << "OK !! " << endl;
    return;
}

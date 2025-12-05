

#include <bits/stdc++.h>
using namespace std;

const unordered_map<string,double> GPA_MAP = {
    {"A+", 4.0}, {"A", 3.6}, {"B+", 3.2}, {"B", 2.8}, {"C+", 2.4}, {"C", 2.0}, {"F", 0.0}
};

string readLineNonEmpty(const string &prompt) {
    string s;
    do {
        cout << prompt;
        getline(cin, s);
        // trim
        auto start = s.find_first_not_of(" \t\r\n");
        if(start==string::npos) s="";
        else s = s.substr(start, s.find_last_not_of(" \t\r\n") - start + 1);
    } while(s.empty());
    return s;
}

double readNumberInRange(const string &prompt, double minv, double maxv) {
    while (true) {
        cout << prompt;
        string line;
        getline(cin, line);
        stringstream ss(line);
        double x;
        if (!(ss >> x) || !(ss.eof())) {
            cout << "  -> Please enter a valid number.\n";
            continue;
        }
        if (x < minv || x > maxv) {
            cout << "  -> Value must be between " << minv << " and " << maxv << ".\n";
            continue;
        }
        return x;
    }
}

int readIntChoice(const string &prompt, int low, int high) {
    while (true) {
        cout << prompt;
        string line;
        getline(cin, line);
        stringstream ss(line);
        int v;
        if (!(ss >> v) || !(ss.eof())) {
            cout << "  -> Enter a valid integer choice.\n";
            continue;
        }
        if (v < low || v > high) {
            cout << "  -> Choice must be between " << low << " and " << high << ".\n";
            continue;
        }
        return v;
    }
}

string gradeFromTotal(double total) {
    if (total >= 90) return "A+";
    if (total >= 80) return "A";
    if (total >= 70) return "B+";
    if (total >= 60) return "B";
    if (total >= 50) return "C";
    return "F";
}

void printResultBox(const string &name, const string &course, double internalM, double finalM,
                    double attendance, double total, double bonus, double finalTotal,
                    double percentage, const string &grade, double gpa, const string &finalResult,
                    const string &failReason = "")
{
    cout << "\n=========================================\n";
    cout << "             RESULT CHECKER\n";
    cout << "=========================================\n";
    cout << "Name        : " << name << "\n";
    cout << "Course      : " << course << "\n";
    cout << "Attendance  : " << attendance << "%\n";
    if (!failReason.empty()) {
        cout << "Result      : FAIL (" << failReason << ")\n";
        cout << "-----------------------------------------\n";
        cout << "Internal    : " << internalM << " / 40\n";
        cout << "Final       : " << finalM << " / 60\n";
        cout << "-----------------------------------------\n";
        cout << "Final Total : " << finalTotal << " / 100\n";
        cout << "Grade       : " << grade << "\n";
        cout << "GPA         : " << fixed << setprecision(2) << gpa << "\n";
        cout << "-----------------------------------------\n";
        return;
    }

    cout << "Internal    : " << internalM << " / 40\n";
    cout << "Final       : " << finalM << " / 60\n";
    cout << "Total (pre) : " << total << " / 100\n";
    cout << "Bonus       : " << bonus << "\n";
    cout << "Final Total : " << finalTotal << " / 100\n";
    cout << "Percentage  : " << fixed << setprecision(2) << percentage << "%\n";
    cout << "Grade       : " << grade << "\n";
    cout << "GPA         : " << fixed << setprecision(2) << gpa << "\n";
    cout << "Result      : " << finalResult << "\n";
    cout << "=========================================\n";
}

bool appendCsv(const string &filename, const vector<string> &fields) {
    ofstream fout(filename, ios::app);
    if (!fout) return false;
    // quote fields and separate by comma
    for (size_t i = 0; i < fields.size(); ++i) {
        string f = fields[i];
        // escape quotes with double quotes
        size_t p = 0;
        string escaped;
        escaped.push_back('"');
        while (p < f.size()) {
            if (f[p] == '"') escaped += "\"\"";
            else escaped.push_back(f[p]);
            ++p;
        }
        escaped.push_back('"');
        fout << escaped;
        if (i + 1 < fields.size()) fout << ',';
    }
    fout << '\n';
    fout.close();
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== Result Checker (Console C++) ===\n\n";

    string name = readLineNonEmpty("Enter student name: ");

    cout << "\nChoose course (type the number):\n";
    cout << "  1) IT    (bonus 5)\n";
    cout << "  2) CS    (bonus 4)\n";
    cout << "  3) CIVIL (bonus 3)\n";
    int choice = readIntChoice("Your choice [1-3]: ", 1, 3);
    string course;
    double bonus = 0;
    if (choice == 1) { course = "IT"; bonus = 5; }
    else if (choice == 2) { course = "CS"; bonus = 4; }
    else { course = "CIVIL"; bonus = 3; }

    double internalMarks = readNumberInRange("Enter internal marks (0 - 40): ", 0.0, 40.0);
    double finalMarks = readNumberInRange("Enter final marks (0 - 60): ", 0.0, 60.0);
    double attendance = readNumberInRange("Enter attendance percentage (0 - 100): ", 0.0, 100.0);

    double totalPre = internalMarks + finalMarks; // out of 100
    double finalTotal = totalPre + bonus;

    // For percentage, cap at 100 (bonus shouldn't make percent >100)
    double percentage = finalTotal;
    if (percentage > 100.0) percentage = 100.0;

    string failReason = "";
    if (attendance < 75.0) {
        failReason = "Short Attendance";
    }

    string grade = gradeFromTotal(finalTotal);
    double gpa = 0.0;
    auto it = GPA_MAP.find(grade);
    if (it != GPA_MAP.end()) gpa = it->second;

    string finalResult = (grade == "F" || !failReason.empty()) ? "FAIL" : "PASS";

    printResultBox(name, course, internalMarks, finalMarks, attendance,
                   totalPre, bonus, finalTotal, percentage, grade, gpa, finalResult, failReason.empty() ? "" : failReason);

    // Save option
    cout << "\nDo you want to save this result to results.csv? (y/n): ";
    string yn;
    getline(cin, yn);
    if (!yn.empty() && (yn[0]=='y' || yn[0]=='Y')) {
        vector<string> row;
        // fields: ISO datetime, name, course, attendance, internal, final, bonus, finalTotal, percentage, grade, gpa, result
        auto t = chrono::system_clock::now();
        time_t tt = chrono::system_clock::to_time_t(t);
        string timestr = string(ctime(&tt));
        // remove trailing newline from ctime
        if (!timestr.empty() && timestr.back()=='\n') timestr.pop_back();

        row.push_back(timestr);
        row.push_back(name);
        row.push_back(course);
        row.push_back(to_string(attendance));
        row.push_back(to_string(internalMarks));
        row.push_back(to_string(finalMarks));
        row.push_back(to_string(bonus));
        row.push_back(to_string(finalTotal));
        row.push_back(to_string(percentage));
        row.push_back(grade);
        {
            ostringstream oss; oss << fixed << setprecision(2) << gpa;
            row.push_back(oss.str());
        }
        row.push_back(finalResult);

        bool ok = appendCsv("results.csv", row);
        if (ok) cout << "Saved to results.csv\n";
        else cout << "Failed to save to results.csv (check permissions)\n";
    }

    cout << "\nProgram finished. Press Enter to exit...";
    string dummy; getline(cin, dummy);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

bool isUnvalid(const string& phoneNumber) {
    for (char c : phoneNumber) {
        if (!isdigit(c)) {
            return true;
        }
    }
    return phoneNumber.length() != 10;
}

long long timeCalc(string timeIn, string timeOut) {
	return ((((int)(timeOut[0] - timeIn[0])) * 10 + (int)(timeOut[1] - timeIn[1])) * 3600 + (((int)(timeOut[3] - timeIn[3])) * 10 + (int)(timeOut[4] - timeIn[4])) * 60 + ((int) (timeOut[6] - timeIn[6])) * 10 + (timeOut[7] - timeIn[7]));
}


//void inpVector(call temp) {
//	string number = temp.fromNumber;
	//for (call& i : input) {
		//if (i.fromNumber == number) {
			//i.timeCall = i.timeCall + temp.timeCall;
			//i.totalCallsNumber = i.totalCallsNumber + 1;
			//return;
		//}
	//}
	//input.push_back(temp);
	//return;
//}

int main() {
    unordered_map <string, pair <long long, long long>> inp;
	string command, fromNumber, toNumber, date, timeIn, timeOut;
	int check = 1, total = 0;

	//Input first block
	cin >> command;
	while (command != "#") {
		cin >> fromNumber >> toNumber >> date >> timeIn >> timeOut;
        total++;
		if (isUnvalid(fromNumber)) check = 0;
		if (isUnvalid(toNumber)) check = 0;
        inp[fromNumber].first = inp[fromNumber].first + 1;
        inp[fromNumber].second = inp[fromNumber].second + timeCalc(timeIn, timeOut);
		cin >> command;
	}

	cin >> command;
	while (command != "#") {
		if (command == "?check_phone_number") cout << check << endl;
		else if (command == "?number_calls_from") {
			string number;
			cin >> number;
			cout << inp[number].first << endl;
		}
		else if (command == "?number_total_calls") cout << total << endl;
		else if (command == "?count_time_calls_from") {
			string number;
			cin >> number;
			cout << inp[number].second << endl;
		}
		cin >> command;
	}

	return 0;
}

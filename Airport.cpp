#include <iostream>

#include <iomanip>

#include <map>

using namespace std;

//######################################## Flight Class ########################################

class Flight {

    public:

        Flight();

	    int GetID();
	    int GetNumber();
	    string GetTime();
	    string GetModel();
	    string GetType();
	    int GetPassengers();
	    int GetRunway();
	    bool GetTakeoffAfter();
	    Flight * GetNextFlight();

	    void SetID(int);
	    void SetNumber(int);
	    bool SetTime(string);
	    void SetModel(string);
	    void SetType(string);
	    void SetPassengers(int);
	    void SetRunway(int);
	    void SetTakeoffAfter(bool);
	    void SetNextFlight(Flight * );
	    void SetNextFlightNull();
	    void SetData(int, int, string, string, string, int, int, bool);
	
	    bool IsDigit(char);
	    void PostponeTime();

    private:

        int id;
	    int number;
	    string time;
	    string model;
	    string type;
	    int passengers;
	    int runway;
	    bool takeoffAfter;
	    Flight * nextFlight;
};

Flight::Flight() {
    id = 0;
    number = 0;
    time = "00:00";
    model = "";
    type = "";
    passengers = 0;
    runway = 0;
    takeoffAfter = false;
    nextFlight = NULL;
}

int Flight::GetID() {
    return id;
}

int Flight::GetNumber() {
    return number;
}

string Flight::GetTime() {
    return time;
}

string Flight::GetModel() {
    return model;
}

string Flight::GetType() {
    return type;
}

int Flight::GetPassengers() {
    return passengers;
}

int Flight::GetRunway() {
    return runway;
}

bool Flight::GetTakeoffAfter() {
    return takeoffAfter;
}

Flight * Flight::GetNextFlight() {
    return nextFlight;
}

void Flight::SetID(int argID) {
    id = argID;
}

void Flight::SetNumber(int argNumber) {
    number = argNumber;
}

bool Flight::SetTime(string t) {
    if (t.length() == 5)
        if (IsDigit(t.at(0)) && IsDigit(t.at(1)) && t.at(2) == ':' && IsDigit(t.at(3)) && IsDigit(t.at(4)))
            if ((t.at(0) == '0' || t.at(0) == '1' || (t.at(0) == '2' && t.at(1) >= '0' && t.at(1) <= '3')) && (t.at(3) >= '0' && t.at(3) <= '5')) {
                time = t;
                return true;
            }
    if (t.length() == 4) {
        if (IsDigit(t.at(0)) && IsDigit(t.at(1)) && t.at(2) == ':' && IsDigit(t.at(3)))
            if (t.at(0) == '0' || t.at(0) == '1' || (t.at(0) == '2' && t.at(1) >= '0' && t.at(1) <= '3')) {
                time = t.substr(0, 3) + "0" + t.substr(3, 1);
                return true;
            }
        if (IsDigit(t.at(0)) && t.at(1) == ':' && IsDigit(t.at(2)) && IsDigit(t.at(3)))
            if (t.at(2) >= '0' && t.at(2) <= '5') {
                time = "0" + t;
                return true;
            }
    }
    if (t.length() == 3)
        if (IsDigit(t.at(0)) && t.at(1) == ':' && IsDigit(t.at(2))) {
            time = "0" + t.substr(0, 2) + "0" + t.substr(2, 1);
            return true;
        }
    return false;
}

bool Flight::IsDigit(char c) {
    if (c >= '0' && c <= '9') return true;
    return false;
}

void Flight::SetModel(string argModel) {
    model = argModel;
}

void Flight::SetType(string argType) {
    type = argType;
}

void Flight::SetPassengers(int argPassengers) {
    passengers = argPassengers;
}

void Flight::SetRunway(int argRunway) {
    runway = argRunway;
}

void Flight::SetTakeoffAfter(bool argTakeoffAfter) {
    takeoffAfter = argTakeoffAfter;
}

void Flight::SetNextFlight(Flight * ptrFlight) {
    nextFlight = ptrFlight;
}

void Flight::SetNextFlightNull() {
    nextFlight = NULL;
}

void Flight::SetData(int argID, int argNumber, string argTime, string argModel, string argType, int argPassengers, int argRunway, bool argTakeoffAfter) {
    id = argID;
    number = argNumber;
    time = argTime;
    model = argModel;
    type = argType;
    passengers = argPassengers;
    runway = argRunway;
    takeoffAfter = argTakeoffAfter;
}

// Adds 30 minutes to flight time.
void Flight::PostponeTime() {
    time[3] += 3;
    if (time.at(3) > '5') {
        time[3] -= 6;
        time[1]++;
    }
    if (time.at(1) > '9') {
        time[1] -= 10;
        time[0]++;
    }
    if (time.substr(0, 2) == "24") {
        time[0] = '0';
        time[1] = '0';
    }
}

//######################################## Airport Class ########################################

class Airport {

    public:

        Airport(string);
    	void Run();

    private:

        string airportName;
	    Flight * firstFlight, * lastFlight;
	    map < string, int > airplaneModelSize;
	    int runwaysCount;
	
	    void InitializeAirport();
	    void AddFlight();
	    void DeleteFlight();
	    void SortFlights(bool);
	    void SwapFlights(Flight * , Flight * );
	    void PrintFlights();
	    void AddRunways();
	    void AddAirplaneModel();
	
	    bool SearchFlightByID(int id);
	    bool SearchFlightByRunwayTime(int runway, string time);
	    Flight * SearchFlightByNumber(int number);
	    Flight * SearchCorrespondingLandingFlight(Flight *);
};

Airport::Airport(string name) {
    airportName = name;
    firstFlight = NULL;
    lastFlight = NULL;
    airplaneModelSize.clear();
}

void Airport::Run() {

    InitializeAirport();

    int command = 0;

    while (command != 7) {

        cout << "\nMenu\n----\n";
        cout << "1) Add New Flight\t";
        cout << "3) Sort Flight Queue\t";
        cout << "5) Add to Airport Runways\t";
        cout << "7) Exit\n";
        cout << "2) Delete Flight\t";
        cout << "4) Print Flight List\t";
        cout << "6) Add New Airplane Model\n";

        cout << "\nEnter Command Number: ";
        cin >> command;

        switch (command) {
        case 1:
            AddFlight();
            break;
        case 2:
            DeleteFlight();
            break;
        case 3:
            SortFlights(true);
            break;
        case 4:
            PrintFlights();
            break;
        case 5:
            AddRunways();
            break;
        case 6:
            AddAirplaneModel();
            break;
        case 7:
            cout << "\nBye!\n";
            break;
        default:
            cout << "Error: Wrong Command!\n";
        }
    }
}

void Airport::InitializeAirport() {

    int airplaneModelsCount;
    string modelName;
    int modelSize;

    cout << "\n* Welcome to " << airportName << " Airport Flight Queuing Program *\n";
    cout << "\nInitializing Airport's Properties\n---------------------------------\n";
    cout << "\nEnter Airport's Runways Count: ";
    cin >> runwaysCount;

    cout << "\nEnter Airplane Models Count: ";
    cin >> airplaneModelsCount;

    for (int i = 1; i <= airplaneModelsCount; i++) {

        cout << "\nAirplane Model (" << i << ") Properties\n";
        modelName = "";
        do {
            cout << "Model Name: ";
            cin >> modelName;
            if (airplaneModelSize.find(modelName) != airplaneModelSize.end())
                cout << "Error: This Model Name Exists.\n";
        } while (airplaneModelSize.find(modelName) != airplaneModelSize.end());

        modelSize = 0;
        do {
            cout << "Model Size (1~" << runwaysCount << "): ";
            cin >> modelSize;
            if (modelSize < 1 || modelSize > runwaysCount)
                cout << "Error: Wrong Model Size.\n";
        } while (modelSize < 1 || modelSize > runwaysCount);
        airplaneModelSize[modelName] = modelSize;
    }

}

void Airport::AddFlight() {

    Flight * flight = new Flight;
    int id = -1, number, passengers, additiveTime = 0;
    string time = "", model = "", type = "", samePlane = "";
    bool isSamePlane = false;

    cout << "\nAdd New Flight\n--------------\n";

    while (id < 0 || SearchFlightByID(id)) {
        cout << "Flight ID: ";
        cin >> id;
        if (SearchFlightByID(id))
            cout << "Error: Flight ID Exists.\n";
        else
            flight -> SetID(id);
    }

    cout << "Flight Number: ";
    cin >> number;
    flight -> SetNumber(number);

    while (!flight -> SetTime(time)) {
        cout << "Flight Time (HH:MM): ";
        cin >> time;
        if (!flight -> SetTime(time))
            cout << "Error: Wrong Time.\n";
    }

    while (airplaneModelSize.find(model) == airplaneModelSize.end()) {
        cout << "Airplane Model: ";
        cin >> model;
        if (airplaneModelSize.find(model) != airplaneModelSize.end())
            flight -> SetModel(model);
        else
            cout << "Error: This Model Not Exist.\n";
    }

    while (type != "L" && type != "l" && type != "T" && type != "t") {
        cout << "Flight Type (L=Landing / T=Takeoff): ";
        cin >> type;
        if (type == "L" || type == "l")
            flight -> SetType("Landing");
        else if (type == "T" || type == "t")
            flight -> SetType("Takeoff");
        else
            cout << "Error: Wrong Letter (Enter L or T).\n";
    }

    cout << "Passengers Count: ";
    cin >> passengers;
    flight -> SetPassengers(passengers);

    // Setting Runway
    Flight * landingFlight = NULL;
    if (flight -> GetType() == "Takeoff")
        landingFlight = SearchCorrespondingLandingFlight(flight);

    if (landingFlight != NULL) {
        while (samePlane != "Y" && samePlane != "y" && samePlane != "N" && samePlane != "n") {
            cout << "There is a Landing Flight with Model " << landingFlight -> GetModel() <<
                " on Runway " << landingFlight -> GetRunway() <<
                ". Is This the Same Airplane (Y / N)? ";
            cin >> samePlane;
            if (samePlane == "Y" || samePlane == "y")
                isSamePlane = true;
            else if (samePlane == "N" || samePlane == "n")
                isSamePlane = false;
            else
                cout << "Error: Wrong Letter (Enter Y or N).\n";
        }
    }

    if (isSamePlane) {
    	
        while (SearchFlightByRunwayTime(landingFlight -> GetRunway(), flight -> GetTime())) {
            flight -> PostponeTime();
            additiveTime++;
        }
        flight -> SetRunway(landingFlight -> GetRunway());
        landingFlight -> SetTakeoffAfter(true);
        
    } else {
    	
        int minRunway = -1;
        while (minRunway == -1) {
            for (int i = airplaneModelSize[model]; i <= runwaysCount; i++) {
                if (!SearchFlightByRunwayTime(i, flight -> GetTime())) {
                    minRunway = i;
                    break;
                }
            }
            if (minRunway == -1) {
                flight -> PostponeTime();
                additiveTime++;
            }
        }
        flight -> SetRunway(minRunway);
    }
    flight -> SetTakeoffAfter(false);

    if (firstFlight == NULL) {
        firstFlight = flight;
        lastFlight = flight;
    } else {
        lastFlight -> SetNextFlight(flight);
        lastFlight = flight;
    }

    cout << "\nInfo: Flight Number " << flight -> GetNumber() <<
        " Inserted into Runway " << flight -> GetRunway() << " ";

    if (additiveTime == 0)
        cout << "On Time (" << flight -> GetTime() << ").\n";
    else
        cout << "with " << additiveTime * 30 << " Minutes Delay (" << flight -> GetTime() << ").\n";

}

void Airport::DeleteFlight() {

    cout << "\nDelete Flight\n-------------\n";

    if (firstFlight != NULL) {

        int flightNumber;

        cout << "Flight Number to Delete: ";
        cin >> flightNumber;

        Flight * flightToDelete = SearchFlightByNumber(flightNumber);

        if (flightToDelete != NULL) {

            if (flightToDelete == firstFlight) {

                firstFlight = firstFlight -> GetNextFlight();

            } else {

                Flight * prevFlight = firstFlight;
                while (prevFlight -> GetNextFlight() != NULL && prevFlight -> GetNextFlight() != flightToDelete)
                    prevFlight = prevFlight -> GetNextFlight();
                prevFlight -> SetNextFlight(prevFlight -> GetNextFlight() -> GetNextFlight());

            }
            cout << "\nInfo: Flight Number " << flightNumber << " Deleted.\n";
        } else {
            cout << "\nError: Flight Number " << flightNumber << " Not Exists.\n";
        }

    } else {
        cout << "\nNo Flights to Delete.\n";
    }
}

void Airport::SortFlights(bool showCommandMessages) {

    if (showCommandMessages) cout << "\nSort Flight Queue\n-----------------\n";

    if (firstFlight != NULL) {

        int swapped;

        Flight * lPtr; // left pointer will always point to the start of the list
        Flight * rPrt = NULL; // right pointer will always point to the end of the list
        do {
            swapped = 0;
            lPtr = firstFlight;
            while (lPtr -> GetNextFlight() != rPrt) {
                if (lPtr -> GetTime() > lPtr -> GetNextFlight() -> GetTime() || (lPtr -> GetTime() == lPtr -> GetNextFlight() -> GetTime() && lPtr -> GetRunway() > lPtr -> GetNextFlight() -> GetRunway())) {
                    SwapFlights(lPtr, lPtr -> GetNextFlight());
                    swapped = 1;
                }
                lPtr = lPtr -> GetNextFlight();
            }
            rPrt = lPtr;
        } while (swapped);

        if (showCommandMessages) cout << "\nInfo: Flights Queue Sorted by Time.\n";
    } else
    if (showCommandMessages) cout << "\nNo Flights in Queue.\n";

}

void Airport::SwapFlights(Flight * flight1, Flight * flight2) {
    Flight tempFlight;
    tempFlight.SetData(flight1 -> GetID(), flight1 -> GetNumber(), flight1 -> GetTime(), flight1 -> GetModel(), flight1 -> GetType(), flight1 -> GetPassengers(), flight1 -> GetRunway(), flight1 -> GetTakeoffAfter());
    flight1 -> SetData(flight2 -> GetID(), flight2 -> GetNumber(), flight2 -> GetTime(), flight2 -> GetModel(), flight2 -> GetType(), flight2 -> GetPassengers(), flight2 -> GetRunway(), flight2 -> GetTakeoffAfter());
    flight2 -> SetData(tempFlight.GetID(), tempFlight.GetNumber(), tempFlight.GetTime(), tempFlight.GetModel(), tempFlight.GetType(), tempFlight.GetPassengers(), tempFlight.GetRunway(), tempFlight.GetTakeoffAfter());
}

void Airport::PrintFlights() {

    cout << "\nFlight List\n-----------\n";

    if (firstFlight != NULL) {

        SortFlights(false);

        int runwayNumber = -1;
        do {
            cout << "Enter Runway Number (1~" << runwaysCount << " / 0=All Runways): ";
            cin >> runwayNumber;
            if (runwayNumber < 0 || runwayNumber > runwaysCount)
                cout << "Error: Wrong Runway Number.\n";
        } while (runwayNumber < 0 || runwayNumber > runwaysCount);

        Flight * flight = firstFlight;

        int runwayFlightsCount = 0;

        do {
            if (runwayNumber == 0 || flight -> GetRunway() == runwayNumber) runwayFlightsCount++;
            flight = flight -> GetNextFlight();
        } while (flight != NULL);

        if (runwayFlightsCount > 0) {

            cout << "\n";
            cout << "         ID     Number       Time      Model       Type   Passengers     Runway\n";
            cout << "----------- ---------- ---------- ---------- ---------- ------------ ----------\n";

            flight = firstFlight;

            do {
                if (runwayNumber == 0 || flight -> GetRunway() == runwayNumber)
                    cout << setw(11) << flight -> GetID() <<
                    setw(11) << flight -> GetNumber() <<
                    setw(11) << flight -> GetTime() <<
                    setw(11) << flight -> GetModel() <<
                    setw(11) << flight -> GetType() <<
                    setw(13) << flight -> GetPassengers() <<
                    setw(11) << flight -> GetRunway() << "\n";
                flight = flight -> GetNextFlight();
            } while (flight != NULL);

        } else
            cout << "\nNo Flights in Runway Number " << runwayNumber << ".\n";
    } else
        cout << "\nNo Flights in List.\n";

}

void Airport::AddRunways() {
    cout << "\nAdd to Airport Runways\n----------------------\n";
    cout << "There are " << runwaysCount << " Runways defined in this airport.\n";
    cout << "How many New Runways do you want to add: ";
    int newRunwaysCount = 0;
    cin >> newRunwaysCount;
    runwaysCount += newRunwaysCount;
    cout << "\nInfo: " << newRunwaysCount << " New Runways added to Airport. " <<
        "Now there are " << runwaysCount << " Runways in Airport.\n";
}

void Airport::AddAirplaneModel() {

    cout << "\nAdd New Airplane Model\n----------------------\n";

    string modelName = "";
    do {
        cout << "Model Name: ";
        cin >> modelName;
        if (airplaneModelSize.find(modelName) != airplaneModelSize.end())
            cout << "Error: This Model Name Exists.\n";
    } while (airplaneModelSize.find(modelName) != airplaneModelSize.end());

    int modelSize = 0;
    do {
        cout << "Model Size (1~" << runwaysCount << "): ";
        cin >> modelSize;
        if (modelSize < 1 || modelSize > runwaysCount)
            cout << "Error: Wrong Model Size.\n";
    } while (modelSize < 1 || modelSize > runwaysCount);
    airplaneModelSize[modelName] = modelSize;

    cout << "\nInfo: New Airplane Model " << modelName << " with Size " << modelSize << " added to Airplane Models.\n";
}

bool Airport::SearchFlightByID(int argID) {

    if (firstFlight == NULL) return false;
    else {
        Flight * flight = firstFlight;
        do {
            if (flight -> GetID() == argID)
                return true;
            flight = flight -> GetNextFlight();
        } while (flight != NULL);
    }
    return false;
}

bool Airport::SearchFlightByRunwayTime(int argRunway, string argTime) {

    if (firstFlight == NULL) return false;
    else {
        Flight * flight = firstFlight;
        do {
            if (flight -> GetRunway() == argRunway && flight -> GetTime() == argTime)
                return true;
            flight = flight -> GetNextFlight();
        } while (flight != NULL);
    }
    return false;
}

Flight * Airport::SearchFlightByNumber(int argNumber) {

    if (firstFlight == NULL) return NULL;
    else {
        Flight * flight = firstFlight;
        do {
            if (flight -> GetNumber() == argNumber)
                return flight;
            flight = flight -> GetNextFlight();
        } while (flight != NULL);
    }
    return NULL;
}

Flight * Airport::SearchCorrespondingLandingFlight(Flight * argFlight) {
    if (firstFlight == NULL) return NULL;
    else {
        Flight * flight = firstFlight;
        do {
            if (flight -> GetType() == "Landing" &&
            	(!flight -> GetTakeoffAfter()) &&
                flight -> GetModel() == argFlight -> GetModel() &&
                flight -> GetTime() < argFlight -> GetTime())
                return flight;
            flight = flight -> GetNextFlight();
        } while (flight != NULL);
    }
    return NULL;
}

//######################################## Main ########################################

int main() {
    Airport airport("Isfahan");
    airport.Run();
    return 0;
}


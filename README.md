# Airport Flight Management System

This is a C++ program that simulates the management of flights at an airport. The program includes two main classes, `Flight` and `Airport`, that handle the details of flight scheduling, adding new flights, sorting them, and managing runways. The program interacts with the user through a menu, allowing for commands such as adding a flight, deleting a flight, sorting flights, and adding new airplane models.

## Features

- **Flight Management**: Allows adding, deleting, and sorting flights.
- **Flight Information**: Manage flight details like ID, number, time, type, model, and passengers.
- **Runway Management**: Assign runways to flights and ensure no runway is double-booked at the same time.
- **Airplane Models**: Define airplane models with size constraints that determine the runway assignment.

## Classes

### `Flight`
The `Flight` class handles the details of a single flight, including:
- Flight ID
- Flight number
- Flight time (HH:MM)
- Model and type of the airplane
- Number of passengers
- Runway assignment
- Time postponement for managing delays

#### Key Methods:
- `GetID()`, `GetNumber()`, `GetTime()`, `GetModel()`, etc. - Getter methods for flight attributes.
- `SetData()` - Sets flight data for all attributes.
- `PostponeTime()` - Adds 30 minutes to the flight time for delays.
- `SetTime()` - Validates and sets the flight time in HH:MM format.

### `Airport`
The `Airport` class manages multiple flights, including their addition, deletion, and sorting. It also handles airport-specific information like the number of runways and available airplane models.

#### Key Methods:
- `AddFlight()` - Adds a new flight after validating flight information.
- `DeleteFlight()` - Deletes an existing flight.
- `SortFlights()` - Sorts the flight queue based on flight details.
- `AddRunways()` - Adds more runways to the airport if needed.
- `AddAirplaneModel()` - Adds new airplane models to the airport's available models.
- `SearchFlightByID()` - Searches for a flight by its ID.
- `SearchFlightByRunwayTime()` - Searches for a flight by runway and time to avoid conflicts.
  
## Menu Options
Upon running the program, the user is presented with a menu with the following options:
1. Add New Flight
2. Delete Flight
3. Sort Flight Queue
4. Print Flight List
5. Add to Airport Runways
6. Add New Airplane Model
7. Exit

## Installation and Usage

1. **Clone the Repository:**
    ```bash
    git clone <repository_url>
    ```

2. **Compile the Program:**
    Use the following command to compile the program using `g++`:
    ```bash
    g++ -o flight_management flight_management.cpp
    ```

3. **Run the Program:**
    Execute the program:
    ```bash
    ./flight_management
    ```

4. **Interact with the Menu:**
    The user will be prompted to choose from the menu options, input flight details, and manage the flight schedule.

## Example

Here’s an example interaction with the menu:

```
Menu
----
1) Add New Flight   3) Sort Flight Queue   5) Add to Airport Runways   7) Exit
2) Delete Flight    4) Print Flight List    6) Add New Airplane Model

Enter Command Number: 1
Add New Flight
--------------
Flight ID: 101
Flight Number: 500
Flight Time (HH:MM): 14:30
Airplane Model: A320
Flight Type (L=Landing / T=Takeoff): T
Passengers Count: 150
...
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---


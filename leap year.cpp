#include <iostream>
#include <string>
using namespace std;


struct stDate
{
    short Year;
    short Month;
    short Day;
};


//--------------------------------------------
// Check Leap Year
//--------------------------------------------
bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0)
        || (Year % 400 == 0);
}


//--------------------------------------------
// Number Of Days In Month
//--------------------------------------------
short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    int Days[12] =
    {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    return (Month == 2)
        ? (IsLeapYear(Year) ? 29 : 28)
        : Days[Month - 1];
}


//--------------------------------------------
// Number Of Days In Year
//--------------------------------------------
short NumberOfDaysInAYear(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
}


//--------------------------------------------
// Day Of Week Order
//--------------------------------------------
short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    // 0: Sun
    // 1: Mon
    // 2: Tue
    // 3: Wed
    // 4: Thu
    // 5: Fri
    // 6: Sat

    return (Day + y + (y / 4)
        - (y / 100)
        + (y / 400)
        + ((31 * m) / 12)) % 7;
}


//--------------------------------------------
// Day Short Name
//--------------------------------------------
string DayShortName(short DayOfWeekOrder)
{
    string DaysNames[] =
    {
        "Sun",
        "Mon",
        "Tue",
        "Wed",
        "Thu",
        "Fri",
        "Sat"
    };

    return DaysNames[DayOfWeekOrder];
}


//--------------------------------------------
// Read Day
//--------------------------------------------
short ReadDay()
{
    short Day;

    cout << "Please enter a Day? ";
    cin >> Day;

    return Day;
}


//--------------------------------------------
// Read Month
//--------------------------------------------
short ReadMonth()
{
    short Month;

    cout << "Please enter a Month? ";
    cin >> Month;

    return Month;
}


//--------------------------------------------
// Read Year
//--------------------------------------------
short ReadYear()
{
    short Year;

    cout << "Please enter a Year? ";
    cin >> Year;

    return Year;
}


//--------------------------------------------
// Read Full Date
//--------------------------------------------
stDate ReadFullDate()
{
    stDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}


//--------------------------------------------
// Number Of Days From Beginning Of Year
//--------------------------------------------
short NumberOfDaysFromTheBeginningOfTheYear
(
    short Day,
    short Month,
    short Year
)
{
    short TotalDays = 0;

    for (int i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInAMonth(i, Year);
    }

    TotalDays += Day;

    return TotalDays;
}


//--------------------------------------------
// Is End Of Week
//--------------------------------------------
bool IsEndOfWeek(stDate Date)
{
    short Index = DayOfWeekOrder(
        Date.Day,
        Date.Month,
        Date.Year
    );

    return (Index == 6);
}


//--------------------------------------------
// Is Weekend
//--------------------------------------------
// OVERLOADING - Version 1
//--------------------------------------------
bool IsWeekend(stDate Date)
{
    short Index = DayOfWeekOrder(
        Date.Day,
        Date.Month,
        Date.Year
    );

    return (Index == 5 || Index == 6);
}


//--------------------------------------------
// Is Weekend
//--------------------------------------------
// OVERLOADING - Version 2
//--------------------------------------------
bool IsWeekend(short Day, short Month, short Year)
{
    short Index = DayOfWeekOrder(
        Day,
        Month,
        Year
    );

    return (Index == 5 || Index == 6);
}


//--------------------------------------------
// Is Business Day
//--------------------------------------------
bool IsBusinessDay(stDate Date)
{
    return !IsWeekend(Date);
}


//--------------------------------------------
// Days Until End Of Week
//--------------------------------------------
short UntilSaysEndOfWeek(stDate Date)
{
    return 6 - DayOfWeekOrder(
        Date.Day,
        Date.Month,
        Date.Year
    );
}


//--------------------------------------------
// Days Until End Of Month
//--------------------------------------------
short UntilSaysEndOfMonth(stDate Date)
{
    return NumberOfDaysInAMonth(
        Date.Month,
        Date.Year
    ) - Date.Day;
}


//--------------------------------------------
// Days Until End Of Year
//--------------------------------------------
short UntilSaysEndOfYear(stDate Date)
{
    return NumberOfDaysInAYear(Date.Year)
        - NumberOfDaysFromTheBeginningOfTheYear(
            Date.Day,
            Date.Month,
            Date.Year
        ) + 1;
}


//--------------------------------------------
// Main
//--------------------------------------------
int main()
{
    stDate Date = ReadFullDate();


    cout << "\nToday is "
        << DayShortName(
            DayOfWeekOrder(
                Date.Day,
                Date.Month,
                Date.Year
            )
        )
        << " , "
        << Date.Day
        << "/"
        << Date.Month
        << "/"
        << Date.Year
        << endl;


    cout << "\nIs it End of Week?\n";

    if (IsEndOfWeek(Date))
        cout << "Yes it is End of week.\n";
    else
        cout << "No Not end of week.\n";


    cout << "\nIs it Weekend?\n";

    if (IsWeekend(Date))
        cout << "Yes it is a week end.\n";
    else
        cout << "No it is not a week end.\n";


    cout << "\nIs it Business Day?\n";

    if (IsBusinessDay(Date))
        cout << "Yes it is a business day.\n";
    else
        cout << "No it is NOT a business day.\n";


    cout << "\nDays until end of week : "
        << UntilSaysEndOfWeek(Date)
        << " Day(s)."
        << endl;


    cout << "Days until end of month : "
        << UntilSaysEndOfMonth(Date)
        << " Day(s)."
        << endl;


    cout << "Days until end of year : "
        << UntilSaysEndOfYear(Date)
        << " Day(s)."
        << endl;


    // Testing the overloaded function
    cout << "\nTesting Overloading:\n";

    if (IsWeekend(Date.Day, Date.Month, Date.Year))
        cout << "The overloaded function says: Weekend.\n";
    else
        cout << "The overloaded function says: Not Weekend.\n";


    system("pause>0");

    return 0;
}
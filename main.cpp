//This program is my logger/diary to log my activities for future review

/*TODO:
 *Expand otion 4 (lsit commands) into a more elaborate help and move to different number in menu.
 *Change greeting to version.
 *Possibility to save the colour configuration.
 *[Unnecesarry]An option in the menu screen to display the log and start logging in one sequence
 *[Unnecesarry]A Todo funcion accessible from the menu screen.
 *Graphical representation of the letters - green against black background.
 *->the colours in linux concole was a bit more limited option than what i have in mind
 *->should set up a proper ubuntu window, this will break code compatibility with windows though
 *->will gave to do windows window separatedy (with SDL?) if I'll ever port this (I think i should).
*/

#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

void welcome();//displays welcome text
int choicer(const int& minNum, const int& maxNum);//returns int if it is = or between minnum and maxnum
void graphicsOptions();//allows change of text, background and boldness
void changeTxtColour();
void changeBckgColour();
void gfxMoreOptions();
void versionHistory();
void logging();//the main purpose of the program
void displayLog();//displays the log file
void listCommands();//lists available escape commands of the program
const string getTime(string _s = "%Y-%m-%d[%H:%M:%S](%A)");//return date and time based on tokens passed

int main()
{
    welcome();

    int choice;
    do
    {
        cout <<"\nMAIN MENU\n";
        cout << "1 - Start logging\n";
        cout << "2 - Display the log\n";
        cout << "3 - Display version history\n";
        cout << "4 - Lists available commands\n";
        cout << "5 - Graphics Settings(LINUX Terminal)\n";
        cout << "0 - Quit.\n";
        choice = choicer(0, 5);
        if(choice == 1)
            logging();
        else if(choice == 2)
            displayLog();
        else if(choice == 3)
            versionHistory();
        else if(choice == 4)
            listCommands();
        else if(choice == 5)
            graphicsOptions();
        else if(choice == 0)
            break;
        else
            cout << "\n\nFREAKING OUT\n";
    }while(choice != 0);

    cout << "\nQuitting.\n";
    return 0;
}

void welcome()
{
    cout << "\nThis is Mylo(my logger) [should release as YOLO(Your Logger)]";
    cout << "\nThis program is a digital diary that stores it's info in an"
        "\neasily human-readable file.\n";
}

int choicer(const int& minNum, const int& maxNum)
{
    if(minNum > maxNum)
    {
        cout << "/nError: choicer(): minNum can not be larger than maxNum, returning 0";
        return 0;
    }
    int num;
    do
    {
        cin >> num;
        if(num < minNum || num > maxNum)
            cout << "Ivalid choice, try again.\n";
    }while(num < minNum || num > maxNum);
    return num;
}

void graphicsOptions()
{
    int choice;
    do
    {
        cout << "\nGRAPHICS SETTINGS (Linux)\n";
        cout << "1 - Text colour.\n";
        cout << "2 - Background colour.\n";
        cout << "3 - More options.\n";
        cout << "0 - Close menu.\n";

        choice = choicer(0, 3);
        switch (choice)
        {
        case 1:
            changeTxtColour();
            break;
        case 2:
            changeBckgColour();
            break;
        case 3:
            gfxMoreOptions();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    }while(choice != 0);
}

void changeTxtColour()
{
    cout << "\nGRAPHICS SETTINGS -> TEXT COLOUR\n";
    cout << "1 - Black\n";
    cout << "2 - Red\n";
    cout << "3 - Green\n";
    cout << "4 - Yellow\n";
    cout << "5 - Blue\n";
    cout << "6 - Purple\n";
    cout << "7 - Cyan\n";
    cout << "8 - White\n";
    cout << "0 - Close Menu\n";
    int choice = choicer(0, 8);
    switch (choice)
    {
    case 1:
        cout << "\033[30m";
        cout << "Text is now black.\n";
        break;
    case 2:
        cout << "\033[31m";
        cout << "Text is now red.\n";
        break;
    case 3:
        cout << "\033[32m";
        cout << "Text is now green.\n";
        break;
    case 4:
        cout << "\033[33m";
        cout << "Text is now yellow.\n";
        break;
    case 5:
        cout << "\033[34m";
        cout << "Text is now blue.\n";
        break;
    case 6:
        cout << "\033[35m";
        cout << "Text is now purple.\n";
        break;
    case 7:
        cout << "\033[36m";
        cout << "Text is now cyan.\n";
        break;
    case 8:
        cout << "\033[37m";
        cout << "Text is now white.\n";
        break;
    case 0:
        break;
    default:
        cout << "Invalid choice.\n";
    }
}

void changeBckgColour()
{
    cout << "\nGRAPHICS SETTINGS -> BACKGROUND COLOUR\n";
    cout << "1 - Black\n";
    cout << "2 - Red\n";
    cout << "3 - Green\n";
    cout << "4 - Yellow\n";
    cout << "5 - Blue\n";
    cout << "6 - Purple\n";
    cout << "7 - Cyan\n";
    cout << "8 - White\n";
    cout << "0 - Close Menu\n";
    int choice = choicer(0, 8);
    switch (choice)
    {
    case 1:
        cout << "\033[40m";
        cout << "Background is now black.\n";
        break;
    case 2:
        cout << "\033[41m";
        cout << "Background is now red.\n";
        break;
    case 3:
        cout << "\033[42m";
        cout << "Background is now green.\n";
        break;
    case 4:
        cout << "\033[43m";
        cout << "Background is now yellow.\n";
        break;
    case 5:
        cout << "\033[44m";
        cout << "Background is now blue.\n";
        break;
    case 6:
        cout << "\033[45m";
        cout << "Background is now purple.\n";
        break;
    case 7:
        cout << "\033[46m";
        cout << "Background is now cyan.\n";
        break;
    case 8:
        cout << "\033[47m";
        cout << "Background is now white.\n";
        break;
    case 0:
        break;
    default:
        cout << "Invalid choice.\n";
    }
}

void gfxMoreOptions()
{
    cout << "\nGRAPHICS SETTINGS -> ADDITIONAL OPTIIONS\n";
    cout << "1 - Resest\n";
    cout << "2 - Bold\n";
    cout << "3 - Dim\n";
    cout << "0 - Close Menu\n";
    int choice = choicer(0, 3);
    switch (choice)
    {
    case 1:
        cout << "\033[0m";
        cout << "All parameters reset to default.\n";
        break;
    case 2:
        cout << "\033[1m";
        cout << "Text is now bold.\n";
        break;
    case 3:
        cout << "\033[2m";
        cout << "Text is now dim.\n";
        break;
    case 0:
        break;
    default:
        cout << "Invalid choice.\n";
    }
}

void versionHistory()
{
    cout << endl;
    cout << "***VERSION HISTORY***\n";
    cout << "2013.09.02 00:10 - 0.01\n";
    cout << "--First entry sucessfully saved into file.\n";
    cout << "\n2013.09.02 01:06 - 1.00\n";
    cout << "--Finally the resulting log looks exactly as I envisioned.\n";
    cout << "--Now moving on to polish the program user-friendlyness and extras.\n";
    cout << "\n2013.09.02 02:22 - 1.10\n";
    cout << "--Added a menu, current functions:1.Displaying this history.2.Logging.\n";
    cout << "--02:50 added a 'Quit'(if before logging) function to run nicer in terminal.\n";
    cout << "\n2013.09.02 03:17 - 1.20\n";
    cout << "--TimeBuffer gets displayer into console now, easyer to judge 80chars now.\n";
    cout << "\n2013.09.03 00:37 - 1.30\n";
    cout << "--Added commands: typing \\menu - quits to the main menu.\n";
    cout << "\n2013.09.03 00:45 - 1.31\n";
    cout << "--Redone some things, added the 'List commands' menu option.\n";
    cout << "\n2013.09.03 01:55 - 1.40\n";
    cout << "--Added 'Display log' menu option.\n";
    cout << "\n2013.09.03 03:37 - 1.50\n";
    cout << "--This could be called a sort of a milestone as I have found quite a\n"
        "few situations where the program starts begaving weirdly and bloats the\n"
        "log file with useless entries in most cases. ALL KNOWN ISSUES ELIMINATED.\n";
    cout << "\n2013.09.06 01:48 - 1.51\n";
    cout << "--Unwanted enpty line after typing in location is no locger produced.\n"
        "and the location string can now be filled with spaces like is intuitive.\n";
    cout << "\n2013.09.06 2:23 - 1.52\n";
    cout << "--Done some code optimisation and tidying. Modified display of this history.\n";
    cout << "\n2013.09.07 04:40 - 1.53\n";
    cout << "--Changed the format of the log a little bit with a few generated lines.\n";
    cout << "\n2013.09.07 16:26 - 1.60\n";
    cout << "--Added an option to change the colour of text to main menu.\n";
    cout << "\n2013.09.07 18:19 - 1.70\n";
    cout << "--Created a menu system for Graphic Options and a lot of settings.\n";
    cout << "\n2013.09.09 01:08 - 1.71\n";
    cout << "--Fixed the fact that an entry was missing in the colour select menu.\n";
    cout << "***END***\n";
}

const string getTime(string _s) {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    //%F and %T seems to not work on windows
    strftime(buf, sizeof(buf), _s.c_str(), &tstruct);

    return buf;
}


void logging()
{
    string theInput;
    ofstream theLog;
    const string theTime = getTime();

    theLog.open("TheLog", ios::out | ios::app | ios::binary);

    theLog << "\n[New session at " << theTime << "]\n";
    cout << "Declare your location: ";
    cin.ignore();//dumps the leftover \n from menu selection and anything else if present
    getline(cin, theInput);

	cout << "\nStarting at [" << theTime << "]\n\n";

    if(theInput != "0" && theInput != ""){
		theLog << "Location: " << theInput << endl;
	}

    int a = 0;
    while(a <= 70)
    {
		cout << ">";
        getline(cin, theInput);

        if(theInput == "\\menu"){ // "\\menu" = literal "\menu"
            break;
		}

        theLog << ">" << theInput << endl;

        if(theInput.size() > 70)
        {
            cout << "\nError, String exceeded the limit of 80.\n";
            cout << "Breaking to main menu.\n";
            break;
        }
    }
    theLog << "[End of session at " << getTime() << "]\n";
    theLog.close();
}

void displayLog()
{
    cout << "\nDISPLAYING LOG\n";
    ifstream theLog;
    string line;
    theLog.open("TheLog", ios::in | ios::binary);
        while(! theLog.eof())
        {
            getline(theLog, line);
            cout << line << endl;
        }
    theLog.close();
}

void listCommands()
{
    cout << "\nCOMMANDS";
    cout << "\n \\menu - quits to the main menu.\n";
}

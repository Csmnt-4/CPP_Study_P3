#include <iostream>
#include <string>

#include <unordered_map>

int main() {
    std::string getRaceOrJob(int);
    std::string getNameOrSurnameOrNick(int);
    void printOut(std::string, std::string, std::string, std::string, std::string);

    std::string race;
    std::string job;

    std::string name;
    std::string surname;
    std::string nick;
    std::cout << "Let's create a character!\n";

    int indicator = -1;
    do {
        std::cout << "What do you want to configure?\n\n";

        std::cout << "1) Race\n";
        std::cout << "2) Job\n";
        std::cout << "3) Name\n";
        std::cout << "4) Surname\n";
        std::cout << "5) Nickname\n\n";
        std::cout << "6) Print out the character!\n";
        std::cout << "0) Exit\n\n";
        std::cin >> indicator;
        
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');

        switch (indicator) {
            case 1: {
                race = getRaceOrJob(indicator);
                };
                break;

            case 2: {
                job = getRaceOrJob(indicator);
                };
                break;

            case 3: {
                name = getNameOrSurnameOrNick(indicator);
                };
                break;

            case 4: {
                surname = getNameOrSurnameOrNick(indicator);;
                };
                break;

            case 5: {
                nick = getNameOrSurnameOrNick(indicator);;
                };
                break;

            case 6: {
                printOut(race, job, name, surname, nick);
                };
                break;

            case 0: {
                std::cout << "\nSee you later, bye~!\n\n";
                std::system("pause");
                };
                break;

            default: {
                std::cout << "\nIncorrect input, could you please try again?\n\n";
                };
                break;
        }

    std::system("cls");
    } while (indicator > 0);
}

void printOut(std::string race, std::string job, std::string name, std::string surname, std::string nick) {
    std::system("cls");
    std::cout << "Your character:";

    if (!race.empty()) {
        std::cout << "\nRace:\t" << race;
    };
    if (!job.empty()) {
        std::cout << "\nJob:\t" << job;
    };

    if (!nick.empty()) {
        name += " \"" + nick + "\" ";
    };
    if (!surname.empty()) {
        name += surname;
    };
    if (!name.empty()) {
        std::cout << "\nName:\t" << name;
    };

    std::cout << "\n\n";
    std::system("pause");
}

std::string getNameOrSurnameOrNick(int indicator) {
    std::system("cls");
    switch (indicator) {
    case 3: {
        std::cout << "Enter the name for your character!\n\n";};
        break;

    case 4: {
        std::cout << "Enter the surname for your character!\n\n";};
        break;

    case 5: {
        std::cout << "Enter the nickname for your character!\n\n";};
        break;

    default: {
        std::cout << "\nSomething went wrong, could you please try again?\n\n"; };
        break;
    }

    std::string string;
    while (string.size() == 0) {
        std::getline(std::cin, string);
        if (string.size() != 0) {
            return string;
        } else {
            std::cout << "\nEmpty input, could you please repeat?\n\n";
        }
    }
    return "";
}

std::string getRaceOrJob(int indicator) {
    std::string string;

    std::system("cls");
    switch (indicator) {
        case 1: {
            std::unordered_map<std::string, std::string> map{
                {"one",     "Human"},
                {"1",       "Human"},
                {"1)",      "Human"},
                {"Human",   "Human"},
                {"human",   "Human"},

                {"two",     "Dwarf"},
                {"2",       "Dwarf"},
                {"2)",      "Dwarf"},
                {"Dwarf",   "Dwarf"},
                {"dwarf",   "Dwarf"},

                {"three",   "Elf"},
                {"3",       "Elf"},
                {"3)",      "Elf"},
                {"Elf",     "Elf"},
                {"elf",     "Elf"},

                {"four",    "Halfing"},
                {"4",       "Halfing"},
                {"4)",      "Halfing"},
                {"Halfing", "Halfing"},
                {"halfing", "Halfing"},

                {"five",    "Gnome"},
                {"5",       "Gnome"},
                {"5)",      "Gnome"},
                {"Gnome",   "Gnome"},
                {"gnome",   "Gnome"},

                {"six",     "Tiefling"},
                {"6",       "Tiefling"},
                {"6)",      "Tiefling"},
                {"Tiefling", "Tiefling"},
                {"tiefling", "Tiefling"},

                {"seven",   "Dragonborn"},
                {"7",       "Dragonborn"},
                {"7)",      "Dragonborn"},
                {"Dragonborn",  "Dragonborn"},
                {"Dragonborn",  "Dragonborn"},

                {"eight",   "Half-Elf"},
                {"8",       "Half-Elf"},
                {"8)",      "Half-Elf"},
                {"Half-Elf", "Half-Elf"},
                {"Half-elf", "Half-Elf"},
                {"half-elf", "Half-Elf"},
                {"Half Elf", "Half-Elf"},
                {"Half elf", "Half-Elf"},
                {"half elf", "Half-Elf"},

                {"nine",    "Half-Orc"},
                {"9",       "Half-Orc"},
                {"9)",      "Half-Orc"},
                {"Half-Orc", "Half-Orc"},
                {"Half-orc", "Half-Orc"},
                {"half-orc", "Half-Orc"},
                {"Half Orc", "Half-Orc"},
                {"Half orc", "Half-Orc"},
                {"half orc", "Half-Orc"},

                {"10",      ""},
                {"10)",     ""},
                {"X",       ""},
                {"x",       ""},
                {"Exit",    ""},
                {"exit",    ""},
            };
            auto end = map.end();

            std::cout << "Choose your race!\n\n";
            std::cout << "1) Human\t6) Tiefling\n";
            std::cout << "2) Dwarf\t7) Dragonborn\n";
            std::cout << "3) Elf\t\t8) Half-Elf\n";
            std::cout << "4) Halfing\t9) Half-Orc\n";
            std::cout << "5) Gnome\n\t\tx) Exit\n";

            auto it = map.find("");
            do {
                std::getline(std::cin, string);
                auto it = map.find(string);
                if (it != end) {
                    string = it->second;
                    return string;
                } else {
                    std::cout << "\nIncorrect input, could you please repeat?\n\n";
                }
            } while (it == end);
            return "";
            }
            break;

        case 2: {
            std::unordered_map<std::string, std::string> map{
                {"one",     "Thief"},
                {"1",       "Thief"},
                {"1)",      "Thief"},
                {"Thief",   "Thief"},
                {"thief",   "Thief"},

                {"two",     "Archer"},
                {"2",       "Archer"},
                {"2)",      "Archer"},
                {"Archer",  "Archer"},
                {"archer",  "Archer"},

                {"three",   "Warrior"},
                {"3",       "Warrior"},
                {"3)",      "Warrior"},
                {"Warrior", "Warrior"},
                {"warrior", "Warrior"},

                {"four",    "Mage"},
                {"4",       "Mage"},
                {"4)",      "Mage"},
                {"Mage",    "Mage"},
                {"mage",    "Mage"},

                {"five",    "Cook"},
                {"5",       "Cook"},
                {"5)",      "Cook"},
                {"Cook",   "Cook"},
                {"cook",   "Cook"},

                {"six",     "Bard"},
                {"6",       "Bard"},
                {"6)",      "Bard"},
                {"Bard",    "Bard"},
                {"bard",    "Bard"},

                {"seven",   "Herbalist"},
                {"7",       "Herbalist"},
                {"7)",      "Herbalist"},
                {"Herbalist",  "Herbalist"},
                {"herbalist",  "Herbalist"},

                {"eight",   "Paladin"},
                {"8",       "Paladin"},
                {"8)",      "Paladin"},
                {"Paladin", "Paladin"},
                {"paladin", "Paladin"},

                {"nine",    "Alchemist"},
                {"9",       "Alchemist"},
                {"9)",      "Alchemist"},
                {"Alchemist", "Alchemist"},
                {"alchemist", "Alchemist"},

                {"10",      ""},
                {"10)",     ""},
                {"X",       ""},
                {"x",       ""},
                {"Exit",    ""},
                {"exit",    ""},
            };
            auto end = map.end();

            std::cout << "Choose your job!\n\n";
            std::cout << "1) Thief\t6) Bard\n";
            std::cout << "2) Archer\t7) Herbalist\n";
            std::cout << "3) Warrior\t8) Paladin\n";
            std::cout << "4) Mage\t\t9) Alchemist\n";
            std::cout << "5) Cook\n\t\tx) Exit\n";
            auto it = map.find("");
            do {
                std::getline(std::cin, string);
                auto it = map.find(string);
                if (it != end) {
                    string = it->second;
                    return string;
                } else {
                    std::cout << "\nIncorrect input, could you please repeat?\n\n";
                }
            } while (it == end);
            return "";
            }
            break;

        default: {
            std::cout << "\nSomething went woring.\n\n";
            return ""; 
            }
            break;
    }
}

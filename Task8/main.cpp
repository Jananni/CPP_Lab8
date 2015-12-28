

/* CS 2A Lab 6
 * Instructor Solution
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class DateProfile
{
private:
   char gender;
   char searchGender;
   int romance;
   int finance;
   string name;

   double determineGenderFit(DateProfile partner);
   double determineRomanceFit(DateProfile partner);
   double determineFinanceFit(DateProfile partner);

public:
   static const int MIN_ROMANCE;
   static const int MAX_ROMANCE;
   static const int MIN_FINANCE;
   static const int MAX_FINANCE;
   static const int MIN_NAME_LEN;
   static const int MAX_NAME_LEN;
   static const char DEFAULT_GEN;
   static const char DEFAULT_SEARCH_GEN;
   static const int DEFAULT_ROMANCE;
   static const int DEFAULT_FINANCE;
   static const string DEFAULT_NAME;

   DateProfile();
   DateProfile(char gen, char searchGen, int intRomance, int intFinance,
               string profileName);
   bool setGen(char gen);
   bool setSearchGen(char searchGen);
   bool setRomance(int intRomance);
   bool setFinance(int intFinance);
   bool setName(string profileName);
   void setAll(char gen, char searchGen, int intRomance, int intFinance,
               string profileName);
   void setDefaults();
   double fitValue(DateProfile partner);

   // accessors
   char getGen()
   {
      return gender;
   }
   char searchGen()
   {
      return searchGender;
   }
   int getRomance()
   {
      return romance;
   }
   int getFinance()
   {
      return finance;
   }
   string getName()
   {
      return name;
   }

};

// define static constants
int const DateProfile::MIN_ROMANCE = 0;
int const DateProfile::MAX_ROMANCE = 10;
int const DateProfile::MIN_FINANCE = 0;
int const DateProfile::MAX_FINANCE = 10;
int const DateProfile::MIN_NAME_LEN = 3;
int const DateProfile::MAX_NAME_LEN = 20;
char const DateProfile::DEFAULT_GEN = 'f';
char const DateProfile::DEFAULT_SEARCH_GEN = 'm';
int const DateProfile::DEFAULT_ROMANCE = 5;
int const DateProfile::DEFAULT_FINANCE = 5;
string const DateProfile::DEFAULT_NAME = "Amy Peterson";

void displayTwoProfiles(DateProfile profile1, DateProfile profile2);

// client ---------------------------------------------------------------------
int main()
{
   DateProfile applicant1, applicant2, applicant3, applicant4;
   applicant1.setAll('m', 'm', 6, 2, "Josh");
   applicant3.setAll('f', 'm', 2, 10, "Allison");
   applicant4.setAll('m', 'f', 1, 7, "Bob Wilson");

   displayTwoProfiles(applicant1, applicant1);
   displayTwoProfiles(applicant1, applicant2);
   displayTwoProfiles(applicant1, applicant3);
   displayTwoProfiles(applicant1, applicant4);

   displayTwoProfiles(applicant2, applicant1);
   displayTwoProfiles(applicant2, applicant2);
   displayTwoProfiles(applicant2, applicant3);
   displayTwoProfiles(applicant2, applicant4);

   displayTwoProfiles(applicant3, applicant1);
   displayTwoProfiles(applicant3, applicant2);
   displayTwoProfiles(applicant3, applicant3);
   displayTwoProfiles(applicant3, applicant4);

   displayTwoProfiles(applicant4, applicant1);
   displayTwoProfiles(applicant4, applicant2);
   displayTwoProfiles(applicant4, applicant3);
   displayTwoProfiles(applicant4, applicant4);

}

void displayTwoProfiles(DateProfile profile1, DateProfile profile2)
{
   cout << "Fit between " << profile1.getName() << " and " << profile2.getName()
   << ":" << endl;
   cout << profile1.fitValue(profile2) << endl << endl;
}

//Date Profile class methods
//constructors

DateProfile::DateProfile()
{
   setDefaults();
}

DateProfile::DateProfile(char gen, char searchGen, int intRomance,
                         int intFinance, string profileName)
{
   setAll(gen, searchGen, intRomance, intFinance, profileName);
}

// mutators
bool DateProfile::setGen(char gen)
{
   gender = gen;
   return true;
}

bool DateProfile::setSearchGen(char searchGen)
{
   searchGender = searchGen;
   return true;
}

bool DateProfile::setRomance(int intRomance)
{
   if (intRomance > MAX_ROMANCE || intRomance < MIN_ROMANCE)
      return false;
   romance = intRomance;
   return true;
}

bool DateProfile::setFinance(int intFinance)
{
   if (intFinance > MAX_FINANCE || intFinance < MIN_FINANCE)
      return false;
   finance = intFinance;
   return true;
}

bool DateProfile::setName(string profileName)
{
   if (profileName.length() > MAX_NAME_LEN ||
       profileName.length() < MIN_NAME_LEN)
      return false;
   name = profileName;
   return true;
}

void DateProfile::setAll(char gen, char searchGen, int intRomance,
                         int intFinance, string profileName)
{
   setGen(gen);
   setSearchGen(searchGen);
   setRomance(intRomance);
   setFinance(intFinance);
   setName(profileName);
}

void DateProfile::setDefaults()
{
   gender = DEFAULT_GEN;
   searchGender = DEFAULT_SEARCH_GEN;
   romance = DEFAULT_ROMANCE;
   finance = DEFAULT_FINANCE;
   name = DEFAULT_NAME;
}

double DateProfile::fitValue(DateProfile partner)
{
   if(determineGenderFit(partner) == 1.0)
   {
      double value = ( determineRomanceFit(partner) +
                      determineFinanceFit(partner) )/2;
      return value;
   }
   return 0.0;
}

// helper method
double DateProfile::determineGenderFit(DateProfile partner)
{
   if(this->gender == partner.searchGender &&
      this->searchGender == partner.gender)
   {
      return 1.0;
   }
   return 0.0;
}

double DateProfile::determineRomanceFit(DateProfile partner)
{
   double value = 1 - abs(this->romance - partner.romance) * 0.1;
   return value;
}

double DateProfile::determineFinanceFit(DateProfile partner)
{
   double value = 1 - abs(this->finance - partner.finance) * 0.1;
   return value;
}


/* ------------------------------- run -----------------------------------
 
 Fit between Josh and Josh:
 1

 Fit between Josh and Amy Peterson:
 0

 Fit between Josh and Allison:
 0

 Fit between Josh and Bob Wilson:
 0

 Fit between Amy Peterson and Josh:
 0

 Fit between Amy Peterson and Amy Peterson:
 0

 Fit between Amy Peterson and Allison:
 0

 Fit between Amy Peterson and Bob Wilson:
 0.7

 Fit between Allison and Josh:
 0

 Fit between Allison and Amy Peterson:
 0

 Fit between Allison and Allison:
 0

 Fit between Allison and Bob Wilson:
 0.8

 Fit between Bob Wilson and Josh:
 0

 Fit between Bob Wilson and Amy Peterson:
 0.7

 Fit between Bob Wilson and Allison:
 0.8

 Fit between Bob Wilson and Bob Wilson:
 0
 
 Program ended with exit code: 0
 
 ------------------------------------------------------------------------- */

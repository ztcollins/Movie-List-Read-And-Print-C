#include "student_functions.h"
#include <stdio.h>

int main() {

// char t[] = "  test";
// Clean_Whitespace(t);
// if (t == "test") give points
// else give 0;
//
// "test  "
// "test   test"
// "\t  \t test    test  \n"
//
// "IronMAn"
// "bLAck panTHer"
// "The dread pirate roberts"
//
// "Ironman"
// "Black Panther"
// "The Dread Pirate Roberts"
//
// `

	// the string to test
  	char myString[] = "\t How to train  your  DRAGON  \0";
 
  	printf("Before: \"%s\"\n", myString);

  	// add the function you want to test
	Fix_Case(myString);
	
	printf("After:  \"%s\"\n", myString);

  	Clean_Whitespace(myString);

	printf("After:  \"%s\"\n", myString);

  	Fix_Case(myString);

  	printf("After:  \"%s\"\n", myString);

	char yearToTest[] = "2005\0";

	int year = String_To_Year(yearToTest);

	printf("%d\n", year);

	char directerTest[] = "Bucky Badger";

	Director_Last_Name(directerTest);

	printf("%s\n", directerTest);

	char ratingTest[] = "-1.3453\0";

	float rating = String_To_Rating(ratingTest);

	printf("%f\n", rating);

	char dollarsTestK[] = "123K";

	char dollarsTestM[] = "123M";

	long long kExtended = String_To_Dollars(dollarsTestK);	
  
	long long mExtended = String_To_Dollars(dollarsTestM);

	printf("%lld\n", kExtended);

	printf("%lld\n", mExtended);

  	return 0;
}

/* Zachary Collins
 * ztcollins@wisc.edu
*/

/* This function takes a string as input and removes 
 * leading and trailing whitespace including spaces
 * tabs and newlines. It also removes multiple internal
 * spaces in a row. Arrays are passed by reference.
 */

#include <stdio.h>
#include <stdlib.h>
#include "student_functions.h"

void Clean_Whitespace(char str[]) {
    
	int count = 0;

	for(int i = 0; str[i]; i++) {
		if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
			str[count++] = str[i];
		} else if(str[i] == ' ' && str[i-1] > 33) {
			str[count++] = str[i];
		}
	}

	str[count] = '\0';
    	return;
}

/* This function takes a string and makes the first
 * letter of every word upper case and the rest of the
 * letters lower case
 */ 
void Fix_Case(char str[]) {
    	
	if(str[0] > 95) {
		str[0] = str[0]-32;
	}
	//printf("%s\n", str);
	for(int i = 0; str[i]; i++) {
                if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
                        if(str[i+1] != ' ' && str[i+1] != '\t' && str[i+1] != '\n') {
				i++;
                        	if(str[i] > 95) {
                                	str[i] = str[i]-32;
                	        }
				
			}
                }
		else{
			if(str[i] < 95 && i != 0) {
				str[i] = str[i]+32;
			}
		}
		//printf("%s\n", str);
        }

    	return;
}

/* this function takes a string and returns the 
 * integer equivalent
 */
int String_To_Year(char str[]) {
    	
	int sum = 0;

	for(int i = 0; str[i]; i++) {
		sum = sum*10 + (str[i] - 48);	
	}

    	return sum;
}


/* this function takes the name of a 
 * director as a string and removes all but
 * the last name.  Example:
 * "Bucky Badger" -> "Badger"
 */
void Director_Last_Name(char str[]) {
    	
	int count = 0;
	int capitalCount = 0;
	int capitals = 0;
	int lastNameStart = 0;
	
	/*if(str[0] == ' ') {
		count++;
	}*/

	//printf("%s\n", str);
	Fix_Case(str);

	//printf("%s\n", str);
	Clean_Whitespace(str);

	//printf("%s\n", str);

	while(str[capitalCount]) {
		capitalCount++;
		if(str[capitalCount] < 95) {
			capitals++;
		}

	}
	//printf("%d\n", capitals);
	while(str[count]) {
		if(str[count] < 95) {
			capitals--;
			//printf("%c\n", str[count]);
		}
		if(capitals == 0) {
			lastNameStart = count;
			break;
		}
		count++;
	}
	//printf("%d\n", lastNameStart);

	count = lastNameStart;

	for(int i = 0; str[i]; i++) {
                
		if(str[count]) {
			str[i] = str[count];
			count++;
		}
		else {
			str[i] = ' ';
		}
        }
	/*Fix_Case(str);
	Clean_Whitespace(str);

	while(str[count]) {
		count++;
	}

	int length = count-1;

	while(str[length] > 95) {
		length--;
	}

	int lastNameIndex = length;

	for(int i = 0; i < count-lastNameIndex; i++) {
		str[i] = str[count-lastNameIndex+i];
	}	*/
    	return;
}


/* this function takes the a string and returns
 * the floating point equivalent
 */
float String_To_Rating(char str[]) {
    	float sum = 0, coefficient = 1;
	int i = 0, point = 0;

	if(str[0] == '-') {
		i++;
		coefficient = -1;
	}

	for(; str[i]; i++) {

		if(str[i] == '.') {
			point = 1;
		}

		int decimal = str[i] - '0';

		if(decimal >= 0 && decimal <= 9) {
			if(point) {
				coefficient /= 10.0f;
			}
			sum = sum * 10.0f + (float)decimal;
		}	
	}

    return sum*coefficient;
}


/* this function takes a string representing
 * the revenue of a movie and returns the decimal
 * equivlaent. The suffix M or m represents millions,
 * K or k represents thousands.
* example: "123M" -> 123000000 
*/
long long String_To_Dollars(char str[])  {
    
	long long sum = 0;

        for(int i = 0; str[i]; i++) {

		if(str[i] == 'm' || str[i] == 'M') {
			sum = sum*1000000;
		}
		else if(str[i] == 'k' || str[i] == 'K') {
                        sum = sum*1000;
                }else{
			sum = sum*10 + (str[i] - 48);
		}
        }

        return sum;

}


/* This function takes the array of strings representing 
 * the csv movie data and divides it into the individual
 * components for each movie.
 * Use the above helper functions.
 */
void Split(char csv[10][1024], int num_movies, char titles[10][1024], int years[10], char directors[10][1024], float ratings[10], long long dollars[10]) {

	//num_movies = csv[0][0]-48;
	
	
	for(int i = 0; i < num_movies; i++) {
		char buf[1024];
		char yearBUF[1024];
		char dollarBUF[1024];
		char ratingBUF[1024];
		int yearCOUNT = 0;
		int count = 0;
		int j = 0;
		int field = 0;
	while(field != 6) {
		while(csv[i][count] != ',' && csv[i][count]) {
			if(csv[i][count] == '\n') {
				break;
			}
			buf[j] = csv[i][count];
			j++;
			count++;
		}
		for(int l = 0; l < j; l++) {
			if(field == 0) {
				//Clean_Whitespace(buf);
				Fix_Case(buf);
				titles[i][l] = buf[l];
			}
			if(field == 1) {
				yearBUF[l] = buf[l];
				yearCOUNT++;
				
				if(yearCOUNT == 5) {
					Clean_Whitespace(yearBUF);
                                	years[i] = String_To_Year(yearBUF);
					//printf("%s", yearBUF);
				}

                        }
			if(field == 2) {
                                //directors[i][l] = buf[l];
                        }
			if(field == 3) {
                                directors[i][l] = buf[l];
                        }
			if(field == 4) {
				ratingBUF[l] = buf[l];
				//Clean_Whitespace(buf);
                                //ratings[i] = String_To_Rating(buf);
                        }
			if(field == 5) {
				//printf("%s", buf);
				dollarBUF[l] = buf[l];
			}

		}
		if(field == 4) {
			//Clean_Whitespace(ratingBUF);
			ratings[i] = String_To_Rating(ratingBUF);
			for(int i = 0; i < 12; i++) {
                                ratingBUF[i] = '\0';
                        }
		}
		if(field == 5) {
			//printf("%s", dollarBUF);
			Clean_Whitespace(dollarBUF);
			//printf("%s", dollarBUF);
                        dollars[i] = String_To_Dollars(dollarBUF);
			for(int i = 0; i < 12; i++) {
				dollarBUF[i] = '\0';
                        }
		}
		for(int i = 0; i < 150; i++) {
                                buf[i] = '\0';
                }
		field++;
		j = 0;
		count++;
	}

	}
	
	return;
}



/* This function prints a well formatted table of
 * the movie data 
 * Row 1: Header - use name and field width as below
 * Column 1: Id, field width = 3, left justified
 * Column 2: Title, field width = lenth of longest movie + 2 or 7 which ever is larger, left justified, first letter of each word upper case, remaining letters lower case, one space between words
 * Column 3: Year, field with = 6, left justified
 * Column 4: Director, field width = length of longest director last name + 2 or 10 (which ever is longer), left justified, only last name, first letter upper case, remaining letters lower case
 * column 5: Rating, field width = 6, precision 1 decimal place (e.g. 8.9, or 10.0), right justified
 * column 6: Revenue, field width = 11, right justified
 */
void Print_Table(int num_movies, char titles[10][1024], int years[10], char directors[10][1024], float ratings[10], long long dollars[10]) {
   	
       	
	int id_length = 3;
	int title_length = 7; //longest + 2
	int year_length = 6;
	int director_length = 10; // longest + 2
	int rating_length = 6;
	int revenue_length = 11;

		

	//LONGEST TITLE
	int titleBuf = 0;
	//int capitalCount = 0;
	/*for(int titleRow = 0; titleRow < num_movies; titleRow++) {
		Clean_Whitespace(titles[i]);
		while(str[capitalCount]) {
                	if(str[capitalCount] < 95) {
                        	capitals++;
                	}
			capitalCount++;
        	}		
	}*/
	/*

	for(int titleRow = 0; titleRow < num_movies; titleRow++) {
		int titleCount = 0;
		titleBuf = 0;
		Clean_Whitespace(titles[titleRow]);
		while(titles[titleRow][titleBuf]) {
			titleCount++;
			titleBuf++;
		}
		//printf("%d\n", titleCount);
		if((titleCount+2) > title_length) {
			title_length = titleCount+2;
		}
		//printf("%d\n", title_length);
	}
	
	//LONGEST DIRECTOR
	
	int directorBuf = 0;
	
	char directorLastName[10][1024];
	int nameBuf = 0;

	for(int nameRow = 0; directors[nameRow][nameBuf]; nameRow++) {
		char lastName[1024];
		while(directors[nameRow][nameBuf]) {
			lastName[nameBuf] = directors[nameRow][nameBuf];
			nameBuf++;
		}
		//printf("%s", lastName);
		
		Director_Last_Name(lastName);
		Clean_Whitespace(lastName);
		//printf("%s", lastName);
		nameBuf = 0;
		while(lastName[nameBuf]) {
			directorLastName[nameRow][nameBuf] = lastName[nameBuf];
			nameBuf++;
		}
		for(int i = 0; i < 120; i++) {
                                lastName[i] = '\0';
                }
		nameBuf = 0;
	}

	for(int directorRow = 0; directorRow < num_movies; directorRow++) {
                int directorCount = 0;
		directorBuf = 0;

                while(directorLastName[directorRow][directorBuf]) {
                        if(directorLastName[directorRow][directorBuf] > 33) {
				directorCount++;
			}
			directorBuf++;
			//directorCount++;
			//directorBuf++;
			//printf("%d\n", directorCount);
                }
		//printf("%d\n", directorCount);
                if((directorCount+2) > director_length) {
                        director_length = directorCount+2;
                }
		//printf("%d\n", director_length);
        }
	*/

	
	//PRINTER
	
	
	printf("%-*s", id_length,"Id");
	printf("%-*s", title_length,"Title");
	printf("%-*s", year_length,"Year");
	printf("%-*s", director_length,"Director");
	printf("%*s", rating_length,"Rating");
	printf("%*s\n", revenue_length,"Revenue");

	for(int i = 0; i < num_movies; i++) {
		//printf("%*.1f\n", rating_length, ratings[i]);
		//printf("%*lld\n", revenue_length, dollars[i]);
		printf("%-*d", id_length, i+1);
		printf("%-*s", title_length, titles[i]);
		printf("%-*d", year_length, years[i]);
		printf("%-*s", director_length, directorLastName[i]);
		//Clean_Whitespace(ratings[i]);
		printf("%*.1f", rating_length, ratings[i]);
		printf("%*lld", revenue_length, dollars[i]);
		printf("\n");
		
		}
	

    	return;
}



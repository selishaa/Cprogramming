// Selisha Thapa
/*
 * This program takes input from a specified file, processes each character, and creates an output file
 * based on certain criteria. It calculates the size difference between the input and output files,
 * and reports relevant statistics, including the number of letters not included in the output.
 */

#include <stdio.h>
#include <ctype.h>

int main() {
    char inputFileName[20], outputFileName[20]; //declaring variable which holds the name of the input file
    char first, second; // declaring variable which holds the first and second letter
    char currentChar; // declaring variable which holds the current character
    int inputSize = 0, outputSize = 0, lettersNotOutput = 0; // declaring variable which holds the size of input, output and letters not output
    FILE *inputFile; // declaring variable which holds the input file
    FILE *outputFile ; // declaring variable which holds the output file

    // Prompt the user for input file name
    printf("Enter the input file name: "); // asking the user to enter the input file name
    scanf("%s", inputFileName); // reading the input file name

    // Prompt the user for output file name
    printf("Enter the output file name: "); // asking the user to enter the output file name
    scanf("%s", outputFileName); // reading the output file name

    // Validate and input two letters
    do {
        printf("Enter two letters separated by a blank space: "); // asking the user to enter two letters separated by a blank space
        scanf(" %c %c", &first, &second);
    } while (!isalpha(first) || !isalpha(second) || tolower(first) >= tolower(second)); // validating the input two letters

    inputFile = fopen(inputFileName, "r"); // opening the input file in read mode
    outputFile = fopen(outputFileName, "w"); // opening the output file in write mode

    if (inputFile == NULL || outputFile == NULL) { // checking if the input file and output file is empty
        printf("Error opening files.\n"); // printing the error message
        return 1; // returning 1 if the file is empty
    }



    // Read characters from the input file and process them
    while (fscanf(inputFile, "%c", &currentChar) == 1) {  // reading the characters from the input file and processing them.The fscanf function scans each
        // character and stores it in the currentChar variable. The loop continues as long as fscanf successfully reads and assigns a character
        inputSize++; // incrementing the input size
        printf("%c%d",currentChar,inputSize); // printing the current character and the size of the input file



        if ( (isalpha(currentChar) && (tolower(currentChar) >= tolower(first) && tolower(currentChar) <= tolower(second))) ||
            isspace(currentChar) || ispunct(currentChar)) {
            // Output the character if it is a letter between the two input letters, a space, or punctuation. his condition ensures filtering for specific characters of interest
            // during character processing.

            outputSize++; // incrementing the output size
        } else if (isalpha(currentChar)) {
            // Count the number of letters not output
            lettersNotOutput++; // incrementing the letters not output
        }
    }

    // Close files
    fclose(inputFile); // closing the input file
    fclose(outputFile); // closing the output file

    // Calculate the percentage file change based on the difference between input and output sizes
    double percentageChange = (double) outputSize/ inputSize * 100; // calculating the percentage change

    // Output a short report
    printf("Size of %s is: %d\n", inputFileName, inputSize); // printing the size of the input file
    printf("Size of %s is: %d\n", outputFileName, outputSize); // printing the size of the output file
    printf("Letters not output is: %d\n", lettersNotOutput); // printing the letters not output
    printf("Difference in size is: %.2f%%\n", percentageChange); // printing the difference in size

    return 0; // returning 0 if the program is executed successfully
}


/**
 OUTPUT
p1in1-2.txt

Size of p1in1-2.txt is: 158
Size of output.txt is: 111
Letters not output is: 47
Difference in size is: 70.25%

output file
Infomion i no knoledge;
knoledge i no idom,
idom i no h,
h -- i no be,
be i no loe,
loe i no mic.
MIC i he BE!


p1in2-2.txt

Size of p1in2-2.txt is: 716
Size of output.txt is: 591
Letters not output is: 108
Difference in size is: 82.54%

Output file
ution is efine s "inferene to the est explntion,"
 tsk of generting n explntion to ount for the
pperne of  given set of finings or t [].  Within
the ontext of hnwritten hrter reognition, the tsk
is one of hpothesiing the hrters (or smols/wors)
responsile for the fetures foun in snne itmps;
the tsk ttempts to fin the est olletion of hrters to
explin these fetures.  ution hs previousl een
pplie to  wie rnge of interprettion prolems inluing
speeh reognition [], ignosis [, , ], meil test
interprettion [], stor unerstning [], nturl
lnguge unerstning [, ], theor formtion n legl
resoning [].

 */







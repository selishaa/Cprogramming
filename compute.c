
// compute.c which contains all the functions related to computation of the program

#include "header.h" // Include header file for function prototypes which are defined in header.h file

// Function to compute the starting salary, potential bonus and potential ceiling based on the student's information and store the results in the appropriate variables using pointers
void compute(int yearsOfWorkExp, int numHonorsCourses, int numExtraCurricular, int numVolunteer, double GPA, const char *major, const char *minor, int *baseSalary, int *potentialBonus, int *potentialCeiling) {
    int totalActivities;
    // Initialize potential bonus to 0
    *potentialBonus = 0; // Initialize potential bonus to 0

    // Check major and minor disciplines
    if (isTech(major) ) { // Check if the major is tech
        *baseSalary = 56000; // Base salary for tech majors


    } else if (isScience(major) ) { // Check if the major is science
        *baseSalary = 48000; // Base salary for science majors


    } else if (isHumanities(major) ) { // Check if the major is humanities
        *baseSalary = 36000; // Base salary for humanities majors


    } else { // Default base salary for other majors
        *baseSalary = 40000; // Default base salary for other majors

    }

// check minor bonuses
    if (isTech(minor)) { // Check if the minor is tech
        *baseSalary += 4500; // Bonus for tech minors

    }else if (isScience(minor)) { // Check if the minor is science
        *baseSalary += 2500; // Bonus for science minors

    }

    // Adjust base salary based on years of work experience
    if (yearsOfWorkExp > 5) { // Check if the years of work experience is greater than 5
        *baseSalary += 4000; // Bonus for work experience greater than 5 years
    } else if (yearsOfWorkExp >= 4) {// Check if the years of work experience is greater than or equal to 4
        *baseSalary += 3200; // Bonus for work experience greater than or equal to 4 years
    } else if (yearsOfWorkExp == 3) { // Check if the years of work experience is 3
        *baseSalary += 2400; // Bonus for work experience of 3 years
    } else if (yearsOfWorkExp >= 1) { // Check if the years of work experience is greater than or equal to 1
        *baseSalary += 1200; // Bonus for work experience greater than or equal to 1 year
    }

    // Adjust base salary based on GPA
    if (GPA > 3.25) { // Check if the GPA is greater than 3.25
        *baseSalary += BONUS_HIGH_GPA; // Bonus for high GPA
    } else if (GPA < 2.50) { // Check if the GPA is less than 2.50
        *baseSalary -= BONUS_LOW_GPA; // Penalty for low GPA
    }

    // Compute total activities  honors, extracurricular activities and volunteer activities
    totalActivities = numHonorsCourses + numExtraCurricular + numVolunteer;// Compute total activities which is the sum of honors courses, extracurricular activities, and volunteer activities

    // Compute potential bonus
    if (totalActivities > BONUS_ACTIVITY_THRESHOLD) { // Check if the total activities exceed the threshold for bonus activity
        *potentialBonus = (totalActivities - BONUS_ACTIVITY_THRESHOLD) * BONUS_ACTIVITY_AMOUNT; // Bonus for each activity over the threshold
    }

    // Apply tech bonus for having both major and minor in tech
    if (isTech(major) && isTech(minor)) { // Check if the major and minor are both tech
        *potentialBonus += BONUS_TECH_TECH_MINOR; // Bonus for having both major and minor in tech
    }

    if (isHumanities(major) ) { // Check if the major is humanities
        *potentialBonus -= BONUS_HUMANITIES; // Penalty for having a major in humanities
    }

    // Ensure potential bonus is not negative
    if (*potentialBonus < 0) { // Check if the potential bonus is negative
        *potentialBonus = 0; // Set the potential bonus to 0 if it is negative
    }

    // Compute potential ceiling
    *potentialCeiling = 10000; // Initialize potential ceiling to 10000

    // Adjust potential ceiling based on work experience
    if (yearsOfWorkExp > CEILING_EXPERIENCE_THRESHOLD) { // Check if the years of work experience exceed the threshold for potential ceiling
        *potentialCeiling += 20000; // Bonus for work experience greater than the threshold
    }

    // Adjust potential ceiling based on major and minor
    if (isTech(major) && (isTech(minor) || isScience(minor))) { // Check if the major is tech and the minor is tech or science
        *potentialCeiling += 16000; // Bonus for having major in tech and minor in tech or science
    } else if (isHumanities(major) && isHumanities(minor)) { // Check if the major is humanities and the minor is humanities
        *potentialCeiling -= 3800; // Penalty for having major and minor in humanities
    }
}


void range(int baseSalary, int potentialBonus, int potentialCeiling, int *expectedStartingSalary, int *maxCareerSalary) {// Calculate expected starting salary and maximum career salary based on the base salary, potential bonus, and potential ceiling by using pointers to store the results
    // Calculate expected starting salary
    *expectedStartingSalary = baseSalary + (potentialBonus / 3); // Calculate expected starting salary by adding one-third of the potential bonus to the base salary


    // Calculate maximum career salary
    *maxCareerSalary = baseSalary + potentialCeiling + potentialBonus; // Calculate maximum career salary by adding the potential ceiling and potential bonus to the base salary
}

// Output the student's first name, last name, expected starting salary, and maximum career salary to the console
void update(int *totalStudents, int *totalTechMajors, int *totalStartingSalary, int *totalMaxSalary, int *totalStartingTechSalary, int *totalMaxTechSalary, const char *major, int startingSalary, int maxSalary) {
    // Update total number of students
    (*totalStudents)++; // Increment the total number of students

    // Update total starting and maximum salaries of all students
    *totalStartingSalary += startingSalary; // Add the starting salary to the total starting salary
    *totalMaxSalary += maxSalary; // Add the maximum salary to the total maximum salary

    // Check if the student is a tech major
    if (isTech(major)) { // Check if the major is tech
        // Update total number of tech majors
        (*totalTechMajors)++;// Increment the total number of tech majors

        // Update total starting and maximum salaries for tech majors
        *totalStartingTechSalary += startingSalary; // Add the starting salary to the total starting salary for tech majors
        *totalMaxTechSalary += maxSalary; // Add the maximum salary to the total maximum salary for tech majors
    }
}

int isTech(const char *str) {  // Check if the discipline is tech and return 1 if it is tech and 0 otherwise
    return strcmp(str, "ASE") == 0 || strcmp(str, "CIT") == 0 || strcmp(str, "CSC") == 0 || // Check if the discipline is ASE, CIT, or CSC
           strcmp(str, "CYS") == 0 || strcmp(str, "DFX") == 0 || strcmp(str, "DSC") == 0;  // Check if the discipline is CYS, DFX, or DSC
}


int isScience(const char *str) { // Check if the discipline is science and return 1 if it is science and 0 otherwise
    return strcmp(str, "BIO") == 0 || strcmp(str, "CHE") == 0 || strcmp(str, "PHY") == 0 || strcmp(str, "MAT") == 0; // Check if the discipline is BIO, CHE, PHY, or MAT
}


int isHumanities(const char *str) { // Check if the discipline is humanities and return 1 if it is humanities and 0 otherwise
    return strcmp(str, "ANT") == 0 || strcmp(str, "ART") == 0 || strcmp(str, "ENG") == 0 || // Check if the discipline is ANT, ART, or ENG
           strcmp(str, "HIS") == 0 || strcmp(str, "MUS") == 0 || strcmp(str, "PHI") == 0 || // Check if the discipline is HIS, MUS, or PHI
           strcmp(str, "SOC") == 0;
}



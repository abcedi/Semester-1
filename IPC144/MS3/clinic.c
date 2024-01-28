/*/////////////////////////////////////////////////////////////////////////
						Assignment 1 - Milestone 3
Full Name  : Abcedi Ilacas
Student ID#: 138180211
Email      : ailacas1@myseneca.ca
Section    : NBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
	printf("Pat.# Name            Phone#\n"
		"----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
	if (fmt == FMT_FORM)
	{
		printf("Name  : %s\n"
			"Number: %05d\n"
			"Phone : ", patient->name, patient->patientNumber);
		displayFormattedPhone(patient->phone.number);
		printf(" (%s)\n", patient->phone.description);
	}
	else
	{
		printf("%05d %-15s ", patient->patientNumber,
			patient->name);
		displayFormattedPhone(patient->phone.number);
		printf(" (%s)\n", patient->phone.description);
	}
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
	printf("Clinic Appointments for the Date: ");

	if (isAllRecords)
	{
		printf("<ALL>\n\n");
		printf("Date       Time  Pat.# Name            Phone#\n"
			"---------- ----- ----- --------------- --------------------\n");
	}
	else
	{
		printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
		printf("Time  Pat.# Name            Phone#\n"
			"----- ----- --------------- --------------------\n");
	}
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient, const struct Appointment* appoint, int includeDateField)
{
	if (includeDateField)
	{
		printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
			appoint->date.day);
	}
	printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
		patient->patientNumber, patient->name);

	displayFormattedPhone(patient->phone.number);

	printf(" (%s)\n", patient->phone.description);
}

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
	int selection;

	do {
		printf("Veterinary Clinic System\n"
			"=========================\n"
			"1) PATIENT     Management\n"
			"2) APPOINTMENT Management\n"
			"-------------------------\n"
			"0) Exit System\n"
			"-------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 2);
		putchar('\n');
		switch (selection)
		{
		case 0:
			printf("Are you sure you want to exit? (y|n): ");
			selection = !(inputCharOption("yn") == 'y');
			putchar('\n');
			if (!selection)
			{
				printf("Exiting system... Goodbye.\n\n");
			}
			break;
		case 1:
			menuPatient(data->patients, data->maxPatient);
			break;
		case 2:
			menuAppointment(data);
			break;
		}
	} while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
	int selection;

	do {
		printf("Patient Management\n"
			"=========================\n"
			"1) VIEW   Patient Data\n"
			"2) SEARCH Patients\n"
			"3) ADD    Patient\n"
			"4) EDIT   Patient\n"
			"5) REMOVE Patient\n"
			"-------------------------\n"
			"0) Previous menu\n"
			"-------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 5);
		putchar('\n');
		switch (selection)
		{
		case 1:
			displayAllPatients(patient, max, FMT_TABLE);
			suspend();
			break;
		case 2:
			searchPatientData(patient, max);
			break;
		case 3:
			addPatient(patient, max);
			suspend();
			break;
		case 4:
			editPatient(patient, max);
			break;
		case 5:
			removePatient(patient, max);
			suspend();
			break;
		}
	} while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
	int selection;

	do {
		printf("Edit Patient (%05d)\n"
			"=========================\n"
			"1) NAME : %s\n"
			"2) PHONE: ", patient->patientNumber, patient->name);

		displayFormattedPhone(patient->phone.number);

		printf("\n"
			"-------------------------\n"
			"0) Previous menu\n"
			"-------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 2);
		putchar('\n');

		if (selection == 1)
		{
			printf("Name  : ");
			inputCString(patient->name, 1, NAME_LEN);
			putchar('\n');
			printf("Patient record updated!\n\n");
		}
		else if (selection == 2)
		{
			inputPhoneData(&patient->phone);
			printf("Patient record updated!\n\n");
		}
	} while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
	int selection;

	do {
		printf("Appointment Management\n"
			"==============================\n"
			"1) VIEW   ALL Appointments\n"
			"2) VIEW   Appointments by DATE\n"
			"3) ADD    Appointment\n"
			"4) REMOVE Appointment\n"
			"------------------------------\n"
			"0) Previous menu\n"
			"------------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 4);
		putchar('\n');
		switch (selection)
		{
		case 1:
			viewAllAppointments(data);  // ToDo: You will need to create this function!
			suspend();
			break;
		case 2:
			viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
			suspend();
			break;
		case 3:
			addAppointment(data->appointments, data->maxAppointments,
				data->patients, data->maxPatient);  // ToDo: You will need to create this function!
			suspend();
			break;
		case 4:
			removeAppointment(data->appointments, data->maxAppointments,
				data->patients, data->maxPatient);  // ToDo: You will need to create this function!
			suspend();
			break;
		}
	} while (selection);
}

// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
	int i, found = 0;

	displayPatientTableHeader();

	for (i = 0; i < max; i++)
	{
		if (patient[i].patientNumber != 0)
		{
			displayPatientData(&patient[i], fmt);
			found = 1;
		}
	}
	if (found == 0)
	{
		printf("*** No records found ***\n");
	}
	printf("\n");
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
	int input = -1;

	do
	{
		printf("Search Options\n");
		printf("==========================\n");
		printf("1) By patient number\n");
		printf("2) By phone number\n");
		printf("..........................\n");
		printf("0) Previous menu\n");
		printf("..........................\n");
		printf("Selection: ");

		input = inputIntRange(0, 2);
		printf("\n");

		switch (input)
		{
		case 1:
			searchPatientByPatientNumber(patient, max);
			suspend();
			break;

		case 2:
			searchPatientByPhoneNumber(patient, max);
			suspend();
			break;
		}
	} while (input != 0);
}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
	int i, index = 0;

	for (i = 0; i < max && index == 0; i++)
	{
		if (patient[i].patientNumber == 0)
		{
			index = i;
		}
	}
	if (index == 0)
	{
		printf("ERROR: Patient listing is FULL!\n");
	}
	else
	{
		patient[index].patientNumber = nextPatientNumber(patient, max);
		inputPatient(&patient[index]);
		printf("*** New patient record added ***\n");
	}
	printf("\n");
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
	printf("Enter the patient number: ");
	int patientNumber = inputInt();

	printf("\n");
	int index = findPatientIndexByPatientNum(patientNumber, patient, max);

	if (index != -1)
	{
		menuPatientEdit(&patient[index]);
	}
	else
	{
		printf("ERROR: Patient record not found!\n");
		printf("\n");
	}
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
	printf("Enter the patient number: ");
	int patientNumber = inputIntPositive();
	char confirm;

	int index = findPatientIndexByPatientNum(patientNumber, patient, max);
	printf("\n");

	if (index != -1)
	{
		displayPatientData(&patient[index], FMT_FORM);
		printf("\n");

		printf("Are you sure you want to remove this patient record? (y/n): ");
		confirm = inputCharOption("yn");

		if (confirm == 'y')
		{
			patient[index].patientNumber = 0;
			printf("Patient record has been removed!");
		}
		else
		{
			printf("Operation aborted.");
		}
	}
	else
	{
		printf("ERROR: Patient record not found!");
	}
	printf("\n\n");
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* dataEntry)
{
	int i = 0;
	int list;

	bubbleSort(dataEntry->appointments);
	displayScheduleTableHeader(&dataEntry->appointments->date, 1);

	for (i = 0; i < dataEntry->maxAppointments; i++)
	{
		if (dataEntry->appointments[i].patientNumber != 0)
		{
			list = findPatientIndexByPatientNum(dataEntry->appointments[i].patientNumber, dataEntry->patients, dataEntry->maxPatient);

			displayScheduleData(&dataEntry->patients[list], &dataEntry->appointments[i], 1);
		}
	}
	printf("\n");
	return;
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* dataEntry)
{
	int i, year, month, day;
	int list;
	int search = 1;

	getDate(&year, &month, &day);
	printf("\n");

	for (i = 0; i < dataEntry->maxAppointments && search; i++)
	{
		if (dataEntry->appointments[i].date.year == year && dataEntry->appointments[i].date.month == month && dataEntry->appointments[i].date.day == day)
		{
			displayScheduleTableHeader(&dataEntry->appointments[i].date, 0);
			search = 0;
		}
	}

	for (i = 0; i < dataEntry->maxAppointments; i++)
	{
		if (dataEntry->appointments[i].date.year == year && dataEntry->appointments[i].date.month == month && dataEntry->appointments[i].date.day == day)
		{
			list = findPatientIndexByPatientNum(dataEntry->appointments[i].patientNumber, dataEntry->patients, dataEntry->maxPatient);

			displayScheduleData(&dataEntry->patients[list], &dataEntry->appointments[i], 0);
		}
	}

	if (search)
	{
		printf("No matching appointments found.\n");
	}
	printf("\n");
	return;
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appointment, int max, struct Patient* patient, int maxPatient)
{
	int patientNum;
	int year, month, day, hour, min, i;
	int list = -1;
	int retry = 0;
	int avail = 1;

	printf("Patient Number: ");
	patientNum = inputIntPositive();

	list = findPatientIndexByPatientNum(patientNum, patient, maxPatient);

	if (list == -1)
	{
		printf("\n");
		printf("*** No records found ***\n");
	}
	else
	{
		for (i = 0; i < max && list == -1; i++)
		{
			if (appointment[i].patientNumber == 0)
			{
				list = i;
			}
		}

		if (list == -1)
		{
			printf("\n");
			printf("ERROR: Appointment timeslot is not available!\n");
		}
		else
		{
			while (retry == 0)
			{
				avail = 1;

				getDate(&year, &month, &day);
				getTime(&hour, &min);

				for (i = 0; i < max && avail; i++)
				{
					if (appointment[i].date.year == year && appointment[i].date.month == month && appointment[i].date.day == day && appointment[i].time.hour == hour && appointment[i].time.min == min)
					{
						printf("\n");
						printf("ERROR: Appointment timeslot is not available!\n\n");
						avail = 0;
					}
				}

				if (avail)
				{
					appointment[list].patientNumber = patientNum;
					appointment[list].date.year = year;
					appointment[list].date.month = month;
					appointment[list].date.day = day;
					appointment[list].time.hour = hour;
					appointment[list].time.min = min;

					retry = 1;
				}
			}

			bubbleSort(appointment);
			printf("\n");
			printf("*** Appointment scheduled! ***\n\n");
		}
	}
	return;
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appointment, int max, struct Patient* patient, int maxPatient)
{
	int inputNum, year, month, day, i;
	int retry = 0;
	int list = -1;
	char input;

	printf("Patient Number: ");
	inputNum = inputIntPositive();
	list = findPatientIndexByPatientNum(inputNum, patient, maxPatient);

	if (list == -1)
	{
		printf("ERROR: Patient record not found!\n\n");
	}
	else
	{
		getDate(&year, &month, &day);

		for (i = 0; i < max && retry == 0; i++)
		{
			if (appointment[i].patientNumber == inputNum && appointment[i].date.year == year && appointment[i].date.month == month && appointment[i].date.day == day)
			{
				printf("\n");
				displayPatientData(&patient[list], FMT_FORM);

				printf("Are you sure you want to remove this appointment (y,n): ");
				input = inputCharOption("yn");

				if (input == 'y')
				{
					printf("\n");
					printf("Appointment record has been removed!\n\n");

					appointment[i].patientNumber = 0;
					appointment[i].date.day = 0;
					appointment[i].date.month = 0;
					appointment[i].date.year = 0;
					appointment[i].time.min = 0;
					appointment[i].time.hour = 0;
				}
				else
				{
					printf("Operation aborted!");
				}

				retry = 1;
			}
		}
	}
	return;
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
	printf("Search by patient number: ");
	int patientNumber = inputInt();
	printf("\n");

	int index = findPatientIndexByPatientNum(patientNumber, patient, max);

	if (index != -1)
	{
		displayPatientData(&patient[index], FMT_FORM);
	}
	else
	{
		printf("*** No records found ***\n");
	}
	printf("\n");
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
	char num[PHONE_LEN + 1] = { 0 };
	int i, found = 0;

	printf("Search by phone number: ");
	inputCString(num, PHONE_LEN, PHONE_LEN);
	printf("\n");

	displayPatientTableHeader();

	for (i = 0; i < max; i++)
	{
		if (strcmp(num, patient[i].phone.number) == 0)
		{
			displayPatientData(&patient[i], FMT_TABLE);
			found = 1;
		}
	}
	if (!found)
	{
		printf("\n*** No records found ***\n");
	}
	printf("\n");
	return;
}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
	int i, highestNum = 0;
	for (i = 0; i < max; i++)
	{
		if (patient[i].patientNumber > highestNum)
		{
			highestNum = patient[i].patientNumber;
		}
	}
	return highestNum + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
	int i;
	for (i = 0; i < max; i++)
	{
		if (patient[i].patientNumber == patientNumber)
		{
			return i;
		}
	}
	return -1;
}

// Sort arrays using bubble sort
void bubbleSort(struct Appointment* app)
{
	int i, j;
	struct Appointment temp = { 0 };

	for (i = 0; i < MAX_APPOINTMENTS; i++)
	{
		for (j = 0; j < MAX_APPOINTMENTS - 1 - i; j++)
		{
			if (app[j].date.year > app[j + 1].date.year ||
				(app[j].date.year == app[j + 1].date.year &&
					(app[j].date.month > app[j + 1].date.month ||
						(app[j].date.month == app[j + 1].date.month &&
							(app[j].date.day > app[j + 1].date.day ||
								(app[j].date.day == app[j + 1].date.day &&
									(app[j].time.hour > app[j + 1].time.hour ||
										(app[j].time.hour == app[j + 1].time.hour &&
											app[j].time.min > app[j + 1].time.min))))))))
			{
				temp = app[j];
				app[j] = app[j + 1];
				app[j + 1] = temp;
			}
		}
	}
	return;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
	printf("Patient Data Input\n");
	printf("------------------\n");
	printf("Number: %05d\n", patient->patientNumber);
	printf("Name  : ");

	inputCString(patient->name, 1, NAME_LEN);
	printf("\n");

	inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone)
{
	int input = 0;

	printf("Phone Information\n");
	printf("-----------------\n");
	printf("How will the patient like to be contacted?\n");
	printf("1. Cell\n");
	printf("2. Home\n");
	printf("3. Work\n");
	printf("4. TBD\n");
	printf("Selection: ");

	input = inputIntRange(1, 4);
	printf("\n");

	switch (input)
	{
	case 1:
		strcpy(phone->description, "CELL");
		break;
	case 2:
		strcpy(phone->description, "HOME");
		break;
	case 3:
		strcpy(phone->description, "WORK");
		break;
	case 4:
		strcpy(phone->description, "TBD");
		return;
	}

	if (input >= 1 && input <= 3)
	{
		printf("Contact: %s\n", phone->description);
		printf("Number : ");

		inputCString(phone->number, PHONE_LEN, PHONE_LEN);
		printf("\n");
	}
}

void getDate(int* year, int* month, int* day)
{
	int maxDays;

	printf("Year        : ");
	*year = inputIntPositive();

	printf("Month (1-12): ");
	*month = inputIntRange(1, 12);

	switch (*month)
	{
	case 2:
		maxDays = (*year % 4 == 0) ? 29 : 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		maxDays = 30;
		break;
	default:
		maxDays = 31;
		break;
	}

	printf("Day (1-%d)  : ", maxDays);
	*day = inputIntRange(1, maxDays);

	return;
}

void getTime(int* hr, int* min)
{
	int retry = 0;

	while (retry == 0)
	{
		printf("Hour (0-23)  : ");
		*hr = inputIntRange(0, 23);

		printf("Minute (0-59): ");
		*min = inputIntRange(0, 59);

		if (*hr >= START && *hr <= END && *min % INTERVAL == 0)
		{
			if (!(*hr == END && *min == 30))
			{
				return;
			}
			printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n\n", START, END, INTERVAL);
		}
		else
		{
			printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n\n", START, END, INTERVAL);
		}
	}
	return;
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
	int i = 0;
	FILE* fp = fopen(datafile, "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Cannot open the file.\n");
		return 0;
	}

	while (i < max && fscanf(fp, "%d|%15[^|]|%4[^|]|%10[^\n]", &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number) != EOF)
	{
		i++;
	}

	fclose(fp);
	return i;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
	int i = 0;
	FILE* fp = fopen(datafile, "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Cannot open the file.\n");
		return 0;
	}

	while (i < max && fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min) != EOF)
	{
		i++;
	}

	fclose(fp);
	return i;
}
#include <ctime>

//#include "CleaningSchedule.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

int main (int argc, char **argv)
{
  int aflag = 0;
  int bflag = 0;
  char *cvalue = NULL;
  int index;
  int c;

  opterr = 0;

  while ((c = getopt (argc, argv, "abc:")) != -1)
    switch (c)
      {
      case 'a':
        aflag = 1;
		printf ("avalue = %s\n",avalue);
        break;
      case 'b':
        bflag = 1;
		avalue = optarg;
		printf ("avalue = %s\n",avalue);
        break;
			case 'y':
			
      case 'c':
        cvalue = optarg;
        break;
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }
	
	cout << "Using data: aflag";
	cout << "bflag";
	printf ("aflag = %d, bflag = %d, cvalue = %s\n", aflag, bflag, cvalue);

	for (index = optind; index < argc; index++)
		printf ("Non-option argument %s\n", argv[index]);
  return 0;
}



//int main(int argc, char* argv[])
//{
//	time_t t = time(0);   // get time now
//	tm dateTime;
//	localtime_s(&dateTime, &t);
//	dateTime.tm_year;
//
//	// generate schedule
////	CleaningSchedule* cleaningSchedule = new CleaningSchedule();
////	cleaningSchedule->Generate(dateTime);
////	cleaningSchedule->Save();
//
//	return 0;
//}
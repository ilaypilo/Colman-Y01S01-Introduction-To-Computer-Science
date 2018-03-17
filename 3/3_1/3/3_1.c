/*
Author: Ilay Pilosof
ID: 304961519
Date: 11/12/2016
Purpose: The program gets a date and show the date of the next day.
*/
#include <stdio.h>

void main(){
	int month,day,maxDay,valid=1;
	printf("Please enter the day and month:\n");
	scanf("%d%d",&day,&month);
	// determain the numbers of days in each month
	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			maxDay=31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			maxDay = 30;
			break;
		case 2:
			maxDay=28;
			break;
		default:
		// wrong month input
			maxDay = 0;
			valid = 0;
			break;
	}
	// if day input invalid
	if(day>maxDay || day<1){
		valid=0;
	} else if(day==maxDay){
		// if the end of the month
		day=0;
		if(month!=12){
			month+=1;
		} else {
			// and if the end of the year
			month=1;	
		}
	}
	// inc day
	day+=1;
	// check if date is valid
	if(valid==1){
		printf("%d.%d\n",day,month);
	} else {
		printf("Invalid Date.\n");
	}
	
}

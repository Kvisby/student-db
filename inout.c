#include <stdio.h>
#include <stdlib.h>

#include "common.h"

void enter_count(int *c) {
	printf("Please enter number of students: \n");
	scanf(" %d", c);
	printf("\n");
}


void data_input(int count, student_type *s){
	if (count <1)
		return;
	if(count > MAX_STUDENTS){
		printf("Too much data for input \n");
		return;
	}
	for (int i=0; i < count; i++){
		printf("Please enter data for Student %d: \n", i+1);
		scanf("%s %s %d %d", (s+i)->name, (s+i)->lastname,
					 &(s+i)->group_id, &(s+i)->course);
		printf("\n");
	}
	return;
}

void data_output(int count, student_type *s){
	if (count < 1){
		printf("nothing to show\n");
		goto exit;
	}
	if (count > MAX_STUDENTS){
		printf("Too much data to show\n");
		goto exit;
	}
	printf("User entered data:\n");
	for(int i = 0; i<count; i++){
		printf("%s\t%s\t%d\t%d\n", (s+i)->name, (s+i)-> lastname,
					 (s+i)->group_id, (s+i)->course);
	}
	exit: 
	return;
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "common.h"

void data_input(int count, student_type *s);
void data_output(int count, student_type *s);
int data_save(int count, student_type *s, const char *file );
student_type *data_read(const char *file,int *count );
void enter_count(int *c);


int main(){
	int c = 0;
	int yn = 0;
	char *file = "data.bin";
	student_type *s;
	student_type *data;
	int err = 0;
	
	printf("Do you want to see existing student data (1/0)?\n");
	scanf("%d", &yn);
	if (yn==1){
	    data = data_read(file, &c);
	    if	(!data) {
			printf("Error reading Database: (%m)\n");
		}  else	{
			printf("There are %d students in database: \n", c);
			data_output (c, data);
			free(data);
		}
	}
	enter_count(&c);
	s = (student_type *)malloc(sizeof(student_type)*c);
	data_input(c, s);
	data_output(c, s);
	
	printf("Do you want to save the data(1/0)?");
	scanf("%d", &yn);
	if (yn == 1){
		printf("saving data to %s ----\n", file);
		err = data_save(c, s, file);
		if (err){
			printf("Error saving data: (%d)\n", err);
		}
	}
	free(s);
	return 0;
}

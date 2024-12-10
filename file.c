#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "common.h"

int data_save(int count, student_type *s, const char *file){
	int fd;
	ssize_t bw = 0;
	int data_size = 0;
	
	if (count < 1)
		return 0;
	
	data_size = count * sizeof(student_type);
	
	if (!s || !file)
		return -DATA_SAVE_ERR_INPUT;
	
	fd = open(file, O_CLOEXEC | O_CREAT | O_WRONLY | O_APPEND, 0600);
	if(fd<0){
		return -DATA_SAVE_ERR_OPEN;
	}
	
	bw = write(fd, s, data_size);
	if (bw<data_size){
		close(fd);
		return -DATA_SAVE_ERR_WRITE;
	}
	
	close(fd);
	return DATA_SAVE_OK;
}

student_type *data_read(const char *file, int *count_return){
	 int fd;
	 ssize_t br = 0;
	 int count = 0;
	 student_type *data = NULL;
	
	 //return NULL;
	
	if (!file)
		 return data;
	
	printf("Data file is %s\n", file);
  
	fd = open(file, O_RDWR, 0600);
	if (fd<0){
		printf("Error opening file: %d ($m)\n", fd);
		return data;
	} else {
		printf("File descriptor is %d \n", fd);
	}
  	data = (student_type * )malloc(sizeof(student_type));
  	if (!data) {
	 	//printf("Cant malloc!\n");
  	 	goto exit;
	}
  	//printf("Entering loop\n");
	while(1){
	 	br = read(fd, data + count, sizeof(student_type));
		//printf("BR is %u \n", br);
	 	if (br<sizeof(student_type)) {
			//printf("Reach EOF!\n");
		 	goto exit;
		};
		//printf("count is %d\n", count);
		count++;
		data = (student_type *)realloc(data, sizeof(student_type ) * (count + 1));
		if (!data) {
			//printf("Cant realloc!\n");
			goto exit;
		};
	 }
exit:
	 close(fd);
	 printf("count is %d\n", count);
	 *count_return = count;
	 return data;
}

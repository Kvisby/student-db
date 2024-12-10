#define MAX_STUDENTS	10

enum {
	DATA_SAVE_OK,
	DATA_SAVE_ERR_INPUT,
	DATA_SAVE_ERR_OPEN,
	DATA_SAVE_ERR_WRITE, 
	DATA_READ_ERR_FILE
};

typedef struct {
	char name[20];
	char lastname[20];
	int group_id;
	int course;
} student_type; // uzcep type student_type

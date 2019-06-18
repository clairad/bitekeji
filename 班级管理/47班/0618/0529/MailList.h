#ifndef _MAILLIST_H
#define _MAILLIST_H

#define PERSPACE 3
#define FILENAME "maillist.bin"

enum{
	ADD_MSG = 1,
	DELETE_MSG,
	SEARCH_MSG,
	CHANGE_MSG,
	DISPLAY_MSG,
	EMPTY_MSG,
	SAVE_FILE
};

struct MailList{
	char name[50];
	char gender;
	char telnum[30];
	char addr[200];
	int age;
};

typedef struct {
	struct MailList * allMsg;
	int count;
	int limit;
}MailLists;

void inputData(struct MailList * oneData);

void initMailList(MailLists * data);
void destoryMailList(MailLists * data);
void addMailList(MailLists * data, struct MailList oneData);
void searchData(MailLists data, char * find, int * searchres);
void deleteOneData(MailLists * data, int n);
void outputData(MailLists data);
void outputSearchData(MailLists data, int * outputdata);
int catchOneData(MailLists data, char *find);

int saveData(MailLists allData, const char * filename);
int loadData(MailLists * allData, const char * filename);
#endif /* _MAILLIST_H */
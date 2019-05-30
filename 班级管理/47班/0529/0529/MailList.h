#ifndef _MAILLIST_H
#define _MAILLIST_H

enum{
	ADD_MSG = 1,
	DELETE_MSG,
	SEARCH_MSG,
	CHANGE_MSG,
	DISPLAY_MSG,
	EMPTY_MSG
};

struct MailList{
	char name[50];
	char gender;
	char telnum[30];
	char addr[200];
	int age;
};

extern struct MailList g_allMsg[1000];
extern int g_count;

void inputData();
void outputData();

#endif /* _MAILLIST_H */
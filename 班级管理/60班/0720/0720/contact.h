#ifndef _CONTACT_H_
#define _CONTACT_H_

#include "List.h"
#include "seqlist.h"

enum{
	ADD_MSG = 1,
	DELETE_MSG,
	SEARCH_MSG,
	CHANGE_MSG,
	DISPLAY_MSG,
	EMPTY_MSG
};

typedef struct Contact{
	char name[32];
	char sex;
	char age;
	char phonenum[13];
	char address[256];
}Contact;

int Contactcmp(Contact c1, Contact c2);
void fillData(Contact * src, char * name, char sex, char age, char * pn, char * addr);
Contact createData();
void printData(Contact data);

void contactAdd(List * plist, Contact c);
SeqList contactFind(List * plist, char * find);
void contactDelete(List * plist, char * find);


#endif /*_CONTACT_H_*/

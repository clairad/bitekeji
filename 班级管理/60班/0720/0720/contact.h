#ifndef _CONTACT_H_
#define _CONTACT_H_

typedef struct{
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

#endif /*_CONTACT_H_*/
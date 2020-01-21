void printInt(long long int l);
void printString(void *);
void error();
long long int readInt();
void * readString();
void * concatStrings(void * s1, void * s2);
long long int stringsEqual(void * ss1, void * ss2);
long long int stringsNotEqual(void * ss1, void * ss2);
void deleteString(char * s);
void checkDelete();
void * getMemory(long long int size);
void freeMemory(void * mem);
void * wrapDestructable(void * ptr, long long int isString);
void * wrapUndestructable(void * ptr, long long int isString);
void * getValue(void * ptr);
void incCounter(void * ptr);
void decCounter(void * ptr);


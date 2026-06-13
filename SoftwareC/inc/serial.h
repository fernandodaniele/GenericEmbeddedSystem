#ifndef Serial_h
#define Serial_h

int serialInit(int newCOM);
int sendCommand(char command);
int readResponse();

#endif /* Serial_h */

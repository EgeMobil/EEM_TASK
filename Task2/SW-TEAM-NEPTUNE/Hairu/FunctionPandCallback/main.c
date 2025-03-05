#include <stdio.h>
#include <string.h>



// typedef for callback function pointer
typedef void (*LoggingCallbackHandler)(const char*);

// the types of logging I decide to implement are as follows
/**
 * 
 * 1. Console Logging(on the terminal)
 * 2. File logging(create and save txt file on memory)
 * 3. Network logging (I will send the data over a netwok to a remote server)
 * 
 *  */

 void LogToConsole(const char* message){
    printf("The new message is: %s\n", message);
 }


 
 void LogToFile(const char* message){

    FILE* file = fopen("logginfo.txt", "a");
    if (file != NULL) {
        fprintf(file, "Saving: %s\n", message);
        fclose(file);
    } else {
        printf("Error opening file.\n");
    }
 }

 
 void LogToNetwork(const char* message){
    printf("The the message is sent to remote server! %s\n", message);
 }

void CallbackProcessor(const char *message, LoggingCallbackHandler handler){

    if (message != NULL && handler != NULL) {
        // Invoking the callback function
        handler(message);
    } else {
        printf("Invalid message or handler.\n");
    }
}

int main(){
    const char* consoleExampleData = "This message is for the Terminal";
    const char* FileExampleData = "This message is saved to file!";
    const char* NetworkSampleData = "This data is being sent to remote server";

    CallbackProcessor(consoleExampleData, LogToConsole);
    CallbackProcessor(FileExampleData,LogToFile);
    CallbackProcessor(NetworkSampleData, LogToNetwork);

    return 0; 


}
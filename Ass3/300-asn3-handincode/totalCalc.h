#include "input.h"
#include "struct.h"
#include <pthread.h>
#include "array.h"
#include "parsing.h"
#include "mainStruct.h"
#include "alpha.h"
#include "beta.h"
#include <math.h>
#include "parsing2.h"
#include "alpha2.h"
#include "beta2.h"





#define BARRIER_THRESHOLD 2

#define MAX_STRUCTS 10 // max number of structs to be stored in the dynamic array

// int structIndex = 0; - defined in myChannels.c was formerly used to keep index position but now we use theCount because structIndex was reset to 0 at every execution of totalCalc.h in main()


struct ChannelStruct collection[MAX_STRUCTS];
// TO DO: define how we make the size of collection dynamically allocated, currently hardcoded to 10



// void printCollectionStruct(theCount) {
//     for (int i = 0; i < theCount + 1; i++) {
//     printf("Collection of Structs index %d:\n", i);
//     printf("Alpha: %f\n", collection[i].alpha);
//     printf("Beta: %f\n", collection[i].beta);
//     printf("Input Array: ");
//     for (int j = 0; j < collection[i].sizeOfArr; j++) {
//         printf("%f ", collection[i].inputArr[j]);
//     }
//     printf("\n\n");
//     }
// }


void printArray2A(float arr[], int size) {
    printf("printingOutputA: ");
    printf("printArray2A: ");
    for (int i = 0; i < size; i++) {
        printf(" %f ", arr[i]);
    }
    printf("\n");
}

void printArray2B(float arr[], int size) {
    printf("printing output B: ");
    printf("printArray2B: ");
    for (int i = 0; i < size; i++) {
        printf(" %f ", arr[i]);
    }
    printf("\n");
}

void printArray2C(int arr[], int size) {
    printf("printing contents of metaDataStruct: ");
    for (int i = 0; i < size; i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

int executeTotalCalc(struct MetaDataStruct * metaDataStruct) { // passes in the collection index
    
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);

    // pthread_barrier_t barrier;
    // pthread_barrier_init(&barrier,NULL,BARRIER_THRESHOLD);
    

    // pthread_barrier_t barrier;

    // printf("executeTotalCalc: \n");
    // printf("metaDataStruct->numOfInputFiles: %d\n", metaDataStruct->numOfInputFiles);
    // printf("metaDataStruct->numOfThreads: %d\n", metaDataStruct->numOfThreads);
    // printf("metaDataStruct->numConsumed: %d\n", metaDataStruct->numConsumed);
    // printf("metaDataStruct->bufferSize: %d\n", metaDataStruct->bufferSize);
    // printf("metaDataStruct->count: %d\n", metaDataStruct->count);
    // printArray2C(metaDataStruct->indexArr, metaDataStruct->numOfInputFiles / metaDataStruct->numOfThreads);

    // int theCount = metaDataStruct->count;
    // printf("theCount: %d\n", theCount);
    // float alpha = 1;
    // printf("alpha: %f\n", alpha);
    // float beta = 1;
    // printf("beta: %f\n", beta);

    // i am not storing the prevSamples anywhere, just overwriting the passed in prevSamples
    float prevSamples = -1; // initialize prevSamples to -1 in beginning of every read always

    // const int sizeOfArr = countInputFile(); // calls input.h to know what size arrays to create 
    int sizeOfArr = metaDataStruct->count; // calls input.h to know what size arrays to create 
    // printf("57 sizeOfArr: %d\n", sizeOfArr);

    int indexArrCount = 0;
    int numberOfLoops = (metaDataStruct->numOfInputFiles / metaDataStruct->numOfThreads); // 2

    FILE * fpArr[MAX_MAIN_STRUCTS];

    for (int i = 0; i < numberOfLoops; i++) {
            int numberToReplace = metaDataStruct->indexArr[i];
            char * path = metaDataStruct->structArray[numberToReplace].path;
            removeNewline(path);
            FILE *fp = fopen(path, "r");  // Open the file for reading
            //*fp array
            fpArr[i] = fp;
    }
    float sampleValueInLoop = prevSamples;
    while (1) {
        // ARRAY CREATION BY NUMBEROFINPUTFILES
        int flag[numberOfLoops];
        int num;
        int sum;
        // float sampleValueInLoop = prevSamples;
        float newNum;
        float newNum2;
        float writeToFileArr[metaDataStruct->numOfInputFiles];
        int counterInsideLoop;
        for (int i = 0; i < numberOfLoops; i++) {
            flag[i] = 0;
        };
        for (int j = 0; j < numberOfLoops; j++) {
            // counterInsideLoop = i;
            int numberToReplace = metaDataStruct->indexArr[j]; // [0,1]
            // printf("115 numberToReplace: %d, index position %d \n", numberToReplace, j);

            char * path = metaDataStruct->structArray[numberToReplace].path;
            FILE *fp = fpArr[j];
            // parsingInputFile(path, metaDataStruct->bufferSize);
            // printf("119 metaDataStruct->structArray[i].alpha: %f. this is index position %d\n", metaDataStruct->structArray[j].alpha, j);
            
            // printf("line 1 in parsingInputFile\n");
            char line[256];  // Example: Allocate space for a line of up to 255 characters
            // printf("124 %s\n", path);
            if (fp == NULL) {
                // printf("Failed to open the file.\n");
                perror("Error opening files");
                return 1;  // Or perform appropriate error handling
            }
            int bytesRead;
            

            bytesRead = fread(line, 1, metaDataStruct->bufferSize, fp);
            if (bytesRead == 0) {
                
                flag[j] = 1;
                break;
                
            }
            
            // for (int k = 0; k < metaDataStruct->bufferSize; k++) {
            //         printf("82 %c\n", line[k]);
            //     }
            // printf("\n");

            // scanf("%s", line);
            num = atoi(line);
            // printf("127 Converted integer: %d\n", num);
            // printf("148 metaDataStruct->structArray[i].alpha: %f. this is index position %d\n", metaDataStruct->structArray[j].alpha, j);
            // printf("149 metaDataStruct->structArray[0].alpha: %f\n", metaDataStruct->structArray[0].alpha);
            // printf("150 metaDataStruct->structArray[1].alpha: %f\n", metaDataStruct->structArray[1].alpha);

            newNum = findAlphaVal2(num, sampleValueInLoop, metaDataStruct->structArray[j].alpha); // executes the alpha calculation and stores the result in outputArrayA
            sampleValueInLoop = newNum;
            // printf("150 sampleValueInLoop: %f\n", sampleValueInLoop);
            // printf("151 newNum: %f\n", newNum);
            newNum2 = newNum * metaDataStruct->structArray[j+1].beta;
            // printf("159 newNum2: %f\n", newNum2);
            writeToFileArr[j] = newNum2;
            // printf("161 writeToFileArr[%d]: %f\n", j, writeToFileArr[j]);

            // COMPUTE WITH ALPHA AND BETA CALCS, then assign to the array below
            // ASSIGN THE LINE TO 0 or 1 index position of the array 
            // STORE LINE IN THE ARRAY

                // sscanf(buffer, "%*[^0-9]%d", dest);
                // printf("75 %d\n",bytesRead);
                // Process the line here (e.g., print it)
                
                // line[bufferSize-1] = '\0';
                // printf("77 %s", line);

                
                // fflush(stdin);
                // Process other lines as needed
                

    
            //end of file read when bytesRead == 0;
            // fclose(fp);
            
            
        }

     
        int sizeOfWriteToFileArr = sizeof(writeToFileArr) / sizeof(writeToFileArr[0]);

        for (int i = 0; i < sizeOfWriteToFileArr; i++) {
            sum += writeToFileArr[i];
        }

        // printf("Sum: %d\n", sum);

        
    


        // COMPUTE BOTH THE VALUES IN THE ARRAY , add 1 + 5 = 6
        // OUTPUT 6 to the output file,
        // do this for eevery buffer size combination of the input files to get the file output file


        // if lock config = 1 , then do this
        if (metaDataStruct->lock_config == 1) {
            // PTHREAD LOCK
            pthread_mutex_lock(&mutex);
            writeToOutputFile(sum);
            pthread_mutex_unlock(&mutex);
            // PTHREAD UNLOCK

        } else {
            writeToOutputFile(sum);
        }


        // WRITE PTHREAD BARRIER FOR GLOBAL CHECKPOINTING 1, then it waits for all the other threads to also go into and finish this while loop before continuing
        // if(metaDataStruct->global_checkpointing==1){
        //     printf("\nWAIT\n");
        //     pthread_barrier_wait(&barrier);
        //     printf("\nAFTER\n");
        // }
        int flag2 = 0;
        for (int i = 0; i < numberOfLoops; i++) {
            
            if (flag[i] == 0) {
                flag2 = 0;
                break;
                
            }
            else if (flag[i] != 0) {
                flag2 = 1;    
                // break;    
            }
        };
        if (flag2 == 1) {
            return 0;

        }

    }
    // pthread_barrier_destroy(&barrier);
    pthread_mutex_destroy(&mutex);
    // for (int i = 0; i < metaDataStruct->numOfInputFiles / metaDataStruct->numOfThreads; i++) {
    //     int numberToReplace = metaDataStruct->indexArr[i]; // 0
        
    //     char * path = metaDataStruct->structArray[numberToReplace].path;

    //     parsingInputFile(path, metaDataStruct->bufferSize);
    //     // printf("78 path: %s\n", path);

    //     // float alpha = metaDataStruct->structArray[numberToReplace].alpha;
    //     // printf("74 alpha: %f\n", alpha);
    //     // float beta = metaDataStruct->structArray[numberToReplace].beta;
    //     // printf("76 beta: %f\n", beta);
    //     // char * path = metaDataStruct->structArray[numberToReplace].path;
    //     // printf("78 path: %s\n", path);


    // }

    

    

    // take sizeOfArr and create inputArr, outputArrayA and outputArrayB with correct sizing
    // float* inputArr = malloc(sizeOfArr * sizeof(float));  // dummy array for testing


    // for (int i = 0; i < sizeOfArr; i++) {

    //     inputArr[i] = 1;
    //     // inputArr[i] = mainCollection->structArray[theCount].inputArr[i];
    //     // printf("64 inputArr[%d]: %f\n", i, inputArr[i]);
    // }

    // float outputArrayA[sizeOfArr]; // needs to store the amount of lines found in the input file (ex. file_1.txt), size will match inputArr
    // float outputArrayB[sizeOfArr]; // size will match outputArrayA

    // struct ChannelStruct testChannelStruct = createChannelStruct(); // calls struct.h to create a new struct for each input file read and stores the alpha/beta values in testChannelStruct struct

    // findAlphaVal(inputArr, prevSamples, alpha, outputArrayA); // executes the alpha calculation and stores the result in outputArrayA
    // findBetaVal(outputArrayA, beta, outputArrayB); // executes the beta calculation and stores the result in outputArrayB


    // findAlphaVal(inputArr, prevSamples, testChannelStruct.alpha, outputArrayA); // executes the alpha calculation and stores the result in outputArrayA
    // findBetaVal(outputArrayA, testChannelStruct.beta, outputArrayB); // executes the beta calculation and stores the result in outputArrayB

    // used to test whats in each array
    // printArray2A(outputArrayA, sizeOfArr);
    // printArray2B(outputArrayB, sizeOfArr);

    // if (theCount == 0) {
    // writeToOutputFileA(outputArrayB, sizeOfArr); // calls array.h to write the outputArrayB to the output file
    // } else {
    // writeToOutputFileB(outputArrayB, sizeOfArr); // calls array.h to append the outputArrayB to the output file
    // }

    // struct ChannelStruct resultStruct = addtoStruct(testChannelStruct, outputArrayB, sizeOfArr); 
    // adds the outputArrayB to the testChannelStruct struct returns the resultStruct; called in struct.h

    // collection[theCount] = resultStruct;
    // // add the resultStruct creation into the collection of structs array named "collection"
    // // struct ChannelStruct collection[MAX_STRUCTS]; - defined at the top of this file

    // printCollectionStruct(theCount); // print to see the collection of structs array
 

    // structIndex++; // incremented at the file; global variable -- deprecated in favour of theCount


    //FREE MEMORY WHERE MALLOC'D
    // free(inputArr); // free the memory allocated for inputArr
    // free(outputArrayA); - NOT USED , doesnt seem needed cause no malloc of outputArrayA
    // free(outputArrayB); - NOT USED , doesnt seem needed cause no malloc of outputArrayB


    // return theCount; // return theCount to be used in the next iteration of the loop
    return 0;
}




/* below code block was for testing - now deprecated */

// findAlphaVal(samplesA, prevSamples, alpha, outputArrayA); // this function is working

// findBetaVal(samplesB, beta, outputArrayB); // this function is working

// printArray(outputArrayA, sizeA); // this function is working
// expected output should be 1, 1.5, 2.25 

// printArray(outputArrayB, sizeB); // this function is working
// expected output should be 0.5,1,1.5

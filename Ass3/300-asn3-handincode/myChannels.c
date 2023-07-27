#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "myChannels.h"
#include "totalCalc.h"


#define MAX_THREADS 10
#define MAX_MAIN_STRUCTS 50

void printCharArray(char* arr) {
    printf("%s\n", arr);
}



int structIndex = 0;

int main(int argc, char* argv[]) {
    

    
     // this will be determined by the parsing function
    // dummy for testing , should use the function above //MALLOC THIS//
    int numConsumed = 0; // dummy for testing , 
    int count = 0; // dummy for testing ,


    

    struct MasterStruct structForMainCollection;
    char metadatapath[256];
    char output_file_path[256];
    int bufferSize;
    int numOfThreads;
    int lock_config;
    int global_checkpointing;
    if(argc<7){
        printf("Please enter your arguments");
        return 0;
    }
    if(argc>7){
        printf("Too many arguments");
        return 0;
    }
    else{
        bufferSize = atoi(argv[1]);
        numOfThreads = atoi(argv[2]);
        strcpy(metadatapath, argv[3]);
        lock_config = atoi(argv[4]);
        global_checkpointing = atoi(argv[5]);
        strcpy(output_file_path, argv[6]);
    }
    
    // printf("TESTING bufferSize: %d\n",bufferSize);
    // printf("TESTING numOfThreads: %d\n",numOfThreads);
    // printf("TESTING metadatapath: %s\n",metadatapath);
    // printf("TESTING lock_config: %d\n",lock_config);
    // printf("TESTING global_checkpointing: %d\n",global_checkpointing);
    // printf("TESTING output_file_path: %s\n",output_file_path);
    
    // struct MetaDataStruct mainCollection;
    int numberOfInputFiles = parsingNumberOfInputFiles(metadatapath);

    pthread_t threads[numOfThreads];
    struct InputFileStruct inputFileStructArray[numberOfInputFiles];
    // struct MetaDataStruct mainCollection;


    // mainCollection.numOfInputFiles = numberOfInputFiles; // 4
    // mainCollection.numOfThreads = numOfThreads; // 2
    // mainCollection.numConsumed = numConsumed; // 0
    // mainCollection.bufferSize = bufferSize; // 2
    // mainCollection.count = count; // 0

    int inputFilesPerThread = numberOfInputFiles / numOfThreads; // 6 divided by 3 = 2 input files each // this is the size of the array that will be passed to each thread, it is the number of input files divided by the number of threads, this is the number of input files each thread will be responsible for
    int counter;
    int inputFileArrSample[] = {1,2,3,4};

    for (int i = 0; i < numOfThreads ; i++) {
        structForMainCollection.metaDataStruct[i] = createMetaDataStruct(numberOfInputFiles, numConsumed, count, bufferSize, numOfThreads, metadatapath, lock_config, global_checkpointing, output_file_path);
    }

    int original_array[numberOfInputFiles]; // Declare the original_array with size 6
    
    // Populate the original_array using a for loop
    // for (int i = 0; i < numberOfInputFiles; i++) {
    //     original_array[i] = i; // fills it as {0,1,2,3,4,5}
    // }

    // for (int j = 0; j < inputFilesPerThread; j++) {
    // //         structForMainCollection.metaDataStruct[j].indexArr[counter] = counter;
    // }

    int arrays[numOfThreads][inputFilesPerThread];

    // Populate the arrays using nested for loops
    int count2 = 0;
    for (int i = 0; i < numOfThreads; i++) {
        for (int j = 0; j < inputFilesPerThread; j++) {
            arrays[i][j] = count2;
            structForMainCollection.metaDataStruct[i].indexArr[j] = arrays[i][j];
            count2++;
        }
    }

    // printf("line 50 %d \n", structForMainCollection.metaDataStruct[0].indexArr[0]);
    // printf("line 50 %d \n", structForMainCollection.metaDataStruct[0].indexArr[1]);
    // printf("line 50 %d \n", structForMainCollection.metaDataStruct[1].indexArr[0]);
    // printf("line 50 %d \n", structForMainCollection.metaDataStruct[1].indexArr[1]);
    // printf("line 50 %d \n", structForMainCollection.metaDataStruct[2].indexArr[0]);
    // printf("line 50 %d \n", structForMainCollection.metaDataStruct[2].indexArr[1]);
    



    // for (int i = 0; i < numberOfInputFiles ; i++) {
    //     mainCollection.structArray[i] = createInputFileStruct(0.5, 2 , 3); // implement once we have input file parse to a struct
    //     //printInputFileStructRest(&mainCollection.structArray[i]);
    // }




    // for (int i = 0; i < numberOfInputFiles ; i++) {
    //     mainCollection.structArray[i].inputArr = inputFileArrSample;
    //     // printf("line 80 %d \n", mainCollection.structArray[i].inputArr[0]);
    //     //printInputFileStructInputArr(&mainCollection.structArray[i]);
    // }

    // printMetaDataStruct(&mainCollection);

    // pthread_create(&threads[0], NULL, executeTotalCalc, (void *)&mainCollection);

    // pthread_join(threads[0], NULL);


    parsingMetaData(structForMainCollection.metaDataStruct->metadatapath , inputFileStructArray);

        for (int i = 0; i < numOfThreads ; i++) {
            structForMainCollection.metaDataStruct[i].structArray = inputFileStructArray;
        // printf("line 80 %d \n", mainCollection.structArray[i].inputArr[0]);
        //printInputFileStructInputArr(&mainCollection.structArray[i]);
    }


    // printf("line 108 %f \n", structForMainCollection.metaDataStruct[0].alpha);
    // printf("line 108 %f \n", structForMainCollection.metaDataStruct[1].alpha);
    // printf("line 109 %f \n", structForMainCollection.metaDataStruct[0].beta);
    // printf("line 110 %s \n", structForMainCollection.metaDataStruct[0].path);

    // printCharArray(structForMainCollection.metaDataStruct[0].path);

    // printf(inputFileStructArray[0].path);
    // printf(inputFileStructArray[1].path);
    // printf(inputFileStructArray[2].path);
    // printf(inputFileStructArray[3].path);

    // // print the alpha and beta for inputFileStructArray
    // printf("line 123 %f \n", inputFileStructArray[0].alpha);
    // printf("line 123 %f \n", inputFileStructArray[1].alpha);
    // printf("line 123 %f \n", inputFileStructArray[2].alpha);
    // printf("line 123 %f \n", inputFileStructArray[3].alpha);
    // printf("line 123 %f \n", inputFileStructArray[0].beta);
    // printf("line 123 %f \n", inputFileStructArray[1].beta);
    // printf("line 123 %f \n", inputFileStructArray[2].beta);
    // printf("line 123 %f \n", inputFileStructArray[3].beta);


    
    // if (numOfThreads == 1) {
    //     pthread_create(&threads[0], NULL, executeTotalCalc, (void *)&structForMainCollection.metaDataStruct[0]); // this is index[0] = first execution always begins at 0, defined at globalvar level
        
    // }
    // else if (numOfThreads < 1) {
    //     printf("Error: numThreads is less than 1\n");
    // }
    // else if (numOfThreads > 1){
        // int count = 0;
        // pthread_barrier_t barrier;
        // pthread_barrier_init(&barrier,NULL,BARRIER_THRESHOLD);
        for (int i = 0; i < numOfThreads; i++) {
            // printf("73 count is %d\n", mainCollection.count);
            // printf("74 count is %d\n", mainCollection.numOfThreads);
            pthread_create(&threads[i], NULL, executeTotalCalc, (void *)&structForMainCollection.metaDataStruct[i]); // this is index[count++], 2nd and up execution defined by local variable "count" inside the loop that increments ++ after each execution
            
            
            // pthread_join(threads[i], NULL);
            // printf("78 count is %d\n", mainCollection.count);
            // if (mainCollection.count < mainCollection.numOfThreads - 1) {
            //     mainCollection.count++;
            //     mainCollection.numConsumed++;
            //     printf("82 count is %d\n", mainCollection.count);
            // }
        }
        // Wait for all threads to finish
        for (int i = 0; i < numOfThreads; i++) {
            pthread_join(threads[i], NULL);
            
            
        }



    // }
    


    



    return 0;
}



// JULY 7
    // NEXT STEPS: TO BE DONE ONLY AFTER EVERYTHING ABOVE IS COMPLETE
    // IMPLEMENT 4/5/6 of assignment once everything that is TO DO is complete
    // implement 4. lock configurations 5. global checkpointing 6. local checkpointing as definde in asn criteria
    // implement 7. output file path, which just sums up all the ChannelStruct struct's input Arrays found in collection by their corresponding index position and stores them in an output file by line, each line representing the index position of the sum of all input arrays found in collection (the struct of struct)


    /* Below destroy loop does not work, will figure out later */
    // FREE MEMORY Via Destroy function on each MyStruct instance in the collection and then the collection itself
    // for (int i = 0; i < numThreads; i++) {
    //     destroyMyStruct(&collection[i]);
    //     free(&collection);
    //     printf("destroyed collection of structs\n");
    // }
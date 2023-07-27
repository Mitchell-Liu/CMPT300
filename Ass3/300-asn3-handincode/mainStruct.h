#define MAX_MAIN_STRUCTS 50


// array of InputFileStruct and pass into parsing2
// 

// struct InputFileStruct inputFileArray[MAX_MAIN_STRUCTS];

struct InputFileStruct {
    //  int * inputArr;
     float alpha;
     float beta;
     int sizeOfArr;
     char path[MAX_MAIN_STRUCTS];
};

struct MetaDataStruct {
     int indexArr[MAX_MAIN_STRUCTS];
     int numOfInputFiles;
     int numOfThreads;
     int numConsumed;
     int bufferSize;
     int count;
     int global_checkpointing;
     char metadatapath[256];
     char output_file_path[256];
     int lock_config;
     struct InputFileStruct * structArray;
    //  float beta;
    //  int sizeOfArr;
    //  char path[MAX_MAIN_STRUCTS];
};

// struct MetaDataStruct {
//      struct InputFileStruct * structArray;
//      int numOfInputFiles;
//      int numOfThreads;
//      int numConsumed;
//      int bufferSize;
//      int count;
// };

struct MasterStruct {
     struct MetaDataStruct metaDataStruct[MAX_MAIN_STRUCTS];
     
};




// void printInputFileStructInputArr(const struct InputFileStruct* structArray) {
void printInputFileStructRest(struct InputFileStruct * structArray) {
    // printf("24 print InputFileStruct: %d\n", inputArr[0]);
    // printf("25 print InputFileStruct: %d\n", inputArr[1]);
    // printf("26 print InputFileStruct: %d\n", inputArr[2]);
    // int sizeOfArr2 = sizeof(inputArr) / sizeof(inputArr[0]);
    // for (int i = 0; i < numberOfInputFiles; i++) {
        printf("line 28 %f \n", structArray->alpha); 
        printf("line 29 %f \n", structArray->beta); 
        printf("line 30 %d \n", structArray->sizeOfArr); 
    // }
    // printf(structArray->alpha);
    // printf(structArray->beta);
    // printf(structArray->sizeOfArr);
    printf("\n");
}


// void printInputFileStructInputArr(const struct InputFileStruct* structArray) {
// void printInputFileStructInputArr(struct InputFileStruct * structArray) {
    
//     printf("24 print InputFileStruct: %d\n", structArray->inputArr[0]);
//     printf("24 print InputFileStruct: %d\n", structArray->inputArr[1]);
//     printf("24 print InputFileStruct: %d\n", structArray->inputArr[2]);
//     printf("\n");
// }

void printMetaDataStruct(const struct MetaDataStruct * channelstruct) {
    
    printf("printMetaDataStruct numOfInputFiles %d\n", channelstruct->numOfInputFiles);
    printf("printMetaDataStruct numOfThreads %d\n", channelstruct->numOfThreads);
    printf("printMetaDataStruct numConsumed %d\n", channelstruct->numConsumed);
    printf("printMetaDataStruct bufferSize %d\n", channelstruct->bufferSize);
    printf("printMetaDataStruct count %d\n", channelstruct->count);
}

// struct InputFileStruct addInputArray(int * inputFileArrSample) {
//     struct InputFileStruct inputFileChannel; 

//     int sizeOfInputFileArrSample = sizeof(inputFileArrSample) / sizeof(inputFileArrSample[0]);

//     inputFileChannel.inputArr = malloc(sizeOfInputFileArrSample * sizeof(int)); // Allocate memory for 3 integers

    
//     // Copy values from outputArrayB to inputArr
//     for (int i = 0; i < sizeOfInputFileArrSample; i++) {
//         inputFileChannel.inputArr[i] = inputFileArrSample[i];
//     }


//     return inputFileChannel;
// }

struct MetaDataStruct createMetaDataStruct(int numOfInputFiles, int numConsumed, int count, int bufferSize, int numOfThreads, char*metadatapath, int lock_config, int global_checkpointing, char* output_file_path) {
    struct MetaDataStruct metaDataChannel; // create a new struct for each input file read
    
    metaDataChannel.global_checkpointing =global_checkpointing;
    metaDataChannel.lock_config = lock_config;
    strcpy(metaDataChannel.metadatapath, metadatapath);
    strcpy(metaDataChannel.output_file_path, output_file_path);
    metaDataChannel.numOfInputFiles = numOfInputFiles;
    metaDataChannel.numOfThreads = numOfThreads;
    metaDataChannel.numConsumed = numConsumed;
    metaDataChannel.bufferSize = bufferSize;
    metaDataChannel.count = count;
    
    
    return metaDataChannel;

}


struct InputFileStruct createInputFileStruct(float alpha, float beta, int sizeOfArr) {
    struct InputFileStruct inputFileChannel; // create a new struct for each input file read
    
    //how to print contents of inputFile array
    // printf("inputFile[0] is %d\n", inputFileArrSample[0]);
    // int sizeOfArr23 = sizeof(inputFileArrSample) / sizeof(inputFileArrSample[0]);
    // for (int i = 0; i < 3; i++) {
    //     printf("line 52 %d \n", inputFileArrSample[i]); // each index position in this single array in channel struct
    // }
    // int sizeOfArrInCreateInputFileStruct = sizeof(inputFileArrSample) / sizeof(inputFileArrSample[0]);
    
    // inputFileChannel.inputArr = malloc((sizeOfArrInCreateInputFileStruct+1) * sizeof(int)); 


    inputFileChannel.sizeOfArr = sizeOfArr;

    
    // // print above to test
    // printf("64 sizeOfArrInCreateInputFileStruct is %d\n", sizeOfArrInCreateInputFileStruct); // 2


    // for (int i = 0; i <= sizeOfArrInCreateInputFileStruct + 1 /*3 */; i++) {
    //     inputFileChannel.inputArr[i] = 5;// print inputFile array to test    
    //     // printf("inputFile[0] is %d\n", inputFileChannel.inputArr[i]);
   
    // }
    // printf("72 sizeOfArrInCreateInputFileStruct is %d\n", sizeOfArrInCreateInputFileStruct); // 2

    // below is dummy data
    inputFileChannel.alpha = alpha; // from metadata file for input file 1
    inputFileChannel.beta = beta; // from metadata file for input file 1
    
    
    return inputFileChannel;

}
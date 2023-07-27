struct ChannelStruct {
     float * inputArr;
     float alpha;
     float beta;
     int sizeOfArr;
};


void printArrayStruct(const struct ChannelStruct* arrayStruct) {
    printf("printArrayStruct: ");
    for (int i = 0; i < 3; i++) {
        printf("%f ", arrayStruct->inputArr[i]); // each index position in this single array in channel struct
    }
    printf("\n");
}

void printStruct(const struct ChannelStruct * channelstruct) {
    printf("channelstruct alpha %f\n", channelstruct->alpha);
    printf("channelstruct beta %f\n", channelstruct->beta);
    
}


struct ChannelStruct createChannelStruct() {
    struct ChannelStruct channel; // create a new struct for each input file read
    
    // TO DO: write a parsing function stored in parsing.h to fgets the alpha/beta from meta file and place the values here, may need know the index position of the read file or track it somehow, havent thought about this

    // below is dummy data
    channel.alpha = 1.0; // from metadata file for input file 1
    channel.beta = 0.8; // from metadata file for input file 1
    

    return channel;
}

struct ChannelStruct addtoStruct(struct ChannelStruct testChannelStruct, float * outputArrayB, int sizeOfArr) {
    // testChannelStruct.inputArr = outputArrayB;

    testChannelStruct.inputArr = malloc(sizeOfArr * sizeof(int)); // Allocate memory for 3 integers
    testChannelStruct.sizeOfArr = sizeOfArr;

    
    // Copy values from outputArrayB to inputArr
    for (int i = 0; i < sizeOfArr; i++) {
        testChannelStruct.inputArr[i] = outputArrayB[i];
    }

    // printStruct( &testChannelStruct);
    // printArrayStruct( &testChannelStruct.inputArr);

    return testChannelStruct;
}
// broke out alpha and beta functions into separate .h



int storeStructIndex(int structIndex) {
    static int staticStructIndex = 0;
    staticStructIndex = structIndex;
    return staticStructIndex;
}

void printArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("printArray: arr[%d] is %f // ", i, arr[i]);
    }
    printf("\n");
}


// void destroyMyStruct(struct MyStruct * myStruct) {
//     // free(myStruct->inputArr);
//     // free(myStruct->alpha);
//     // free(myStruct->beta);
//     // free(myStruct->sizeOfArr);
//     free(myStruct);
//     printf("destroyed struct\n");
// }

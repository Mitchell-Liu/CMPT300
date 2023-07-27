void writeToOutputFile(float value) {

    FILE *file = fopen("output.txt", "a+");

    if (file == NULL) {
        printf("Unable to open the file.\n");
        
    }

    fprintf(file, "%.1f \n", value);

    fclose(file);

    // printf("Array written to the file successfully.\n");

}




void writeToOutputFileA(float * outputArrayB, int sizeOfArr) {

    int size = sizeof(outputArrayB) / sizeof(outputArrayB[0]);

    FILE *file = fopen("output.txt", "w");

    if (file == NULL) {
        printf("Unable to open the file.\n");
        
    }

        for (int i = 0; i < size+1; i++) {
        if (i < size + 1 - 1) {
            fprintf(file, "%.1f ", outputArrayB[i]);
        } else {
            fprintf(file, "%.1f\n", outputArrayB[i]);
        }
    }

    // for (int i = 0; i < size+1; i++) {
    //     // fprintf(file, "%.6f\n", outputArrayB[i]);
    //     fprintf(file, "%.1f\n", outputArrayB[i]);
        
    // }

    // for (int i = 0; i < size+1; i++) {
    //     // fprintf(file, "%.6f\n", outputArrayB[i]);
    //     fprintf(file, "%.1f\n", outputArrayB[i]);
        
    // }

    fclose(file);

    // printf("Array written to the file successfully.\n");

}

void writeToOutputFileB(float * outputArrayB, int sizeOfArr) {

    
    int size = sizeof(outputArrayB) / sizeof(outputArrayB[0]);

    FILE *file = fopen("output.txt", "a");

    if (file == NULL) {
        printf("Unable to open the file.\n");
        
    }

    for (int i = 0; i < size+1; i++) {
        if (i < size + 1 - 1) {
            fprintf(file, "%.1f ", outputArrayB[i]);
        } else {
            fprintf(file, "%.1f\n", outputArrayB[i]);
        }
    }

    // for (int i = 0; i < size+1; i++) {
    //     // fprintf(file, "%.6f\n", outputArrayB[i]);
    //     fprintf(file, "%.1f\n", outputArrayB[i]);
        
    // }

    fclose(file);

    // printf("Array written to the file successfully.\n");

}
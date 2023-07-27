// #include <cstdio>
void removeNewline(char* str) {
    size_t length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}

int parsingMetaData(char * metaDatapath, struct InputFileStruct *  inputFileStructArray)  {

  // printf("line 1 in parsingMetaData\n");
  char line[256];  // Example: Allocate space for a line of up to 255 characters
  FILE *fp = fopen(metaDatapath, "r");  // Open the file for reading
  if (fp == NULL) {
    printf("Failed to open the file.\n");
    return 1;  // Or perform appropriate error handling
  }
  int flag = 0;
  int counter = 0;
  while (fgets(line, sizeof(line), fp) != NULL) {
    // Process the line here (e.g., print it)
    // printf("15 counter: %d\n", counter);
    if (flag == 2) {
      inputFileStructArray[counter].beta = atof(line);
      flag = 0;
      // printf("28 beta %f\n", inputFileStructArray[counter].beta);
      counter++;
    }
    
    if (flag == 1) {
      inputFileStructArray[counter].alpha = atof(line);
      flag = 2;
      // printf("23 alpha %f\n", inputFileStructArray[counter].alpha);
    }

    if (strstr(line, "/input_files") != NULL) {
        
        // printf("String found: %s", line);
        strcpy(inputFileStructArray[counter].path, line);
        // printf("31 path: %s\n", (*inputFileStructArray)[counter].path);
        flag = 1;
        
        // Do something with the line that contains the specific string
    }


    // Process other lines as needed
    // printf("%s", line);
    

  }

  

  fclose(fp);
  return 1;
}



int * parsingInputFile(char * path, int bufferSize)  {
  removeNewline(path);
  // printf("line 1 in parsingInputFile\n");
  char line[256];  // Example: Allocate space for a line of up to 255 characters
  FILE *fp = fopen(path, "r");  // Open the file for reading
  // printf("58 %s\n", path);
  // printf("\n");
  if (fp == NULL) {
    // printf("Failed to open the file.\n");
    perror("Error opening file");
    return NULL;  // Or perform appropriate error handling
  }
  int bytesRead = 0;
  

  while ((bytesRead = fread(line, 1, bufferSize, fp)) > 0) {
    // sscanf(buffer, "%*[^0-9]%d", dest);
    // printf("75 %d\n",bytesRead);
    // Process the line here (e.g., print it)
    
    // line[bufferSize-1] = '\0';
    // printf("77 %s", line);

    // for (int i = 0; i < bufferSize; i++) {
    //     printf("82 %c\n", line[i]);
    // }
    // printf("\n");
    // fflush(stdin);
    // Process other lines as needed
    

  }
  //end of file read when bytesRead == 0;
  fclose(fp);
  return NULL;
}

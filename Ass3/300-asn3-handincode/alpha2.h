
float default_alpha2 = 1.0;

// typedef struct {
//     float sampleValueIntoFuncion;
//     float previous_sampleValIntoFunction;

// } AlphaValue;

// low-pass flter value (alpha)
// computes the alpha value given passed in parameters and returns alpha value
float alphaCalculation2(float alpha, float sampleValue, float previous_sampleValue) {

    float new_sampleValue;
    // conditional check
    // printf("line 16.h %f \n", alpha);

    if (!(alpha >= 0.000000 && alpha <= 1.000000)) {
        printf("The alpha is not between 0.0 and 1.0.\n");
        return -1;
    } 

    // printf("line 23 %f \n", previous_sampleValue);


    if ( previous_sampleValue == -1) {
        new_sampleValue = (alpha * sampleValue) + (1 - alpha); 

        return new_sampleValue;
    }

    

    new_sampleValue = (alpha * sampleValue) + (1 - alpha) * previous_sampleValue; 
    // calculates the return sample value


    // printf("line 41 %f \n", new_sampleValue);
    return new_sampleValue;
    

    // i need to return the new_sampleValue which is stored as the new previous_sampleValue
}

float findAlphaVal2(int inputNum, float prevSamples, float alpha) {

    // int sizeSamples = (sizeof(samples) / sizeof (samples[0])) + 1;
    // // printf("sizeSamples is %d\n", sizeSamples);
    // printf("49 inisde findAlphaVal2\n");
    float finalAlphaVal;
    // int samplesCount = 0;
    //print inputNum
    // printf("53 inputNum is %d\n", inputNum);
    // print prevSamples
    // printf("55 prevSamples is %f\n", prevSamples);
    // printf("56 alpha is %f\n", alpha);

    if (inputNum == -1) {
        printf("Empty \n");
    }


    // for (int i = 0; i < sizeSamples; i++) {
    //     if (samples[i] == -1.0) {
    //         printf("Empty \n");
    //     }
    //     else {
    //         // printf("line 37 %f \n", samples[i]);
    //     }
    // }

        // while (samplesCount < sizeSamples) {
        
        // printf("print samplesCount for INDEX POSITION %d\n", samplesCount);

        finalAlphaVal = alphaCalculation2(alpha, inputNum, prevSamples);
        if (finalAlphaVal == -1 ) {
            printf("finalAlphaVal is invalid\n");
        }
        // printf("print finalAlphaVal %f\n", finalAlphaVal);
        // prevSamples = finalAlphaVal;
        // outputArray[samplesCount] = finalAlphaVal;
        // printf("print outputArray[outputArrayCount] %f\n", outputArray[samplesCount]);

        // samplesCount++;

    // }
    // printf("88 print finalAlphaVal %f\n", finalAlphaVal);
    return finalAlphaVal;
    // 0.0 signifies entire looping has been run and outputArray is fully populated;

}

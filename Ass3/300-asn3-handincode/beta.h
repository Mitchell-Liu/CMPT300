
float default_beta = 1.0;

// typedef struct {
//     float sampleValueIntoFuncion;
//     float previous_sampleValIntoFunction;

// } BetaValue;

// amplification value (beta)
// computes the beta value given passed in parameters and returns beta value
float betaCalculation(float beta, float sampleValue) {

    float new_sampleValue;
    // conditional check
    // printf("line 16.h %f \n", beta);

    if (!(beta > 0.000000)) {
        printf("The beta is not greater than 0.0.\n");
        return -1;
    } 

    // printf("line 23 %f \n", beta);
    // printf("line 24 %f \n", sampleValue);

    new_sampleValue = (beta * sampleValue); 
    // calculates the return sample value

    // printf("line 29 %f \n", new_sampleValue);
    return new_sampleValue;
    
    // i need to return the new_sampleValue 
}

float findBetaVal(float * samples, float beta, float * outputArray) {

    int sizeSamples = (sizeof(samples) / sizeof (samples[0])) + 1;
    // printf("sizeSamples is %d\n", sizeSamples);

    float finalBetaVal;
    int samplesCount = 0;


    for (int i = 0; i < sizeSamples; i++) {
        if (samples[i] == -1.0) {
            printf("Empty \n");
        }
        else {
            // printf("line 52 %f \n", samples[i]);
        }
    }

        while (samplesCount < sizeSamples) {
        
        // printf("print samplesCount for INDEX POSITION %d\n", samplesCount);

        finalBetaVal = betaCalculation(beta, samples[samplesCount]);
        if (finalBetaVal == -1 ) {
            printf("beta value is invalid");
        }
        // printf("print finalBetaVal %f\n", finalBetaVal);

        outputArray[samplesCount] = finalBetaVal;
        // printf("print outputArray[samplesCount] %f\n", outputArray[samplesCount]);

        samplesCount++;

    }
    return 0.0;
    // 0.0 signifies entire looping has been run and outputArray is fully populated;

}

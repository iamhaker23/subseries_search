/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   timingExperiment.c
 * Author: Hakeem
 *
 * Created on 22 November 2017, 18:50
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "series.h"
#include "subseriesMatcher.h"

/*
 * Simple C Test Suite
 */

void seriesSubsearchAlgoTimingExperiment() {
    printf("timingExperiment seriesSubsearchAlgoTimingExperiment\n");
    
    
    int n = 10;
    int k = 3;
    MAX_RANDOM_VALUE = 10;
    SeriesList* list = newSeriesList();
    //populates list as an n*n list of series
    randomlyPopulateSeriesList(n, list);
    Series* lookingFor = newSeries();
    randomlyPopulateSeries(k, lookingFor);
    
    
    printf("Printing series list:\n");
    printSeriesList(list);
    printf("\nPrinting series to look for:\n");
    printSeries(lookingFor);
    
    
    clock_t start, end;
    double duration;
    
    start = clock();
    Result* result = subseriesMatching(lookingFor, list);
    end = clock();
    duration = (end - start) / CLOCKS_PER_SEC;
    
    printf("%d,%d,%lf,\n", n, k, duration);
    
    
}


int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% timingExperiment\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% seriesSubsearchAlgoTimingExperiment (timingExperiment)\n");
    seriesSubsearchAlgoTimingExperiment();
    printf("%%TEST_FINISHED%% time=0 seriesSubsearchAlgoTimingExperiment (timingExperiment) \n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
